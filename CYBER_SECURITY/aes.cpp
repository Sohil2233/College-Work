#include <iostream>
#include <vector>
using namespace std;

const int Nb = 3; // Block size in 32-bit words (3 words = 3 * 4 bytes = 12 bytes)

// AES S-box
const unsigned char sbox[256] = {
    //... (You need to fill this array with AES S-box values)
};

// AES Inverse S-box
const unsigned char rsbox[256] = {
    //... (You need to fill this array with AES inverse S-box values)
};

// Rijndael's Galois field multiplication
unsigned char gfMul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    unsigned char hiBitSet;
    for (int counter = 0; counter < 8; counter++) {
        if (b & 1)
            p ^= a;
        hiBitSet = a & 0x80;
        a <<= 1;
        if (hiBitSet)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}

void SubBytes(vector<vector<unsigned char>>& state) {
    for (int i = 0; i < Nb; i++)
        for (int j = 0; j < Nb; j++)
            state[i][j] = sbox[state[i][j]];
}

void InvSubBytes(vector<vector<unsigned char>>& state) {
    for (int i = 0; i < Nb; i++)
        for (int j = 0; j < Nb; j++)
            state[i][j] = rsbox[state[i][j]];
}

void ShiftRows(vector<vector<unsigned char>>& state) {
    vector<unsigned char> temp(Nb);
    for (int i = 1; i < Nb; i++) {
        for (int j = 0; j < Nb; j++)
            temp[j] = state[i][(j + i) % Nb];
        for (int j = 0; j < Nb; j++)
            state[i][j] = temp[j];
    }
}

void InvShiftRows(vector<vector<unsigned char>>& state) {
    vector<unsigned char> temp(Nb);
    for (int i = 1; i < Nb; i++) {
        for (int j = 0; j < Nb; j++)
            temp[j] = state[i][(j - i + Nb) % Nb];
        for (int j = 0; j < Nb; j++)
            state[i][j] = temp[j];
    }
}

void MixColumns(vector<vector<unsigned char>>& state) {
    unsigned char temp[4];
    for (int i = 0; i < Nb; i++) {
        temp[0] = gfMul(state[0][i], 2) ^ gfMul(state[1][i], 3) ^ state[2][i];
        temp[1] = state[0][i] ^ gfMul(state[1][i], 2) ^ gfMul(state[2][i], 3);
        temp[2] = gfMul(state[0][i], 3) ^ state[1][i] ^ gfMul(state[2][i], 2);
        for (int j = 0; j < Nb; j++)
            state[j][i] = temp[j];
    }
}

void InvMixColumns(vector<vector<unsigned char>>& state) {
    unsigned char temp[4];
    for (int i = 0; i < Nb; i++) {
        temp[0] = gfMul(state[0][i], 14) ^ gfMul(state[1][i], 11) ^ gfMul(state[2][i], 13);
        temp[1] = gfMul(state[0][i], 13) ^ gfMul(state[1][i], 14) ^ gfMul(state[2][i], 11);
        temp[2] = gfMul(state[0][i], 11) ^ gfMul(state[1][i], 13) ^ gfMul(state[2][i], 14);
        for (int j = 0; j < Nb; j++)
            state[j][i] = temp[j];
    }
}

void AddRoundKey(vector<vector<unsigned char>>& state, const vector<unsigned char>& roundKey) {
    for (int i = 0; i < Nb; i++)
        for (int j = 0; j < Nb; j++)
            state[i][j] ^= roundKey[i * Nb + j];
}

void printState(const vector<vector<unsigned char>>& state) {
    for (int i = 0; i < Nb; i++) {
        for (int j = 0; j < Nb; j++) {
            cout << hex << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<unsigned char>> state(Nb, vector<unsigned char>(Nb));
    vector<unsigned char> key(Nb * Nb);

    cout << "Enter a 3x3 matrix (9 bytes) as integers:" << endl;
    for (int i = 0; i < Nb; i++)
        for (int j = 0; j < Nb; j++)
            cin >> state[i][j];

    cout << "Enter a 3x3 key matrix (9 bytes) as integers:" << endl;
    for (int i = 0; i < Nb * Nb; i++)
        cin >> key[i];

    // Encryption
    AddRoundKey(state, key);
    SubBytes(state);
    ShiftRows(state);
    MixColumns(state);
    AddRoundKey(state, key);

    cout << "Encrypted matrix:" << endl;
    printState(state);

    // Decryption
    AddRoundKey(state, key);
    InvMixColumns(state);
    InvShiftRows(state);
    InvSubBytes(state);
    AddRoundKey(state, key);

    cout << "Decrypted matrix:" << endl;
    printState(state);

    return 0;
}
