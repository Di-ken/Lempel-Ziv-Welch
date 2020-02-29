#include <iostream>
using namespace std;

struct bit_field {
    unsigned x: 9;
};

int main() {
    bit_field b;
    b.x = 0;
    int s = 256;
    b.x |= s;
    cout << b.x;
}

