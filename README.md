# Foxtrot-OTP
This is a C++ class-based implementation of the one-time pad cryptographic method.

## Small Disclaimer Before we begin:
<b>This implementation is not necessarily cryptographically secure.</b> While the one-time-pad method itself is secure, this 
implementation may not be (is probably not, in fact) commercially secure. This is because no secure memory management takes place - keys and plain-text are passed around as `std::string` and `std::vector<int>`, so may reside in memory after the termination of the application.

It is therefore not advisable to implement Foxtrot on a shared computer with the expectation of security.

## Description:
The Foxtrot engine provides a Windows-specific key generation and encryption/decryption utility using the one-time-pad method.
The engine itself is comprised of a single class `Foxtrot` containing all methods associated with the engine.

### Key Generation
Foxtrot uses Windows' `CryptGenRandom()` to generate random pads for use as keys.

## Installation:
Since Foxtrot is only a single header/source class, you can simply add `Foxtrot.h` and `Foxtrot.cpp` to your project directory and `#include "Foxtrot.h"` in your implementation file.

## Usage Example:
Here's an example of how to use Foxtrot to generate a key, encrypt a message with it, then decrypt the same message:
```
#include <iostream>     //std::cout
#include "Foxtrot.h"    //Foxtrot engine

int main() {
    Foxtrot foxtrot;                                                    //Create an instance of the engine.

    NString key = foxtrot.generateKey(1000);                            //Generate a key 1000 characters long.
    std::cout << "Key: " << foxtrot.toString(key) << "\n";              //Print our key.

    std::string cipherText = foxtrot.encrypt("Hello World!", key);      //Encrypt "Hello World!" using our key.
    std::cout << "Cipher text: " << cipherText << "\n";                 //Print our cipher text.

    std::string plainText = foxtrot.decrypt(cipherText, key);           //Decrypt the cipher text using our key.
    std::cout << "Plain text: " << plainText << "\n";                   //Prints "Hello World!".

    return 0;
}

```
