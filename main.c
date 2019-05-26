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

    BiletSayisiDosyasi(1);

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
   //YOLCU EKLEME + (...)
}


void Bilet_kaydiGuncelle()
{
   // ARANAN KAYITTAN İSTENEN OZELLIK GUNCELLENECEK VE GUNCEL HALI EKRANA BASTIRILACAK
}

void Bilet_kaydiSil()
{
   // BİLET KODUNA GORE ARANAN BİLET SİLİNECEK
}

void Fis_Bastir()
{
   //BİLET NUMARASINA GORE GIRILEN BILETIN OZELLIKLERİ BASTİRİLİACAK
}


void DosyayaYaz(Bilet *bilet)
{
    int i,j;

    FILE *dosya;

    dosya = fopen("dosya","a+");

    if(dosya==NULL)
    {
        printf("Dosya Acilamadi");
        exit(0);
    }

    for(i=0;i<1;i++)
    {
       fprintf(dosya,"%s %s %d %d %d %d",bilet->Kalkis_Sehri , bilet->Varis_Sehri , bilet->Gun , bilet->Ay , 2019 , bilet->yolcu_Sayisi );

       for(j=0;j<bilet->yolcu_Sayisi;j++)
       {
           fprintf(dosya,"%d %s %s %d", (bilet->Yolcular+j)->yas , (bilet->Yolcular+j)->Ad , (bilet->Yolcular+j)->Soyad , (bilet->Yolcular+j)->koltuk_numarasi);
       }
    }

    fclose(dosya);

     // BİLETLER DOSYAYA STRUCT BİLGİLERİ HALİNDE YAZİLACAK ********************************
}

void DosyadanOku(Bilet *bilet)
{

    int i,j;

    Bilet *tumBiletler

    tumBiletler = (Bilet *)malloc(sizeof(Bilet)*BiletSayisiDosyasi(0));

    //DOSYADAN YENI STRUCTA OKUMA İSLEMLERİNI YAP.

    dosya = fopen("dosya","r");

    if(dosya==NULL)
    {
        printf("Dosya Acilamadi");
        exit(0);
    }

    for(i=0;i<BiletSayisiDosyasi(0);i++)
    {
        fscanf(dosya,"%s %s %d %d %d %d",(tumBiletler+i)->Kalkis_Sehri , (tumBiletler+i)->Varis_Sehri , &(tumBiletler+i)->Gun , &(tumBiletler+i)->Ay , 2019 , &(tumBiletler+i)->yolcu_Sayisi );

        (tumBiletler+i)->Yolcular = (Bilet *)malloc((tumBiletler+i)->yolcu_Sayisi * sizeof(Bilet));

        for(j=0 ; j<(tumBiletler+i)->yolcu_Sayisi ; j++)
        {
            fscanf(dosya,"%d %s %s %d", &((tumBiletler+i)->Yolcular+j)->yas , ((bilet+i)->Yolcular+j)->Ad , ((bilet+i)->Yolcular+j)->Soyad , &((bilet+i)->Yolcular+j)->koltuk_numarasi);
        }

    }


    for(i=0;i<sSayisi;i++)
    {
        printf("%s %s %d",(ogrrr+i)->ad,(ogrrr+i)->soyad,(ogrrr+i)->yas);
        printf("\n");
    }

    fclose(dosya);

}

int BiletSayisiDosyasi(int eklenecek)
{
   //FONKSİYON EKLEME DURUMUNDA "1" , SİLME DURUMUNDA "-1" , SADECE BİLET SAYİSİ GORME DURUMUNDA "0" GONDERILEREK ACİLİR.

   int biletSayisi=0;
   int sayac=0,t;

   FILE *bsd

   bsd = fopen("BSD","a+");

   if(bsd == NULL)
   {
       printf("Dosya Acilamadi...");
       exit(0);
   }

   if(eklenecek==1)
   {
     fprintf(bsd,"%d",eklenecek);

     while(!feof(bsd))
     {
         fscanf(bsd,"%d",t);
         sayac += t;
     }
     biletSayisi = sayac;
   }
   else
   {
     fscanf(bsd,"%d",biletSayisi);
     return biletSayisi;
   }
   fclose(bsd);

   //SİLME KISMINDA BİLETSAYİSİNİ AL 1 AZALT   FOR İLE AZALMIŞ MİKTARI TEKRAR DOSYAYA YAZDIR ACIS MODU W OLMASI GEREKIR
}
