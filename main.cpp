#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

char *Encrypt(char *rawText, int key) {
    int length = strlen(rawText);
    char *encryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char element = rawText[i];

        if (isalpha(element)) {
            if (islower(element)) {
                encryptedText[i] = (element - 'a' + key) % 26 + 'a';
            } else {
                encryptedText[i] = (element - 'A' + key) % 26 + 'A';
            }
        } else {
            encryptedText[i] = element;
        }
    }
    encryptedText[length] = '\0';
    return encryptedText;
}

char *Decrypt(char *encryptedText, int key) {
    int length = strlen(encryptedText);
    char *decryptedText = new char[length + 1];
    for (int i = 0; i < length; i++) {
        char element = encryptedText[i];

        if (isalpha(element)) {
            if (islower(element)) {
                decryptedText[i] = (element - 'a' - key + 26) % 26 + 'a';
            } else {
                decryptedText[i] = (element - 'A' - key + 26) % 26 + 'A';
            }
        } else {
            decryptedText[i] = element;
        }
    }
    decryptedText[length] = '\0';
    return decryptedText;
}

int main() {
    
    return 0;
}
