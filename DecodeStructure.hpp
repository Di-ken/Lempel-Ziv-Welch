#pragma once

#include "Incs.hpp"

class Decode {
    public:
        ifstream inFile;
        ofstream outFile;
        string symbols;
        int symbolIndex;
        unsigned char ch;
        unsigned char buffer;
        int bufferSize;
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
};

