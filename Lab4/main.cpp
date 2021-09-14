#include <iostream>
#include "COneCTwo.h"

using namespace std;
void printAll(CTwo* TwoArr[], int n) //принимает массив указателей
{
    int i;
    for(i=0; i<n; i++)
    {
        (*TwoArr[i]).print();
        std::cout<<"------------"<<std::endl;
    }
}
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
    CThree2.Setl(77);
    CThree2.print();
    cout<< endl;

    cout << "====Demonstration of CFour class work====" << endl;
    CFour CFour1(100500, COne2, 555, "someNLab4Value");
    CFour CFour2=CFour1;
    CFour1.print();
    cout<< endl;
    CFour2.print();

    cout << "====Demonstration of printAll====" << endl;
    CTwo *TwoArr[3];

    COne COne_0(0, "str0");
    COne COne_1(1, "str1");
    COne COne_2(2, "str2");

    CTwo CTwo_0(10, COne_0);
    CThree CThree_1(101, COne_1, -101);

    CFour CFour_2(1002, COne_2, -102, "Lab4Value_2");

    TwoArr[0]=&CTwo_0;
    TwoArr[1]=&CThree_1;
    TwoArr[2]=&CFour_2;

    printAll(TwoArr, 3);
    cout << "====End of demonstration====" << endl;
    return 0;
}
