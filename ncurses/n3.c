#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    char buf[2000];

    initscr();

    int row, col, maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);
    WINDOW *win = newwin(maxY, maxX, 0, 0); // Rows: 10, Columns: 30, Start position: (1, 1)
    box(win, 0, 0);
    wrefresh(win);
    wgetch(win);
    endwin();
    return 0;
}