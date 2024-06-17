#include <iostream>
using namespace std;
extern "C" {
    char *Encrypt(char *rawText, int key);
    char *Decrypt(char *encryptedText, int key);
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