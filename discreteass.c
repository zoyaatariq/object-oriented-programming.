#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5   // Number of people/nodes in the network

// Adjacency matrix representing who is connected to whom
int network[N][N] = {
    {0,1,1,0,0},  // A connected to B, C
    {1,0,1,1,0},  // B connected to A, C, D
    {1,1,0,0,1},  // C connected to A, B, E
    {0,1,0,0,0},  // D connected to B
    {0,0,1,0,0}   // E connected to C
};

// Function to simulate the diffusion process
void diffusion(int source, float probability) {
    int received[N] = {0};   // To track who has received the message
    received[source] = 1;    // Source starts with the message

    int newRound = 1;        // Flag to check if new people got the message
    int round = 1;           // Count rounds of spreading

    srand(time(0));          // Initialize random seed

    printf("\nStarting Diffusion Simulation...\n");
    printf("Source: Person %c\n", 'A' + source);
    printf("Forwarding Probability: %.2f\n\n", probability);

    while (newRound) {
        newRound = 0;
        printf("Round %d:\n", round);

        for (int i = 0; i < N; i++) {
            if (received[i]) {
                // Each informed person tries to send to their friends
                for (int j = 0; j < N; j++) {
                    if (network[i][j] && !received[j]) {
                        float chance = (float)rand() / RAND_MAX;
                        if (chance < probability) {
                            received[j] = 1;
                            newRound = 1;
                            printf("  Person %c forwarded message to %c\n", 'A' + i, 'A' + j);
                        }
                    }
                }
            }
        }

        if (!newRound)
            printf("  No new forwards this round.\n");

        printf("\n");
        round++;
    }

    printf("Final Result:\n");
    for (int i = 0; i < N; i++) {
        if (received[i])
            printf("  Person %c received the message.\n", 'A' + i);
    }
}

int main() {
    printf("=== Simple Diffusion Model (WhatsApp Spread Simulation) ===\n");

    int source = 0;      // 'A' starts the message
    float p = 0.5;       // 50% chance to forward the message

    diffusion(source, p);

    return 0;
}
