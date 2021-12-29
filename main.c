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
    // dosya açma işlemi//
    FILE *sayi1;
    FILE *sayi2;
    ;
    if ((sayi1 = fopen("sayi1.txt", "r")) == NULL)
    {
        fprintf(stderr, "\nError open \"sayi1.txt\" file\n");
        exit(EXIT_FAILURE);
    }
    else if ((sayi2 = fopen("sayi2.txt", "r")) == NULL)
    {
        fprintf(stderr, "\nError open \"sayi2.txt\" file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
    //////////
    short girdi;
    puts("Lutfen islem seciniz.");
    scanf("%d", &girdi);
    while (girdi <= 5 && girdi >= 1)
    {
        switch (girdi)
        {
        case 1: //[1]-> Dosyadan sayilari oku: (1)

            break;
        case 2: //[2]-> Okunan sayilari ekrana yaz: (2)

            break;
        case 3: //[+/-]-> Islem seciniz: (+ veya -)
            puts("Islem seciniz.[+/-]");
            char matIslem;
            gets(matIslem);
            break;
        case 4: //[4]-> Sonucu ekrana yazdır: (4)

            break;
        case 5: //[5]-> Cikis : (5)
            puts("Program basari ile sonlandiriliyor.");
            return EXIT_SUCCESS;
            break;
        default:
            puts("Hatali islem girisi! Cikis yapiliyor...");
            return EXIT_FAILURE;
            break;
        }
    }
    }
}