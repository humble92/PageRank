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

using namespace std;

class matrix {
private:
    vector<vector<double>> data;

    //just for study for using array
    int arg1;
    int arg2;
    double *array;
    double array2[2][2];
public:
    //default constructor
    matrix() : array2 {{0.0,0.0},{0.0,0.0}}{

        //This is solution for using array
        arg1 = arg2 = 1;
        array = new double[arg1 * arg2];

        //vector<double> inner(1, 0.0);
        data.push_back({0.0});
    }

    //constructor matrix(m) where m is int > 0
    matrix(int m) {
        if(m<=0) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<m ; m1++)
            {
                data.push_back(vector<double>(m, 0.0));
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
        }
    }

    //set value
    void set_value(int m, int n, double val) {
        if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
            throw ("out of range error");
        } else {
            data[m][n] = val;
        }
    }

    //get value
    double get_value(int m, int n) {
        if( m<0 || n<0 || m >= data.size() ||  n >= data[0].size()) {
            throw ("out of range error");
        }
        return data[m][n];
    }

    //clear to 0.0
    void clear() {
        for (int m1=0 ; m1<data.size() ; m1++)
        {
            for (int m2=0 ; m2<data[0].size() ; m2++)
            {
                data[m1][m2] = 0.0;
            }
        }
    }

    // automatically destroyed
//    ~matrix()
//    {
//    }

    friend ostream & operator << (ostream &out, const matrix m) {
        for (int m1=0 ; m1<m.data.size() ; m1++)
        {
            for (int m2=0 ; m2<m.data[0].size() ; m2++)
            {
                out << setw(5) << m.data[m1][m2];
            }
            out << endl;
        }
        return out;
    }

};


#endif //PAGERANK_MATRIX_HPP
