#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
/*  ќбъ€вление переменных*/
    Queue<float> Q1;

    cout << "Q1.IsEmpty()=" << Q1.IsEmpty() <<endl;
    try
    {
        Q1.Pop();
    }
    catch(const char *ExeptStr)
    {
        cout<< "Exeption catched!: " << ExeptStr <<endl;
    }
    try
    {
        cout << "Q1.GetFront()=" << Q1.GetFront() <<endl;
    }
    catch(const char* ExeptStr)
    {
        cout << "Exeption catched!: "<< ExeptStr  <<endl;
    }
    Q1.Push(12.3);
    cout << "Q1.GetFront()=" << Q1.GetFront() <<endl;
    cout << "Q1.IsEmpty()=" << Q1.IsEmpty() <<endl;
    try
    {
        Q1.Pop();
    }
    catch(const char *ExeptStr)
    {
        cout<< "Exeption catched!: " << ExeptStr <<endl;
    }
    cout << "Q1.IsEmpty()=" << Q1.IsEmpty() <<endl;

    cout << "-------------------------" <<endl;
    Q1.Push(-23.4);
    Q1.Push(-45.6);
    cout << "Q1.GetFront()=" << Q1.GetFront() <<endl;
    cout << "Q1.IsEmpty()=" << Q1.IsEmpty() <<endl;
    try
    {
        Q1.Pop();
    }
    catch(const char *ExeptStr)
    {
        cout<< "Exeption catched!: " << ExeptStr <<endl;
    }
    cout << "Q1.IsEmpty()=" << Q1.IsEmpty() <<endl;
    cout << "End of demo" <<endl;
    return 0;
}
