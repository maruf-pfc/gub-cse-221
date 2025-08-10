// Find the second maximum/second minimum element of an array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, max, min, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The second maximum element is: %d\n", a[1]);
    printf("The second minimum element is: %d\n", a[n - 2]);
    return 0;
}