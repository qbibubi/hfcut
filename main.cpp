#include <ncurses.h>

void menu(WINDOW* win, int selected, char options[5][8]);

int main(int argc, char const *argv[])
{
    char welcome[] = "Welcome to hfuct!";
    char options[5][8] = {"PLAY", "OPTIONS", "HELP", "CREDITS", "EXIT"};
    int selected = 0;
    int yMax, xMax;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, yMax, xMax);

    WINDOW* win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
    box(win, 0, 0);

    menu(win, selected, options);

    while (int ch = wgetch(win))
    {
        switch (ch)
        {
        case 'w':
            selected--;
            selected = (selected < 0) ? 4 : selected;
            break;
        case 's':
            selected++;
            selected = (selected > 4) ? 0 : selected;
            break;

        default:
            selected = 0;
            break;
        }

        menu(win, selected, options);
    }
    
    endwin();
}

void menu(WINDOW* win, int selected, char options[5][8]) {
    for (size_t i = 0; i < 5; i++)
    {
        if (i == selected)
            wattron(win, A_REVERSE);
        mvwprintw(win, i+1, 1, "%s", options[i]);
        wattroff(win, A_REVERSE);
    }
}