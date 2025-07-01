#include "queue.h"

Note::Note() {

}

Note::Note(const Note& o_note) {
    data_x = o_note.data_x;
    data_y = o_note.data_y;
    next = o_note.next;
    prev = o_note.prev;
}

Note::~Note(){

}



Queue::Queue() {
    head = new Note;
    tail = new Note;
    head->next = tail;
    tail->prev = head;

}

Queue::~Queue() {
    delete head;
    delete tail;
}

//set to tail, get from head

void Queue::push(int x, int y) {
    Note* new_note = new Note;
    Note* tmp = new Note;
    tmp = tail;
    new_note->data_x = x;
    new_note->data_y = y;
    new_note->next = tail;
    new_note->prev = tail->prev;
    tmp->prev->next = new_note;
    tail->prev = new_note;
    delete tmp;
}

void Queue::pop(int& x, int& y) {

}

void Queue::remove() {

}