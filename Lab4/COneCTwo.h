#ifndef CONECTWO_H_INCLUDED
#define CONECTWO_H_INCLUDED

#include <string>
class COne
{
private:
    long l;
    std::string s;
public:
/*  ������������ � ����������*/
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

/*  ���������� = */
    COne& operator=(const COne &COne2);
};

class CTwo
{
protected: //����� ����� protected, ����� �� ������ �������������� print()
    long l;
    COne obj;
public:
/*  ������������ � ����������*/
    CTwo();
    CTwo(long Nl, COne Nobj);
    CTwo(const CTwo &CTwo1);
    ~CTwo();

/*  Getters Setters*/
    virtual void print();

    void Setl(long Nl);
    void Setobj(COne Nobj);

/*  ���������� = */
    CTwo& operator=(const CTwo &CTwo2);

};
class CThree: public CTwo
{
protected: //��� print()
    int lab3value;
public:
/*  ������������ � ����������*/
    CThree();
    CThree(long Nl, COne Nobj, int Nlab3value);
    CThree(const CThree &CThree1);
    ~CThree();

/*  Getters Setters*/
    virtual void print();
    int Getlab3value();
    void Setlab3value(int Nlab3value);
};

class CFour: public CThree
{
private:
    std::string Lab4Value;
public:
    /*  ������������ � ����������*/
    CFour();
    CFour(long Nl, COne Nobj, int Nlab3value, std::string NLab4Value);
    CFour(const CFour &CFour1);
    ~CFour();

    /*  Getters Setters*/
    virtual void print();
    std::string GetLab4Value();
    void SetLab4Value(int NLab4Value);
};
#endif // CONECTWO_H_INCLUDED
