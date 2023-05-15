#include <stdio.h>

void bubbleSort(int arr[], int size) {
	int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Aranan eleman bulundu
        } else if (arr[mid] < target) {
            low = mid + 1;  // Ýkinci yarýda devam et
        } else {
            high = mid - 1;  // Ýlk yarýda devam et
        }
    }

    return -1;  // Aranan eleman bulunamadý
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    int aranan = 76;
	printf("Akif Silan  1220505044\n\n");
    // Diziyi sýralama
    bubbleSort(dizi, boyut);

    int sonuc = binarySearch(dizi, 0, boyut - 1, aranan);

    if (sonuc == -1) {
        printf("Aranan eleman bulunamadi.\n");
    } else {
        printf("Aranan eleman %d, indeks: %d\n", aranan, sonuc);
    }

    return 0;
}

