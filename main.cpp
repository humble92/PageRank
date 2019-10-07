#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <cfloat>

using std::cout;
using std::max;

bool areEqualAbs(float a, float b, float epsilon) {
    return (fabs(a - b) <= epsilon);
}

bool areEqual(float a, float b, float epsilon) {
    return (fabs(a - b) <= epsilon * std::max(1.0f, std::max(a, b)));
}

bool areEqualRel(float a, float b, float epsilon) {
    return (fabs(a - b) <= epsilon * std::max(fabs(a), fabs(b)));
}

int main(int argc, char *argv[])
{
    cout << "minimum: " << FLT_MIN      << "\n";
    cout << "maximum: " << FLT_MAX      << "\n";
    cout << "epsilon: " << FLT_EPSILON  << "\n";

    float a = 0.0000001f;
    float b = 0.0000002f;
    if (areEqualRel(a, b, FLT_EPSILON)) {
        cout << "are equal a: " << a << " b: " << b << "\n";
    }
    a = 1000001.f;
    b = 1000002.f;
    if (areEqualRel(a, b, FLT_EPSILON)) {
        cout << "are equal a: " << a << " b: " << b << "\n";
    }
}