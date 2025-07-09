#ifndef PLAYER_H
#define PLAYER_H

#include "queue.h"
#include "screen.h"

#define COUNT_OF_STAPS 3
#define WIN_SITUATIONS [[00, 01, 02], [10, 11, 12], [20, 21, 22], [00, 10, 20], [01, 11, 21], [02, 12, 22], [00, 11, 22], [02, 11, 20]]
#define COUNT_OF_WIN_SITUATIONS 8
#define COUNT_OF_SIGN_IN_WIN_SITUATIONS 3

class Player {
private:
     char* sign;
     Queue staps;

     void set_all_cell_empty();

public:
    Player(char* sign);

    ~Player();

    char* get_sign();

    void get_el(const int num_of_el, int& x, int& y);

    void make_stap(const int x, const int y);

    bool check_for_win(Screen* screen);

};

#endif