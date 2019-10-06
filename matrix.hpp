//
// Created by humbl on 10/1/2019.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <exception>
#include <cmath>
#include <vector>

using namespace std;

class matrix {
private:
    int row;
    int col;
    vector<vector<double>> data;
public:
    //default constructor
    matrix() {
        //vector<double> inner(1, 0.0);
        data.push_back({0.0});
        row = col = 1;
    }

    //constructor matrix(m) where m is int > 0
    matrix(int m) {
        if(m<=0) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<m ; m1++)
            {
                data.push_back(vector<double>(m, 0.0));
                row = col = m;
            }
        }
    }

    //constructor matrix(m1, m2) where m1, m2 is int > 0
    matrix(int m, int n) {
        if(m<=0 || n<=0) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<m ; m1++)
            {
                data.push_back(vector<double>(n, 0.0));
            }
            row = m;
            col = n;
        }
    }

    //constructor matrix(int size, arr[]) where size is int
    matrix(int size, double arr[]) {
        if( float(sqrt(size)) != ceil(sqrt(size))) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<size ; m1++)
            {
                data.push_back(vector<double>(arr, arr + size));
            }
            row = col = size;
        }
    }

    //set value
    void set_value(int m, int n, double val) {
        if( m<0 || n<0 || m >= row ||  n >= col) {
            throw ("out of range error");
        } else {
            data[m][n] = val;
        }
    }

    //get value
    double get_value(int m, int n) {
        if( m<0 || n<0 || m >= row ||  n >= col) {
            throw ("out of range error");
        }
        return data[m][n];
    }

    //clear to 0.0
    void clear() {
        for (int m1=0 ; m1<row ; m1++)
        {
            for (int m2=0 ; m2<col ; m2++)
            {
                data[m1][m2] = 0.0;
            }
        }
    }

    // automatically destroyed
//    ~matrix()
//    {
//    }
};


#endif //PAGERANK_MATRIX_HPP
