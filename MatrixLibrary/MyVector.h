#pragma once
#ifndef _MYAECTOR_
#define _MYAECTOR_

#include <iostream>
#include <algorithm>

int MAX_VECTOR_SIZE = 100000000;

using namespace std;

template <class T>
class Vector
{
protected:
    int Length;
    int StartIndex;
    T* x;
public:
    Vector<T>* vec;
    Vector(int _Length = 0, int _startindex = 0);
    Vector(const Vector<T>& A);
    virtual ~Vector();

    Vector<T> operator +(const Vector<T>& A); //скалярное сложение
    Vector<T> operator -(const Vector<T>& A); //скалярное вычитание
    Vector<T> operator *(const Vector<T>& A); //скалярное умножение
    Vector<T> operator +(const T& tmp); //прибавить скаляр
    Vector<T> operator -(const T& tmp); //вычесть на скаляр
    Vector<T> operator *(const T& tmp); //умножение на скаляр
    Vector<T>& operator =(const Vector<T>& A);
    T& operator[] (const int index);

    bool operator ==(const Vector<T>& A) const;
    bool operator !=(const Vector<T>& A) const;
    Vector<T>& operator +=(Vector<T>& A);
    Vector<T>& operator -=(Vector<T>& A);

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const Vector<T1>& A);
    template <class T1>
    friend istream& operator>> (istream& istr, Vector<T1>& A);

    int GetLength();
    int GetStartIndex();
};


#define MIN(a,b)(a>=b?b:a)
#define MAX(a,b)(a>=b?a:b)

template <class T>
inline Vector<T>::Vector(int _length, int _startindex)
{
    if (_length < 0 || _startindex < 0 || _length > MAX_VECTOR_SIZE)
        throw exception();
    Length = _length;
    StartIndex = _startindex;
    x = new T[Length];
}

template <class T>
inline Vector<T>::Vector(const Vector<T>& A)
{
    Length = A.Length;
    StartIndex = A.StartIndex;
    x = new T[Length];
    for (int i = 0; i < Length; i++)
        this->x[i] = A.x[i];
}

template <class T>
inline Vector<T>::~Vector()
{
    if (x != NULL)
    {
        delete[] x;
    }
    x = NULL;
    Length = 0;
    StartIndex = 0;
}

template <class T>
inline Vector<T> Vector<T>::operator +(const Vector<T>& A)
{
    Vector<T> res;
    res.Length = MIN(Length, A.Length);
    res.x = new T[res.Length];
    for (int i = 0; i < res.Length; i++)
    {
        res.x[i] = x[i] + A.x[i];
    }
    return res;
}

template <class T>
inline Vector<T> Vector<T>::operator -(const Vector<T>& A)
{
    Vector<T> res;
    res.Length = MIN(Length, A.Length);
    res.x = new T[res.Length];
    for (int i = 0; i < res.Length; i++)
    {
        res.x[i] = x[i] - A.x[i];
    }
    return res;
}

template <class T>
inline Vector<T> Vector<T>::operator *(const Vector<T>& A)
{
    Vector<T> res;
    res.Length = MIN(Length, A.Length);
    res.x = new T[res.Length];
    for (int i = 0; i < res.Length; i++)
    {
        res.x[i] = x[i] * A.x[i];
    }
    return res;
}

template <class T>
inline Vector<T> Vector<T>::operator +(const T& tmp)
{
    for (int i = 0; i < Length; i++)
    {
        x[i] = x[i] + tmp;
    }
    return *this;
}

template <class T>
inline Vector<T> Vector<T>::operator -(const T& tmp)
{
    for (int i = 0; i < Length; i++)
    {
        x[i] = x[i] - tmp;
    }
    return *this;
}

template <class T>
inline Vector<T> Vector<T>::operator *(const T& tmp)
{
    for (int i = 0; i < Length; i++)
    {
        x[i] = x[i] * tmp;
    }
    return *this;
}

template <class T>
inline Vector<T>& Vector<T>::operator =(const Vector<T>& A)
{
    if (this == &A)
        return *this;
    if (Length != A.Length)
    {
        delete[] x;
        x = new T[A.Length];
    }
    Length = A.Length;
    StartIndex = A.StartIndex;
    for (int i = 0; i < Length; i++)
        x[i] = A.x[i];
    return *this;
}

template <class T>
inline T& Vector<T>::operator[] (const int index)
{
    if ((index - StartIndex) >= 0 && (index - StartIndex) < Length)
        return x[index - StartIndex];
    else throw exception();
}

template <class T>
inline bool Vector<T>::operator ==(const Vector<T>& A) const
{
    if (Length != A.Length || StartIndex != A.StartIndex)
        return false;
    for (int i = 0; i < Length; i++)
        if (x[i] != A.x[i])
            return false;
    return true;
}

template <class T>
inline bool Vector<T>::operator !=(const Vector<T>& A) const
{
    if (Length != A.Length || StartIndex != A.StartIndex)
        return true;
    for (int i = 0; i < Length; i++)
        if (x[i] != A.x[i])
            return true;
    return false;
}

template <class T>
inline Vector<T>& Vector<T>::operator +=(Vector<T>& A)
{
    Length = MIN(Length, A.Length);
    for (int i = 0; i < Length; i++)
    {
        x[i] += A.x[i];
    }
    return *this;
}

template <class T>
inline Vector<T>& Vector<T>::operator -=(Vector<T>& A)
{
    Length = MIN(Length, A.Length);
    for (int i = 0; i < Length; i++)
    {
        x[i] -= A.x[i];
    }
    return *this;
}

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1>& A) {
    for (int i = 0; i < A.Length; i++)
    {
        ostr << A.x[i] << endl;
    }
    return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1>& A) {
    for (int i = 0; i < A.Length; i++)
    {
        istr >> A.x[i];
    }
    return istr;
}

template <class T>
int Vector<T>::GetLength()
{
    return Length;
}

template <class T>
int Vector<T>::GetStartIndex()
{
    return StartIndex;
}

#endif