#include "game.h"
#include <iostream>

using namespace std;

Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    main_screen = new Screen(SIZE_OF_SCREEN, SIZE_OF_SCREEN);
    main_screen->set_all_el(EMPTY);
    player_cross = new Player(BLUE_CROSS);
    player_circle = new Player(RED_CIRCLE);
    cell = new char[2];
    ans_one_more = new char[1];
}

Game::~Game() {
    delete main_screen;
    delete player_cross;
    delete player_circle;
    delete [] cell;
    delete [] ans_one_more;
}

void Game::main_cyrcle() {
    int x, y;
    do {
        while (running) {
            show_screen();
            who_go();
            get_input_cell(x, y, MSG_INPUT);
            make_stap(x, y);
            set_els_to_screen();
            check_win();
            counter++;
        } 
        show_screen();
        congratulation();
        set_start_value();
        one_more = is_one_more();
    } while (one_more);
}

void Game::show_screen() {
    cout << endl;
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
        cout << RED << "Cyrcle" << RESET << " is going now." << endl;
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

void Game::make_stap(const int x, const int y) {
    if (counter%2 == 0) {
        player_cross->make_stap(x, y);
    } else {
        player_circle->make_stap(x, y);
    }
}

void Game::set_els_to_screen() {
    int cross_x, cross_y, circle_x, circle_y;
    main_screen->set_all_el(EMPTY);
    for (int i = 0; i < COUNT_OF_STAPS; i++) {
        player_cross->get_el(i+1, cross_x, cross_y);
        player_circle->get_el(i+1, circle_x, circle_y);
        if ((cross_x != -1) && (cross_y != -1)) {
            main_screen->set_el(cross_x, cross_y, BLUE_CROSS);
        }
        if ((circle_x != -1) && (circle_y != -1)) {
            main_screen->set_el(circle_x, circle_y, RED_CIRCLE);
        }
    }
}

void Game::check_win() {
    if (counter%2 == 0) {
        running = !(player_cross->check_for_win(main_screen));
    } else {
        running = !(player_circle->check_for_win(main_screen));
    }
}

void Game::congratulation() {
    if ((counter-1)%2 == 0) {
        cout << BLUE << "Cross" << RESET;
    } else {
        cout << RED << "Circle" << RESET;
    }
    cout << " is the WINNER!!!\nCONGRATILATIONS!!!!!" << endl;
}

void Game::set_start_value() {
    counter = 0;
    main_screen->set_all_el(EMPTY);
    player_cross->set_all_cell_empty();
    player_circle->set_all_cell_empty();
    running = true;
}

bool Game::is_one_more(const char* msg) {
    cout << msg;
    cin >> ans_one_more;
    if (get_str_len(ans_one_more) != 1) { 
        return is_one_more(MSG_NOT_CORRECT_ONE_MORE_ANS);
    }
    if ((ans_one_more[0] != 'Y') && (ans_one_more[0] != 'y') && (ans_one_more[0] != 'n') && (ans_one_more[0] != 'N')) {
        return is_one_more(MSG_NOT_CORRECT_ONE_MORE_ANS);
    }
    if ((ans_one_more[0] == 'y') || (ans_one_more[0] == 'Y')) {
        return true;
    }
    return false;
}
