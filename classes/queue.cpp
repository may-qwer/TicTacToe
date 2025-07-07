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

void Note::set_data(const int x, const int y) {
    data_x = x;
    data_y = y;
}

void Note::set_next(Note* n) {
    next = n;
}

void Note::set_prev(Note* p) {
    prev = p;
}

int Note::get_x() {
    return data_x;
}

int Note::get_y() {
    return data_y;
}

Note* Note::get_next() {
    return next;
}

Note* Note::get_prev() {
    return prev;
}

Queue::Queue(int l) {
    len = l;
    head = new Note;
    tail = new Note;
    head->set_next(tail);
    head->set_prev(0);
    tail->set_next(0);
    tail->set_prev(head);
}

Queue::~Queue() {
    delete head;
    delete tail;
}

//set to tail, get from head

void Queue::push(const int x, const int y) {
    if (len != get_len()) {
        Note* new_note = new Note;
        new_note->set_data(x, y);
        new_note->set_next(tail);
        tail->get_prev()->set_next(new_note);
        new_note->set_prev(tail->get_prev());
        tail->set_prev(new_note);
    }
}

void Queue::peek(int& x, int& y) {
    x = head->get_next()->get_x();
    y = head->get_next()->get_y();
}

void Queue::peek(const int num_of_el, int& x, int& y) {
    Note* tmp = head;
    for (int i = 0; i < num_of_el; i++) {
        tmp = tmp->get_next();
    }
    x = tmp->get_x();
    y = tmp->get_y();
}

void Queue::pop(int& x, int& y) {
    if (get_len() != 0) {
        Note* tmp = new Note;
        tmp = head->get_next();
        x = head->get_next()->get_x();
        y = head->get_next()->get_y();
        head->set_next(head->get_next()->get_next());
        delete tmp;
    }
}

int Queue::get_len(Note* el) {
    if (el != tail) {
        return get_len(el->get_next()) + 1; 
    }
    return -1;
}

int Queue::get_len() {
    return get_len(head);
}

int Queue::get_max_len() {
    return len;
}

void Queue::remove() {
    int tmp_x, tmp_y;
    while (head->get_next() != tail) {
        pop(tmp_x, tmp_y);
    }
}