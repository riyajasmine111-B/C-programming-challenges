#include <stdio.h>

int main() 
{
    int x[12], n, i, j, k, t;
    int sum = 0, minimum, maximum, secondlargest = -1;
    int peak = 0, count = 1, longest = 1;
    float average;
    int r, d, div = 0;
    
    printf("please enter the total number of readings between 5 to 12: ");
    scanf("%d", &n);

    while (n<5 || n>12) 
    {
        printf("Enter the N values between 5 to 12: ");
        scanf("%d",&n);
    }
    for (i = 0; i < n; i++) {
        printf("Enter reading %d: ", i + 1);
        scanf("%d", &x[i]);
        while (x[i] < 0 || x[i] > 1000)
        {
            printf("Enter the particular value between 0 and 1000: ");
            scanf("%d",&x[i]);
        }
    }
    printf("\n The original array is: ");
    for (i = 0; i<n; i++)
    {
        printf("%d ", x[i]);
    }
    minimum = x[0];
    maximum = x[0];
    
    for (i=0; i<n; i++)
    {
        sum = sum + x[i];

        if (x[i] < minimum)
            minimum = x[i];

        if (x[i] > maximum)
            maximum = x[i];
    }
     average= (float)sum / n;

    printf("\nSum is = %d", sum);
    printf("\nAverage is  = %.2f", average);
    printf("\nMinimum is = %d", minimum);
    printf("\nMaximum is = %d", maximum);

    for (i = 0; i < n; i++) 
    {
        if (x[i] < maximum&& x[i] > secondlargest)
            secondlargest = x[i];
    }

    if (secondlargest == -1)
        printf("\nThe is no second largest value");
    else
        printf("\nThe second largest value is = %d", secondlargest);

    for (i = 1; i < n - 1; i++) {
        if (x[i] > x[i - 1] && x[i] > x[i + 1])
            peak++;
    }

    printf("\nThe number of peaks = %d", peak);
 
    for (i=1; i<n; i++) {
        if (x[i]>x[i - 1])
            count++;
        else
            count = 1;

        if (count > longest)
            longest = count;
    }

    printf("\nLongest increasing run = %d", longest);

    printf("\nEnter the value of K: ");
    scanf("%d", &k);

    k = k % n;  

    if (k < 0)
        k = k + n;

    for (j = 0; j < k; j++)
    {
        t = x[n - 1];
    for (i = n - 1; i > 0; i--)
    {
            x[i] = x[i - 1];
    }
        x[0] = t;
    }

    printf("\nthe rotated array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n now enter the last two digits of your registration number: ");
    scanf("%d", &r);

    while (r < 0 || r > 99)
    {
        printf("Enter any number from 0 to 99: ");
        scanf("%d", &r);
    }

    d = (r % 9) + 1;

    for (i = 0; i < n; i++)
    {
        if (x[i] % d == 0)
            div++;
    }
    printf("\nD = %d", d);
    printf("\nDivisible count = %d\n", div);

    return 0;
}
