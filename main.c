#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct Yolcu_Bilgileri
{
  int Yas;
  char Ad[30];
  char Soyad[30];
  int koltuk_numarasi;


}yolcu;

typedef struct BiletBilgisi
{
  int biletNO;
  char Kalkis_Sehri[30];
  char Varis_Sehri[30];

  int koltuklarDizisi[21][5];

  int Gun;
  int Ay;
  int Yil;


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
         Bilet_al(bilet);
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

void Bilet_al(Bilet *bilet)
{

    bilet = (Bilet *)malloc(sizeof(Bilet)*1);
    Koltuklar(bilet);

    int i,j;

    for(i=0;i<1;i++)
    {
        Sefer(bilet);
        Tarih(bilet);

        printf("Kac Tane Bilet Alacaginizi Seciniz: ");
        scanf("%d",&bilet->yolcu_Sayisi);

        bilet->Yolcular = (yolcu *)malloc((bilet->yolcu_Sayisi)*sizeof(yolcu));

        for(j=0 ; j<(bilet+i)->yolcu_Sayisi ; j++)
        {
            printf("%d. yolcunun Adi : ");
            scanf("%d", &((bilet)->Yolcular+j)->Ad);

            printf("%d. yolcunun Soyadi : ");
            scanf("%d", &((bilet)->Yolcular+j)->Soyad);

            printf("%d. yolcunun Yasi: ");
            scanf("%d", &((bilet)->Yolcular+j)->Yas);

            koltukSecimi(bilet , j);
        }
    }



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

    int kalkis_sehri;
    int varis_sehri;

    printf("Kalkis Sehri Seciniz : ");
    scanf("%d",&kalkis_sehri);

    printf("Varis Sehri Seciniz : ");
    scanf("%d",varis_sehri);


    strcpy(Sehirler[kalkis_sehri-1],bilet->Kalkis_Sehri);
    strcpy(Sehirler[varis_sehri-1],bilet->Varis_Sehri);

}

void Tarih(Bilet *bilet)
{

   int i;
   char Aylar[12][40]={"Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik"};
   char Gunler[7][40]={"Pazartesi","Sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar"};

   int ay;
   int gun;


   for(i=0;i<12;i++)
   {
       printf("\n%d-) %s ",i+1,Aylar[i]);
   }

    printf("\nTarih Giriniz(2019 Yili Icerisinde)\n");
    printf("\nAY(1-12): ");
    scanf("%d",&ay);

    if(0>ay || ay>12)
    {
        printf("Gecersiz Tarih\n");
        system("CLS");
        Tarih()
    }


    printf("Ayin Kacinda Gideceginizi Seciniz (1-30): ");
    scanf("%d",&bilet->Gun);

    printf("Bilet Tarihi : %d.%d.%d ", bilet->Gun , bilet->Ay , 2019);



}


void Koltuklar(Bilet *bilet)
{
  int i,j,t=0;

  for(i=0; i<21; i++)
  {
      for(j=0; j<5; j++)
      {
      if(j!=2)
      {
        bilet->koltuklarDizisi[i][j]=t+1;
        t++;
      }
      else
      {
        bilet->koltuklarDizisi[i][j]= 32;
      }

  }
  }
}

void koltukSecimi(Bilet *bilet , y)
{

int UcakSecilenKoltuk;
int i,j,k;
//************************************************DIZIYI YAZDIRMA

for(i=0 ; i<y ; i++)
{
    for(j=0; j<21; j++)
    {
        for(k=0; k<5; k++)
        {
            if(k!=2)
            {
                printf("[%d]",bilet->koltuklarDizisi[j][k]);
            }
            else
            {
                printf("%c",bilet->koltuklarDizisi[j][k]);
            }
        }
      printf("\n");
    }
   //****************************************************************


      printf("Koltuk Seciniz: ");
      scanf("%d",&UcakSecilenKoltuk);

      if(UcakSecilenKoltuk<1 || UcakSecilenKoltuk>84)
      {
             printf("UZGUNUZ!! Sectiginiz Koltuk Bulunmamaktadir");
             delay(1200);
             system("CLS");
             koltukSecimi(Bilet *bilet , y);
      }



        for(j=0; j<21; j++)
            for(k=0; k<5; k++)
            {
              if( ((bilet)->Yolcular+y)->koltuk_numarasi == UcakSecilenKoltuk )
              {
                  printf("Secilen Koltuk Dolu Lutfen Farkli Bir koltuk Seciniz..");
                  system("CLS");
                  koltukSecimi(Bilet *bilet , y);
              }
              if( UcakSecilenKoltuk == bilet->koltuklarDizisi[i][j] )
              {
                  printf("Koltuk Secilmistir..");
                  ((bilet)->Yolcular+y)->koltuk_numarasi = UcakSecilenKoltuk;
                  bilet->koltuklarDizisi[i][j] = 0;
              }


            }
}















}

void Ekleme()
{

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





