//
// Created by humbl on 10/13/2019.
//

#ifndef PAGERANK_PAGERANK_HPP
#define PAGERANK_PAGERANK_HPP

class matrix;

class pageRank {
public:
    void getRankMatrix(matrix *pTransition, matrix &rank);
    void normalize(matrix &matrix);
    void printRank(matrix *pMatrix);
    void process();
};


#endif //PAGERANK_PAGERANK_HPP
