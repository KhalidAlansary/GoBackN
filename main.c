#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_SIZE 4

/**
 * @brief Simulate error occurrence
 *
 * @return true if error occurred (33.33% probability), false otherwise
 */
bool error_occurred() {
  return !(rand() % 3);
}

/**
 * @brief Sender function
 *
 * @param frames Array of frames
 * @param N Number of frames
 */
void sender(const char* frames[], const size_t N) {
  size_t window_start = 0;

  while (window_start < N) {
    size_t window_end = window_start + WINDOW_SIZE;
    if (window_end > N) {
      window_end = N;
    }

    // Send frames within the window
    for (size_t i = window_start; i < window_end; i++) {
      printf("Sending frame %zu: %s\n", i, frames[i]);
    }

    // Receive ACKs
    for (size_t i = window_start; i < window_end; i++) {
      if (error_occurred()) {
        printf("Error occurred while sending frame %zu\n", i);
        break;
      }
      printf("Received ACK for frame %zu\n", i);
      window_start++;
    }
  }
}

/**
 * @brief Receiver function
 *
 * @param frames Array of frames
 * @param N Number of frames
 */
void receiver(const char* frames[], const size_t N) {
  size_t window_start = 0;

  while (window_start < N) {
    size_t window_end = window_start + WINDOW_SIZE;
    if (window_end > N) {
      window_end = N;
    }

    // Receive frames within the window
    for (size_t i = window_start; i < window_end; i++) {
      if (error_occurred()) {
        printf("Error occurred while receiving frame %zu\n", i);
        break;
      }
      printf("Received frame %zu: %s\n", i, frames[i]);
    }

    // Send ACKs
    for (size_t i = window_start; i < window_end; i++) {
      printf("Sending ACK for frame %zu\n", i);
      window_start++;
    }
  }
}

int main() {
  srand(time(NULL));
  const char* frames[] = {"Hello", "World", "This", "Is", "A", "Test"};

  // Simulate sender
  printf("Sender\n");
  sender(frames, sizeof(frames) / sizeof(frames[0]));

  // Simulate receiver
  printf("\nReceiver\n");
  receiver(frames, sizeof(frames) / sizeof(frames[0]));

  return EXIT_SUCCESS;
}
