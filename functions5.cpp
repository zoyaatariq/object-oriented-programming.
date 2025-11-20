#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    string caesar = text;
    for (int i = 0; i < caesar.size(); i++)
        caesar[i] = char(caesar[i] + key);

    cout << "Caesar Encrypted: " << caesar << endl;

    string xorEnc = text;
    for (int i = 0; i < xorEnc.size(); i++)
        xorEnc[i] = xorEnc[i] ^ key;

    cout << "XOR Encrypted: " << xorEnc << endl;

    return 0;
}
