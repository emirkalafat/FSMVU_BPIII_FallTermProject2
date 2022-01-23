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
    uint8_t *cevapArray;
    int sayi1Boyut;
    int sayi2Boyut;
    int cevapBoyut;
    int girdi;
    puts("===============Cok Basamakli Sayilar Ile Islemler=========");
    do{
    puts("..::Lutfen islem seciniz::..");
    puts("[1] Dosyadan sayilari oku."
        "\n[2] Okunan sayilari ekrana yazma."
        "\n[3] Toplama islemini gerceklestir."
        "\n[4] Cikarma islemini gerceklestir."
        "\n[5] Sonucu ekrana yazdir."
        "\n[6] Cikis. ");
    scanf("%d", &girdi);
    switch (girdi)
        {
        case 1: //Dosyadan sayilari oku
            if ((sayi1File = fopen("test1.txt", "r")) == NULL ){
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "test1.txt");
                break;
            }
            else if((sayi2File = fopen("test2.txt", "r")) == NULL){
                printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "test2.txt");
                break;
            }
            else{
                sayi1Boyut=arrayBoyutHesapla(sayi1File);
                sayi2Boyut=arrayBoyutHesapla(sayi2File);
                cevapBoyut=buyukBoyutuDondur(sayi1Boyut,sayi2Boyut)+1;
                sayi1Array=int8ArrayOlustur(sayi1Boyut);
                sayi2Array=int8ArrayOlustur(sayi2Boyut);

                printf("Birinci sayinin boyutu: %d\n",sayi1Boyut);
                printf("Ikinci sayinin boyutu: %d\n",sayi2Boyut);
                
                arrayDoldur(sayi1File,sayi1Array);
                arrayDoldur(sayi2File,sayi2Array);

            }
            break;
        case 2: //[2]-> Okunan sayilari ekrana yaz: (2)
            puts(".:Sayi1.txt dosyasindan okunan sayi:.");
            arrayYazdir(sayi1Array,sayi1Boyut);
            puts("======================================");
            puts(".:Sayi2.txt dosyasindan okunan sayi:.");
            arrayYazdir(sayi2Array,sayi2Boyut);
            puts("======================================");
            break;
        case 3: //Toplama İşlemi.
            cevapArray = int8ArrayOlustur(cevapBoyut);
            toplamaIslemi(sayi1Array,sayi2Array,sayi1Boyut,sayi2Boyut,cevapArray,cevapBoyut);
            break;
        case 4:
            printf("%d\n",(uint8_t)'0');
            puts("HAZIR DEGIL");
        case 5: //Sonucu ekrana yazdır:
            if ((cevap = fopen("sonuclar.txt", "w")) == NULL ){
            printf( "%s dosyasini acmada sorun yasandi.\nAna menuye donuluyor...", "sonuclar.txt");
            break;
            }
            int n;
            for(n=0;n<buyukBoyutuDondur(sayi1Boyut,sayi2Boyut)+1;n++) {
            fprintf(cevap,"%d",cevapArray[n]);
            }
            //arrayBoyutuIleYazdir(cevapArray,buyukBoyutuDondur(sayi1Boyut,sayi2Boyut)+1);
            break;
        case 6: //çıkış komutu!!While kırılır.
            break;
        default:
            puts("Hatali islem girisi! Lutfen 1-2-3-4-5-6 seceneklerinden birini seciniz.");
            break;
        }
    }while (girdi != 6);
    //free(sayi1Array);
    //free(sayi2Array);
    puts("Program basari ile sonlandirildi.");
    return EXIT_SUCCESS;
}