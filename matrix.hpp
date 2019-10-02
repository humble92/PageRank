//
// Created by humbl on 10/1/2019.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <exception>
#include <cmath>

using namespace std;

class matrix {
private:
    int height;
    int width;
    double** array;
public:
    //default constructor
    matrix() {
        array = reinterpret_cast<double **>(new double[1][1]);
        array[0][0] = 0.0;
        height = width = 1;
    }

    //constructor matrix(m) where m is int > 0
    matrix(int m) {
        if(m<=0) {
            bool ex = true;
        }
        try {
            for (int m1=0 ; m1<m ; m1++)
            {
                for (int m2=0 ; m2<m ; m2++)
                {
                    array[m1][m2] = 0.0;
                }
            }
            height = width = m;
        }
        catch (bool ex) {
            throw ("out of range error");
        }
    }

    //constructor matrix(m1, m2) where m1, m2 is int > 0
    matrix(int m, int n) {
        if(m<=0 || n<=0) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<m ; m1++)
            {
                for (int m2=0 ; m2<n ; m2++)
                {
                    array[m1][m2] = 0.0;
                }
            }
            width = m;
            height = n;
        }
    }

    //constructor matrix(int size, arr[][]) where size is int
    matrix(int size, double** arr) {
        if( float(sqrt(size)) != ceil(sqrt(size))) {
            throw ("out of range error");
        } else {
            for (int m1=0 ; m1<sqrt(size) ; m1++)
            {
                for (int m2=0 ; m2<sqrt(size) ; m2++)
                {
                    array[m1][m2] = arr[m1][m2];
                }
            }
        }
    }

    //set value
    void set_value(int m, int n, double val) {
        if( m<0 || n<0 || m >= width ||  n >= height) {
            throw ("out of range error");
        } else {
            array[m][n] = val;
        }
    }

    //get value
    double get_value(int m, int n) {
        if( m<0 || n<0 || m >= width ||  n >= height) {
            throw ("out of range error");
        }
        return array[m][n];
    }

    //clear to 0.0
    void clear() {
        for (int m1=0 ; m1<width ; m1++)
        {
            for (int m2=0 ; m2<height ; m2++)
            {
                array[m1][m2] = 0.0;
            }
        }
    }

    ~matrix()
    {
        for(int i = 0; i < width; ++i) {
            delete [] array[i];
        }
        delete [] array;
    }
};


#endif //PAGERANK_MATRIX_HPP
