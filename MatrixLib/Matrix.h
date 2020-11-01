#pragma once

#include <iostream>

#include "MyVector.h"

int MAX_MATRIX_SIZE = 1000;

template <class T>
class TMatrix : public Vector<Vector<T>>
{
public:
    TMatrix(int _size = 0); //инициализатор
    TMatrix(const TMatrix<T>& A); //копирование
    TMatrix(const Vector<Vector<T>>& A); // преобразование типа

    bool operator==(const TMatrix& A) const;      // сравнение
    bool operator!=(const TMatrix& A) const;      // сравнение

    TMatrix<T>& operator= (const TMatrix<T>& A);     // присваивание
    TMatrix<T> operator+ (const TMatrix<T>& A);      // сложение
    TMatrix<T> operator- (const TMatrix& A);      // вычитание
    TMatrix<T> operator* (const TMatrix<T>& A);      //умножение
    TMatrix<T> operator/ (const TMatrix<T>& A);      //деление
    TMatrix<T>& operator +=(const TMatrix<T>& A);
    TMatrix<T>& operator -=(const TMatrix<T>& A);

    //потоки ввода и вывода
    friend istream& operator>>(istream& in, TMatrix<T>& A)
    {
        for (int i = 0; i < A.GetLength(); i++)
            for (int j = A[i].GetStartIndex(); j < A.GetLength(); j++)
                in >> A[i][j];
        return in;
    }

    friend ostream& operator<<(ostream& out, const TMatrix<T>& A)
    {
        TMatrix<T> res(A);
        for (int i = 0; i < res.GetLength(); i++)
        {
            for (int j = res[i].GetStartIndex(); j < res.GetLength(); j++)
                out << res[i][j] << ' ';
            out << endl;
        }   
        return out;
    }

};

template <class T>
inline TMatrix<T>::TMatrix(int _size) : Vector<Vector<T>>(_size)
{
    if (_size < 0 || _size > MAX_MATRIX_SIZE)
        throw exception();
    for (int i = 0; i < _size; i++)
        x[i] = Vector<T>(_size - i, i);
}

template <class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& A) : Vector<Vector<T>>(A)
{
}

template<class T>
inline TMatrix<T>::TMatrix(const Vector<Vector<T>>& A) : Vector<Vector<T>>(A)
{
}

template<class T>
bool TMatrix<T>::operator==(const TMatrix& A) const
{
    if (Length != A.Length || StartIndex != A.StartIndex)
        return false;
    for (int i = 0; i < Length; i++)
        if (x[i] != A.x[i])
            return false;
    return true;
}

template<class T>
bool TMatrix<T>::operator!=(const TMatrix& A) const
{
    if (Length != A.Length || StartIndex != A.StartIndex)
        return true;
    for (int i = 0; i < Length; i++)
        if (x[i] != A.x[i])
            return true;
    return false;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& A)
{
    if (this == &A) 
        return *this;
    Vector<Vector<T>>::operator =(A);
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& A)
{
    TMatrix<T> tmp(*this);
    for (int i = 0; i < this->Length; i++)
        tmp.x[i] = tmp.x[i] + A.x[i];
    return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A)
{
    TMatrix<T> tmp(*this);
    for (int i = 0; i < this->Length; i++)
        tmp.x[i] = tmp.x[i] - A.x[i];
    return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& A)
{
    TMatrix<T> tmp(*this);
    for (int i = 0; i < this->Length; i++)
        tmp.x[i] = tmp.x[i] * A.x[i];
    return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator/(const TMatrix<T>& A)
{
    TMatrix<T> tmp(*this);
    for (int i = 0; i < this->Length; i++)
        tmp.x[i] = tmp.x[i] * A.x[i];
    return tmp;
}

template<class T>
TMatrix<T>& TMatrix<T>::operator +=(const TMatrix<T>& A)
{
    for (int i = 0; i < this->Length; i++)
        x[i] += A.x[i];
    return *this;
}

template<class T>
TMatrix<T>& TMatrix<T>::operator -=(const TMatrix<T>& A)
{
    for (int i = 0; i < this->Length; i++)
        x[i] -= A.x[i];
    return *this;
}


