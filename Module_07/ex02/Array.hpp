#pragma once

#include <iostream>

template <typename T>
class Array
{
    private:
        unsigned int    _n;
        T               *_array;

    public:
        Array() : _n(0), _array(new T[0]) {}
        Array(unsigned int n) : _n(n), _array(new T[n]()) {} // like calloc
        Array(const Array &other) : _n(other._n), _array(new T[other._n])
        {
            for (unsigned int i = 0; i < _n; i++)
                _array[i] = other._array[i];
        }
        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _array;
                _n = other._n;
                _array = new T[_n];
                for (unsigned int i = 0; i < _n; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        }
        ~Array() { delete[] _array; }

        T &operator[](unsigned int index)
        {
            if (index >= _n)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        const T &operator[](unsigned int index) const
        {
            if (index >= _n)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        unsigned int size() const { return _n; }

};