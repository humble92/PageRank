//
// Created by humbl on 10/13/2019.
//

#ifndef PAGERANK_PAGERANK_HPP
#define PAGERANK_PAGERANK_HPP

#include <string>

using namespace std;
class matrix;

class pageRank {
public:
    void getRankMatrix(matrix *pTransition, matrix &rank);
    void normalize(matrix &matrix);
    void printRank(matrix *pMatrix);
    void process(string filename);
};


#endif //PAGERANK_PAGERANK_HPP
