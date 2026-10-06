#include <stdio.h>
float SimpleInterest(float P, float T, float R) {
    return (P * T * R) / 100;
}
int main() {
    float P, T, R, SI;

    printf("Enter Principal: ");
    scanf("%f", & P);

    printf("Enter Time: ");
    scanf("%f", & T);

    printf("Enter Rate: ");
    scanf("%f", & R);

    SI = SimpleInterest(P, T, R);

    printf("Simple Interest = %.2f", SI);

    return 0;
}
