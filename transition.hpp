//
// Created by humbl on 10/13/2019.
//

#ifndef PAGERANK_TRANSITION_HPP
#define PAGERANK_TRANSITION_HPP

#include "connectivity.hpp"

class transition : public matrix {
public:
    transition() = default;
    transition(const connectivity* c);
private:
};


#endif //PAGERANK_TRANSITION_HPP
