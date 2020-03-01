#pragma once

#include "Incs.hpp"

class Encode {
    public:
        int codeIndex, currentIndex;
        int bitSize;
        string currentString;
        unordered_map<string, unsigned int> dictionary;
        char buffer;
        int bufferSize;
        ifstream inFile;
        ofstream outFile;

        Encode();
        ~Encode();

        void printDictionary();

        void initializeDictionary(string all);
        bool doesExist(string entry);

        void Compress(string in);
        
        void writeBit(int bit);
        void writeBuffer(unsigned n);
        void padRemainingBits();
};

