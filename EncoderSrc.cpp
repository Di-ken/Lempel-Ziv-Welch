#include "encodeHelper.hpp"
#include "encodeRoutines.hpp"
#include "decodeRoutines.hpp"

#include <sstream>

void show(char a) {
    
}

int main() {
    Encode enc;
    string tp, all;
    enc.outFile.open("out.txt", std::ios::in);
    enc.inFile.open("in.txt", std::ios::in);

    while (getline(enc.inFile, tp)) all += tp;

    enc.initializeDictionary(all);
    enc.Compress(all);

    enc.inFile.close();
    enc.outFile.close();
/*
    ifstream of;
    of.open("out.txt", std::ios::in | std::ios::binary);

    string s;
    while (getline(of, tp)) {
        for (auto t: tp) {
            int x = (int) t;
            if (x < 0) x += 256;
            cout << x << endl;
        }
    }
*/

    Decode dec;
    dec.Decompress();
    

}

