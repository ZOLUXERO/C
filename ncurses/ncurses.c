#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

// macro para definir el comportamiento creo
#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

const char kubeBuffer[4096];

void pipeexecl()
{
    int link[2];
    pid_t pid;
    char foo[4096];

    if (pipe(link) == -1)
        die("pipe");

    if ((pid = fork()) == -1)
        die("fork");

    if (pid == 0)
    {
        dup2(link[1], STDOUT_FILENO);
        dup2(link[1], STDERR_FILENO);
        close(link[0]);
        close(link[1]);
        // execl("/usr/local/bin/kubectl", "kubectl", "get", "all", (char *)0);
        // execl("/usr/local/bin/kubectl", "kubectl", "config", "get-contexts", (char *)0);
        // execl("/bin/tail", "tail", "-f", "/var/log/apt/history.log", (char *)0);
        die("system");
    } else {
        close(link[1]);
        int nbytes = read(link[0], foo, sizeof(foo));
        printf("%.*s", nbytes, foo);
        wait(NULL);
    }
}

int main() {
    int ch;
    char buf[2000];
    // FILE *command = popen("tail -f /var/log/apt/history.log", "r");
    // 2>&1 adds stdout and stderr to the output stdin doesn't work with this:
    FILE *command = popen("kubectl get all -o wide 2>&1", "r");

    initscr();
    // WINDOW *win = newwin(LINES -1, COLS, 0, 0); // Rows: 10, Columns: 30, Start position: (1, 1)
    WINDOW *padd = newpad(0, 0);
    // box(win, 0, 0); // Add a box around the window
    // wrefresh(win);
    wprintw(padd, "adfa");
    wrefresh(padd);
    wgetch(padd);
    prefresh(padd, 0, 0, 0, 0, 0, 0);
    endwin();

    int row, col, maxY, maxX;
    // getmaxyx(win, maxY, maxX);
    row = 1;
    col = 2;
    int contador = 0;
    int curr = 0;
    // scrollok(win, TRUE);
    // while (fgets(buf, sizeof(buf), command) != NULL)
    // {
    //     for (const char *ptr = buf; *ptr != '\0'; ++ptr) {
    //         if (contador > curr)
    //         {
    //             row++;
    //             col = 2;
    //             curr = contador;
    //             mvwprintw(win, row, col, "%d", contador);
    //             col = 6;
    //         }
    //         mvwprintw(win, row, col, "%c", *ptr);
    //         wrefresh(win);

    //         // Move to the next row if the current row is filled
    //         if (++col >= maxX - 2) {
    //             col = 2;
    //             if (++row >= maxY - 2) {
    //                 // wscrl(win, 10);
    //                 // wsetscrreg(win, 49, 59);
    //                 // break; // Stop if the window is filled
    //             }
    //         }
    //     }
    //     contador++;
    // }
    // keypad(win, TRUE);
    // int comp = 1;
    // char test[1000];
    // while (comp == 1)
    // {
    //     int c = wgetch(win);
    //     switch (c)
    //     {
    //     case KEY_UP:
    //         wscrl(win, -1);
    //         wprintw(win, "key up");
    //         break;
    //     case KEY_DOWN:
    //         wscrl(win, +1);
    //         wprintw(win, "key down");
    //         break;
        
    //     default:
    //         wclear(win);
    //         wprintw(win, "not reading");
    //         comp = 2;
    //         break;
    //     }
    //     wrefresh(win);
    // }
    
    // wrefresh(win);
    // wgetch(win);

    // endwin();

    return 0;
    
    

    // initscr();
    // WINDOW *win = newwin(LINES -3, COLS, 0,0); // Rows: 10, Columns: 30, Start position: (1, 1)
    // box(win, 0, 0); // Add a box around the window
    // wrefresh(win);

    // // Your long text
    // const char *longText = "This is a very long text that you want to display without breaking the box in ncurses. You need to handle the wrapping manually. asdfas fasf sdafasd fasfas fasfdsfa sfsdfasf asfsafsdf asfa sfsfsad fasdf asfasdfas fasfd asfsf asdf asf";

    // // Print the long text without breaking the box
    // int row, col, maxRows, maxCols;
    // getmaxyx(win, maxRows, maxCols); // Get the dimensions of the window
    // row = 1; // Start printing from the second row to avoid the box
    // col = 2; // Start printing from the third column to leave space for the box border

    // FILE *command = popen("kubectl config get-contextsss", "r");
    // FILE *command = popen("kubectl get all -o wide", "r");
    // char buf[2000];
    // // touchwin(win);
    // // getch();
    // wrefresh(win);
    // // if (command == NULL)
    // // {
    // //     printw("Error: command is NULL");
    // // }
    // // scrollok(win, TRUE);win
    // mvwprintw(win, 1, 1,str);
    
    // // pclose(command);
    // // delwin(win);
    // // endwin();

    // wgetch(win);


    // for (const char *ptr = longText; *ptr != '\0'; ++ptr) {
    //     mvwprintw(win, row, col, "%c", *ptr);
    //     wrefresh(win);

    //     // Move to the next row if the current row is filled
    //     if (++col >= maxCols - 3) {
    //         col = 2;
    //         if (++row >= maxRows - 2)
    //             break; // Stop if the window is filled
    //     }
    // }
    // while (fgets(buf, sizeof(buf), command) != NULL)
    // {
    //     // mvwprintw(win, 1, 2, "%s", buf);
    //     wprintw(win, "aaa");
    //     wscrl(win, 1);
    //     wrefresh(win);
    // }

    // Wait for a key press before exiting
    // wgetch(win);
    // // Clean up and exit
    // endwin();
    // return 0;

}

