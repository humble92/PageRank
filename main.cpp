#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "connectivity.hpp"
#include "transition.hpp"
#include "main.hpp"

using namespace std;
const string filename = "../connectivity.txt";
const int precision = 2;
const int valWidth = 5;

using namespace std;

int main() {

    //input
    matrix * conMatrix = new connectivity(filename);
    cout << "Connectivity Matirx: " << endl << *conMatrix << endl;

    cout << fixed << setprecision(precision);

    //do Markov process
    matrix * trMatrix = new transition((connectivity*) conMatrix);
    int size = trMatrix->getData().size();
    matrix rankMatrix(size, 1);
    getRankMatrix(trMatrix, rankMatrix);

    //output
    printoutRank(&rankMatrix);

    //free memory
    delete conMatrix;
    delete trMatrix;

    return 0;
}

//Do Markov process - rank process
void getRankMatrix(matrix *pTransition, matrix &rank) {
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
void normalize(matrix &rank) {
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
void printoutRank(matrix *rankMatrix) {
    cout << "[Page Rank]" << endl;
    char ch('A');
    for (int i=0 ; i < rankMatrix->getData().size() ; i++)
    {
        cout << "Page " << ch++ << ": " << setw(valWidth) << rankMatrix->get_value(i, 0) * 100.0 << "%" << endl;
    }
}
