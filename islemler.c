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
uint8_t *arrayOlustur(int matrisBoyutu){
    int *matris = malloc(matrisBoyutu*sizeof(uint8_t));
    return matris;
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
int toplamaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2){
    int elde = 0;
    if(boyut1<boyut2){

    }
    else{

    }
}
int cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2){

}