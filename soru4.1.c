//Alıştırma 4.1
#include <stdio.h>

//sezar şifreleme için gereken fonksiyon tanımı
void sezarsifreleme(char mesaj[], int anahtar){
    int i = 0;
    char harf;
    
    //mesaj bitene kadar oluşacak döngünün yazılması
    while(mesaj[i] != '\0'){
        harf = mesaj[i];
      
      //büyük harflerin kontrol edilmesi
      //eğer harf 'A'dan eşit büyükse ve 'Z' den eşit küçükse harf büyüktür
      if(harf >= 'A' && harf <= 'Z'){
          harf = (harf - 'A' + anahtar) % 26 + 'A';
      }
      
      //küçük harflerin kontrol edilmesi
      //eğer harf 'a' dan eşit büyükse ve 'z' den eşit küçükse harf küçüktür
      else if(harf >= 'a' && harf <= 'z'){
          harf = (harf - 'a' + anahtar) % 26 + 'a';
      }
      
      //harften başka bir karakter girildiyse boşlul sayı vb. o karaktere dokunma olduğu gibi yaz
      
      mesaj[i] = harf;
     i++;
    }
}

int main() {
   
  char mesaj[100];
  int anahtar;
  
  //kullanıcıdan şifrelemek istediği mesajı alma
  printf("sifrelemek istediginiz mesaji girniz: ");
  fgets(mesaj, 100, stdin);
  
  //mesajı şifrelemek için kullanıcıdan 1 ile 25 arasında anahtar değer isteme
  printf("mesaji sifrelemek icin 1 ile 25 arasinda bir anahtar deger girini: ");
  scanf("%d", &anahtar);
  
  //girilen mesajı şifreleyen kod eğer bu kodu yazmazsak kodumuz çalışır fakat şifreleme yapmaz
  sezarsifreleme(mesaj, anahtar);
  
  //şifrelenmiş mesajı ekrana yazdırma
  printf("sifreli mesajiniz: %s", mesaj);

    return 0;
}