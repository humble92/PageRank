//
// Created by humbl on 10/12/2019.
//

#ifndef PAGERANK_CONNECTIVITY_HPP
#define PAGERANK_CONNECTIVITY_HPP

#include "matrix.hpp"

class connectivity : public matrix {
public:
    connectivity() = default;
    connectivity(string filename, string delimiter);
    friend class transition;

private:
    bool analyseValidity();
    vector<int> importance;
    int matrixSize;
};

#endif //PAGERANK_CONNECTIVITY_HPP
