#ifndef GAME_H
#define GAME_H

#include "screen.h" 

class Game {
private:
    bool running;
    bool one_more;
    Screen* main_screen;
    
public:
    void main_cycle();

    Game();

    ~Game();

    void show_screen();

};

#endif