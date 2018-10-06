#include "main.hpp"

int main(void) {

    Input   input("ft_retro.log");
    WINDOW *w = initscr();
    bool    loop = true;
    int     c;

    clear();
	noecho();
    notimeout(w, true);
	cbreak();
    keypad(w, TRUE);

    while (loop) {
        
        // Store Last Key + Log
        input.setLastKey(wgetch(w));
    }

    clrtoeol();
	refresh();
	endwin();
    return 0;
}