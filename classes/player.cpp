#include "player.h"

Player::Player(char* sign) : staps(3){
    this->sign = sign;
    set_all_cell_empty();
}

Player::~Player() {
    staps.remove();
}

char* Player::get_sign() {
    return sign;
}

void Player::get_el(const int num_of_el, int& x, int& y) {
    staps.peek(num_of_el, x, y);
}

void Player::make_stap(const int x, const int y) {
    staps.pop();
    staps.push(x, y);
}

bool Player::check_for_win(Screen* screen) {
    int k = 0;
    int x, y;
    for (int i = 0; i < COUNT_OF_WIN_SITUATIONS; i++) {
        for (int j = 0; j < COUNT_OF_SIGN_IN_WIN_SITUATIONS; j++) {
            x = WIN_SITUATIONS[i][j]/10;
            y = WIN_SITUATIONS[i][j]%10;
            if (screen->get_el(x, y) == sign) {
                k++;
            }
        }
        if (k == 3) {
            return true;
        }
        k = 0;
        x = 0;
        y = 0;
    }
    return false;
}

void Player::set_all_cell_empty() {
    for (int i = 0; i < staps.get_max_len(); i++) {
        staps.push(-1, -1);
    }
}
