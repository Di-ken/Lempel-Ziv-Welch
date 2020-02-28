#include "Incs.hpp"

class Encode {
    public:
        int codeIndex, currentIndex;
        string currentString;
        unordered_map<string, int> dictionary;
        int currentBitLength;
        char currentBit;
        ifstream inFile;
        ofstream outFile;

        Encode();
        ~Encode();

        void writeBit(int bit);
        void printDictionary();

        void initializeDictionary();
        void addEntry();
        bool doesExist(string entry);

        void Compress(string in);
};

