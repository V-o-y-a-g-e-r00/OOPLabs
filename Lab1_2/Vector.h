#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>


class Vector
{
private:
    int Dimension; //размерность
 //   int *pElements=nullptr; //массив элементов
    int IndexErrorHandle=-123; // для передачи ссылки за границы диапазона.
    int *MemHelper=nullptr; // проверяем конструктор копирования
    int *pElements=nullptr; //массив элементов
public:
    Vector(int NDimension);
    Vector(const Vector & v); //Конструктор копирования. Для работы методов, возвращающих объект
    ~Vector();

    int GetDimension();
    // void ResetDimension(int NDimension);
    void PrintElements();
    void SetElements();

    double GetAbs();
/* методы для перегрузки операторов */
    int &operator[](int i);
    Vector &operator =( const Vector& v2); //нельзя присвоить временный объект к неконстантной ссылке.

/* методы для +-* */
    Vector operator +(const Vector& v2);
    Vector operator -(const Vector& v2);
    int operator *(const Vector& v2);
};

#endif // VECTOR_H_INCLUDED
