#include <chrono>
#include <ctime>
#include <curses.h>
#include <unistd.h>

void init_curses() {
    initscr();
    raw();
    curs_set(0);
    nodelay(stdscr, true);
    timeout(250);
}

int main() {
    init_curses();
    int ch;
    while (true) {
        auto givemetime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        mvprintw(0, 0, "Current time : %s", ctime(&givemetime));
        ch = getch();
        switch (ch) {
            case 'q':
                endwin();
                return 0;
                break;
        }
        // clear();
        curs_set(0);
        refresh();
    }
}
