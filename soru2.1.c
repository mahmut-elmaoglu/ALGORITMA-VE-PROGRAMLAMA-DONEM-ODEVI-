#include <stdio.h>

// Alıstırma 2.1
// Özyinelemeli Fonksiyon
int ucgenSayisi(int n) {
    // n=1 ise 1 döndür
    if (n == 1) {
        return 1;
    }
    // Özyineleme Adımı: n + (n-1)'in üçgen sayısı
    return n + ucgenSayisi(n - 1);
}

int main() {
    int N, i;

    printf("Kac adet ucgen sayisi yazdirilsin (N): ");
    scanf("%d", &N);

    printf("N=%d ucgen sayilar = ", N);
    
    // 1'den N'e kadar döngü kurup her sayı için fonksiyonu çağırıyoruz
    for (i = 1; i <= N; i++) {
        printf("%d ", ucgenSayisi(i));
    }
    
    printf("\n");

    return 0;
}