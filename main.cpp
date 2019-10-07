#include <iostream>
#include <sstream>
#include "matrix.hpp"

using namespace std;

int main() {

    //constructor test
    matrix m;
    matrix m1(2);
    matrix m2(3,4);
    double a[] = { 10, 20, 30, 40};
    matrix m3(4, a);

    m2.set_value(0,0,2.0);
    cout << m2.get_value(0,0) << endl;
    m2.clear();
    m3.clear();

    cout << m2 <<endl;

    //constructor test
    double b[] = { 10, 20, 30, 40};
    matrix m4(4, a);
    matrix m5(4, b);

    if (m4 == m5) cout << "!!";
    else cout << ":(";

    return 0;
}