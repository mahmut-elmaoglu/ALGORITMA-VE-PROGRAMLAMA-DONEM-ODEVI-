#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- FONKSİYON PROTOTİPLERİ ---
void yatay_grafik_ciz(int ciro[], int ay_sayisi);
void dikey_grafik_ciz(int ciro[], int ay_sayisi);

int main() {
    int aylik_cirolar[12];
    char *ay_isimleri[] = {
        "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
        "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"
    };
    
    // Rastgele sayı atamak için gerekli kod
    srand(time(NULL));

    //Veriyi Üreten kod sadece bir sefer üretir ve iki fonksiyona da aynı veriyi gönderir
    for (int i = 0; i < 12; i++) {
        aylik_cirolar[i] = rand() % 10 + 1;
    }
    //Alıştırma 1.1
    printf("--- AYLIK CIROLAR --- \n");

    //Aylık ciroları ekrana yazdırma
    for(int i = 0; i < 12; i++){
        printf("%-10s: %dK\n", ay_isimleri[i], aylik_cirolar[i]);
    }
    
    printf("\n");

    //Yatay grafiği çizme
    yatay_grafik_ciz(aylik_cirolar, 12);

    printf("\n\n");


    //Dikey grafiğini çizme
    dikey_grafik_ciz(aylik_cirolar, 12);
    
    return 0;
}
    
  

// --- YATAY GRAFİK FONKSİYONU ---
void yatay_grafik_ciz(int ciro[], int ay_sayisi){
    int max_deger = 0;
    int MAX_UZUNLUK = 10; 
    
    char *ay_isimleri[] = {
        "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
        "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"
    };

    //Maksimumu bulma
    for (int i = 0; i < ay_sayisi; i++) {
        if (ciro[i] > max_deger) max_deger = ciro[i];
    }
    
    //Alıştırma 1.2
    printf("--- YATAY CIRO GRAFIGI ---\n");
    
    for (int i = 0; i < ay_sayisi; i++) {
        printf("%-10s: ", ay_isimleri[i]); //Ay ismini sola dayalı yaz

        //Yıldız sayısını hesapla ve ekrana yazdır
        int yildiz = (int)(((float)ciro[i] / max_deger) * MAX_UZUNLUK);
        for (int j = 0; j < yildiz; j++) {
            printf(" * ");
       }
       printf("\n");
    }
    }

// --- SÜTUN GRAFİĞİ FONKSİYONU ---
void dikey_grafik_ciz(int ciro[], int ay_sayisi) {
    int max_deger = 0;
    int MAX_YUKSEKLIK = 15;
    
    //Alt kısma sığması için kısa isimler yazdırdık
    char *kisa_isimler[] = {
        "Oca", "Sub", "Mar", "Nis", "May", "Haz",
        "Tem", "Agu", "Eyl", "Eki", "Kas", "Ara"
    };

    
    for (int i = 0; i < ay_sayisi; i++) {
        if (ciro[i] > max_deger) max_deger = ciro[i];
    }

    //Her ayın yıldız yüksekliğini hesaplayıp diziye atma
    int yildiz_yukseklikleri[12];
    for (int i = 0; i < ay_sayisi; i++) {
        yildiz_yukseklikleri[i] = (int)(((float)ciro[i] / max_deger) * MAX_YUKSEKLIK);
    }

    //Alıştırma 1.3
    printf("--- DIKEY CIRO GRAFIGI ---\n\n");
    
    for (int i = MAX_YUKSEKLIK; i > 0; i--) {
        printf("   "); 
        for (int j = 0; j < ay_sayisi; j++) {
            if (yildiz_yukseklikleri[j] >= i) {
                printf(" *  ");
            } else {
                printf("    "); 
            }
        }
        printf("\n");
    }

    
    printf("   ");
    for(int i=0; i<ay_sayisi; i++) printf("--- ");
    printf("\n");

    //Ay İsimlerini ekrana yazma
    printf("   ");
    for (int i = 0; i < ay_sayisi; i++) {
        printf("%s ", kisa_isimler[i]);
    }
    printf("\n");

}
