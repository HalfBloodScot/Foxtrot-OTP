#ifndef FOXTROT_OTP_FOXTROT_H
#define FOXTROT_OTP_FOXTROT_H

#include <vector>    //For std::vector.
#include <string>    //For std::string
#include <iostream>  //Printing to std::cout.
#include <windows.h> //For acquiring a cryptographic context.

/**
 * The internal representation of a string inside the Foxtrot class.
 */
typedef std::vector<int> NString;

/**
 * @brief The Foxtrot class.
 *
 * Provides key generation, string encryption and string decryption
 * using the OTP cryptographic method.
 */
class Foxtrot {
protected:
    HCRYPTPROV cryptHandle;                  /**< Secure windows CSRNG generation. **/
    const int SupportedAsciiRange = 94;      /**< The number of supported ASCII characters. **/
    const int LowestSupportedAsciiChar = 32; /**< The decimal id of the lowest supported ASCII char. **/

    /**
     * Either encrypts or decrypts the provided text using the provided key.
     *
     * @param text      The text to be encrypted/decrypted.
     * @param key       The random key associated with this encryption operation.
     * @param encrypt   True if encrypting the text, false if decrypting.
     *
     * @return The encrypted/decrypted text.
     */
    NString rotate(const NString& text, const NString& key, bool encrypt);

    /**
     * Wraps a number into the range of supported ASCII characters using modular.
     * arithmetic.
     *
     * @param num       The number to map to the domain.
     *
     * @return num mapped onto the domain [LLowestSupportedAsciiChar, LowestSupportedAsciiChar + SupportedAsciiRange].
     */
    int mapToDomain(int num);
public:
    /**
     * Attempts to acquire a cryptography context from windows for generating secure
     * random bits.
     *
     * @throws A const char* exception if windows fails to acquire a cryptography context.
     */
    Foxtrot();

    /**
     * Converts a std::string to an NString (a std::vector<int>) for internal use
     * in the object.
     *
     * @param string The std::string to be converted.
     * @return The NString equivalent to the argument.
     */
    NString toNString(const std::string& string);

    /**
     * Converts an NString to a std::string.
     *
     * @param nstring The NString to be converted.
     * @return The std::string equivalent of the provided NString.
     */
    std::string toString(const NString& nstring);

    /**
     * Generates a random key using a windows secure cryptographic context.
     *
     * @param numCharacters The number of characters in the generated key.
     * @return A secure randomly generated key.
     */
    NString generateKey(int numCharacters);

    /**
     * Decrypts a std::string using the provided key.
     *
     * @param cipherText    The encrypted cipher-text.
     * @param key           The key to use in the decryption process.
     * @return The decrypted cipher-text.
     */
    std::string decrypt(const std::string& cipherText, NString& key);

    /**
     * Encrypts a std::string using the provided key.
     *
     * @param plainText     The plain-text.
     * @param key           The key to use in the encryption process.
     * @return The encrypted plain-text.
     */
    std::string encrypt(const std::string& plainText, NString& key);

    /**
     * Prints the provided nString to std::cout.
     *
     * @param NString The nString to print through std::cout.
     */
    void print(const NString& nString);
};

#endif //FOXTROT_OTP_FOXTROT_H
