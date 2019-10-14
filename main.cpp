#include <string>
#include "pageRank.hpp"

using namespace std;

int main() {

    //processing file
    const string filename = "../connectivity.txt";

    //page rank class generation
    pageRank googleRank;

    //process page rank
    googleRank.process(filename);

    return 0;
}
