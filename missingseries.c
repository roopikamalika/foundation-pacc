#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        if(arr[i + 1] - arr[i] != 1)
        {
            printf("Missing Number = %d", arr[i] + 1);
            break;
        }
    }

    return 0;
}