**Overview:**

This project implements cryptographic memory management techniques within an operating system environment. It leverages pthread for multithreading, dynamic memory allocation for efficient memory usage, and encryption/decryption mechanisms to secure user input strings.

**Aim:**

The aim of this multithreaded program is to demonstrate efficient and secure data processing through parallel execution, facilitating robust encryption and decryption functionalities in contemporary environments. By leveraging pthreads for concurrent handling of encryption and decryption operations, the program showcases the capability to manage cryptographic tasks concurrently, optimizing performance and ensuring data security.

**Theory:**

In this multithreaded program, the following operations are handled concurrently using pthreads:

Data Encryption:
Upon receiving input data from the user, the program initiates the encryption process.
Utilizing pthreads, multiple threads are spawned to encrypt the data concurrently.
Encrypted data is then stored in the RAM.

Memory Management:
The program dynamically allocates memory space to store the encrypted data in the RAM.
Memory addresses corresponding to the allocated space are retained for subsequent retrieval.

File Writing:
After encryption, the program writes the memory address to a specified file.
This file serves as a reference for locating encrypted data in the memory.

Data Decryption:
Upon retrieving the memory address from the file, the program initiates the decryption process.
Similar to encryption, pthreads are employed for concurrent decryption operations.
Decrypted data is then made available for further processing.

Memory Deallocation:
Once decryption is completed, the program frees the allocated memory space.
This ensures efficient memory management and prevents memory leaks.
