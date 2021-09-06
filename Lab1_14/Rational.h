#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

class Rational
{
private:
    void Simplify();
public:
  //  void Simplify();
/*  Переменные*/
    int P;
    int Q;
/*  Конструкторы*/
    Rational();
    Rational(int NP, int NQ);

    void Print();
    void Scan();
/*  Перегрузка операторов + - * /   */
    Rational operator +(Rational r2);
    Rational operator -(Rational r2);
    Rational operator *(Rational r2);
    Rational operator /(Rational r2);

/*  Перегрузка операторов == !=  >  <  >=  <= */
    bool operator ==(Rational r2);
    bool operator !=(Rational r2);

    bool operator >(Rational r2);
    bool operator <(Rational r2);

    bool operator >=(Rational r2);
    bool operator <=(Rational r2);
};

#endif // RATIONAL_H_INCLUDED
