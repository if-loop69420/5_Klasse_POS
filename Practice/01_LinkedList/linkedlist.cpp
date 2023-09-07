#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = unique_ptr<Node>(nullptr);
}

LinkedList::LinkedList(int value){
    this->head = unique_ptr<Node>(new Node(value));
}

void LinkedList::insert(int value) {
    if(this->head == nullptr) {
        auto to_insert = new Node(value);
        this->head = unique_ptr<Node>(to_insert);
    } else {
        this->head->insert(value);
    }
}


void LinkedList::remove(int value) {
    if(this->head->value == value) {
        this->head = this->head->get_next();
    } else {
        this->head->remove(value);
    }
}


bool LinkedList::find(int value) {
    if(this->head->value == value) {
        return true;
    } else {
        return this->head->find(value);
    }
}


Node::Node(int value) {
    this->value = value;
    this->next = unique_ptr<Node>(nullptr);
}

void Node::insert(int value) {
    if(this->value > value) {
        this->next->insert(value);
    } else {
        auto to_insert = new Node(value);
        to_insert->next = std::move(this->next);
        this->next = unique_ptr<Node>(to_insert);
    }
}

void Node::remove(int value) {
    if(this->next != nullptr) {
        if(this->next->value == value) {
            this->next = std::move(this->next->next);
        } else {
            this->next->remove(value);
        }
    }
}

bool Node::find(int value) {
    if(this->value == value) {
        return true;
    } else if(this->next == nullptr){
        return false;
    } else {
        return this->next->find(value);
    }
}

unique_ptr<Node> Node::get_next() {
    return std::move(this->next);
}
