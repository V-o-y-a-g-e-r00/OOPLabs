#include <iostream>
#include "COneCTwo.h"

using namespace std;

int main()
{
/*  Демонстрация работы класса COne*/
    cout << "====Demonstration of COne class work====" << endl;
    COne COne1;
    COne COne2(5, "some initializated string");
    cout << "COne1.print()=" << endl;
    COne1.print();
    cout<< endl;
    cout << "COne2.print()=" << endl;
    COne2.print();
    cout<< endl;
    cout << "COne COne3=COne2; COne3.print()=" << endl;
    COne COne3=COne2;
    COne3.print();
    cout<< endl;

    cout << "====Demonstration of CTwo class work====" << endl;
    CTwo CTwo1;
//     cout <<"-------"<<endl;
    CTwo CTwo2(6, COne2);
    cout << "CTwo1.print()=" << endl;
    CTwo1.print();
    cout<< endl;
    cout << "CTwo2.print()=" << endl;
    CTwo2.print();
    cout<< endl;
    cout << "CTwo CTwo3=CTwo2; CTwo3.print()=" << endl;
 //   CTwo CTwo3;
    CTwo CTwo3=CTwo2;
    CTwo3.print();
    cout<< endl;

    cout << "====Demonstration of CThree class work====" << endl;
    CThree CThree1;
    CThree1.print();

    CThree CThree2(444, COne2, 555);
    CThree2.print();
    return 0;
}
