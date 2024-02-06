#include <stdio.h>

// Function to calculate distance traveled by the first bird
double firstBirdDistance(double a, double b, double c, int n) {
    if (n == 0) {
        return 0;
    } else {
        return c + firstBirdDistance(a, b, c, n - 1);
    }
}

// Function to calculate distance traveled by the second bird during Nth trip
double secondBirdDistance(double a, double b, double c, double d, int n) {
    if (n == 0) {
        return 0;
    } else {
        return d + secondBirdDistance(a, b, c, d, n - 1);
    }
}

int main() {
    double a, b, c, d;
    int n;

    // Input values for train speeds and bird speeds
    printf("Enter speed of the first train (a): ");
    scanf("%lf", &a);

    printf("Enter speed of the second train (b): ");
    scanf("%lf", &b);

    printf("Enter speed of the first bird (c, c > a): ");
    scanf("%lf", &c);

    printf("Enter speed of the second bird (d, d > b): ");
    scanf("%lf", &d);

    // Input the number of trips (N)
    printf("Enter the number of trips (N): ");
    scanf("%d", &n);

    // Calculate and display distances
    printf("Distance traveled by the first bird: %.2lf kilometers\n", firstBirdDistance(a, b, c, n));
    printf("Distance traveled by the second bird during Nth trip: %.2lf kilometers\n", secondBirdDistance(a, b, c, d, n));

    return 0;
}