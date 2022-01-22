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
int buyukBoyutuDondur(int boyut1,int boyut2){
    return boyut1>boyut2 ? boyut1 : boyut2;
}
void toplamaIslemi(uint8_t *sayi1,uint8_t *sayi2,int boyut1, int boyut2,uint8_t *sonuc){
    int elde = 0;
    int a=boyut1-1,b=boyut2-1;
    if(boyut1>boyut2){
        while (a>=0)
        {
            if (b<-1)
            {
                sonuc[a] = (*sayi1+a);
            }
            if(b=-1){
                sonuc[a]=(*sayi1+a)+elde;
            }
            else{
                sonuc[a] = ((*sayi1+a)+(*sayi2+b)+elde)%10;
                elde = ((*sayi1+a)+(*sayi2+b)+elde)/10;
            }
            a--;
            b--;
        }
        sonuc[0]=elde;
    }
    else{
        while (b>=0)
        {
            if (b<-1)
            {
                sonuc[b] = (*sayi2+b);
            }
            if(b=-1){
                sonuc[b]=(*sayi2+b)+elde;
            }
            else{
                sonuc[b] = ((*sayi1+a)+(*sayi2+b)+elde)%10;
                elde = ((*sayi1+a)+(*sayi2+b)+elde)/10;
            }
            a--;
            b--;
        }
        sonuc[0]=elde;
    }
}
int cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2){

}