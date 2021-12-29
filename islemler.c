/*
* @file islemler.c
* @description operations with files islemler.c file
* @assignment Computer Engineering III Fallterm Project II
* @date 28.12.2021
* @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "islemler.h"

void hello(){
    printf("hello");
}
void dosyadanOku(){

}
void yazdir(){

}
FILE *dosyaAc(FILE *file,char *dosyaAdi){
    if ((file = fopen(dosyaAdi, "r")) == NULL)
    {
        fprintf(stderr, "\nError open \"%s\" file\n",dosyaAdi);
        exit(EXIT_FAILURE);
    }
    else return file;
}
void matrisYazdir(int *matris,int boyut){
    //bu fonksiyon verilen matrisin elemanlarını düzün sırada yazdırmayı sağlıyor.
    puts("*************************");
    for (int i = 0; i < boyut; i++)
    {
        printf("%d ",*(matris+i));
    }
}
int *matrisOlustur(int matrisBoyutu){
    //bu fonksiyon heap alanında matris için uygun boyutta yer ayırıp sışarı yolluyor.
    int *matris = malloc(matrisBoyutu*sizeof(int));
    return matris;
}