#pragma once
#include"NodeP.h"
#include<iostream>
using namespace std;


template<class T>
class PriorityQueue
{
    NodeP<T>* Front;
    NodeP<T>* Rear;
public:
    PriorityQueue()
    {
        Front = nullptr;
        Rear = nullptr;
    }

    bool isempty()
    {
        return !Front;
    }

    void enqueue(T Val, int Prio=0)
    {
        NodeP<T>* NewNode = new NodeP<T>;
        NewNode->SetData(Val);
        NewNode->SetPriority(Prio);
        NewNode->SetNext(nullptr);
        if (isempty())
        {
            Front = NewNode;
            Rear = NewNode;
            return;
        }
        NodeP<T>* Temp = Front;
        if (!Temp->GetNext() || Temp->GetPriority() < Prio)
        {
            if (Temp->GetPriority() < Prio)
            {
                NewNode->SetNext(Front);
                Front = NewNode;
                while (Temp->GetNext())
                {
                    Temp = Temp->GetNext();
                }
                Rear = Temp;
            }
            else
            {
                Temp->SetNext(NewNode);
                Rear = NewNode;
            }
            return;
        }
        while (Temp)
        {
            if (!Temp->GetNext())
                break;
            if (Temp->GetNext()->GetPriority() < Prio)
            {
                NewNode->SetNext(Temp->GetNext());
                Temp->SetNext(NewNode);
                if (NewNode->GetNext() == nullptr)
                    Rear = NewNode;
                return;
            }
            Temp = Temp->GetNext();
        }
        Rear->SetNext(NewNode);
        Rear = NewNode;
    }

    void dequeue()
    {
        if (isempty())
        {
            return;
        }
        if (Front == Rear)
        {
            delete Front;
            Front = Rear = nullptr;
            return;
        }
        NodeP<T>* ptr = Front;
        Front = Front->GetNext();
        delete ptr;
    }

    void display()
    {
        NodeP<T>* ptr = Front;
        int i = 1;
        while (ptr)
        {
            cout << "Node" << i++ << " = " << ptr->GetData() << endl;
            ptr = ptr->GetNext();
        }
    }
};