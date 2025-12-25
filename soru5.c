#include <stdio.h>
#define N 5

// yol bulma fonksiyonu
int yolBul(int labirent[N][N], int cozum[N][N], int x, int y) {
    // sınır dışı, duvar (0) veya daha önce geçilmiş (1) varsa eğer fonksiyonu 0 olarak döndür
    if (x < 0 || x >= N || y < 0 || y >= N || labirent[x][y] == 0 || cozum[x][y] == 1) {
        return 0;
    }

    cozum[x][y] = 1;

    // biz her ne kadar satır ve sütunu 5 olarak bilsekte bilgisayar indekse baktığı için bilgisayarın anlayacağı bir kod yazmalıyız bu nedenle x ve y yi 4 e eşitlemeliyiz
    if (x == N - 1 && y == N - 1) return 1;

    // aşağı, sağa, yukarı, sola gidilmesi gereken yönü bulma
    if (yolBul(labirent, cozum, x + 1, y) || 
        yolBul(labirent, cozum, x, y + 1) || 
        yolBul(labirent, cozum, x - 1, y) || 
        yolBul(labirent, cozum, x, y - 1)) {
        return 1;
    }

    cozum[x][y] = 0; 
    return 0;
}

int main() {
    // 1: yol, 0: duvar
    int labirent[N][N] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int cozum[N][N] = {0};

    //labirenti ekrana yazdırma
    printf("--- LABIRENT ---\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", labirent[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // giriş çıkış kontrolü
    if (labirent[0][0] == 0 || labirent[N-1][N-1] == 0) {
        printf("Hata: Giris veya Cikis kapali.\n");
        return 0;
    }

    //çözümü bulup ekrana yazdırma
    if (yolBul(labirent, cozum, 0, 0)) {
        printf("cikis yolu bulundu: \n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", cozum[i][j]);
            }
            printf("\n");
        }
    }
    
    //eğer çözüm bulunmazsa ekrana çıkış yolu bulunamadı yazdırma
    else {
        printf("Cikis yolu bulunamadi.\n");
    }

    return 0;
}