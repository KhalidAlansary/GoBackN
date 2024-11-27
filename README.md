# Network Simulation Project

This project simulates a simple network communication protocol using a sliding window mechanism. The code consists of a sender and a receiver function that handle the transmission and acknowledgment of frames.

## Files

- `main.c`: Contains the implementation of the sender and receiver functions, as well as the main function to run the simulation.

## How It Works

1. **Sender**: Sends frames within a window and waits for acknowledgments (ACKs). If an error occurs during transmission, it stops and retries.
2. **Receiver**: Receives frames within a window and sends back ACKs. If an error occurs during reception, it stops and retries.

The simulation uses a 33.33% probability to simulate errors during transmission and reception.

## Running the Simulation

To compile and run the simulation, use the following commands:

```bash
cmake -B build
```
    
```bash
cd build
```

```bash
./gobackn
```
