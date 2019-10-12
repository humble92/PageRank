//
// Created by humbl on 10/12/2019.
//

#ifndef PAGERANK_CONNECTIVITY_HPP
#define PAGERANK_CONNECTIVITY_HPP

#include "matrix.hpp"

class connectivity : public matrix {
public:
    connectivity() = default;
    connectivity(int m) : matrix(m) {}
    connectivity(string filename, string delimiter);

private:
    bool validateConnectivity();
};

#endif //PAGERANK_CONNECTIVITY_HPP
