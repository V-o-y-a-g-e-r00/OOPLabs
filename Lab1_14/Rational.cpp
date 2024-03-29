#include "Rational.h"
#include <iostream>
#include <math.h>
#include <cstring>

Rational::Rational():P(0), Q(1)
{
//    std::cout<< "constructorDef"<<std::endl;
}

Rational::Rational(int NP, int NQ): P(NP), Q(NQ) //������ ������������� ������
{
//   std::cout<< "constructorPar"<<std::endl;
    if(Q==0)
    {
        std::cout << "Division by zero!" <<std::endl;
    }
}
void Rational::Print()
{
    std::cout << "P/Q=" << P << "/" << Q <<std::endl;
}
void Rational::Scan()
{
    char buff[256]; // ����� ��� �������� ������
    while(1)
    {
        std::cout << "Input P:";
        std::cin >> buff;
        if(strlen(buff)==strspn(buff, (char*)"-0123456789"))
        {
            std::string strbuff(buff);
            P=std::stoi(strbuff);
            break;
        }
        else
        {
            std::cout << "Wrong characters!" << std::endl;
        }
    }



    while(1)
    {
        std::cout << "Input Q:";
        std::cin >> buff;
        if(strlen(buff)==strspn(buff, (char*)"-0123456789"))
        {
            std::string strbuff(buff);
            Q=std::stoi(strbuff);
            break;
        }
        else
        {
            std::cout << "Wrong characters!" << std::endl;
        }
    }
}
void Rational::Simplify()
{
    if(P!=0)
    {
        int m=abs(P), n=abs(Q);
        while(m!=n)
        {
            if(m>n)
            {
                m=m-n;
            }
            else
            {
                n=n-m;
            }
        }
        P/=n;
        Q/=n;
    }
    else Q=1;
    if(Q<0)
    {
        P=-P;
        Q=-Q;
    }
}
Rational Rational::operator +(Rational r2)
{

    Rational r3(this->P*r2.Q+r2.P*this->Q, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
Rational Rational::operator -(Rational r2)
{

    Rational r3(this->P*r2.Q-r2.P*this->Q, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
Rational Rational::operator *(Rational r2)
{
    Rational r3(this->P*r2.P, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
Rational Rational::operator/(Rational r2)
{
    if(r2.P!=0)
    {
        Rational r3(this->P*r2.Q, this->Q*r2.P);
        r3.Simplify();
        return r3;
    }
    else
    {
        std::cout<<"Division by zero!"<<std::endl;
        Rational r3(0, 0); //��� ����� ���-�� ��-�������. ���������� ����� ����.
        return r3;
    }
}
bool Rational::operator ==(Rational r2)
{
    this->Simplify();
    r2.Simplify();
    if(this->P == r2.P && this->Q == r2.Q) return true;
    else return false;
}
bool Rational::operator !=(Rational r2)
{
    if(*this==r2) return false;
    else return true;
}
bool Rational::operator >(Rational r2)
{
    this->Simplify();
    r2.Simplify();
    Rational Rtemp1= *this;
    Rtemp1.P*=r2.Q;
    r2.P*=Rtemp1.Q;
    if(Rtemp1.P>r2.P) return true;
    else return false;
}
bool Rational::operator <(Rational r2)
{
    this->Simplify();
    r2.Simplify();
    Rational Rtemp1= *this;
    Rtemp1.P*=r2.Q;
    r2.P*=Rtemp1.Q;
    if(Rtemp1.P<r2.P) return true;
    else return false;
}
bool Rational::operator >=(Rational r2)
{
    if(*this < r2) return false;
    else return true;
}
bool Rational::operator <=(Rational r2)
{
    if(*this > r2) return false;
    else return true;
}
