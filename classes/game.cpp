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


Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    main_screen = new Screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
}

Game::~Game() {
    delete main_screen;
}

void Game::main_cycle() {
    do {
        while (running) {
            main_screen->set_all_el(EMPTY);
            show_screen();

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