#include "game.h"
#include "screen.h" 
#include <iostream>

using namespace std;

#define SIZE_OF_SCREEN 3


Game::Game() {
    running = true;
    one_more = false;
}

Game::~Game() {

}

void Game::main_cycle() {
    do {
        while (running) {
            Screen main_screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
            main_screen.set_all_el('^');
            for (int i = 0; i < SIZE_OF_SCREEN; i++) {
                for (int j = 0; j < SIZE_OF_SCREEN; j++) {
                    cout << main_screen.get_el(i, j);
                }
            }
        } 
    } while (one_more);
}