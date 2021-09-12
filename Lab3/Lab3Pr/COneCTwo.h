#ifndef CONECTWO_H_INCLUDED
#define CONECTWO_H_INCLUDED

#include <string>
class COne
{
private:
    long l;
    std::string s;
public:
/*  Конструкторы и деструктор*/
    COne();
    COne(long Nl, std::string Ns);
    COne(const COne &COne1);
    ~COne();
/*  Getters Setters*/
//    long Getl();
//    std::string Gets();
    void print();

    void Setl(long Nl);
    void Sets(std::string Ns);

/*  Перегрузка = */
    COne& operator=(const COne &COne2);
};

class CTwo
{
protected: //Пусть будет protected, иначе не сможем переопределить print()
    long l;
    COne obj;
public:
/*  Конструкторы и деструктор*/
    CTwo();
    CTwo(long Nl, COne Nobj);
    CTwo(const CTwo &CTwo1);
    ~CTwo();

/*  Getters Setters*/
    void print();

    void Setl(long Nl);
    void Setobj(COne Nobj);

/*  Перегрузка = */
    CTwo& operator=(const CTwo &CTwo2);

};
class CThree: public CTwo
{
private:
    int lab3value;
public:
/*  Конструкторы и деструктор*/
    CThree();
    CThree(long Nl, COne Nobj, int Nlab3value);
    CThree(const CThree &CThree1);
    ~CThree();

/*  Getters Setters*/
    void print();
    int Getlab3value();
    void Setlab3value(int Nlab3value);
};

#endif // CONECTWO_H_INCLUDED
