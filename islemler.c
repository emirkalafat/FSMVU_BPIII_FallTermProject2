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
#include "islemler.h"

int arrayBoyutHesapla(FILE *acilmisDosya){
    int count=0;
    char ch;
    do
    {
        ch = fgetc(acilmisDosya);
        if(ch!='\n')
            count++;
        else
            continue;
    }while (ch != EOF);
    rewind(acilmisDosya);
    return count-1;
}
void charToUint(char *charArray,uint8_t *sayiArray){
    int i = 0;
    for (i = 0; charArray[i] != '\0'; i++)
        sayiArray[i]=atoi(charArray[i]);
    
}
uint8_t *arrayOlustur(int arrayBoyutu){
    uint8_t *array = malloc(arrayBoyutu*sizeof(uint8_t));
    return array;
}
void arrayDoldur(FILE *acilmisDosya,char *array){
    int son = 0;
    while (fscanf(acilmisDosya,"%c",&array[son])!= EOF)
    {
        son++;
    }
    fclose(acilmisDosya);
    array[son] = '\0';
}
void arrayYazdir(uint8_t *array){
    int i = 0;
    for (i = 0; array[i] != '\0'; i++)
        printf("%d", array[i]);
    puts("");
}
void arrayBoyutuIleYazdir(uint8_t *array, int boyut){
    int i=0;
    for (i = 0; i < boyut; i++)
        printf("%d",array[i]);
    puts("");
}
int buyukBoyutuDondur(int boyut1,int boyut2){
    return boyut1>boyut2 ? boyut1 : boyut2;
}
void toplamaIslemi(uint8_t *sayi1,uint8_t *sayi2,int boyut1, int boyut2,uint8_t *sonuc){
    uint8_t elde = 0;
    uint8_t ondalik = 10;
    int a=boyut1;
    int b=boyut2-1;
    
    if(boyut1>boyut2){
        while (a>=0)
        {
            if (b<=0)
            {
                sonuc[a] = (sayi1[a-1]+sayi2[b]+elde)%ondalik;
                elde = (sayi1[a-1]+sayi2[b]+elde)/ondalik;
            }
            else{
                sonuc[a] = sayi1[a-1]+elde;
            }
            a--;
            b--;
        }
        sonuc[0]=elde;
    }
    //else{
    //    while (b>=0)
    //    {
    //        if (b<-1)
    //        {
    //            sonuc[b] = (*sayi2+b);
    //        }
    //        if(b=-1){
    //            sonuc[b]=(*sayi2+b)+elde;
    //        }
    //        else{
    //            sonuc[b] = ((*sayi1+a)+(*sayi2+b)+elde)%10;
    //            elde = ((*sayi1+a)+(*sayi2+b)+elde)/10;
    //        }
    //        a--;
    //        b--;
    //    }
    //    sonuc[0]=elde;
    //}
}
void cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2){

}