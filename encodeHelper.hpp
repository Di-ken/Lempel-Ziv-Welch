// Utility Routines.

#include "EncoderStructure.hpp"

Encode::Encode() {
    codeIndex = 256, currentIndex = 0;
    bitSize = 9;
    buffer = 0, bufferSize = 0;
}

Encode::~Encode() {}

void Encode::initializeDictionary(string all) {
    for (int t=0;t<256;++t) {
        if (!dictionary[string(1, char(t))])
            dictionary[string(1, char(t))] = t;
    }
}

void Encode::printDictionary() {
    for (auto itr=dictionary.begin();itr!=dictionary.end();++itr)
        cout << itr->first << " " << itr->second << endl;
}

bool Encode::doesExist(string entry) {
    return dictionary[entry] != (int) NULL;
}

