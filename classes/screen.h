#ifndef SCREEN_H
#define SCREEN_H

class Screen {
private:
    char*** screen;
    int x_size;
    int y_size;

public:
    Screen(const int x_sz, const int y_sz);

    Screen(const Screen& o_screen);

    ~Screen();

    void get_sizes(int& x_size, int& y_size);

    char* get_el(const int x, const int y);

    void set_el(const int x, const int y, char* el);

    void set_all_el(char* el);

};

#endif