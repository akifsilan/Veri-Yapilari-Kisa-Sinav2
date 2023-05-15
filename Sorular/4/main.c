#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Eleman {
    int veri;
    struct Eleman* sonraki;
};

struct Kuyruk {
    struct Eleman* bas;
    struct Eleman* son;
};

struct Eleman* elemanOlustur(int veri) {
    struct Eleman* yeniEleman = (struct Eleman*)malloc(sizeof(struct Eleman));
    yeniEleman->veri = veri;
    yeniEleman->sonraki = NULL;
    return yeniEleman;
}

void kuyrugaEkle(struct Kuyruk* kuyruk, int veri) {
    struct Eleman* yeniEleman = elemanOlustur(veri);
    if (kuyruk->son == NULL) {
        kuyruk->bas = kuyruk->son = yeniEleman;
    } else {
        kuyruk->son->sonraki = yeniEleman;
        kuyruk->son = yeniEleman;
    }
    printf("Eleman eklendi: %d\n", veri);
}

void kuyruktanCikar(struct Kuyruk* kuyruk) {
    if (kuyruk->bas == NULL) {
        printf("Kuyruk boþ!\n");
        return;
    }
    struct Eleman* temp = kuyruk->bas;
    kuyruk->bas = kuyruk->bas->sonraki;
    if (kuyruk->bas == NULL)
        kuyruk->son = NULL;
    printf("Eleman çýkarýldý: %d\n", temp->veri);
    free(temp);
}

void kuyrukuGoruntule(struct Kuyruk* kuyruk) {
    if (kuyruk->bas == NULL) {
        printf("Kuyruk boþ!\n");
        return;
    }
    struct Eleman* temp = kuyruk->bas;
    printf("Kuyruk elemanlarý: ");
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "turkish");
	
    struct Kuyruk kuyruk;
    kuyruk.bas = kuyruk.son = NULL;
    int secim, veri;

	printf("Akif Silan  1220505044\n\n");
    while (1) {
        printf("1. Ekle\n");
        printf("2. Çýkar\n");
        printf("3. Görüntüle\n");
        printf("4. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek veriyi girin: ");
                scanf("%d", &veri);
                kuyrugaEkle(&kuyruk, veri);
                break;
            case 2:
                kuyruktanCikar(&kuyruk);
                break;
            case 3:
                kuyrukuGoruntule(&kuyruk);
                break;
            case 4:
                exit(0);
            default:
                printf("Geçersiz seçim!\n");
        }
    }

    return 0;
}

