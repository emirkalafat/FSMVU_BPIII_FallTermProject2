/*
 * @file main.h
 * @description operations with files main.c file
 * @assignment Computer Engineering III Fallterm Project II
 * @date 28.12.2021
 * @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include "islemler.h"

int main(int argc, char const *argv[])
{
    //Tanımlamalar
    FILE *sayi1File;
    FILE *sayi2File;
    int *sayi1Array;
    int *sayi2Array;
    int sayi1Boyut;
    int sayi2Boyut;

    int girdi;
    int son = 0;
    puts("===============Cok Basamakli Sayilar Ile Islemler=========");
    do{
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
                printf( "%s dosyasini acmada sorun yasandi.\n", "sayi1.txt");
                break;
            }
            else if((sayi2File = fopen("sayi2.txt", "r")) == NULL){
                printf( "%s dosyasini acmada sorun yasandi.\n", "sayi2.txt");
                break;
            }
            else{
                sayi1Boyut=arrayBoyutHesapla(sayi1File);
                sayi2Boyut=arrayBoyutHesapla(sayi2File);
                sayi1Array=arrayOlustur(sayi1Boyut);
                sayi2Array=arrayOlustur(sayi2Boyut);


            }

            


            break;
        case 2: //[2]-> Okunan sayilari ekrana yaz: (2)

            break;
        case 3: //[+/-]-> Islem seciniz: (+ veya -)
            puts("Islem seciniz.[+/-]");
            char matIslem;
            scanf("%c",matIslem);
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
        case 5: //[5]-> Cikis : (5)
            puts("Program basari ile sonlandiriliyor.");
            return EXIT_SUCCESS;
            break;
        default:
            puts("Hatali islem girisi! Lutfen 1-2-3-4-5 seceneklerinden birini seciniz.");
            break;
        }
    }
    while (girdi <= 5 && girdi >= 1);
}