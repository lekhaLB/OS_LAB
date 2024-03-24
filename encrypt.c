#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char charToBinary(char c, int binaryArray[])
{
    int i, j = 0; // Initialize j to 0
    for (i = 7; i >= 0; --i)
    {
        binaryArray[7 - i] = (c >> i) & 1; // Store original binary representation
    }
    // Invert each bit in the binary array
    for (i = 0; i < 8; ++i)
    {
        binaryArray[i] = (binaryArray[i] == 0) ? 1 : 0;
    }
    int asciiValue = 0;
    for (i = 0; i < 8; ++i)
    {
        asciiValue += binaryArray[i] << (7 - i);
    }
    return (char)asciiValue;
}
char *encryptMemory(const char *data)
{
    int dataSize = strlen(data);
    char *encryptedData = (char *)malloc(dataSize + 1); // Allocate memory for encrypted data
    if (encryptedData == NULL)
    {
        // Handle memory allocation error
        return NULL;
    }
    int binaryArray[8]; // Binary array to store the binary representation of each character
    for (int i = 0; i < dataSize; ++i)
    {
        encryptedData[i] = charToBinary(data[i], binaryArray);
    }
    encryptedData[dataSize] = '\0'; // Null-terminate the encrypted data string
    printf("Encrypted Data : %s\n", encryptedData);
    return encryptedData;
}
char *decryptMemory(const char *data)
{
    int dataSize = strlen(data);
    char *decryptedData = (char *)malloc(dataSize + 1); // Allocate memory for encrypted data
    if (decryptedData == NULL)
    {
        // Handle memory allocation error
        return NULL;
    }
    int binaryArray[8]; // Binary array to store the binary representation of each character
    for (int i = 0; i < dataSize; ++i)
    {
        decryptedData[i] = charToBinary(data[i], binaryArray);
    }
    decryptedData[dataSize] = '\0'; // Null-terminate the encrypted data string
    return decryptedData;
}
