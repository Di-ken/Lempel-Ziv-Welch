#include "EncoderStructure.hpp"

Encode::Encode() {
    codeIndex = 0, currentIndex = 0;
    currentBitLength = 0;
}

Encode::~Encode() {}

void Encode::initializeDictionary() {
    for (int itr=0;itr < 256;++itr)
        this->dictionary[std::to_string((char) itr)] = itr;
}

void Encode::printDictionary() {
    for (int itr=0;itr<dictionary.size();++itr)
        cout << this->dictionary[std::to_string((char) itr)] << " ";
}

void Encode::addEntry() {
    this->dictionary[this->currentString] = ++this->codeIndex;
}

bool Encode::doesExist(string entry) {
    return this->dictionary[entry] != (int) NULL;
}
