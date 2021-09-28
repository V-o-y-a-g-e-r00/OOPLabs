#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <typename T>
class Node
{
public:
    T NodeVal;
    Node* Next;
/*  �����������*/
    Node(T NNodeVal);
};

template <typename T>
class Queue
{
private:
    Node<T>* First;
    Node<T>* Last;
    Node<T>* SearchPenultPointer();
public:
/*  ������������ � ����������*/
    Queue();
    Queue(const Queue& Q2); //��� ������������ � ��. ��������� �� ������� ��������� ����������� �������.
    ~Queue();
/*  ������ Push Pop GetFront IsEmpty*/
    bool IsEmpty() const; //����������� ����� ��� ������ ������������ �����������.

    void Push(T NNodeVal);
    void Pop();
    T GetFront();
};
#include "queue.inl" //���������� ����������

#endif // QUEUE_H_INCLUDED
