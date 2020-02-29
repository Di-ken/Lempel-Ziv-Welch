#include "encodeHelper.hpp"
#include "encodeRoutines.hpp"

int main() {
    Encode enc;
    enc.outFile.open("out.txt", std::ios::out | std::ios::binary);
    enc.inFile.open("in.txt", std::ios::in);

    string tp, all;
    while (getline(enc.inFile, tp)) {
        all += tp;
    }
    enc.initializeDictionary(all);
    enc.Compress(all);

    enc.outFile.close();
    enc.inFile.close();
}

