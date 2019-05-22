#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct Yolcu_Bilgileri
{
  int Yas;
  char Isim[30];
  char SoyIsim[30];
  int TC_kimlikNo;

}yolcu;

typedef struct BiletBilgisi
{
  int biletNO;
  char Kalkis_Sehri[30];
  char Varis_Sehri[30];
  //TARÝH BÝLGÝLERÝ GÝRÝLECEK

  int yolcu_Sayisi;

  *yolcu Yolcular;

}Bilet;


int main()
{
 AnaMenu();
}

void AnaMenu()
{

   Bilet *bilet;

   bilet = (Bilet *)malloc(sizeof(Bilet)*1);

   int secim;
   printf("1-Bilet Al\n");
   printf("2-Bilet Guncelle\n");
   printf("3-Bilet Kaydı Sil\n");
   printf("4-Biletler Icin Fis Bastir\n");
   printf("5-Cikis");

   printf("Lutfen Yapmak Istediginiz islemi seciniz: ");
   scanf("%d",%secim);

       if(secim==1)
       {
         Bilet_Al(bilet);
       }
       else if(secim==2)
       {
         Bilet_kaydiGuncelle();
       }
       else if(secim==3)
       {
         Bilet_kaydiSil();
       }
       else if(secim==4)
       {
         Fis_Bastir();
       }
       else if(secim==5)
       {
         exit(0);
       }
       else
       {
         AnaMenu();
       }
}
void Bilet_Al(Bilet *bilet)
{

  int i,j;


  Sefer(bilet);


  for(i=0;i<1;i++)
  {





   for(j=0;j<)
   {

   }

  }
   // BİLAT AL KISMINI SEFER KISMININ ALTINA TASI****************************************************************************
}

void Sefer(Bilet *bilet)
{
    char Sehirler[6][40] = {"Ankara","Konya","Istanbul","Izmir","Antalya"};

    printf("Sehirler \n");
    printf("1- Ankara");
    printf("2- Konya");
    printf("3- Istanbul");
    printf("4- Izmır");
    printf("5- Antalya");

    int sayac=0;
    int i=0;
    int kalkis_sehri;
    int varis_sehri;
    int Farkli_sefer;

    while(1==1)
    {
        sayac += 1;

        bilet = (Bilet *)realloc(bilet,sizeof(Bilet)*sayac);

        printf("Kalkis Sehri Seciniz : ");
        scanf("%d",&kalkis_sehri);

        printf("Varis Sehri Seciniz : ");
        scanf("%d",&varis_sehri);



        strcpy( (bilet+i)->Kalkis_Sehri, kalkis_sehri);
        strcpy( (bilet+i)->Varis_Sehri,varis_sehri );


        printf("Farkli Bir Sefer Olusturmak Ister misiniz:\n");
        printf("1-Evet \n 2-Hayir");
        scanf("%d",&Farkli_sefer);
        if(Farkli_sefer==1)
        {
            system("CLS");
        }
        else if(Farkli_sefer==2)
        {
            break;
        }
        else
        {
         printf("Hatali Secim...")
         break;
        }


        i += 1;
    }




}


void Koltuklar()
{

  //KOLTUKLAR SECILIR
}


void Bilet_kaydiGuncelle()
{

}

void Bilet_kaydiSil()
{

}

void Fis_Bastir()
{

}
