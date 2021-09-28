template <typename T>
Rational<T>::Rational():P(0), Q(1)
{
//    std::cout<< "constructorDef"<<std::endl;
}
template <typename T>
Rational<T>::Rational(T NP, T NQ): P(NP), Q(NQ) //Список инициализации членов
{
//   std::cout<< "constructorPar"<<std::endl;
    if(Q==0)
    {
        std::cout << "Division by zero!" <<std::endl;
    }
}
template <typename T>
void Rational<T>::Print()
{
    std::cout << "P/Q=" << P << "/" << Q <<std::endl;
}
template <typename T>
void Rational<T>::Scan()
{
    char buff[256]; // буфер для хранения строки
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
template <typename T>
void Rational<T>::Simplify()
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
template <typename T>
Rational<T> Rational<T>::operator +(Rational<T> r2)
{

    Rational r3(this->P*r2.Q+r2.P*this->Q, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
template <typename T>
Rational<T> Rational<T>::operator -(Rational<T> r2)
{

    Rational r3(this->P*r2.Q-r2.P*this->Q, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
template <typename T>
Rational<T> Rational<T>::operator *(Rational<T> r2)
{
    Rational r3(this->P*r2.P, this->Q*r2.Q);
    r3.Simplify();
    return r3;
}
template <typename T>
Rational<T> Rational<T>::operator/(Rational<T> r2)
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
        Rational r3(0, 0); //тут нужно как-то по-другому. исключение может быть.
        return r3;
    }
}
template <typename T>
bool Rational<T>::operator ==(Rational<T> r2)
{
    this->Simplify();
    r2.Simplify();
    if(this->P == r2.P && this->Q == r2.Q) return true;
    else return false;
}
template <typename T>
bool Rational<T>::operator !=(Rational<T> r2)
{
    if(*this==r2) return false;
    else return true;
}
template <typename T>
bool Rational<T>::operator >(Rational<T> r2)
{
    this->Simplify();
    r2.Simplify();
    Rational Rtemp1= *this;
    Rtemp1.P*=r2.Q;
    r2.P*=Rtemp1.Q;
    if(Rtemp1.P>r2.P) return true;
    else return false;
}
template <typename T>
bool Rational<T>::operator <(Rational<T> r2)
{
    this->Simplify();
    r2.Simplify();
    Rational Rtemp1= *this;
    Rtemp1.P*=r2.Q;
    r2.P*=Rtemp1.Q;
    if(Rtemp1.P<r2.P) return true;
    else return false;
}
template <typename T>
bool Rational<T>::operator >=(Rational<T> r2)
{
    if(*this < r2) return false;
    else return true;
}
template <typename T>
bool Rational<T>::operator <=(Rational<T> r2)
{
    if(*this > r2) return false;
    else return true;
}
