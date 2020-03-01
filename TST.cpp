#include <iostream>
using namespace std;
int bits = 10;

void showB(unsigned n) {
    if (n > 1) showB(n >> 1);

    cout << (n & 1);
}

void Bwithpad(unsigned n) {
    for (int t=bits-1;t>=0;--t) {
        int k = (n >> t);

        if (k & 1)
            cout << 1;
        else
            cout << 0;
    }
}

int main() {
    unsigned n;
    
    Bwithpad(512);
}

