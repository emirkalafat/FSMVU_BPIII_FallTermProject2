/*
* @file islemler.c
* @description operations with files islemler.c file
* @assignment Computer Engineering III Fallterm Project II
* @date 28.12.2021
* @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "islemler.h"

int arrayBoyutHesapla(FILE *acilmisDosya){
    int count=0;
    char ch;
    do
    {
        ch = fgetc(acilmisDosya);
        count++;
    }while (ch != EOF);
    rewind(acilmisDosya);
    return count;
}
uint8_t *arrayOlustur(int arrayBoyutu){
    int *array = malloc(arrayBoyutu*sizeof(uint8_t));
    return array;
}
void arrayDoldur(FILE *opeandFile, uint8_t *array){
    int son = 0;
    while (fscanf(opeandFile,"%1d",&array[son])!= EOF)
    {
        son++;
    }
    fclose(opeandFile);
    array[son] = '\0';
}
void arrayYazdir(uint8_t *array){
    int i = 0;
    for (i = 0; array[i] != '\0'; i++)
        printf("%d", array[i]);
}
int toplamaIslemi(uint8_t *sayi1,uint8_t *sayi2,int boyut1, int boyut2,uint8_t *sonuc){
    int elde = 0;
    int i;
    if(boyut1<boyut2){
        sonuc = arrayOlustur(boyut2+1);
        
    }
    else{
        sonuc = arrayOlustur(boyut1+1);
        for (i = 0; array[i] != '\0'; i++)
        printf("%d", array[i]);
    }
}
int cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2){

}