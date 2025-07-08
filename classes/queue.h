#ifndef QUEUE_H
#define QUEUE_H

class Note {
private:
    int data_x = -127;
    int data_y = -127;
    Note* next = nullptr;
    Note* prev = nullptr;

public:
    Note();

    Note(const Note& o_note);

    ~Note();

    void set_data(const int x, const int y);

    void set_next(Note* n);

    void set_prev(Note* p);

    int get_x();

    int get_y();

    Note* get_next();

    Note* get_prev();

};

class Queue {
private:
    Note* head;
    Note* tail;
    int len;

    int get_len(Note* el);

public:
    Queue(int l);

    ~Queue();

    void push(const int x, const int y);

    void peek(int& x, int& y);

    void peek(const int num_of_el, int& x, int& y);

    void pop(int& x, int& y);

    void pop();

    int get_max_len();

    int get_len();

    void remove();

};

#endif