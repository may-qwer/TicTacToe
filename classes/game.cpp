#include "game.h"
#include <iostream>

using namespace std;

#define SIZE_OF_SCREEN 3
#define BLUE_CROSS "\033[1;34mX\033[0m"
#define RAD_CYRCLE "\033[1;31mO\033[0m"
#define EMPTY " "
#define BLUE "\033[1;34m"
#define RAD "\033[1;31m"
#define RESET "\033[0m"
#define MSG_INPUT "Enter number, like 11, of cell, where you wont to set you sign: "
#define MSG_NUT_CORRECT_INPUT "Your input is not correct. Try again: "



Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    main_screen = new Screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
    player_cross = new Player(BLUE_CROSS);
    player_cyrcle = new Player(RAD_CYRCLE);
    cell = new char[2];
}

Game::~Game() {
    delete main_screen;
    delete player_cross;
    delete player_cyrcle;
}

void Game::main_cycle() {
    do {
        while (running) {
            main_screen->set_all_el(EMPTY);
            show_screen();
            who_go();
            get_input_cell(x, y, MSG_INPUT);
            


            counter++;
            //tmp
            running = false;
        } 
    } while (one_more);
}

void Game::show_screen() {
    cout << "  | 1 | 2 | 3 |" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < SIZE_OF_SCREEN; i++) {
        cout << i+1 << " | ";
        for (int j = 0; j < SIZE_OF_SCREEN; j++) {
            cout << main_screen->get_el(i, j);
            cout << " | ";
        }
        cout << "\n---------------";
        cout << endl;
    }
    cout << endl;
}

void Game::who_go() {
    if (counter%2 == 0) {
        cout << BLUE << "Cross" << RESET << "is going now." << endl;
    } else {
        cout << RAD << "Cyrcle" << RESET << "is going now." << endl;
    }
}

void Game::get_input_cell(int& x, int& y, const char* msg)  {
    cout << msg;
    cin >> cell;
    if (get_str_len(cell) != 2) {
        get_input_cell(x, y, MSG_NUT_CORRECT_INPUT);
    }
    int tmp_x, tmp_y;
    tmp_x = convert_char_to_int(cell[0]) + 1;
    tmp_y = convert_char_to_int(cell[1]) + 1;
    if ((tmp_x < 1) || (tmp_x > 3) || (tmp_y < 1) || (tmp_y > 3)) {
        get_input_cell(x, y, MSG_NUT_CORRECT_INPUT);
    }
    x = tmp_x;
    y = tmp_y;
}

int Game::get_str_len(const char* str) {
    int len = 0;
    while(str[len] != 0) {
        len++;
    }
    return len;
}

int Game::convert_char_to_int(const char el) {
    return int(el) - int('0');
}