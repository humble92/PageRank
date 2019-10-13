#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "connectivity.hpp"
#include "probability.hpp"

using namespace std;
const string filename = "../connectivity.txt";
const string delimiter  = " ";

using namespace std;

int main() {

    matrix m = connectivity(filename, delimiter);
    matrix * m0 = new connectivity(filename, delimiter);


    cout << *m0 << endl;

    matrix p = probability((connectivity*) m0);

    cout << fixed << setprecision(3);

    double a[] = { 10.1001, 20, 30, 40};
    double b[] = { 10.1001, 20.000000000000001, 30, 40};
    //constructor test
    matrix m2(3,4);
    matrix m3(4, a);

    m2.set_value(0,0,2.0);
    cout << m2.get_value(0,0) << endl;

    //constructor test
    matrix m4(4, a);
    matrix m5(4, b);
    m4++;
    m4--;
    ++m5;
    --m5;
    cout << m4 <<endl;
    cout << m5 <<endl;
    if (m4 == m5) cout << "!!" <<endl;
        else cout << ":(" <<endl;

    matrix m6 (m5);
    cout << "m6 : " <<endl << m6 <<endl;
    cout << "m5 : " <<endl << m5 <<endl;
    m6 = m3;
    cout << "m6 again after assignment : " <<endl << m6 <<endl;

    matrix m1 = m5 + m5;

    m3 = m5 - m5;
    cout << "m3 (= m5 - m5) : " <<endl << m3 <<endl;
    m3 -= m5;
    cout << "m3 (-= m5) : " <<endl << m3 <<endl;

    matrix m21(4, 3);
    m2++;
    m21++;
    cout << "m2 : " <<endl << m2 <<endl;
    cout << "m21 : " <<endl << m21 <<endl;
    matrix mm = m2 * m21;
    cout << "mm : " <<endl << mm <<endl;

    delete m0;
    return 0;
}