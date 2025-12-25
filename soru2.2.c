#include <stdio.h>

//Alıştırma 2.2
int main() {
    int n, i, j, k;

    printf("Ucgenin yuksekligi (n) kac olsun: ");
    scanf("%d", &n);

    //Satırları 1'den n'ye kadar kontrol etme
    for (i = 1; i <= n; i++) {
        
        //Eşkenar görünümü için baştaki boşlukları basma
        //Her satırda n - i kadar boşluk bırakıyoruz
        for (j = 1; j <= n - i; j++) {
            printf(" "); 
        }

        //Sayıları basma
        //Her satırda o satırın numarasına kadar 1'den i'ye sayı basarız.
        for (k = 1; k <= i; k++) {
            //Sayı ve yanında bir boşluk basarak üçgeni genişletiyoruz
            printf("%d ", k);
        }

        
        printf("\n");
    }

    return 0;

}
