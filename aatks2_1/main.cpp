#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define A_SIZE 20
#define G_SIZE 10
#define MAX_W 10

//Max deger icin sonsuz sayi
#define INF INT_MAX

void generate(int a[], int size);
void merge(int a[], int left, int mid, int right);
void function1(int a[], int left, int right);
int function2(int a[], int size);
void function3(int g[][G_SIZE], int d[][G_SIZE], int size);
void print1(int a[], int size);
void print2(int g[][G_SIZE], int size);
void print3(int g[][G_SIZE], int size, int t);

int main() {
    int a[A_SIZE];
    int g[G_SIZE][G_SIZE] = {
    { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
    {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
    { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
    { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
    { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
    { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
    { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
    {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
    { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
    {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int d[G_SIZE][G_SIZE];
    int t;

    // Rastgele sayi uretici icin seed
    srand(time(NULL));

    // Calisma suresinin hesaplanmasi
    clock_t start, end;
    double time;

    start = clock();

    generate(a, A_SIZE);
    printf("A:\n");
    print1(a, A_SIZE);

    function1(a, 0, A_SIZE - 1);
    printf("\nFunction1 Sonuc:\n");
    print1(a, A_SIZE);

    t = function2(a, A_SIZE);
    printf("\nFunction2 Sonuc: %d\n", t);

    printf("\nG:\n");
    print2(g, G_SIZE);

    function3(g, d, G_SIZE);
    printf("\nFunction3 Sonuc:\n");
    print2(d, G_SIZE);

    printf("\n%d icin sonuc:\n", t);
    print3(d, G_SIZE, t);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", time);

    return 0;
}

void generate(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (2 * MAX_W) - MAX_W;
    }
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

//Merge Sort Algoritmasi
void function1(int a[], int left, int right) {
     if (left < right) {
        int mid = left + (right - left) / 2;

        function1(a, left, mid);
        function1(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int function2(int a[], int size) {
    int t = 0, current_sum = 0, count=0;
    for (int i = 0; i < size; i++) {
        if (current_sum + a[i] > 0) {
            current_sum = current_sum + a[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > t) {
            t = current_sum;
            count++;
        }
    }
    return t/count;
}

//Dijkstra Algoritmasi
void function3(int g[][G_SIZE], int d[][G_SIZE], int size) {
     for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else if (g[i][j] != 0) {
                d[i][j] = g[i][j];
            }
            else {
                d[i][j] = INF;
            }
        }
    }

    for (int src = 0; src < size; src++) {
        int visited[G_SIZE] = {0};
        d[src][src] = 0;

        for (int count = 0; count < size - 1; count++) {
            int min_dist = INF, min_index;
            for (int v = 0; v < size; v++) {
                if (!visited[v] && d[src][v] <= min_dist) {
                    min_dist = d[src][v];
                    min_index = v;
                }
            }

            visited[min_index] = 1;

            for (int v = 0; v < size; v++) {
                if (!visited[v] && g[min_index][v] && d[src][min_index] != INF &&
                    d[src][min_index] + g[min_index][v] < d[src][v]) {
                    d[src][v] = d[src][min_index] + g[min_index][v];
                }
            }
        }
    }
}

void print1(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

void print2(int g[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (g[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

void print3(int d[][G_SIZE], int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && d[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, d[i][j]);
            }
        }
    }
}
