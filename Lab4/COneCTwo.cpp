#include "COneCTwo.h"
#include "iostream"

/* ======================COne=====================*/
/*   онструкторы и деструктор*/
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
    std::cout << "l=" << l << " s=" << s << std::endl;
}
void COne::Setl(long Nl)
{
    l=Nl;
}
void COne::Sets(std::string Ns)
{
    s=Ns;
}
/*  ѕерегрузка = */
COne& COne::operator=(const COne &COne2)
{
    this->l=COne2.l;
    this->s=COne2.s;
    return *this;
}
/* ======================CTwo=====================*/
/*   онструкторы и деструктор*/
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
/*   онструкторы и деструктор*/
CThree::CThree(): lab3value(33) //не вызываем конструкторы родительских(базовых) классов, поскольку они здесь вызовутс€ по умолчанию
{
    std::cout<<"No param constructor CThree"<<std::endl;
}
CThree::CThree(long Nl, COne Nobj, int Nlab3value): CTwo(Nl, Nobj), lab3value(Nlab3value) //вызываем родительский конструктор (всегда выполн€етс€ первым, независимо от положени€ в списке членов инициализации)
{
    std::cout<<"Yes param constructor CThree"<<std::endl;
}
CThree::CThree(const CThree &CThree1): CTwo(CThree1)
{
    std::cout<<"Copy constructor CThree"<<std::endl;
    this->lab3value=CThree1.lab3value;
}
CThree::~CThree()
{
    std::cout<<"destructor CThree"<<std::endl;
}
/*  Getters Setters*/
void CThree::print() //переопределенный метод. различие между виртуальным методом и обычным переопределенным про€вл€етс€, когда совершетс€ вызов метода при разыменовании указател€ на объект. ѕричем указатель может быть как указателем на дочернего типа, так и указателем родительского типа (оба указывают на один и тот же дочерний объека). ¬ случае указател€ родительсого типа поведение виртуального метода и обычного переопределенного будет разным, а именно в случае виртуального метода будет выбиратьс€ самый дочерний метод, что и позвол€ет реализовывать полиморфизм.
{ //короче, виртуальный метод меньше прив€зан к типу, чем обычный переопределенный.
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
/*  ======================CFour=====================*/
/*   онструкторы и деструктор*/
CFour::CFour():Lab4Value("defaultValue")
{
    std::cout<<"No param constructor CFour"<<std::endl;
}
CFour::CFour(long Nl, COne Nobj, int Nlab3value, std::string NLab4Value):CThree(Nl, Nobj, Nlab3value), Lab4Value(NLab4Value)
{
    std::cout<<"Yes param constructor CFour"<<std::endl;
}
CFour::CFour(const CFour &CFour1):CThree(CFour1) //инициализируем базовый класс нового объекта с помощью старого объекта.
{
    std::cout<<"Copy constructor CFour"<<std::endl;
    this->Lab4Value=CFour1.Lab4Value;
}
CFour::~CFour()
{
    std::cout<<"destructor CFour"<<std::endl;
}
/*  Getters Setters*/
void CFour::print()
{
    std::cout<<"CTwo: l="<< l <<" obj= ";
    obj.print();
    std::cout<<"CThree: lab3value="<< lab3value << " CFour: Lab4Value=" << Lab4Value <<std::endl;
}
std::string CFour::GetLab4Value()
{
    return Lab4Value;
}
void CFour::SetLab4Value(int NLab4Value)
{
    Lab4Value=NLab4Value;
}
