#include <stdio.h>

float distanceFirstBird(float a, float b, float c, float z, int n) {
    if (n == 0) {
        return 0.0;
    }
    
    float time = z / (a + b);
    float distanceCovered = time * c;
    
    return distanceCovered + distanceFirstBird(a, b, c, z - time * (a + b), n - 1);
}

float distanceSecondBird(float a, float b, float c, float d, float z, int n) {
    if (n == 0) {
        return 0.0;
    }

    float time = z / (a + b);
    float distanceCovered = time * d;

    return distanceCovered + distanceSecondBird(a, b, c, d, z - time * (a + b), n - 1);
}

int main() {
    float a, b, c, d, z;
    int n;

    printf("Enter speed of the first train (a): ");
    scanf("%f", &a);

    printf("Enter speed of the second train (b): ");
    scanf("%f", &b);

    printf("Enter speed of the first bird (c): ");
    scanf("%f", &c);

    printf("Enter speed of the second bird (d): ");
    scanf("%f", &d);

    printf("Enter initial distance between the trains (z): ");
    scanf("%f", &z);

    printf("Enter the number of trips : ");
    scanf("%d", &n);

    float firstBirdDistance = distanceFirstBird(a, b, c, z, n);
    float secondBirdDistance = distanceSecondBird(a, b, c, d, z, n);

    printf("Distance traveled by the first bird: %f kilometers\n", firstBirdDistance);
    printf("Distance traveled by the second bird during the %dth trip: %f kilometers\n", n, secondBirdDistance);

    return 0;
}
