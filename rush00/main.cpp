#include "main.hpp"

int main(void) {

    Input   input("ft_retro.log");
    Screen  screen(HEIGHT, WIDTH);

    bool    loop = true;
    
    int x = screen.getHeight();
    int y = screen.getWidth();
    WINDOW *window = screen.getWindow();

    clear();
	noecho();
    notimeout(screen.getWindow(), true);
	cbreak();
    keypad(screen.getWindow(), TRUE);

    while (loop) {
        
        // Store Last Key + Log
        input.setLastKey(wgetch(screen.getWindow()));
        clear();
        getmaxyx(window, x, y);
        mvprintw(y / 10, x / 2, "o");
        refresh();
        input.log(FILE, "x == " ,x);
        input.log(FILE, "y == ", y);
    }

    clrtoeol();
	refresh();
	endwin();
    return 0;
}