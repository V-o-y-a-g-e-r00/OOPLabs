#include "COneCTwo.h"
#include "iostream"

/* ======================COne=====================*/
/*  Конструкторы и деструктор*/
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
/*  Перегрузка = */
COne& COne::operator=(const COne &COne2)
{
    this->l=COne2.l;
    this->s=COne2.s;
    return *this;
}
/* ======================CTwo=====================*/
/*  Конструкторы и деструктор*/
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
