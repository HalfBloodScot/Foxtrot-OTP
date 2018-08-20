#include "Foxtrot.h"

NString Foxtrot::rotate(const NString& text, const NString& key, bool encrypt) {
    if (key.size() < text.size()) {
        std::cout << "Invalid key size!\n";
        return NString();
    }
    NString ciphertext;
    for (int i = 0; i < text.size(); ++i) {
        const int nextChar = encrypt ? text[i] + key[i] : text[i] - key[i];
        ciphertext.push_back(mapToDomain(nextChar));
    }
    return ciphertext;
}

int Foxtrot::mapToDomain(int num) {
    return (num % SupportedAsciiRange + SupportedAsciiRange) % SupportedAsciiRange;
}

Foxtrot::Foxtrot() {
    if (!CryptAcquireContextA(&cryptHandle, NULL, NULL, PROV_RSA_FULL, 0)) {
        throw "Error establishing cryptography context!\n";
    }
}

NString Foxtrot::toNString(const std::string& string) {
    NString temp;
    for (auto& i : string) {
        temp.push_back((int)i - LowestSupportedAsciiChar);
    }
    return temp;
};

std::string Foxtrot::toString(const NString& data) {
    std::string temp;
    for (auto& i : data) {
        temp += i + LowestSupportedAsciiChar;
    }
    return temp;
}

NString Foxtrot::generateKey(int numCharacters) {
    NString key;
    BYTE dataBuffer[numCharacters];
    if (CryptGenRandom(cryptHandle, sizeof(dataBuffer), dataBuffer)) {
        for (int i = 0; i < numCharacters; ++i) {
            key.push_back(mapToDomain(dataBuffer[i]));
        }
    }
    else {
        std::cout << "Key generation failed!\n";
    }
    return key;
}

std::string Foxtrot::decrypt(const std::string &cipherText, NString &key) {
    return toString(rotate(toNString(cipherText), key, false));
}

std::string Foxtrot::encrypt(const std::string &plainText, NString &key) {
    return toString(rotate(toNString(plainText), key, true));
}

void Foxtrot::print(const NString& nString) {
    for (auto& i : nString) {
        std::cout << i << "\n";
    }
}