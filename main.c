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
    int girdi;
    char matIslem;
    puts("===============Cok Basamakli Sayilar Ile Islemler=========");
    do{
    girdi = " ";
    puts("..::Lutfen islem seciniz::..");
    puts("[1] Dosyadan sayilari oku."
        "\n[2] Okunan sayilari ekrana yazma."
        "\n[3] Toplama islemini gerceklestir."
        "\n[4] Cıkarma islemini gerceklestir."
        "\n[4] Sonucu ekrana yazdir."
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
                printf("%d\n",sayi2Boyut);
                arrayDoldur(sayi1File, sayi1Array);
                arrayDoldur(sayi2File,sayi2Array);
                
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
        case 3: //Toplama İşlemi.
            cevapArray = toplamaIslemi(sayi1Array,sayi1Boyut,sayi2Array,sayi2Boyut);
            
            break;
        case 4:
            //TODO: cikarmaIslemi();
            puts("HAZIR DEGIL");
        case 5: //Sonucu ekrana yazdır:
                arrayYazdir(cevap);
            break;
        case 6: //çıkış komutu!!While kırılır.
            break;
        default:
            puts("Hatali islem girisi! Lutfen 1-2-3-4-5-6 seceneklerinden birini seciniz.");
            break;
        }
    }while (girdi != 5);
    free(sayi1Array);
    free(sayi2Array);
    fclose(sayi1File);
    fclose(sayi2File);
    puts("Program basari ile sonlandirildi.");
    return EXIT_SUCCESS;
}