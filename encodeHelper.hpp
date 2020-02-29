#include "EncoderStructure.hpp"

Encode::Encode() {
    codeIndex = 256, currentIndex = 0;
    currentBitLength = 0;
}

Encode::~Encode() {}

void Encode::initializeDictionary(string all) {
    for (int t=0;t<256;++t) {
        if (!this->dictionary[string(1, char(t))])
            this->dictionary[string(1, char(t))] = t;
    }
}

void Encode::printDictionary() {
    for (auto itr=this->dictionary.begin();itr!=this->dictionary.end();++itr)
        cout << itr->first << " " << itr->second << endl;
}

void Encode::addEntry() {
    this->dictionary[this->currentString] = ++this->codeIndex;
}

bool Encode::doesExist(string entry) {
    return this->dictionary[entry] != (int) NULL;
}

void Encode::Compress(string in) {
    int n = in.length();

    while (this->currentIndex <= n) {
        this->currentString += in[this->currentIndex];
        cout << this->currentString << endl;

        if (!this->dictionary[this->currentString]) {
            this->dictionary[this->currentString] = ++this->codeIndex;
            this->outFile << this->dictionary[this->currentString.substr(0, this->currentString.length() - 1)] << " ";

            this->currentString = this->currentString[this->currentString.length() - 1];
        }
        ++this->currentIndex;
    }
}
 
