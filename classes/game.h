#ifndef GAME_H
#define GAME_H

#include "screen.h" 
#include "player.h"

#define SIZE_OF_SCREEN 3
#define BLUE_CROSS "\033[1;34mX\033[0m"
#define RAD_CIRCLE "\033[1;31mO\033[0m"
#define EMPTY " "
#define BLUE "\033[1;34m"
#define RAD "\033[1;31m"
#define RESET "\033[0m"
#define MSG_INPUT "Enter number, like 11, of cell, where you wont to set you sign: "
#define MSG_NOT_CORRECT_INPUT "Your input is not correct. Try again: "
#define MSG_NOT_EMPTY_CELL "You choose not empty cell. Try again: "

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

    bool is_one_more();
    
public:
    void main_cyrcle();

    Game();

    ~Game();

};

#endif