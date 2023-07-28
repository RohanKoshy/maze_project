#include "maze.h"
#include <iostream>
#include <sstream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <stack>

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
            temp1=tempx->right;
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

void Maze::maze_generate()
{
    int visit=0;
    stack<Node*> vis;
    Node* q=start;
    while(visit!=(CAPACITY_X*CAPACITY_Y))
    {
        //cout<<"visit: "<<visit<<endl;
        if(q->visited==false)
        {
            vis.push(q);
            visit++;
        }
        q->visited=true;
        Node *temp=Cpath(q);
        if(temp==nullptr)
        {
            vis.pop();
            temp=vis.top();
        }
        else
        {
            if(temp->l==q)
            {
                *temp->left=' ';
            }
           else if(temp->t==q)
           {
                *temp->top=' ';
           }
           else if(temp->d==q)
           {
                *temp->down=' ';
           }
           else if(temp->r==q)
           {
            *temp->right=' ';
           }
        }
        q=temp;
        //this->print();
    }
}

Maze::Node* Maze::Cpath(Maze::Node* t)
{
    Node* q=t;
    int dir=0;
    vector<Node*> vec;
    if(q->l&&q->l->visited==false)
    {
        vec.push_back(q->l);
        dir++;
    }
    if(q->r&&q->r->visited==false)
    {
        vec.push_back(q->r);
        dir++;
    }
    if(q->t&&q->t->visited==false)
    {
        vec.push_back(q->t);
        dir++;
    }
    if(q->d&&q->d->visited==false)
    {
        vec.push_back(q->d);
        dir++;
    }
    if(dir==0)
    {
        return nullptr;
    }
    int number=Rnumber(dir);
    return vec.at(number);
}
int Maze::Rnumber(int d)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, d-1);
    return distribution(generator);
}
void Maze::testr()
{
    Node* q=start;
    while(q)
    {
        *q->left=' ';
        q=q->r;
    }
    this->print();
}
void Maze::teststack(stack<Maze::Node*> m)
{
    Node* q=m.top();
    while(q)
    {
        cout<<m.top();
        m.pop();
    }
}