// This file contains MAIN Routines needed for Encoding Symbols.

#include "EncoderStructure.hpp"

void Encode::Compress(string in) {
    int n = in.length();

    while (currentIndex <= n) {
        currentString += in[currentIndex];
        cout << currentString << endl;

        if (!dictionary[currentString]) {
            dictionary[currentString] = ++codeIndex;
            outFile << dictionary[currentString.substr(0, currentString.length() - 1)];

            currentString = currentString[currentString.length() - 1];
        }
        ++currentIndex;
    }
}
 
