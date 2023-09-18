Minitalk
--------

Minitalk is a simple communication program, allowing messages to be transmitted between two processes using UNIX signals. The program utilizes the `SIGUSR1` and `SIGUSR2` signals to represent the binary bits of the transmitted message.

Features
------

- Asynchronous communication between the server and client.
- Message transmission using UNIX signals.
- Clean error handling and feedback.
- Minimalistic design with a focus on performance.

Prerequisites
---------

- GCC compiler.
- A UNIX-like operating system.

Compilation
----------

To compile the client and server binaries, simply run:


-make all


This will generate two executables: `client` and `server`.

Usage
------

1. Start the server:

./server

The server will display its Process ID (PID) upon startup:

GETPID ID : 12345

2. In a separate terminal, send a message using the client:

./client [SERVER_PID] "Your message here"

For example:

./client 12345 "Hello, World!"

Server
-----

The server continuously waits for signals (`SIGUSR1` or `SIGUSR2`) from the client. Each signal represents a binary bit of the transmitted character. Once a full byte (8 bits) is received, the server decodes it into the corresponding character and prints it out. 

Client
-----

The client takes the server's PID and the message to be transmitted as arguments. It then sends each character of the message to the server, one bit at a time, using UNIX signals. The `SIGUSR1` signal represents a binary '1', and the `SIGUSR2` signal represents a binary '0'.

Limitations
--------

- Messages are limited to ASCII characters with values from 0 to 127.
- High message throughput might lead to missed signals or message corruption.

Contributing
-----

Feel free to fork the repository, make some changes, and submit pull requests. All contributions are welcome!
