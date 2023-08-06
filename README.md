# Minitalk

This project consists of implementing a communication program in the form of a client and a server in a UNIX environment. The communication between both will be done exclusively using UNIX signals, utilizing the signals SIGUSR1 and SIGUSR2. The goal is to allow the client to send a text string to the server, and the server will display the received string.

## System Requirements
To run this program, you will need a UNIX-based operating system such as Linux or macOS.

## Usage

```bash
# Clone this project
git clone https://github.com/laugarci/minitalk

# Access
cd minitalk

# To run the simulation, compile the philo program using the provided Makefile:
make

# To run (example)
- Launch the server first by executing the following command:

./server

- The server will display its PID on the console and be ready to receive messages from the client.
  Next, run the client with the following parameters:

./client <PID> "<MESSAGE>"

# To remove objects
make clean

# To remove objects and executable
make fclean

```
