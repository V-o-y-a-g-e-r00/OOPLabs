#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

class Rational
{
private:
    void Simplify();
public:
  //  void Simplify();
/*  ����������*/
    int P;
    int Q;
/*  ������������*/
    Rational();
    Rational(int NP, int NQ);

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

#endif // RATIONAL_H_INCLUDED
