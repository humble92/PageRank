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
private:
    vector<vector<double>> data;
public:
    //default constructor
    matrix();

    //constructor matrix(m) where m is int > 0
    matrix(int m);

    //constructor matrix(m1, m2) where m1, m2 is int > 0
    matrix(int m, int n);

    //constructor matrix(int size, arr[]) where size is int
    matrix(int size, double arr[]);

//    matrix(const matrix& v) {
//        for (unsigned i = 0; i < v.data.size(); i++) {
//            data.push_back(vector<double>(v.data[0].size(), 0.0));
//            for (unsigned j=0 ; j < v.data[0].size() ; j++)
//            {
//                data[i][j] = v.data[i][j];
//            }
//        }
//    }

    void mySwap(matrix& first, matrix& second)
    {
        swap(first.data, second.data); //using std::swap
    }

    matrix& operator=(matrix other)
    {
        mySwap(*this, other);
        return *this;
    }

    //set value
    void set_value(int m, int n, double val);

    //get value
    const double get_value(int m, int n);

    //clear to 0.0
    void clear();

    // operator << overloading
    //friend istream & operator >> (istream &in,  matrix m) {}
    friend ostream & operator << (ostream &out, const matrix m);

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

    // automatically destroyed
//    ~matrix()
//    {
//        for (int i=0 ; i < this->data.size() ; i++)
//        {
//            this->data[i].clear();
//        }
//        this->data.clear();
//    }

};

#endif //PAGERANK_MATRIX_HPP
