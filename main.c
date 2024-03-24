#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "encryp.h"
char *filename;
// API to encrypt data, store it in RAM, and write the memory address to a .txt
file void *encryptAndStore(void *args)
{
    const char *data = (const char *)args;
    // Encrypt the data and store it in memory
    char *encryptedData = encryptMemory(data);
    // Write the memory address to the given .txt file
    FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
        fprintf(file, "%p", (void *)encryptedData);
        fclose(file);
        printf("Memory address has been written to %s\n", filename);
    }
    else
    {
        printf("Error: Unable to open file for writing\n");
    }
    pthread_exit(NULL);
}
// Simulated memory decryption function
// API to read .txt file, decrypt data, and free memory
void *readAndDecrypt(void *args)
{

    // Read the memory address from the .txt file
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        void *address;
        fscanf(file, "%p", &address);
        fclose(file);
        // Decrypt the data stored in the memory address
        char *decryptedData = decryptMemory(address);
        // Print the decrypted data
        printf("Decrypted data: %s\n", decryptedData);
        // Free the memory allocated for the decrypted data
        free(decryptedData);
    }
    else
    {
        printf("Error: Unable to open file for reading\n");
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <data_to_encrypt> <filename>\n", argv[0]);
        return 1;
    }
    const char *dataToEncrypt = argv[1];
    filename = argv[2];
    pthread_t encryptThread, decryptThread;
    int encryptThreadStatus, decryptThreadStatus;
    // Create a thread to encrypt and store data
    encryptThreadStatus = pthread_create(&encryptThread, NULL, encryptAndStore, (void *)dataToEncrypt);
    if (encryptThreadStatus)
    {
        printf("Error: Unable to create encrypt thread\n");
        return 1;
    }
    // Wait for the encrypt thread to finish
    pthread_join(encryptThread, NULL);
    // Create a thread to read, decrypt, and free memory
    decryptThreadStatus = pthread_create(&decryptThread, NULL, readAndDecrypt, (void *)filename);
    if (decryptThreadStatus)
    {
        printf("Error: Unable to create decrypt thread\n");
        return 1;
    }
    // Wait for the decrypt thread to finish
    pthread_join(decryptThread, NULL);
    return 0;
}
