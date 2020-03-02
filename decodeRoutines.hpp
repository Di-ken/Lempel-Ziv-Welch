#include "DecodeStructure.hpp"

Decode::Decode() {
    bufferSize = 0, buffer = 0;
    bitSize = 9;
    symbolIndex = -1;

    ch = getNextSymbol();
}

Decode::~Decode() {}

void Decode::Bwithpad(unsigned n) {
    for (int c = 7; c >= 0; c--) {
        unsigned k = n >> c;

        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

void Decode::getFileData() {
    inFile.open("out.txt", std::ios::in | std::ios::binary);
    string data;

    while(getline(inFile, data)) {
        for (int t=0;t<data.length();++t) {
            Bwithpad(data[t]);
            cout << endl;
            // cout << (int) data[t] << " ";
        }
    }
    inFile.close();
}

char Decode::getNextSymbol() {
    return symbols[++symbolIndex];
}

void Decode::Decompress() {
    outFile.open("dec.txt", std::ios::out | std::ios::binary);

    getFileData();

    outFile.close();
}
