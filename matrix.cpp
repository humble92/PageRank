//
// Created by humbl on 10/1/2019.
//

#include "matrix.hpp"

//default constructor
matrix::matrix() {
    //vector<double> inner(1, 0.0);
    data.push_back({0.0});
}

//constructor matrix(m) where m is int > 0
matrix::matrix(int m) {
    if(m<=0) {
        throw ("out of range error");
    } else {
        for (int i=0 ; i < m ; i++)
        {
            data.push_back(vector<double>(m, 0.0));
        }
    }
}

//constructor matrix(m1, m2) where m1, m2 is int > 0
matrix::matrix(int m, int n) {
    if(m<=0 || n<=0) {
        throw ("out of range error");
    } else {
        for (int i=0 ; i < m ; i++)
        {
            data.push_back(vector<double>(n, 0.0));
        }
    }
}

//constructor matrix(size, arr[]) where size is int
matrix::matrix(int size, const double arr[]) {
    if( float(sqrt(size)) != ceil(sqrt(size))) {
        throw ("out of range error");
    } else {
        for (int i=0 ; i < size ; i++)
        {
            data.push_back(vector<double>(arr, arr + size));
        }
    }
}

//implemented using member initializer
//matrix::matrix(const matrix& v) {
//    data = v.data;
//}

//set value
void matrix::set_value(int m, int n, double val) {
    if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
        throw ("out of range error");
    } else {
        data[m][n] = val;
    }
}

//get value
double matrix::get_value(const int m, const int n) const {
    if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
        throw ("out of range error");
    }
    return data[m][n];
}

//get data
const vector<vector<double>> &matrix::getData() const {
    return data;
}

//clear to 0.0
void matrix::clear() {
    for (int i=0 ; i < data.size() ; i++)
    {
        for (int j=0 ; j < data[0].size() ; j++)
        {
            data[i][j] = 0.0;
        }
    }
}

// operator << overloading
ostream & operator << (ostream &out, const matrix& m) {
    for (int i=0 ; i < m.data.size() ; i++)
    {
        for (int j=0 ; j < m.data[0].size() ; j++)
        {
            out << setw(8) << m.data[i][j];
        }
        out << endl;
    }
    return out;
}

// operator == overloading
bool operator==(const matrix& lhs, const matrix& rhs) {
    if(lhs.data.size() != rhs.data.size() || lhs.data[0].size() != rhs.data[0].size()) {
        return false;
    } else {
        for (int i=0 ; i < lhs.data.size() ; i++)
        {
            for (int j=0 ; j < lhs.data[0].size() ; j++)
            {
                //if(lhs.data[i][j] != rhs.data[i][j])
                if(fabs(lhs.data[i][j] - rhs.data[i][j]) >= DBL_EPSILON)
                    return false;
            }
        }
    }
    return true;
}

// operator != overloading
bool operator!=(const matrix& lhs, const matrix& rhs){ return !(lhs == rhs); }

// Define prefix increment operator.
matrix& matrix::operator++()
{
    for (int i=0 ; i < this->data.size() ; i++)
    {
        for (int j=0 ; j < this->data[0].size() ; j++)
        {
            this->data[i][j] += 1.0;
        }
    }
    return *this;
}

// Define postfix increment operator.
matrix matrix::operator++(int)
{
    matrix tmp(*this);
    for (int i=0 ; i < this->data.size() ; i++)
    {
        for (int j=0 ; j < this->data[0].size() ; j++)
        {
            this->data[i][j] += 1.0;
        }
    }
    return tmp;
}

// Define prefix decrement operator.
matrix& matrix::operator--()
{
    for (int i=0 ; i < this->data.size() ; i++)
    {
        for (int j=0 ; j < this->data[0].size() ; j++)
        {
            this->data[i][j] -= 1.0;
        }
    }
    return *this;
}

// Define postfix decrement operator.
matrix matrix::operator--(int)
{
    matrix tmp(*this);
    for (int i=0 ; i < this->data.size() ; i++)
    {
        for (int j=0 ; j < this->data[0].size() ; j++)
        {
            this->data[i][j] -= 1.0;
        }
    }
    return tmp;
}

//Swap function for overloading assignment operator
void mySwap(matrix& first, matrix& second)
{
    swap(first.data, second.data); //using std::swap
}

//overloading assignment operator
matrix& matrix::operator=(matrix other)
{
    mySwap(*this, other);
    return *this;
}

//overload +=
matrix& matrix::operator+=(const matrix& rhs)
{
    if(data.size() != rhs.data.size() || data[0].size() != rhs.data[0].size()) {
        throw ("mismatch size error");
    }

    for (int i=0 ; i < data.size() ; i++)
    {
        for (int j=0 ; j < data[0].size() ; j++)
        {
            data[i][j] += rhs.data[i][j];
        }
    }
    return *this;
}

//overload +
matrix operator+(matrix lhs, const matrix& rhs)
{
    if(lhs.data.size() != rhs.data.size() || lhs.data[0].size() != rhs.data[0].size()) {
        throw ("mismatch size error");
    }

    for (int i=0 ; i < lhs.data.size() ; i++)
    {
        for (int j=0 ; j < lhs.data[0].size() ; j++)
        {
            lhs.data[i][j] += rhs.data[i][j];
        }
    }
    return lhs;
}

//overload -=
matrix& matrix::operator-=(const matrix& rhs)
{
    if(data.size() != rhs.data.size() || data[0].size() != rhs.data[0].size()) {
        throw ("mismatch size error");
    }

    for (int i=0 ; i < data.size() ; i++)
    {
        for (int j=0 ; j < data[0].size() ; j++)
        {
            data[i][j] -= rhs.data[i][j];
        }
    }
    return *this;
}

//overload -
matrix operator-(matrix lhs, const matrix& rhs)
{
    if(lhs.data.size() != rhs.data.size() || lhs.data[0].size() != rhs.data[0].size()) {
        throw ("mismatch size error");
    }

    for (int i=0 ; i < lhs.data.size() ; i++)
    {
        for (int j=0 ; j < lhs.data[0].size() ; j++)
        {
            lhs.data[i][j] -= rhs.data[i][j];
        }
    }
    return lhs;
}


//overload *=
matrix& matrix::operator*=(const matrix& rhs)
{
    if(data[0].size() != rhs.data.size()) {
        throw ("mismatch size error");
    }

    for (int i=0 ; i < data.size() ; i++)
    {
        for (int j=0 ; j < data[0].size() ; j++)
        {
            data[i][j] *= rhs.data[i][j];
        }
    }
    return *this;
}

//overload *
matrix operator*(matrix lhs, const matrix& rhs)
{
    if(lhs.data[0].size() != rhs.data.size()) {
        throw ("mismatch size error");
    }

    matrix tmp(lhs.data.size(), rhs.data[0].size());
    int i, j, k;
    for (i = 0; i < lhs.data.size(); i++)
    {
        for (j = 0; j < rhs.data[0].size(); j++)
        {
            tmp.data[i][j] = 0;
            for (k = 0; k < rhs.data.size(); k++)
                tmp.data[i][j] += lhs.data[i][k] * rhs.data[k][j];
        }
    }

    return tmp; // return the result by value (uses move constructor)
}
