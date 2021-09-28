#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
#include <math.h>
#include <cstring>
template <typename T>
class Rational
{
private:
    void Simplify();
public:
  //  void Simplify();
/*  ����������*/
    T P;
    T Q;
/*  ������������*/
    Rational();
    Rational(T NP, T NQ);

    void Print();
    void Scan();
/*  ���������� ���������� + - * /   */
    Rational operator +(Rational r2);
    Rational operator -(Rational r2);
    Rational operator *(Rational r2);
    Rational operator /(Rational r2);

/*  ���������� ���������� == !=  >  <  >=  <= */
    bool operator ==(Rational r2);
    bool operator !=(Rational r2);

    bool operator >(Rational r2);
    bool operator <(Rational r2);

    bool operator >=(Rational r2);
    bool operator <=(Rational r2);
};
#include "Rational.hpp"

#endif // RATIONAL_H_INCLUDED
