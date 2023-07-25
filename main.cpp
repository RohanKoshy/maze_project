#include "maze.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
  Maze h;
  h.setCapacityX(20);
  h.setCapacityY(10);
  h.create();
  h.print();
}