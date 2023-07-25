#ifndef MAZE_H
#define MAZE_H
#include <iostream>

class Maze
{
    public: 
    void maze_generate();
    void create();
    void print();
    void setCapacityX(int x);
    void setCapacityY(int y);

    private:
    struct Node
    {
        char* top;
        char* down;
        char* left;
        char* right;
        Node* t;
        Node* d;
        Node* l;
        Node* r;
        Node(): top(nullptr), down(nullptr), left(nullptr), right(nullptr), t(nullptr), d(nullptr), l(nullptr), r(nullptr) {}
    };
    Node* start;
    int CAPACITY_X;
    int CAPACITY_Y;
};
#endif