#include "game.h"
#include <iostream>

using namespace std;

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



Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    main_screen = new Screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
    player_cross = new Player(BLUE_CROSS);
    player_cicrle = new Player(RAD_CIRCLE);
    cell = new char[2];
}

Game::~Game() {
    delete main_screen;
    delete player_cross;
    delete player_cicrle;
    delete cell;
}

void Game::main_cyrcle() {
    do {
        while (running) {
            main_screen->set_all_el(EMPTY);
            show_screen();
            who_go();
            get_input_cell(x, y, MSG_INPUT);
            // set_els();
            // make_stap();


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
        cout << BLUE << "Cross" << RESET << " is going now." << endl;
    } else {
        cout << RAD << "Cyrcle" << RESET << " is going now." << endl;
    }
}

void Game::get_input_cell(int& x, int& y, const char* msg)  {
    cout << msg;
    cin >> cell;
    if (get_str_len(cell) != 2) {
        get_input_cell(x, y, MSG_NOT_CORRECT_INPUT);
    }
    x = convert_char_to_int(cell[0]) - 1;
    y = convert_char_to_int(cell[1]) - 1;
    if ((x < 0) || (x > 2) || (y < 0) || (y > 2)) {
        get_input_cell(x, y, MSG_NOT_CORRECT_INPUT);
    }
    if (main_screen->get_el(x, y) != EMPTY) {
        get_input_cell(x, y, MSG_NOT_EMPTY_CELL);
    }
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

void Game::make_stap() {
    if (counter%2 == 0) {
        player_cross->make_stap(x, y);
    } else {
        player_cicrle->make_stap(x, y);
    }
}

void Game::set_els() {
    int cross_x, cross_y, circle_x, circle_y;
    for (int i = 0; i < COUNT_OF_STAPS; i++) {
        player_cross->get_el(i+1, cross_x, cross_y);
        player_cross->get_el(i+1, circle_x, circle_y);
        if ((cross_x != -1) && (cross_y != -1)) {
            main_screen->set_el(cross_x, cross_y, BLUE_CROSS);
        }
        if ((circle_x != -1) && (circle_y != -1)) {
            main_screen->set_el(circle_x, circle_y, RAD_CIRCLE);
        }
    }
}