//  Perechislit vse perestanovki pervih 5ti naturalnih chisel, ispolzuya factorialniyi metod posledovatelnoy vstavki sprava

#include <iostream>
#include <vector>
#define N 5

void printIntVector(std::vector<int> vect) {
    std::vector<int>::iterator it;
    for (it = vect.begin(); it < vect.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

void FMCIR(std::vector<int> vect, int max) {
    std::vector<int>::iterator it;
    std::vector<int> vectCopy;
    int size = vect.size();

    for (int i = vect.size(); i >= 0; i--) {
        vectCopy = vect;
        vectCopy.insert(vectCopy.begin() + i, size+1);
        if (size < max-1) {
            FMCIR(vectCopy, max);
        } else {
            printIntVector(vectCopy);
        }
    }
}

int main() {
    std::vector<int> vector = {};
    std::vector<int>::iterator iter;
    FMCIR(vector, N);
    return 0;
}