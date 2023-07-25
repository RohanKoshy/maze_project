#include "maze.h"
#include <iostream>
#include <sstream>

using namespace std;


void Maze::setCapacityX(int x)
{
    CAPACITY_X=x;
}
void Maze::setCapacityY(int y)
{
    CAPACITY_Y=y;
}
void Maze::create()
{
    Node* tempx;
    Node* tempy;
    char* temp1;
    Node* temp2;
    char* temp3;
    Node* temp5;
    Node* arr[CAPACITY_Y-1];
    for(int i=0;i<CAPACITY_X;i++)
    {
        tempx=new Node();
        tempx->top=new char('_');
        tempx->down=new char('_');
        tempx->right=new char('|');
        if(i==0)
        {
            tempx->left=new char('|');
            temp1=tempx->right;
            start=tempx;
        }
        else
        {
            tempx->left=temp1;
            tempx->l=temp2;
            temp2->r=tempx;
        }
        for(int j=0;j<CAPACITY_Y-1;j++)
        {
            tempy=new Node();
            tempy->down=new char('_');
            tempy->right=new char('|');
            if(j==0)
            {
                tempy->top=tempx->down;
                temp3=tempy->down;
                temp5=tempy;
                tempx->d=tempy;
                tempy->t=tempx;
            }
            else
            {
                tempy->top=temp3;
                temp3=tempy->down;
                tempy->t=temp5;
                temp5->d=tempy;
                temp5=tempy;
                
            }
            if(i==0)
            {
                tempy->left=new char('|');
                arr[j]=tempy;
            }
            else
            {
                tempy->left=arr[j]->right;
                tempy->l=arr[j];
                arr[j]->r=tempy;
                arr[j]=tempy;
            }
        }
        temp2=tempx;
    }
}
void Maze::print()
{
    ostringstream str;
    Node* q;
    bool t=false;

    for(int i=0;i<CAPACITY_Y;i++)
    {
        q=start;
        for(int j=0;j<i;j++)
        {
            q=q->d;
        }
        while(q)
        {        
            if(!t)
            {
                while(q)
                {
                    str<<" "<<q->top;
                    q=q->r;
                }
                str<<"\n";
                q=start;
                t=true;
            }
            if(!q->l)
            {
                str<<q->left;
            }
            str<<q->down<<q->right;
            q=q->r;
        }
        str<<"\n";
    }
    cout<<str.str();
}
