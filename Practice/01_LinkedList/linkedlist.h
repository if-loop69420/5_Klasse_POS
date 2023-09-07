#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <memory>

using namespace std;

class Node
{
public:
    Node(int value);
    void insert(int value);
    void remove(int value);
    bool find(int value);
    unique_ptr<Node> get_next();
    int value;

private:
    unique_ptr<Node> next;
};


class LinkedList
{
public:
    LinkedList();
    LinkedList(int value);
    void insert(int value);
    void remove(int value);
    bool find(int value);

private:
    unique_ptr<Node> head;
};

#endif // LINKEDLIST_H
