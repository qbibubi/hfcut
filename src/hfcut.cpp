#include "../include/hfcut.hpp"

void HFCUT::run() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int row, col;
    getmaxyx(stdscr, row, col);

    Menu m = Menu("Welcome to the hfcut!", "");
    m.AddElement(0, 99, false);


    while (true)
    {
        // TODO: Implement the menu.
        // TODO: Implement the BPM.
        // TODO: Implement the counter.
        // TODO: Implement the exit.

        if (getch() == 'q')
        {
            printw("q pressed");
        }
    }

    endwin();
}