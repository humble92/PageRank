//
// Created by humbl on 10/13/2019.
//

#include <iostream>
#include "pageRank.hpp"
#include "connectivity.hpp"
#include "transition.hpp"

using namespace std;
const int precision = 2;
const int valWidth = 5;

using namespace std;

//process for connectivity.text file and return page rank
void pageRank::process(string filename) {
    //input
    matrix * conMatrix = new connectivity(filename);
    cout << "Connectivity Matirx: " << endl << *conMatrix << endl;

    cout << fixed << setprecision(precision);
    int size = ((connectivity *) conMatrix)->getMatrixSize();

    //do Markov process
    matrix * trMatrix = new transition((connectivity*) conMatrix);
    matrix rankMatrix(size, 1);
    getRankMatrix(trMatrix, rankMatrix);

    //output
    printRank(&rankMatrix);

    //free memory
    delete conMatrix;
    delete trMatrix;
}


//Do Markov process - rank process
void pageRank::getRankMatrix(matrix *pTransition, matrix &rank) {
    int size = rank.getData().size();
    for (int i=0 ; i < size ; i++)
    {
        rank.set_value(i, 0, 1.0);
    }

    matrix tmp;
    do {
        tmp = rank;
        rank = *pTransition * rank;
    } while(tmp != rank);

    normalize(rank);
}

//divide each value by sum
void pageRank::normalize(matrix &rank) {
    int size = rank.getData().size();
    double sum = 0.0;
    for (int i=0 ; i < size ; i++)
    {
        sum += rank.get_value(i, 0);
    }

    for (int i=0 ; i < size ; i++)
    {
        rank.set_value(i, 0, rank.get_value(i, 0) / sum);
    }
}

//print user friendly value ( %)
void pageRank::printRank(matrix *pMatrix) {
    cout << "[Page Rank]" << endl;
    char ch('A');
    for (int i=0 ; i < pMatrix->getData().size() ; i++)
    {
        cout << "Page " << ch++ << ": " << setw(valWidth) << pMatrix->get_value(i, 0) * 100.0 << "%" << endl;
    }
}
