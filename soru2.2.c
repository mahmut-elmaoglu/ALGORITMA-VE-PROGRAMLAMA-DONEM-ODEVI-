#include <stdio.h>

// Alıştırma 2.2
int main() {
    int n, i, j, k;

    printf("Ucgenin yuksekligi (n) kac olsun: ");
    scanf("%d", &n);

    // Dış döngü: Satırları (1'den n'e kadar) kontrol eder
    for (i = 1; i <= n; i++) {
        
        // 1. İç Döngü: Eşkenar görünümü için baştaki boşlukları basar
        // Her satırda (n - i) kadar boşluk bırakırız.
        for (j = 1; j <= n - i; j++) {
            printf(" "); 
        }

        // 2. İç Döngü: Sayıları basar
        // Her satırda o satırın numarasına kadar (1'den i'ye) sayı basarız.
        for (k = 1; k <= i; k++) {
            // Sayı ve yanında bir boşluk basarak üçgeni genişletiyoruz
            printf("%d ", k);
        }

        // Satır bittiğinde alt satıra geç
        printf("\n");
    }

    return 0;
}