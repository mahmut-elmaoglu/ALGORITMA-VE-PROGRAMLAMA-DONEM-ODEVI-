//Alıştırma 4.2
#include <stdio.h>

//sezar şifrelemeyi çözmek için gereken fonksiyon tanımı
void sezarcoz(char mesaj[], int anahtar){
    int i = 0;
    char harf;
    
    //mesaj bitene kadar oluşacak döngünün yazılımı
    while(mesaj[i] != '\0'){
        harf = mesaj[i];
        
        //büyük harflerin kontrol edilmesi
        //eğer harf 'A' dan eşit büyükse ve 'Z' den eşit küçükse harf büyüktür
        //NOT: (Harf - 'A' - Anahtar + 26) % 26 + 'A' ya +26 eklememizin sebebi, çıkarma işlemi sonucu negatif olmasın diye eğer negatif olursa mesajı çözemeyiz.
        if(harf >= 'A' && harf <= 'Z'){
            harf = (harf - 'A' - anahtar + 26) % 26 + 'A';
        }
        
          //küçük harflerin kontrol edilmesi
        //eğer harf 'a' dan eşit büyükse ve 'z' den eşit küçükse harf büyüktür
        //NOT: (Harf - 'a' - Anahtar + 26) % 26 + 'a' ya +26 eklememizin sebebi, çıkarma işlemi sonucu negatif olmasın diye eğer negatif olursa mesajı çözemeyiz.
        else if(harf >= 'a' && harf <= 'z'){
            harf = (harf - 'a' - anahtar + 26) % 26 + 'a';
        }
        
        //harften başka bir karakter girildiyse boşlul sayı vb. o karaktere dokunma olduğu gibi yaz
      
        mesaj[i] = harf;
        i++;
    }
}

int main() {

char sifrelimesaj[100];
int anahtar;

//kullanıcıdan çözülecek şifreli mesajı alma
printf("lutfen sifreli mesaji giriniz: ");
fgets(sifrelimesaj, 100, stdin);

//şifreli mesajı çözmek için gereken anahtar değerini kullanıcıdan alma
printf("sifreyi cozmek icin gerekli olan anahtar degerini giriniz: ");
scanf("%d", &anahtar);

//girilen şifreli mesajı çözmek için gerekli olan kod eğer bu kod olmazsa şifreli kodu çözmek için anahtar değerini girsekte mesaj çözülmeden direkt yazılır
sezarcoz(sifrelimesaj, anahtar);

//çözülen şifreli mesajı ekrana yazdırma
printf("cozulen sifreli mesajiniz soyledir: %s", sifrelimesaj);

    return 0;
}

