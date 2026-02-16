#include <stdio.h>

int main()
{
    int n;
    int arr[100];
    int count[100] = {0};

    scanf("%d", &n);

    // Input array
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(int i = 0; i < n; i++)
    {
        if(count[i] == -1)
            continue;

        int freq = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                freq++;
                count[j] = -1;
            }
        }

        count[i] = freq;
    }

    // Print result
    for(int i = 0; i < n; i++)
    {
        if(count[i] != -1)
        {
            printf("%d:%d ", arr[i], count[i]);
        }
    }

    return 0;
}
