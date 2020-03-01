// This file contains MAIN Routines needed for Encoding Symbols.

#include "EncoderStructure.hpp"

void Encode::writeBit(int bit) {
    if (bufferSize == 8) {
        outFile << buffer;
        buffer = 0;
        bufferSize = 0;
        cout << endl;
    }
    buffer = (buffer << 1) | bit;
    ++bufferSize;
}

void Encode::writeBuffer(unsigned n) {
    if (n > 1) writeBuffer(n >> 1);

    writeBit(n & 1);
    cout << (n & 1);
}

void Encode::Compress(string in) {
    int n = in.length();

    while (currentIndex <= n) {
        currentString += in[currentIndex];

        if (!dictionary[currentString]) {
            dictionary[currentString] = ++codeIndex;
            int bufNow = dictionary[currentString.substr(0, currentString.length() - 1)];
            writeBuffer(bufNow);

            currentString = currentString[currentString.length() - 1];
        }
        ++currentIndex;
    }

    writeBuffer(buffer);
}
