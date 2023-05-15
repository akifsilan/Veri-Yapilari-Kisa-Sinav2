#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int size;
    printf("Akif Silan  1220505044\n\n");
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &size);

    int arr[size];
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. elemani girin: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int aranacak;
    printf("Aranacak elemani girin: ");
    scanf("%d", &aranacak);

    if (linearSearch(arr, size, aranacak)) {
        printf("Eleman dizide bulunuyor.\n");
    } else {
        printf("Eleman dizide bulunmuyor.\n");
    }

    return 0;
}

