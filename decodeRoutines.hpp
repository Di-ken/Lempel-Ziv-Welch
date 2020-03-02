#include "DecodeStructure.hpp"

Decode::Decode() {
    bufferSize = 0, buffer = 0;
    bitSize = 9;
    symbolIndex = -1;

    ch = getNextSymbol();
}

Decode::~Decode() {}

void Decode::getFileData() {
    inFile.open("out.txt", std::ios::in | std::ios::binary);
    string data;

    while(getline(inFile, data)) {
        symbols += data;
    }
    inFile.close();
}

char Decode::getNextSymbol() {
    return symbols[++symbolIndex];
}

void Decode::pullBits() {
}

void Decode::Decompress() {
    outFile.open("dec.txt", std::ios::out | std::ios::binary);

    getFileData();
    pullBits();

    outFile.close();
} 

