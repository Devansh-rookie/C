#include <stdio.h>

// Function to calculate distance traveled by the first bird
double firstBirdDistance(double a, double b, double c, double d, double z,int n_max, int cur_n, double max_time, double time_n, double t_sum, double dist_sum) {
    if (n_max == 0) {
       return dist_sum+(max_time-t_sum)*c;
    }
    else {
        return c + firstBirdDistance(a, b, c, cur_n - 1);
    }
}

// Function to calculate distance traveled by the second bird during Nth trip
// double secondBirdDistance(double a, double b, double c, double d, int n) {
//     if (n == 0) {
//         return 0;
//     } else {
//         return d + secondBirdDistance(a, b, c, d, n - 1);
//     }
// }

int main() {
    double a, b, c, d, z, max_time, time_n, t_sum, dist_sum;
    int n_max, cur_n;
    max_time= (float)(z)/(a+b);
    time_n= (float)z/(c+d);
    t_sum=0.0;dist_sum=0.0;cur_n=0;
    
    return 0;
}