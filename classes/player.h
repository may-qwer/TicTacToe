#ifndef PLAYER_H
#define PLAYER_H

#include "queue.h"

#define COUNT_OF_STAPS 3

class Player {
private:
     char* cell;
     char* sign;
     Queue staps;

     void set_all_cell_empty();

public:
    Player(char* sign);

    ~Player();

    char* get_sign();

    void get_el(const int num_of_el, int& x, int& y);

    void make_stap(const int x, const int y);

    void check_for_win();

};

#endif