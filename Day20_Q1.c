#include <stdio.h>
#include <stdlib.h>

#define SIZE 100003   

typedef struct Node {
    long long key;
    long long count;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

int hash(long long key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

long long getCount(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long*)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long prefixSum = 0;
    long long count = 0;

    insert(0);  

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        count += getCount(prefixSum);

        insert(prefixSum);
    }

    printf("%lld\n", count);

    return 0;
}
