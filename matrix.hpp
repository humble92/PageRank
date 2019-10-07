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
    matrix();

    //constructor matrix(m) where m is int > 0
    matrix(int m);

    //constructor matrix(m1, m2) where m1, m2 is int > 0
    matrix(int m, int n);

    //constructor matrix(int size, arr[]) where size is int
    matrix(int size, double arr[]);

    //set value
    void set_value(int m, int n, double val);

    //get value
    double get_value(int m, int n);

    //clear to 0.0
    void clear();

    //friend istream & operator >> (istream &in,  matrix m) {}
    friend ostream & operator << (ostream &out, const matrix m) {
        for (int i=0 ; i < m.data.size() ; i++)
        {
            for (int j=0 ; j < m.data[0].size() ; j++)
            {
                out << setw(5) << m.data[i][j];
            }
            out << endl;
        }
        return out;
    }

    friend bool operator==(const matrix& lhs, const matrix& rhs) {
        if(lhs.data.size() != rhs.data.size() || lhs.data[0].size() != rhs.data[0].size()) {
            return false;
        } else {
            for (int i=0 ; i < lhs.data.size() ; i++)
            {
                for (int j=0 ; j < lhs.data[0].size() ; j++)
                {
                    if(lhs.data[i][j] != rhs.data[i][j])
                        return false;
                }
            }
        }
        return true;
    }
    friend bool operator!=(const matrix& lhs, const matrix& rhs){ return !(lhs == rhs); }


    // automatically destroyed
//    ~matrix()
//    {
//    }

};

#endif //PAGERANK_MATRIX_HPP
