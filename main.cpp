#include "maze.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
  Maze h;
  h.setCapacityX(5);
  h.setCapacityY(5);
  h.create();
  h.print();
  //h.testr();
  h.maze_generate();
  //h.testr();
  //h.print();
}