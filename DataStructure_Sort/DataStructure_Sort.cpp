#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int list[], int n) {
    int i, j, least, temp;
    int compare = 0;
    int movements = 0;

    for (i = 0; i < n - 1; i++) {
        least = i;

        for (j = i + 1; j < n; j++) {
            compare++;

            if (list[j] < list[least]) {
                least = j;
            }
        }

        SWAP(list[i], list[least], temp);
        movements++;

        print_array(list, n);
    }
   
    printf("Move Count: %d\n", movements);
    printf("Compare Count: %d\n", compare);
}

   

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));

    printf("Original List: ");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        printf("%d ", list[i]);
    }
    printf("\n");

    selection_sort(list, n);

    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}