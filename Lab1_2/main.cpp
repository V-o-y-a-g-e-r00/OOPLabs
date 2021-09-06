#include <iostream>
#include "Vector.h"


using namespace std;

int main()
{
/*  Переменные*/
    int NDimension;
    int P;

/*  Ввод данных*/
    cout << "Input NDimension:";
    cin >> NDimension;

    Vector V1(NDimension);
    cout << "SetElements V1:--------------" <<endl;
    V1.SetElements();
    Vector V2(NDimension);
    cout << "SetElements V2:--------------" <<endl;
    V2.SetElements();
    cout<< endl;

/*  Демонстрация работы Gette-ов в т.ч. Abs*/
    cout << "====Demonstration of Getters work===="<< endl;
    cout << "Dimension V1=" << V1.GetDimension() << endl;
    cout << "PrintElements V1:--------------" <<endl;
    V1.PrintElements();
    cout << "|V1|=V1.GetAbs()="<< V1.GetAbs() <<endl;
    cout <<endl;

/*  Демонсрация работы оператора []      */
    cout << "====Demonstration of [] overload===="<< endl;
    V1[1]=-1234;
    cout << "\"V1[1]=-1234\"" <<endl;
    cout << "PrintElements V1:--------------" <<endl;
    V1.PrintElements();
    cout << endl;

/*  Демонсрация работы оператора =       */
    cout << "====Demonstration of \"=\" overload===="<< endl;
    Vector V3=V1;
    cout << "Vector V3=V1" <<endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

    V3=V2;
    cout << "V3=V2" <<endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

    V3=V3;
    cout << "V3=V3" <<endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

/*  Демонсрация работы операторов +-*    */
    cout << "====Demonstration of \"+-*\" overload===="<< endl;
    V3=V1+V2;
    cout << "V3=V1+V2"<< endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

    V3=V1-V2;
    cout << "V3=V1-V2"<< endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

    V3=V3+V2-(V1-V2)+V3; //2V3+2V2-V1=2V1-2V2+2V2-V1
    cout << "V3=V3+V2-(V1-V2)+V3;"<< endl;
    cout << "PrintElements V3:--------------" <<endl;
    V3.PrintElements();
    cout <<endl;

    P=V1*V2;
    cout << "P=V1*V2="<< P <<endl;
    cout <<endl;

    P=(V1+V2)*V1;
    cout << "P=(V1+V2)*V1=" << P <<endl;
    cin.get();
    return 0; // деструктор вызовется здесь автоматически, явно делать это для неуказателей не нужно
}
