#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    int front = m % n;

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[(front + i) % n]);
    }

    return 0;
}
