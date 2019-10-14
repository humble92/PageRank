//
// Created by humbl on 10/13/2019.
//

#ifndef PAGERANK_MAIN_HPP
#define PAGERANK_MAIN_HPP

void getRankMatrix(matrix *pTransition, matrix &rank);
void normalize(matrix &matrix);
void printoutRank(matrix *pMatrix);


#endif //PAGERANK_MAIN_HPP
