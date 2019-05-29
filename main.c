#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//PROGRAM KAPANDIGINDA DA ONCEDEN ALINMIS KOLTUKLAR SABIT KALMASI (koltuk numarası ile kontrol et).
//ADMİN YETKİSİ İLE BUTUN BİLETLERİ GOREBİLME.
//AÇİLİSTA BİLET KAYDİ SİLME GİBİ DURUMLARİN KONTROLU SAGLANACAK.(ARAMA KISMINDA SAGLANIYOR OLABİLİR)

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

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

// "k_" ile baslayanlar kart bilgileri
//*********
  char k_Ad[30];
  char k_Soyad[30];
  int k_Numara;
  int k_Ay;
  int k_Yil;
  int k_CVV;
//*********


  int yolcu_Sayisi;

  yolcu *Yolcular;

}Bilet;


void Tarih();
int BiletSayisiDosyasi(int);
void DosyadanOku();
void DosyayaYaz(Bilet *,int,int);
void Fis_Bastir();
void Bilet_kaydiSil();
void Bilet_kaydiGuncelle();
void koltukSecimi(int);
void Koltuklar();
void Sefer();
void Bilet_al();
void kartBilgileri();
int BasamakSayisi(int);
int Arama();
void Bileti_Yadir(Bilet *,int);


Bilet *tumBiletler;
Bilet *bilet;
FILE *bsd;
FILE *dosya;


int main()
{
 AnaMenu();
}

void AnaMenu()
{

   int secim;

   printf("1-Bilet Al\n");
   printf("2-Bilet Guncelle\n");
   printf("3-Bilet Kaydı Sil\n");
   printf("4-Biletler Icin Fis Bastir\n");
   printf("5-Cikis");

   printf("Lutfen Yapmak Istediginiz islemi seciniz: ");
   scanf("%d",&secim);

       printf("----------------\n");


       if((secim == 2 ||  secim == 3) && (BiletSayisiDosyasi(0) == 0))
       {
           printf("Mevcut Bilet Kaydi Bulunamadi");
           AnaMenu();
       }
       else
          DosyadanOku();




       if(secim==1)
       {
         Bilet_al();
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
         printf("Hatali Secim Yaptiniz. Lutfen Tekrar Seciniz...");
         AnaMenu();
       }

}

void Bilet_al()
{

    //NOT : TEK SEFERDE FARKLI FARKLI BİLETLER ALMAK MANTIKLI OLMAYACAGI ICIN BİLET AL MENUSU 1 BİLET İCİN TASARLANDI .


    bilet = (Bilet *)malloc(sizeof(Bilet)*1);
    Koltuklar();

    int i,j;

    for(i=0;i<1;i++)
    {
        Sefer();
        Tarih();

        printf("Kac Tane Bilet Alacaginizi Seciniz: ");
        scanf("%d",&bilet->yolcu_Sayisi);

        (bilet)->Yolcular = (yolcu *)malloc((bilet)->yolcu_Sayisi * sizeof(yolcu));

        for(j=0 ; j<(bilet)->yolcu_Sayisi ; j++)
        {
            printf("%d. yolcunun Adi : ",j+1);
            scanf("%s", &((bilet)->Yolcular+j)->Ad);

            printf("%d. yolcunun Soyadi : ",j+1);
            scanf("%s", &((bilet)->Yolcular+j)->Soyad);

            printf("%d. yolcunun Yasi: ",j+1);
            scanf("%d", &((bilet)->Yolcular+j)->Yas);

        }

        koltukSecimi(bilet->yolcu_Sayisi);

        kartBilgileri();

    }

   BiletSayisiDosyasi(1);

   bilet->biletNO = BiletSayisiDosyasi(0);

   DosyayaYaz(bilet,1,-1);

   Bileti_Yadir(bilet,0);


   int secim;

   while(1==1)
   {
   printf("Tebrikler!!Bilet Alma islemi Tamamlanmistir. \n");
   printf("1-Ana Menu \n");
   printf("2-Cikis \n");
   printf("Seciminiz :");
   scanf("%d",&secim);

   if(secim == 1)
   {
       AnaMenu();
   }
   else if(secim == 2)
   {
      exit(0);
   }
   else
    printf("Hatali Bir Secim Yaptiniz Lutfen Tekrar Secin.");

   }

}

void Sefer()
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
    scanf("%d",&varis_sehri);

    strcpy(bilet->Kalkis_Sehri,Sehirler[kalkis_sehri-1]);
    strcpy(bilet->Varis_Sehri,Sehirler[varis_sehri-1]);

}

void Tarih()
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
        Tarih();
    }


    printf("Ayin Kacinda Gideceginizi Seciniz (1-30): ");
    scanf("%d",&bilet->Gun);

    printf("Bilet Tarihi : %d.%d.%d ", bilet->Gun , bilet->Ay , 2019);



}

void Koltuklar()
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

void koltukSecimi(int y)
{

int UcakSecilenKoltuk;
int i,j,k,t;
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


      printf("%d. yolcu icin Koltuk Seciniz: ",i+1);
      scanf("%d",&UcakSecilenKoltuk);

      if(UcakSecilenKoltuk<1 || UcakSecilenKoltuk>84)
      {
             printf("UZGUNUZ!! Sectiginiz Koltuk Bulunmamaktadir");
             delay(1200);
             system("CLS");
             koltukSecimi(y);
      }

          for(t=0;t<y;t++)
          {
              if( (bilet->Yolcular+t)->koltuk_numarasi == UcakSecilenKoltuk )
              {
                  printf("Secilen Koltuk Dolu Lutfen Farkli Bir koltuk Seciniz..");
                  system("CLS");
                  koltukSecimi(y);
              }
          }


          for(j=0;j<21;j++)
          {
              for(k=0;k<5;k++)
              {
                if( UcakSecilenKoltuk == bilet->koltuklarDizisi[j][k] )
                {
                ((bilet)->Yolcular+i)->koltuk_numarasi = UcakSecilenKoltuk;
                bilet->koltuklarDizisi[j][k] = 0;
                printf("Koltuk Secilmistir..");
                }
              }
          }

}

}

void kartBilgileri()
{

    printf("\t\tKART BILGILERI\n");
    printf("Kart Sahibinin Adi: ");
    scanf("%s",bilet->k_Ad);
    printf("Kart Sahibinin Soyadi: ");
    scanf("%s",bilet->k_Soyad);
   //16 HANE FAZLA OLACAGI ICIN 4 HANE KULLANDIM
    printf("\n\n4 Haneli Kart Numaraniz: ");
    scanf("%d",&bilet->k_Numara);



     if(BasamakSayisi(bilet->k_Numara)!=4)
     {
       printf("%d Haneli Bir Numara Girdiniz Lutfen Tekrar Girin...",BasamakSayisi(bilet->k_Numara));
       delay(2000);
       system("CLS");
       kartBilgileri(bilet);
     }

   printf("\nKart Tarihi: **/**\n");
   printf("\t     ");
   printf("Ay:");
   scanf("%d",& bilet->k_Ay);
   printf("\n\t     ");
   printf("Yil:");
   scanf("%d",& bilet->k_Yil);

   if( (bilet->k_Ay)>12 || (bilet->k_Ay)<1 || bilet->k_Yil<2019 )
   {
       printf("Gecersiz Bir Tarih Girdiniz. Lutfen Tekrar Giriniz...");
       delay(1500);
       system("CLS");
       kartBilgileri();
   }


   printf("\n3 Haneli Kart Sifresi: ");
   scanf("%d",& bilet->k_CVV);

}


int BasamakSayisi(int sayi)
{
  int basamakS=0;

     for(basamakS=1;sayi>=10;basamakS++)
     {
         sayi = sayi/10;
     }
  return basamakS;
}

int Arama()
{
   int i;
   int arananBiletNO;

   printf("Lutfen Aradiginiz Biletin Numarasini Giriniz: ");
   scanf("%d",&arananBiletNO);

   for(i=0 ; i< 10; i++)
   {
       if( (tumBiletler+i)->biletNO == arananBiletNO)
       {
           return i;
       }
   }

   printf("Aradiginiz Bilet Numarasiyla Eslesen Bilet Bulunamadi...");
}


void Bilet_kaydiGuncelle()
{
   // ARANAN KAYITTAN İSTENEN OZELLIK GUNCELLENECEK VE GUNCEL HALI EKRANA BASTIRILACAK


}

void Bilet_kaydiSil()
{
   // BİLET KODUNA GORE ARANAN BİLET SİLİNECEK

   int i,j,secim,silinecek,kontrol;

   for(i=0;i<BiletSayisiDosyasi(0);i++)
   {
       printf("%d. bilet no %d",i,(tumBiletler+i)->biletNO);
   }


   printf("Silinecek Bilet No Giriniz : ");
   scanf("%d",&silinecek);


   for(i=0;i< BiletSayisiDosyasi(0) ;i++)
   {

       if( (tumBiletler+i)->biletNO == silinecek )
       {
          Bileti_Yadir(tumBiletler,i);

          printf("Silmek istediginize emin misiniz ?");

          printf("1-Sil \n");
          printf("2-Vazgec \n");
          printf("Seciminiz: ");
          if(secim==1)
          {
              DosyayaYaz(tumBiletler,BiletSayisiDosyasi(0) , i);
          }

       }
   }

}

void Fis_Bastir()
{
   // BİLET NUMARASINA GORE GIRILEN BILETIN OZELLIKLERİ BASTİRİLİACAK
   int GosterilecekBilet = Arama();

   Bileti_Yadir(tumBiletler,GosterilecekBilet);
}

void Bileti_Yadir(Bilet *b,int s)
{
    int i;

    printf("----Bilet Bilgileri----\n\n");

    printf("Bilet No: %d \n",(b+s)->biletNO);
    printf("(Lutfen Bilet Numaranizi Unutmayiniz !) \n");

    printf("Kalkis Sehri : %s \n",(b+s)->Kalkis_Sehri);
    printf("Varis Sehri : %s \n",(b+s)->Varis_Sehri);

    printf("Yolcu Sayisi : %d\n",(b+s)->yolcu_Sayisi);

    printf("Tarih : %d.%d.%d   (gun).(ay).(yil) \n\n", (b+s)->Gun , (b+s)->Ay , 2019 );


    printf("----Kart Bilgileri----\n\n");
    printf("Kart Uzerindeki Isim : %s\n",(b+s)->k_Ad);
    printf("Kart Uzerindeki Soyisim : %s \n",(b+s)->k_Soyad);
    printf("Kart Numarasi %d \n\n",(b+s)->k_Numara);

    printf("----Yolcu Bilgileri----\n\n");

    for(i=0 ; i< ((b+s)->yolcu_Sayisi) ; i++)
    {
        printf("--------------------------------\n");
        printf("**%d. Yolcunun Bilgileri**\n",i);
        printf("--------------------------------\n");
        printf("Isim : %s \n", ((b+s)->Yolcular+i)->Ad);
        printf("Soyisim : %s \n",((b+s)->Yolcular+i)->Soyad);
        printf("Yas : %d \n",((b+s)->Yolcular+i)->Yas);
        printf("Koltuk Numarasi : %d \n",((b+s)->Yolcular+i)->koltuk_numarasi);
    }
    printf("--------------------------------");
}

void DosyayaYaz(Bilet *b,int islemdekiBiletMiktari ,int silmeKontrol) //STRUCTI DOSYAYA YAZAR
{
    //SİLME KONTROL == "-1" DEGİL İSE DOSYA SİLMEK İCİN DOSYA W+ MODDA ACİLİR

    int i,j;

    if(silmeKontrol== -1)
    {
        dosya = fopen("dosya.txt","a+");
    }
    else
    {
        dosya = fopen("dosya.txt","w+");
        BiletSayisiDosyasi(-1);  //DOSYADAN OKU FONKSİYONUNA GECERKEN BİLET SAYİSİ AZALTİLDİ.
                                 //DOSYAYAYAZ FONKSİYONUNDA BİLET SAYİSİNİN AZALMAMIS HALİNİ KULLANIYORUZ
    }

    if(dosya==NULL)
    {
        printf("Dosya Acilamadi");
        exit(0);
    }

    for(i=0; i<islemdekiBiletMiktari ;i++)
    {
       if(i == silmeKontrol)
       {
           continue;
       }
       fprintf(dosya,"%s %s %d %d %d %d %s %s %d %d %d %d %d",(b+i)->Kalkis_Sehri , (b+i)->Varis_Sehri , (b+i)->Gun , (b+i)->Ay , 2019 , (b+i)->yolcu_Sayisi , (b+i)->k_Ad , (b+i)->k_Soyad , (b+i)->k_Numara , (b+i)->k_Ay , (b+i)->k_Yil , (b+i)->k_CVV) , (b+i)->biletNO;

       for(j=0; j < (b+i)->yolcu_Sayisi ;j++)
       {
           fprintf(dosya,"%d %s %s %d",((b+i)->Yolcular+j)->Yas , ((b+i)->Yolcular+j)->Ad , ((b+i)->Yolcular+j)->Soyad , ((b+i)->Yolcular+j)->koltuk_numarasi);
       }
    }


    fclose(dosya);

    printf("Dosyaya Yazma islemi tamamlandi");

     // BİLETLER DOSYAYA STRUCT BİLGİLERİ HALİNDE YAZİLACAK ********************************

     DosyadanOku();

}

//AMAC DOSYA YERINE STRUCT UZERINDEN ISLEM YAPABİLMEK...

void DosyadanOku() //DOSYADAN STRUCTA OKUR
{

    int i,j;

    //DOSYADAN YENI STRUCTA OKUMA İSLEMLERİNI YAP.


    tumBiletler = (Bilet *)malloc(sizeof(Bilet)*BiletSayisiDosyasi(0));
    for(i=0;i< BiletSayisiDosyasi(0) ; i++)
    {
    (tumBiletler+i)->Yolcular = (Bilet *)malloc((tumBiletler+i)->yolcu_Sayisi*sizeof(Bilet));
    }
    //BELLEKTE YER AYİRİLDİ

    dosya = fopen("dosya","a+");

    if(dosya==NULL)
    {
        printf("Dosya Acilamadi");
        exit(0);
    }

    rewind(dosya);

    for(i=0;i<BiletSayisiDosyasi(0);i++)
    {

        fscanf(dosya,"%s %s %d %d %d %d %s %s %d %d %d %d %d",(tumBiletler+i)->Kalkis_Sehri , (tumBiletler+i)->Varis_Sehri , &(tumBiletler+i)->Gun , &(tumBiletler+i)->Ay , &(tumBiletler+i)->Yil , &(tumBiletler+i)->yolcu_Sayisi , (tumBiletler+i)->k_Ad , (tumBiletler+i)->k_Soyad , &(tumBiletler+i)->k_Numara , &(tumBiletler+i)->k_Ay , &(tumBiletler+i)->k_Yil , &(tumBiletler+i)->k_CVV) , &(tumBiletler+i)->biletNO;

        (tumBiletler+i)->Yolcular = (Bilet *)malloc((tumBiletler+i)->yolcu_Sayisi * sizeof(Bilet));

        for(j=0 ; j<(tumBiletler+i)->yolcu_Sayisi ; j++)
        {
            fscanf(dosya,"%d %s %s %d", &((tumBiletler+i)->Yolcular+j)->Yas , ((tumBiletler+i)->Yolcular+j)->Ad , ((tumBiletler+i)->Yolcular+j)->Soyad , &((tumBiletler+i)->Yolcular+j)->koltuk_numarasi);
        }

    }

    fclose(dosya);

}

int BiletSayisiDosyasi(int islem)
{
   //FONKSİYON : EKLEME DURUMUNDA "1" , SİLME DURUMUNDA "-1" , SADECE BİLET SAYİSİ GORME DURUMUNDA "0" GONDERILEREK ACİLİR.

   int biletSayisi=0;
   int sayac=0,t=0;

   if(islem == 0 || islem == 1)
   {
     bsd = fopen("BSD","a+");
   }

   if(islem == -1)
   {
    bsd = fopen("BSD","w+");
   }

   if(bsd == NULL)
   {
       printf("Bilet Sayisi Dosyasi Acilamadi...");
       exit(0);
   }

   if(islem==1) // EKLEME MODU
   {
     fprintf(bsd,"%d",islem);



     rewind(bsd);

     while(!feof(bsd))
     {
         fscanf(bsd,"%d",&t);
         sayac += t;
     }
     biletSayisi = sayac;

   }
   else if(islem == -1) // SİLME MODU
   {

     biletSayisi = BiletSayisiDosyasi(0);
     biletSayisi -= 1;

     for(sayac=0 ; sayac < biletSayisi ; sayac++)
     {
         fprintf(bsd,"%d",1);
     }
     sayac = 0;
     rewind(bsd);

     while(!feof(bsd))
     {
         fscanf(bsd,"%d",&t);
         sayac += t;
     }
     biletSayisi = sayac;
   }
   else // BİLET SAYİSİNİ OGRENME MODU
   {
     rewind(bsd);
     while(!feof(bsd))
     {
         fscanf(bsd,"%d",&t);
         sayac += t;
     }
     biletSayisi = sayac;

     return biletSayisi;
   }

   fclose(bsd);

   //SİLME KISMINDA BİLETSAYİSİNİ AL 1 AZALT   FOR İLE AZALMIŞ MİKTARI TEKRAR DOSYAYA YAZDIR ACIS MODU W OLMASI GEREKIR
}
