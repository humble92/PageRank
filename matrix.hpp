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
public:
    //default constructor
    matrix() {
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

    //friend istream & operator >> (istream &in,  matrix m) {}

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

    friend inline bool operator==(const matrix& lhs, const matrix& rhs) {
        if(lhs.data.size() != rhs.data.size() || lhs.data[0].size() != rhs.data[0].size()) {
            return false;
        } else {
            for (int m1=0 ; m1<lhs.data.size() ; m1++)
            {
                for (int m2=0 ; m2<lhs.data[0].size() ; m2++)
                {
                    if(lhs.data[m1][m2] != lhs.data[m1][m2])
                        return false;
                }
            }
        }
        return true;
    }
    friend inline bool operator!=(const matrix& lhs, const matrix& rhs){ return !(lhs == rhs); }


    // automatically destroyed
//    ~matrix()
//    {
//    }

};

#endif //PAGERANK_MATRIX_HPP
