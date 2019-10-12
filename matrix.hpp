//
// Created by humbl on 10/1/2019.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <exception>
#include <cmath>
#include <vector>
#include <istream>
#include <iomanip>
#include <cfloat>

using namespace std;

class matrix {
protected:
    vector<vector<double>> data;
public:
    //default constructor
    matrix();

    //constructor matrix(m) where m is int > 0
    matrix(int m);

    //constructor matrix(m1, m2) where m1, m2 is int > 0
    matrix(int m, int n);

    //constructor matrix(int size, arr[]) where size is int
    matrix(int size, const double arr[]);

    //copy constructor
    matrix(const matrix& v) : data(v.data) {}

    //set value
    void set_value(int m, int n, double val);

    //get value
    double get_value(const int m, const int n) const;

    //clear to 0.0
    void clear();

    // operator << overloading
    friend ostream & operator << (ostream &out, const matrix& m);
    //friend istream & operator >> (istream &in,  matrix& m) {}

    // operator ==, != overloading
    friend bool operator==(const matrix& lhs, const matrix& rhs);
    friend bool operator!=(const matrix& lhs, const matrix& rhs);

    // Define prefix increment operator.
    matrix& operator++();

    // Define postfix increment operator.
    matrix operator++(int);

    // Define prefix decrement operator.
    matrix& operator--();

    // Define postfix decrement operator.
    matrix operator--(int);

    //overloading assignment operator
    friend void mySwap(matrix& first, matrix& second);
    matrix& operator=(matrix other);

    //overload +=
    matrix& operator+=(const matrix& rhs);

    //overload +
    // passing lhs by value helps optimize chained a+b+c
    friend matrix operator+(matrix lhs, const matrix& rhs);

    //overload -=
    matrix& operator-=(const matrix& rhs);

    //overload -
    // passing lhs by value helps optimize chained a-b-c
    friend matrix operator-(matrix lhs, const matrix& rhs);

    //overload *=
    matrix& operator*=(const matrix& rhs);

    //overload *
    // passing lhs by value helps optimize chained a*b*c
    friend matrix operator*(matrix lhs, const matrix& rhs);

    // automatically destroyed
//    ~matrix()
//    {
//        this->data.clear();
//    }

};

#endif //PAGERANK_MATRIX_HPP
