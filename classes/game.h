#ifndef GAME_H
#define GAME_H

#include "screen.h" 
#include "player.h"

class Game {
private:
    bool running;
    bool one_more;
    int counter;
    Screen* main_screen;
    Player* player_cross;
    Player* player_cyrcle;
    char* cell;
    int x, y;

    void show_screen();

    void who_go();

    void get_input_cell(int& x, int& y, const char* msg);

    int get_str_len(const char* str);

    int convert_char_to_int(const char el);
    
public:
    void main_cycle();

    Game();

    ~Game();

};

#endif