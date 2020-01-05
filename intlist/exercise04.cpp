#include "intlist.hpp"

#include <cassert>
#include <iostream>
using std::endl;
using std::cout;

int main(int argc, char* argv[])
{
    assert(argc == 2);              // We expect one command-line argument,  
    const int N = atoi(argv[1]);    // an integer holding the problem size.
    cout << "Problem Size: " << N << endl;

    IntList myList;

    for (int i = 1;  i < N;  ++i) {
        for (int j = 0;  j < i;  ++j ) {
            for (int k = 0;  k < j*i;  ++k) {
                myList.push_back(i);
	    }
	}
    }
    
    return 0;
}
