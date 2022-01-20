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
int *arrayOlustur(int matrisBoyutu){
    int *matris = malloc(matrisBoyutu*sizeof(int));
    return matris;
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