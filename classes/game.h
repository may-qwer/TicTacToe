#ifndef GAME_H
#define GAME_H

class Game {
private:
    bool running;
    bool one_more;
    
public:
    void main_cycle();

    Game();

    ~Game();

    void show_screen();

};

#endif