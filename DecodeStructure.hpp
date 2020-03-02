#pragma once

#include "Incs.hpp"

class Decode {
    public:
        ifstream inFile;
        ofstream outFile;
        string symbols;
        int symbolIndex;
        unsigned char ch;
        unsigned buffer;
        int bufferSize;
        string all;
        unordered_map<unsigned int, string> dictionary;
        int bitSize;

        Decode();
        ~Decode();

        void printDictionary();

        void initializeDictionary(string all);

        void getFileData();
        void Decompress();
        char getNextSymbol();
        void pullBits();
        void Bwithpad(unsigned n);
};

