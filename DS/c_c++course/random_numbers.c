#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate and print 1000 random numbers
    for (int i = 0; i < 100; i++) {
        printf("%d ", rand());
    }

    return 0;
}
