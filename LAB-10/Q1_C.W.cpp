#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encrypt(const string& input) {
    string encrypted = input;
    for (int i = 0; i < encrypted.length(); ++i) {
        encrypted[i] = encrypted[i] + (i + 4 * (5));
    }
    return encrypted;
}

string decrypt(const string& input) {
    string decrypted = input;
    for (int i = 0; i < decrypted.length(); ++i) {
        decrypted[i] = decrypted[i] - (i + 4 * (5));
    }
    return decrypted;
}

int main() {
    string text, encryptedText, decryptedText;
    cout << "Enter String: ";
    getline(cin, text);

    encryptedText = encrypt(text);
    ofstream fout("encrypted.txt");
    fout << encryptedText;
    fout.close();
    cout << endl << "Encrypted text inserted in file." << endl;

    ifstream fin("encrypted.txt");
    string fromFile;
    getline(fin, fromFile);
    decryptedText = decrypt(fromFile);
    fin.close();

    cout << "Normal text: " << text << endl;
    cout << "Encrypted text from the file: " << encryptedText << endl;
    cout << "Decrypted text read then decoded from file: " << decryptedText << endl;
    return 0;
}
