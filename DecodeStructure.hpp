#pragma once

#include "Incs.hpp"

class Decode {
    public:
        fstream inFile, outFile;
        char buffer;
        int bufferSize;
        unordered_map<unsigned int, string> dictionary;
        int bitSize;

        Deocde();
        ~Decode();

        void printDictionary();

        void initializeDictionary(string all);

        void Decompress(string in);
};

