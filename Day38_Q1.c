#include <stdio.h>
#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else {
        for (int i = rear; i >= front; i--)
            dq[i + 1] = dq[i];
        rear++;
    }
    dq[front] = x;
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    front++;
    if (front > rear) front = rear = -1;
}

void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    rear--;
    if (rear < front) front = rear = -1;
}

int get_front() {
    if (empty()) return -1;
    return dq[front];
}

int get_back() {
    if (empty()) return -1;
    return dq[rear];
}

void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    printf("%d\n", get_front());
    printf("%d\n", get_back());
    printf("%d\n", size());

    pop_front();
    pop_back();

    reverse();
    sort();

    display();

    return 0;
}
