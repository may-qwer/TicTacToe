#ifndef PLAYER_H
#define PLAYER_H

#include "queue.h"

#define COUNT_OF_STAPS 3

class Player {
private:
     char* cell;
     char* sign;
     Queue staps;

public:
    Player(char* sign);

    ~Player();

    char* get_cell();

    char* get_sign();

    void set_cell();

    void make_stap();

    void check_for_win();

};

#endif