#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <typename T>
class Node
{
public:
    T NodeVal;
    Node* Next;
/*   онструктор*/
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
/*   онструкторы и деструктор*/
    Queue();
    Queue(const Queue& Q2); //при присваивании и др. операци€х мы создаем полностью независимую очередь.
    ~Queue();
/*  ћетоды Push Pop GetFront IsEmpty*/
    bool IsEmpty() const; //константный метод дл€ работы конструктора копировани€.

    void Push(T NNodeVal);
    void Pop();
    T GetFront();
};
#include "queue.inl" //подключаем реализацию

#endif // QUEUE_H_INCLUDED
