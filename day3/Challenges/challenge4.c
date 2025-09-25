#include <stdio.h>

int main(void) {
    int a[10], i;
    int size = (int)(sizeof(a) / sizeof(a[0]));

    printf("Entrez %d nombres : ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    printf("Dans l'ordre inverse :");
    for (i = size - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
