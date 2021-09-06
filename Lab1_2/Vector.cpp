#include "Vector.h"
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

Vector::Vector(int NDimension):Dimension(NDimension) //������ ������������� ������
{
 //   std::cout<< "constructor" <<std::endl;
    pElements=new int[Dimension];

}
Vector::Vector(const Vector& v)
{
    int i;
 //   std::cout<<"constructorCOPY"<<std::endl;
    Dimension=v.Dimension;
    MemHelper=new int; //test
    pElements=new int[Dimension];
    for(i=0; i<Dimension; i++)
    {
        pElements[i]=v.pElements[i]; //���� �������� � ����������� [] ����� ������� ����� ��� []    ���    const int&
    }
}
Vector::~Vector()
{
//    std::cout<< "destructor" << std::endl;
    delete [] pElements;
    delete MemHelper; //test
}

int Vector::GetDimension()
{
    return Dimension;
}
void Vector::PrintElements()
{
    int i;
    for (i=0; i<Dimension; i++)
    {
        std::cout << pElements[i] <<std::endl;
    }
}
void Vector::SetElements()
{
    int i;
    char buff[256]; // ����� ��� �������� ������
    for (i=0; i<Dimension; i++)
    {
        std::cin >> buff;
        if(strlen(buff)==strspn(buff, (char*)"-.0123456789"))
        {
            std::string strbuff(buff);
            pElements[i]=std::stoi(strbuff);
        }
        else
        {
            std::cout << "Wrong characters!" << std::endl;
            i--;
        }
    }
}
double Vector::GetAbs()
{
    int i;
    double S;
    for(i=0;i<Dimension;i++)
    {
        S+=pElements[i]*pElements[i];
    }
    return sqrt(S);
}
/* ������ ��� ���������� ���������� */
int& Vector::operator[](int i)  //���������� ��������� ������� [] ������������ ������ �� ���� �������
{
    if(i<Dimension && i>=0)
    {
        return this->pElements[i];
    }
    else
    {
        std::cout<< "Wrong element index!"<< std::endl;
        return IndexErrorHandle;
    }
}
Vector &Vector::operator =( const Vector& v2) //������ ��������� ��������� ������ � ������������� ������.
{
    int i;
    if(this != &v2)
    {
    //    std::cout<< "overloaded = diff obj" << std::endl;
        delete [] this->pElements;
        this->Dimension=v2.Dimension;
        this->pElements=new int[Dimension];
        for(i=0; i<Dimension; i++)
        {
            this->pElements[i]=v2.pElements[i];
        }
    }
    else
    {
   //     std::cout<< "overloaded \"=\" equ obj" << std::endl;
    }
    return *this;
}
Vector Vector::operator +(const Vector& v2)
{
        int i;
        Vector v3(Dimension);
  //      std::cout<< "&v3 : " << &v3 << std::endl;
     //   std::cout<<"v3.pElements :" << v3.pElements << std::endl;
        for (i=0; i<Dimension; i++)
        {
            v3[i]=(*this)[i]+v2.pElements[i];
      //      std::cout << v3[i] << std::endl;
        }
        return v3; //���, �� ������, ������ ���������� ����������� �����������, ������ �� ����� ���� �����������  NRVO (named return value optimization; copy elision) , �.�. ��������� ������� �� �������� ����������� �����������. ����������� ����� � ��������� ����������� �����������, �� ������� �������� �� ����������� �����������.: Under the following circumstances, the compilers are permitted, but not required to omit the copy and move (since C++11) construction of class objects even if the copy/move (since C++11) constructor and the destructor have observable side-effects. The objects are constructed directly into the storage where they would otherwise be copied/moved to. This is an optimization: even when it takes place and the copy/move (since C++11) constructor is not called, it still must be present and accessible (as if no optimization happened at all), otherwise the program is ill-formed:
        //�.�. ������������ ������ � ������ ������ ����� ��������� �� � ��������� ������� �������, � ��� � �������� �������. -fno-elide-constructors ��� ����������
}
Vector Vector::operator -(const Vector& v2)
{
        int i;
        Vector v3(Dimension);
  //      std::cout<< "&v3 : " << &v3 << std::endl;
   //     std::cout<<"v3.pElements :" << v3.pElements << std::endl;
        for (i=0; i<Dimension; i++)
        {
            v3[i]=(*this)[i]-v2.pElements[i];
   //         std::cout << v3[i] << std::endl;
        }
        return v3;
}
int Vector::operator *(const Vector& v2)
{
    int i;
    int P=0; //��� ������������
    for(i=0; i<Dimension; i++)
    {
        P+=this->pElements[i]*v2.pElements[i];
    }
    return P;
}
