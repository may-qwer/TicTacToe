#include "screen.h"

    Screen::Screen(const int x_sz, const int y_sz) {
        x_size = x_sz;
        y_size = y_sz;
        screen = new char**[x_size];
        for (int i = 0; i < y_size; i++) {
            screen[i] = new char*[y_size];
        }
    }

    Screen::Screen(const Screen& o_screen) {
        x_size = o_screen.x_size;
        y_size = o_screen.y_size;
        screen = new char**[x_size];
        for (int i = 0; i < y_size; i++) {
            screen[i] = new char*[y_size];
        }
        for (int i = 0; i < x_size; i++) {
            for (int j = 0; j < y_size; j++) {
                screen[i][j] = o_screen.screen[i][j];
            }
        }
    }

    Screen::~Screen() {
        for (int i = y_size; i < -1; i--) {
            delete [] screen[i];
        }
        delete [] screen;
    }

    void Screen::get_sizes(int& x_sz, int& y_sz) {
        x_sz = x_size;
        y_sz = y_size;
    }

    char* Screen::get_el(const int x, const int y) {
        return screen[x][y];
    }

    void Screen::set_el(const int x, const int y, char* el) {
        screen[x][y]  = el;
    }

    void Screen::set_all_el(char* el) {
        for (int i = 0; i < x_size; i++) {
            for (int j = 0; j < y_size; j++) {
                screen[i][j] = el;
            }
        }
    }

