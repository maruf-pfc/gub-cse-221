// Find the maximum/minimum element of an array.

#include <stdio.h>

int main() {
    int a[10], i, n, max, min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for (i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);

return 0;
}