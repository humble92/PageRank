//
// Created by humbl on 10/12/2019.
//
#include <iostream>
#include <fstream>

#include "connectivity.hpp"

using namespace std;

connectivity::connectivity(string filename, string delimiter) {

    ifstream inputFile(filename.data());
    if (!inputFile.is_open()) {
        throw ("File not open error");
    }
    stringstream ss;
    string line;
    char c;
    data.clear();

    while ( getline (inputFile, line) )
    {
        istringstream iss(line);
        vector<double> rowVector;
        while (iss >> c)
        {
            double value = (double) c - '0';
            rowVector.push_back(value);
        }
        data.push_back(rowVector);
    }
    inputFile.close();

    if(!analyseValidity()) {
        data.clear();
        matrixSize = 0;
        importance.clear();
        throw ("File contents are not valid for connectivity matrix. It should be for square matrix with only 0 or 1.");
    }

}

bool connectivity::analyseValidity() {
    int rowSize = data.size();
    int colSize = data[0].size();
    matrixSize = rowSize;
    int importanceJ;

    for (int i=0 ; i < rowSize ; i++)
    {
        if(rowSize != data[i].size()) {
            return false;
        }

        importanceJ = 0;
        for (int j=0 ; j < colSize ; j++)
        {
            if(data[i][j] != 0.0 && data[i][j] != 1.0) {
                return false;
            }
            importanceJ += data[i][j];
        }
        importance.push_back(importanceJ);
    }

    return true;
}

int connectivity::getMatrixSize() const {
    return matrixSize;
}

