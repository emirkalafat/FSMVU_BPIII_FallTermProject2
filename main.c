/*
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
    FILE *cevap;
    uint8_t *sayi1Array;
    uint8_t *sayi2Array;
    uint8_t *cevap;
    int sayi1Boyut;
    int sayi2Boyut;
    int girdi;
    puts("===============Cok Basamakli Sayilar Ile Islemler=========");
    do{
    girdi = " ";
    puts("..::Lutfen islem seciniz::..");
    puts("[1] Dosyadan sayilari okuma."
        "\n[2] Okunan sayilari ekrana yazma."
        "\n[3] Matematiksel islem secimi."
        "\n[4] Sonucu ekrana yazdirma."
        "\n[5] Cikis. ");
    scanf("%d", &girdi);
    switch (girdi)
        {
        case 1: //Dosyadan sayilari oku
            if ((sayi1File = fopen("sayi1.txt", "r")) == NULL ){
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "sayi1.txt");
                break;
            }
            else if((sayi2File = fopen("sayi2.txt", "r")) == NULL){
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "sayi2.txt");
                break;
            }
            else{
                sayi1Boyut=arrayBoyutHesapla(sayi1File);
                sayi2Boyut=arrayBoyutHesapla(sayi2File);
                sayi1Array=arrayOlustur(sayi1Boyut);
                sayi2Array=arrayOlustur(sayi2Boyut);
                printf("%d\n",sayi1Boyut);
                printf("%d\n",sayi1Boyut);
                arrayDoldur(sayi1File, sayi1Array);
                arrayDoldur(sayi2File,sayi2Array);
                puts("====================");
                arrayYazdir(sayi1Array);
                puts("====================");
                arrayYazdir(sayi2Array);
                puts("====================");
            }
            break;
        case 2: //[2]-> Okunan sayilari ekrana yaz: (2)
            puts(".:Sayi1.txt dosyasindan okunan sayi:.");
            arrayYazdir(sayi1Array);
            puts("======================================");
            puts(".:Sayi2.txt dosyasindan okunan sayi:.");
            arrayYazdir(sayi2Array);
            puts("======================================");
            break;
        case 3: //[+/-]-> Islem seciniz: (+ veya -)
            puts("Islem seciniz.[+/-]");
            char matIslem;
            getc(matIslem);
            if(matIslem == '-'){
                //cikarmaIslemi();
            }
            else if(matIslem == '+'){
                //toplamaIslemi();
            }
            else puts(" + veya - sembollerini kullaniniz.");
            break;
        case 4: //[4]-> Sonucu ekrana yazdır: (4)

            break;
        case 5: /*çıkış komutu!!While kırılır.*/
            break;
        default:
            puts("Hatali islem girisi! Lutfen 1-2-3-4-5 seceneklerinden birini seciniz.");
            break;
        }
    }while (girdi != 5);
    puts("Program basari ile sonlandirildi.");
    return EXIT_SUCCESS;
}