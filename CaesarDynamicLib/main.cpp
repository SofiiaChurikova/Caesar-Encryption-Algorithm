#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
using namespace std;

int main() {
    void *handle = dlopen("./libcaesar.dylib", RTLD_LAZY);
    if (handle == nullptr) {
        cout << "Lib not found" << endl;
        return -1;
    }
    typedef char * (*encrypt_ptr)(char *, int);
    typedef char * (*decrypt_ptr)(char *, int);
    encrypt_ptr Encrypt = (encrypt_ptr) dlsym(handle, "Encrypt");
    decrypt_ptr Decrypt = (decrypt_ptr) dlsym(handle, "Decrypt");
    if (!Encrypt) {
        cout << "Proc1 not found" << endl;
        return -2;
    }
    if (!Decrypt) {
        cout << "Proc2 not found" << endl;
        return -3;
    }
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
    dlclose(handle);
    return 0;
}