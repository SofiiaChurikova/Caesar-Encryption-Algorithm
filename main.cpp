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
                encryptedText[i] = (element - 'a' + key) % 26;
                if (encryptedText[i] < 0) {
                    encryptedText[i] += 26;
                }
                encryptedText[i] += 'a';
            } else {
                encryptedText[i] = (element - 'A' + key) % 26;
                if (encryptedText[i] < 0) {
                    encryptedText[i] += 26;
                }
                encryptedText[i] += 'A';
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
                decryptedText[i] = (element - 'a' - key) % 26;
                if (decryptedText[i] < 0) {
                    decryptedText[i] += 26;
                }
                decryptedText[i] += 'a';
            } else {
                decryptedText[i] = (element - 'A' - key) % 26;
                if (decryptedText[i] < 0) {
                    decryptedText[i] += 26;
                }
                decryptedText[i] += 'A';
            }
        } else {
            decryptedText[i] = element;
        }
    }
    decryptedText[length] = '\0';
    return decryptedText;
}


int main() {
    int choice;
    cout << "Hello!" << endl;
    while (true) {
        cout << "Choose 1 - to encrypt text, 2 - to decrypt text, 3 - to exit" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            char rawText[400];
            int key;
            cout << "Enter the text to encrypt: ";
            cin.getline(rawText, 400);
            cout << "Enter the encryption key: ";
            cin >> key;
            cin.ignore();
            char *encryptedText = Encrypt(rawText, key);
            cout << "Encrypted Text: " << encryptedText << endl;
            delete[] encryptedText;
        } else if (choice == 2) {
            char encryptedText[400];
            int keyDecrypt;
            cout << "Enter the text to decrypt: ";
            cin.getline(encryptedText, 400);
            cout << "Enter the decryption key: ";
            cin >> keyDecrypt;
            cin.ignore();
            char *decryptedText = Decrypt(encryptedText, keyDecrypt);
            cout << "Decrypted Text: " << decryptedText << endl;
            delete[] decryptedText;
        } else if (choice == 3) {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
