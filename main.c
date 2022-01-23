/**
 * @file main.h
 * @description operations with files main.c file
 * @assignment Computer Engineering III Fallterm Project II
 * @date 28.12.2021
 * @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "islemler.h"

int main(int argc, char const *argv[])
{
    //Tanımlamalar
    FILE *sayi1File;
    FILE *sayi2File;
    FILE *cevapFile;
    uint8_t *sayi1Array;
    uint8_t *sayi2Array;
    uint8_t *cevapArray;
    int sayi1Boyut;
    int sayi2Boyut;
    int cevapBoyut;
    int girdi;
    cyan();
    puts("===============Cok Basamakli Sayilar Ile Islemler=============");
    do{
    resetRenk();
    cyan();
    puts("..::Lutfen islem seciniz::..");
    resetRenk();
    puts("[1] Dosyadan sayilari oku."
        "\n[2] Okunan sayilari ekrana yazma."
        "\n[3] Toplama islemini gerceklestir."
        "\n[4] Cikarma islemini gerceklestir."
        "\n[5] Sonucu sonuc dosyasina yazdir."
        "\n[6] Cikis. ");
    scanf("%d", &girdi);
    switch (girdi)
        {
        case 1: //Dosyadan sayilari oku
            if ((sayi1File = fopen("test1.txt", "r")) == NULL ){
                red();
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "test1.txt");
                break;
            }
            else if((sayi2File = fopen("test2.txt", "r")) == NULL){
                red();
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "test2.txt");
                break;
            }
            else{
                sayi1Boyut=arrayBoyutHesapla(sayi1File);
                sayi2Boyut=arrayBoyutHesapla(sayi2File);
                cevapBoyut=sayi1Boyut+1;
                sayi1Array=int8ArrayOlustur(sayi1Boyut);
                sayi2Array=int8ArrayOlustur(sayi2Boyut);
                cevapArray = int8ArrayOlustur(cevapBoyut);

                printf("Birinci sayinin boyutu: %d\n",sayi1Boyut);
                printf("Ikinci sayinin boyutu: %d\n",sayi2Boyut);
                
                arrayDoldur(sayi1File,sayi1Array);
                arrayDoldur(sayi2File,sayi2Array);
            }
            break;
        case 2: //[2]-> Okunan sayilari ekrana yaz: (2)
            cyan();
            puts(".:Sayi1.txt dosyasindan okunan sayi:.");
            resetRenk();
            arrayYazdir(sayi1Array,sayi1Boyut);
            puts("======================================");
            cyan();
            puts(".:Sayi2.txt dosyasindan okunan sayi:.");
            arrayYazdir(sayi2Array,sayi2Boyut);
            reset();
            puts("======================================");
            break;
        case 3: //Toplama İşlemi.
            toplamaIslemi(sayi1Array,sayi2Array,sayi1Boyut,sayi2Boyut,cevapArray,cevapBoyut);
            arrayYazdir(cevapArray,cevapBoyut);
            break;
        case 4: //şimdilik test seçenği
            cikarmaIslemi(sayi1Array,sayi2Array,sayi1Boyut,sayi2Boyut,cevapArray,cevapBoyut);
            arrayYazdir(cevapArray,cevapBoyut);
            break;
        case 5: //Sonucu dosyaya yazdır:
            if ((cevapFile = fopen("sonuclar.txt", "w")) == NULL ){
                red();
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "sonuclar.txt");
                break;
            }

            int n;
            for(n=0;n<cevapBoyut;n++) {
                fprintf(cevapFile,"%d",cevapArray[n]);
            }
            fclose(cevapFile);
            green();
            puts("Islem tamam.");
            break;
        case 6: //çıkış komutu!!While kırılır.
            break;
        default:
            red();
            puts("Hatali islem girisi! Lutfen 1-2-3-4-5-6 seceneklerinden birini seciniz.");
            break;
        }
    }while (girdi != 6);
    free(sayi1Array);
    free(sayi2Array);
    free(cevapArray);
    green();
    puts("Program basari ile sonlandirildi.");
    resetRenk();
    return EXIT_SUCCESS;
}