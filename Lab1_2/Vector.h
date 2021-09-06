#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>


class Vector
{
private:
    int Dimension; //�����������
 //   int *pElements=nullptr; //������ ���������
    int IndexErrorHandle=-123; // ��� �������� ������ �� ������� ���������.
    int *MemHelper=nullptr; // ��������� ����������� �����������
    int *pElements=nullptr; //������ ���������
public:
    Vector(int NDimension);
    Vector(const Vector & v); //����������� �����������. ��� ������ �������, ������������ ������
    ~Vector();

    int GetDimension();
    // void ResetDimension(int NDimension);
    void PrintElements();
    void SetElements();

    double GetAbs();
/* ������ ��� ���������� ���������� */
    int &operator[](int i);
    Vector &operator =( const Vector& v2); //������ ��������� ��������� ������ � ������������� ������.

/* ������ ��� +-* */
    Vector operator +(const Vector& v2);
    Vector operator -(const Vector& v2);
    int operator *(const Vector& v2);
};

#endif // VECTOR_H_INCLUDED
