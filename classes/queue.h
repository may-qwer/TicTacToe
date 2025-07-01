#ifndef QUEUE_H
#define QUEUE_H

class Note {
public:
    int data_x;
    int data_y;
    Note* next;
    Note* prev;

    Note();

    Note(const Note& o_note);

    ~Note();

};

class Queue {
private:
    Note* head;
    Note* tail;

public:
    Queue();

    ~Queue();

    void push(int x, int y);

    void pop(int& x, int& y);

    void remove();

};

#endif