//
// Created by humbl on 10/13/2019.
//

#ifndef PAGERANK_PROBABILITY_HPP
#define PAGERANK_PROBABILITY_HPP

#include "connectivity.hpp"

class probability : public matrix {
public:
    probability() = default;
    probability(const connectivity* c) : matrix(c->matrixSize) {}
private:
};


#endif //PAGERANK_PROBABILITY_HPP
