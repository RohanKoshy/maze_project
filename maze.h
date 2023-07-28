#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <stack>
#include <stdlib.h>

class Maze
{
    public: 
    void maze_generate();
    void create();
    void print();
    void setCapacityX(int x);
    void setCapacityY(int y);
    void testr();

    private:
    struct Node
    {
        char* top;
        char* down;
        char* left;
        char* right;
        bool visited=false;
        Node* t;
        Node* d;
        Node* l;
        Node* r;
        Node(): top(nullptr), down(nullptr), left(nullptr), right(nullptr), t(nullptr), d(nullptr), l(nullptr), r(nullptr) {}
    };
    Node* start;
    int CAPACITY_X;
    int CAPACITY_Y;
    Node* Cpath(Node* t);
    int Rnumber(int d);
    void teststack(std::stack <Node*> m);
};
#endif