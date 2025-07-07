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
    int tmp_x, tmp_y;
    staps.pop(tmp_x, tmp_y);
    staps.push(x, y);
}

void Player::check_for_win() {

}

void Player::set_all_cell_empty() {
    for (int i = 0; i < staps.get_max_len(); i++) {
        staps.push(-1, -1);
    }
}