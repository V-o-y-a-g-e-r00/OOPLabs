#include "COneCTwo.h"
#include "iostream"

/* ======================COne=====================*/
/*  ������������ � ����������*/
COne::COne():l(1), s("No param s")
{
 //   std::cout<<"No param constructor COne"<<std::endl;
}
COne::COne(long Nl, std::string Ns):l(Nl), s(Ns)
{
//    std::cout<<"Yes param constructor COne"<<std::endl;
}
COne::COne(const COne &COne1)
{
//    std::cout<<"Copy constructor COne"<<std::endl;
    l=COne1.l;
    s=COne1.s;
}
COne::~COne()
{
//    std::cout<<"destructor COne"<<std::endl;
}
/*  Getters Setters*/
//long COne::Getl()
//{
//    return l;
//}
//std::string COne::Gets()
//{
//    return s;
//}
void COne::print()
{
    std::cout << "l=" << l << "\ts=" << s << std::endl;
}
void COne::Setl(long Nl)
{
    l=Nl;
}
void COne::Sets(std::string Ns)
{
    s=Ns;
}
/*  ���������� = */
COne& COne::operator=(const COne &COne2)
{
    this->l=COne2.l;
    this->s=COne2.s;
    return *this;
}
/* ======================CTwo=====================*/
/*  ������������ � ����������*/
CTwo::CTwo():l(123), obj()
{
 //   std::cout<<"No param constructor CTwo"<<std::endl;
}
CTwo::CTwo(long Nl, COne Nobj):l(Nl), obj(Nobj)
{
//    std::cout<<"Yes param constructor CTwo"<<std::endl;
}
 CTwo::CTwo(const CTwo &CTwo1)
{
 //   std::cout<<"Copy constructor CTwo"<<std::endl;
    this->l=CTwo1.l;
    this->obj=CTwo1.obj;
}
CTwo::~CTwo()
{
//    std::cout<<"destructor CTwo"<<std::endl;
}
/*  Getters Setters*/
void CTwo::print()
{
    std::cout << "l=" << l << "\tobj=";
    obj.print();
}
void CTwo::Setl(long Nl)
{
    l=Nl;
}
void CTwo::Setobj(COne Nobj)
{
    obj=Nobj;
}
/* ======================CThree=====================*/
/*  ������������ � ����������*/
CThree::CThree(): lab3value(33) //�� �������� ������������ ������������(�������) �������, ��������� ��� ����� ��������� �� ���������
{
    std::cout<<"No param constructor CThree"<<std::endl;
}
CThree::CThree(long Nl, COne Nobj, int Nlab3value): CTwo(Nl, Nobj), lab3value(Nlab3value) //�������� ������������ ����������� (������ ����������� ������, ���������� �� ��������� � ������ ������ �������������)
{
    std::cout<<"Yes param constructor CThree"<<std::endl;
}
CThree::CThree(const CThree &CThree1)
{
    std::cout<<"Copy constructor CThree"<<std::endl;
    this->lab3value=CThree1.lab3value;
}
CThree::~CThree()
{
    std::cout<<"destructor CThree"<<std::endl;
}
/*  Getters Setters*/
void CThree::print() //���������������� �����. �������� ����� ����������� ������� � ������� ���������������� �����������, ����� ���������� ����� ������ ��� ������������� ��������� �� ������. ������ ��������� ����� ���� ��� ���������� �� ��������� ����, ��� � ���������� ������������� ���� (��� ��������� �� ���� � ��� �� �������� ������). � ������ ��������� ������������ ���� ��������� ������������ ������ � �������� ����������������� ����� ������, � ������ � ������ ������������ ������ ����� ���������� ����� �������� �����, ��� � ��������� ������������� �����������.
{ //������, ����������� ����� ������ �������� � ����, ��� ������� ����������������.
    std::cout<<"l="<< l << "\tobj= ";
    obj.print();
    std::cout<< "lab3value=" << lab3value <<std::endl;
   // std::cout<<std::endl;
}
int CThree::Getlab3value()
{
    return lab3value;
}
void CThree::Setlab3value(int Nlab3value)
{
    lab3value=Nlab3value;
}
