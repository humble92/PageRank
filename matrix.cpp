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

//constructor matrix(int size, arr[]) where size is int
matrix::matrix(int size, double arr[]) {
    if( float(sqrt(size)) != ceil(sqrt(size))) {
        throw ("out of range error");
    } else {
        for (int i=0 ; i < size ; i++)
        {
            data.push_back(vector<double>(arr, arr + size));
        }
    }
}

//set value
void matrix::set_value(int m, int n, double val) {
    if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
        throw ("out of range error");
    } else {
        data[m][n] = val;
    }
}

//get value
double matrix::get_value(int m, int n) {
    if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
        throw ("out of range error");
    }
    return data[m][n];
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

