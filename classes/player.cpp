#include "player.h"

Player::Player(char* sign) : staps(3){
    this->sign = sign;
}

Player::~Player() {

}

char* Player::get_cell(const int x, const int y) {

}

char* Player::get_sign() {
    return sign;
}

void Player::set_cell(const int x, const int y) {
    staps.push(x, y);
}

void Player::make_stap() {

}

void Player::check_for_win() {

}