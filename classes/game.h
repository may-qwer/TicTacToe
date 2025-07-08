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
    Player* player_cicrle;
    char* cell;

    void show_screen();

    void who_go();

    void get_input_cell(int& x, int& y, const char* msg);

    int get_str_len(const char* str);

    int convert_char_to_int(const char el);

    void make_stap(const int x, const int y);

    void set_els_to_screen();

    void check_win();
    
public:
    void main_cyrcle();

    Game();

    ~Game();

};

#endif