//
// Created by humbl on 10/12/2019.
//

#ifndef PAGERANK_CONNECTIVITY_HPP
#define PAGERANK_CONNECTIVITY_HPP

#include "matrix.hpp"

class connectivity : public matrix {
public:
    connectivity() = default;
    connectivity(string filename);
    int getMatrixSize() const;
    friend class transition;

private:
    vector<int> importance;
    int matrixSize;
    bool analyseValidity();
};

#endif //PAGERANK_CONNECTIVITY_HPP
