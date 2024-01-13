#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

// macro para definir el comportamiento creo
#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

char kube_buffer[4096];
char *result[2048];
int scroll_offset;

void display_result(WINDOW *reference_window, char *result[], int start_line, int num_lines) {
    wclear(reference_window);
    int current_col, current_row, stri, rows_in_screen, columns_in_screen;
    current_col = 0, current_row = 0, stri = 0, scroll_offset = 0;
    getmaxyx(reference_window, rows_in_screen, columns_in_screen);

    for (int i = 0; i < num_lines; ++i) {
        stri = strlen(result[start_line + i]);
        for (int j = 0; j < stri; j++) {
            mvwprintw(reference_window, current_row, current_col, "%c", result[start_line + i][j]);

            if (current_col++ >= columns_in_screen) {
                current_col = 0;
                current_row++;
                num_lines--;
                scroll_offset++;
            }
        }
        current_col = 0;
        current_row++;
    }
    wrefresh(reference_window);
}

void clean_result_buffer(int num_lines) {
    // Liberar memoria
    for (int i = 0; i < num_lines; ++i) {
        free(result[i]);
    }
}

WINDOW* generate_window(int top_y, int top_x, int position_y, int position_x, bool debug) {
    WINDOW *main_frame = newwin(top_y, top_x, position_y, position_x);
    if (debug) {
        int y, x;
        getmaxyx(main_frame, y, x);
        box(main_frame, 0, 0);
        mvwprintw(main_frame, y / 2, x / 2 - 13, "Current screen size y %d x %d", y, x);
        wrefresh(main_frame);
        wgetch(main_frame);
        wclear(main_frame);
    }
    return main_frame;
}

char* wsplit_string(char *string, int window_size) {
    int split_size, vector_size, size_last_vector, start_position, final_position;
    int size_initial_string =  sizeof(string) / sizeof(char);
    double z = (double)size_initial_string / window_size;
    split_size = (int)z;
    start_position = 0;
    final_position, vector_size = window_size;

    if (z - (int)z != 0) {
        size_last_vector = (window_size * split_size) - size_initial_string;
        split_size++;
    }
    
    // char *string_ptr[split_size];
    char *string_ptr = (char*)malloc(split_size * sizeof(char));
    for (int i = 0; i < split_size; i++) {
        string_ptr[i] = (char*)malloc(vector_size + 1);
        memcpy(string_ptr[i], string + start_position, final_position);
        if (i + 1 == split_size)
            vector_size = size_last_vector;
        start_position = start_position + window_size;
        final_position = final_position + vector_size;
    }
    return string_ptr;
}

int main() {
    int maxY, maxX;
    int maxYwin, maxXwin;
    int num_lines = 0;

    // Variables para el desplazamiento
    int start_line = 0;
    bool keep_running = TRUE;

    initscr();
    getmaxyx(stdscr, maxY, maxX);

    // WINDOW *main_frame = newwin(maxY -10, maxX, 10, 0); // Rows: 10, Columns: 30, Start position: (1, 1)
    WINDOW *main_frame = generate_window(maxY - 11, maxX, 11, 0, FALSE);

    // 2>&1 adds stdout and stderr to the output stdin doesn't work with this:
    FILE *command = popen("kubectl get all -o wide 2>&1", "r");
    if (command == NULL) {
        printf("Error: executing kubectl command");
        return 1;
    }
    
    while (fgets(kube_buffer, sizeof(kube_buffer), command) != NULL) {
        result[num_lines] = strdup(kube_buffer);
        ++num_lines;
    }
    box(main_frame, 0, 0);
    wrefresh(main_frame);

    // Mostrar el resultado inicial
    // WINDOW *info_window = newwin(maxY -12, maxX -4, 11, 2); // Rows: 10, Columns: 30, Start position: (1, 1)
    WINDOW *info_window = generate_window(maxY - 13, maxX - 4, 12, 2, FALSE); // Rows: 10, Columns: 30, Start position: (1, 1)
    keypad(info_window, TRUE);
    // wrefresh(info_window);
    getmaxyx(info_window, maxYwin, maxXwin);
    display_result(info_window, result, start_line, maxYwin);
    while (keep_running)
    {
        int key_press = wgetch(info_window);
        switch (key_press)
        {
        case KEY_UP:
            if (start_line > 0)
                --start_line;
            break;
        case KEY_DOWN:
            if (start_line < (num_lines + scroll_offset) - maxYwin)
                ++start_line;
            break;
        case '/':
            WINDOW *search_frame = generate_window(3, maxX, maxY - (maxY - 8), 0, FALSE);
            box(search_frame, 0, 0);
            wrefresh(search_frame);
            char escape;
            while (escape = wgetch(search_frame)) {
                if (escape == 27)
                    break;
            }
            wclear(search_frame);
            wrefresh(search_frame);
            delwin(search_frame);
            break;
             
        default:
            wclear(main_frame);
            wprintw(main_frame, "not reading");
            keep_running = FALSE;
            break;
        }
        display_result(info_window, result, start_line, maxYwin);
    }
    wgetch(main_frame);

    clean_result_buffer(num_lines);
    
    pclose(command);
    endwin();
    return 0;
}