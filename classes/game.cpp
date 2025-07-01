#include "game.h"
#include <iostream>

using namespace std;

#define SIZE_OF_SCREEN 3


Game::Game() {
    running = true;
    one_more = false;
    main_screen = new Screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
}

Game::~Game() {
    delete main_screen;
}

void Game::main_cycle() {
    do {
        while (running) {
            main_screen->set_all_el(' ');
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