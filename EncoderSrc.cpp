#include "encodeHelper.hpp"
#include "encodeRoutines.hpp"

int main() {
    Encode enc;
    string tp, all;
    enc.outFile.open("out.txt", std::ios::out | std::ios::binary);
    enc.inFile.open("in.txt", std::ios::in);

    while (getline(enc.inFile, tp)) all += tp;

    enc.initializeDictionary(all);
    enc.Compress(all);

    enc.outFile.close();
    enc.inFile.close();
}

