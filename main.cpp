#include <iostream>
#include <sstream>
#include "matrix.hpp"

using namespace std;

int main() {

    //constructor test
    double a[] = { 10, 20, 30, 40};
    matrix m3(4, a);
    double b[] = { 10, 20, 30, 40};
    matrix m1(4, a);
    matrix m2(4, a);

    if (m1 == m2) cout << "!!";

    return 0;
}