#include "EncoderStructure.hpp"

Encode::Encode() {
    codeIndex = 256, currentIndex = 0;
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

void Encode::Compress(string in) {
    int n = in.length();
    while (this->currentIndex <= n) {
        this->currentString += in[this->currentIndex];
        // cout << this->currentString << endl;

        if (!doesExist(this->currentString)) {
            addEntry();
            if (this->outFile.is_open())
                this->outFile << this->dictionary[this->currentString];
            this->currentString = this->currentString[this->currentString.length() - 1];
        }
        
        ++this->currentIndex;
    }
}
 
