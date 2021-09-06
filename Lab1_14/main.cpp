#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    Rational Rat1;
    Rational Rat2;
//    Rational Rat1(6, 5);
//    Rational Rat2(-6, 5);
    Rat1.Scan();
    Rat2.Scan();
    Rat1.Print();
    Rat2.Print();
/*  Перегрузка операторов + - * /   */
    cout << "Rat3=Rat1+Rat2=";
    Rational Rat3=Rat1+Rat2;
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1-Rat2=";
    Rat3=Rat1-Rat2;
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1+(Rat2+Rat1)=";
    Rat3=Rat1+(Rat2+Rat1);
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1*Rat2=";
    Rat3=Rat1*Rat2;
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1*(Rat2*Rat1)=";
    Rat3=Rat1*(Rat2*Rat1);
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1/Rat2=";
    Rat3=Rat1/Rat2;
    Rat3.Print();
    cout<< endl;

    cout << "Rat3=Rat1/(Rat2/Rat1)=";
    Rat3=Rat1/(Rat2/Rat1);
    Rat3.Print();
    cout<< endl;
/*  Перегрузка операторов == !=    */
    cout << "Rat1==Rat2 ?" << (Rat1==Rat2) <<endl;
    cout << "Rat1!=Rat2 ?" << (Rat1!=Rat2) <<endl;

/*  Перегрузка операторов >  <  >=  <=    */
    cout << "Rat1>Rat2 ?" << (Rat1>Rat2) <<endl;
    cout << "Rat1<Rat2 ?" << (Rat1<Rat2) <<endl;
    cout << "Rat1>=Rat2 ?" << (Rat1>=Rat2) <<endl;
    cout << "Rat1<=Rat2 ?" << (Rat1<=Rat2) <<endl;

    return 0;
}
