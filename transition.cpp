//
// Created by humbl on 10/13/2019.
//

#include "transition.hpp"
const double randomWalkProbabilityFactor = 0.85;

//constructor: generate transition matrix from connectivity matrix
transition::transition(const connectivity* c) : matrix(c->matrixSize) {
    //step 1. matrix Q for probability teleport
    int m = c->matrixSize;
    double val = (1.0 - randomWalkProbabilityFactor) * 1.0 / m;
    double col[m];
    fill_n(col, m, val);
    matrix matrixQ(m, col);

    //step 2. probability matrix
    for (int i=0 ; i < m ; i++)
    {
        for (int j=0 ; j < m ; j++)
        {
            if(c->importance[j] == 0) {
                data[i][j] = 1.0 / m;
            } else {
                data[i][j] = c->data[i][j] / c->importance[j];
            }

            //For step 3. transition matrix
            data[i][j] = (data[i][j] * randomWalkProbabilityFactor) + matrixQ.getData()[i][j];
        }
    }
}