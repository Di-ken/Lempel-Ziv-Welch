// This file contains MAIN Routines needed for Encoding Symbols.

#include "EncoderStructure.hpp"

void Encode::writeBit(int bit) {
    if (codeIndex % (int)pow(2, bitSize) == 0)
        ++bitSize;

    if (bufferSize == 8) {
        outFile << buffer;
        buffer = 0;
        bufferSize = 0;
    }
    buffer = (buffer << 1) | bit;
    ++bufferSize;

    return;
}

void Encode::writeBuffer(unsigned n) {
    for (int t=bitSize-1;t>=0;--t) {
        int bit = (n >> t);
        cout << (bit&1);
        writeBit(bit & 1);
    }
    cout << endl;
    return;
}

void Encode::Compress(string in) {
    int n = in.length();

    while (currentIndex <= n) {
        // cout << "Current Bit Size: " << bitSize << " " << codeIndex << endl;
        currentString += in[currentIndex];

        if (!dictionary[currentString]) {
            dictionary[currentString] = ++codeIndex;
            int bufNow = dictionary[currentString.substr(0, currentString.length() - 1)];
            writeBuffer(bufNow);

            currentString = currentString[currentString.length() - 1];
        }
        ++currentIndex;
    }
    // cout << "Code Index: " << codeIndex << endl;
    writeBuffer(buffer);
    return;
}
