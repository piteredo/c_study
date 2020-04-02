#include<stdio.h>

int main(void) {
    int min, max, sum;
    printf("press min,max...");
    scanf("%d, %d", &min, &max);
    sum = (min+max) * (max - min +1) / 2;
    printf("sum of %d ~ %d == %d", min, max, sum);

    return 0;
}
