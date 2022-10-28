#include <math.h>
#include <stdio.h>

typedef enum{false, true} bool;

int main(int argc, char *argv[]){
    long long int n = 1;
    double ang, ang_rad, seno, x, pi;

    while(n >= 0){
        n += 10;

        ang = 360.0/((double) n);
        ang_rad = (((double) M_PI)/180.0)*ang;

        pi = (((double) n)*(sin(ang_rad)))/2.0;

        printf("%d -> PI = %.20lf\n", n, pi);
    }

    return 0;
}
