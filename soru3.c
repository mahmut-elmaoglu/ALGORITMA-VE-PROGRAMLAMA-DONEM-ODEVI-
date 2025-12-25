#include <stdio.h>

// Bir sayının asal olup olmadığını kontrol eden fonksiyon
int asalmi(int sayi) {
    if (sayi < 2) return 0; // 2'den küçük sayılar asal değildir
    for (int i = 2; i * i <= sayi; i++) {
        if (sayi % i == 0) return 0; //Eğer sayı i değerine bölünebiliyorsa asal değildir
    }
    return 1; //Asaldır
}

// Bir karakterin ünlü harf olup olmadığını kontrol eden fonksiyon
int unlumu(char h) {
    
    if (h == 'a' || h == 'e' || h == 'i' || h == 'o' || h == 'u') {
        return 1;
    }
    return 0;
}

int main() {
    int sayac = 0;
    
    printf("Gecerli Gezegen Bob isimleri:\n");

    // Tüm küçük harfleri tarıyoruz (1. Harf)
    for (char h1 = 'a'; h1 <= 'z'; h1++) {
        // Tüm küçük harfleri tarıyoruz (2. Harf)
        for (char h2 = 'a'; h2 <= 'z'; h2++) {
            
            char h3 = h1; //Üçüncü harf birinciyle aynı olmalı

            /* 
            KURAL: Yapı 'Ünlü-Ünsüz-Ünlü' veya 'Ünsüz-Ünlü-Ünsüz' olmalı.
            Bu, h1 ve h2'nin farklı türde olması gerektiği anlamına gelir.
            Eğer ikisi de ünlü veya ikisi de ünsüzse bu ismi atla.
            */
            if (unlumu(h1) == unlumu(h2)) {
                continue;
            }

            // KURAL 2: ASCII toplamı asal sayı olmalı
            int toplam = h1 + h2 + h3;
            
            if (asalmi(toplam)) {
                printf("%c%c%c\n", h1, h2, h3);
                sayac++;
            }
        }
    }
    
    printf("\n");
    
    printf("Toplam Gezegen Bob isimleri %d tanedir.", sayac);

    return 0;
}

/*
Eğer isimlerin ASCII toplamlarını öğrenmek istiyorsak sonda ki if döngüsünü 
if (asalmi(toplam)) {
                printf("%c%c%c (ASCII Toplam: %d)\n", h1, h2, h3, toplam);
                sayac++;
            }
            
    şeklinde değiştirirsek eğer bize isimlerin yanında ASCII toplamlarını verecektir

    */
