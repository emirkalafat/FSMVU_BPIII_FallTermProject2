/**
 * @file islemler.c
 * @description operations with files islemler.c file
 * @assignment Computer Engineering III Fallterm Project II
 * @date 28.12.2021
 * @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include "islemler.h"
void dosyaKapa(FILE *dosya){
    fclose(dosya);
}
int arrayBoyutHesapla(FILE *acilmisDosya)
{
    int count = 0;
    char ch;
    while (!feof(acilmisDosya))
    {
        ch = fgetc(acilmisDosya);
        if (ch != '\n')
        {
            count++;
        }
    }
    rewind(acilmisDosya);
    return count - 1;
}
uint8_t *int8ArrayOlustur(int arrayBoyutu){
    uint8_t *array=malloc(arrayBoyutu*sizeof(uint8_t));
    return array;
}
void arrayDoldur(FILE *acilmisDosya, uint8_t *sayiArray)
{
    int i = 0;
    char c;
    while (!feof(acilmisDosya))
    {
        c = fgetc(acilmisDosya);
        if ((c == '\0'))
            continue; // array de space olusmamasi için
        else if (c == '\n')
            continue; // array e enter girmemsi icin
        else if (c >= '0' && c <= '9')//dosyadan gelen deger sayi ise arraye yazilir
        {
            int sayi = (c - '0');
            *(sayiArray + i) = sayi;
            i++;
        }
    }
    rewind(acilmisDosya);
}
void arrayYazdir(uint8_t *array, int boyut)
{
    int i = 0;
    for (i = 0; i < boyut; i++)
        printf("%d ", *(array+i));
    puts("");
}
int buyukBoyutuDondur(int boyut1, int boyut2)
{
    return boyut1 >= boyut2 ? boyut1 : boyut2;
}
void toplamaIslemi(uint8_t *sayi1, uint8_t *sayi2, int sayi1Boyut, int sayi2Boyut, uint8_t *cevap, int cevapBoyut)
{
    uint8_t *yeniSayiArray;
    if(buyukBoyutuDondur(sayi1Boyut,sayi2Boyut)==sayi1Boyut){
        yeniSayiArray = malloc(sayi1Boyut*sizeof(uint8_t));
        int j = sayi1Boyut;
        for (size_t i = sayi2Boyut -1; i > 0; i--)
        {
            *(yeniSayiArray+j)= *(sayi2+i);
            j--;
        }
    }
    else if(buyukBoyutuDondur(sayi1Boyut,sayi2Boyut)==sayi2Boyut){
        yeniSayiArray = malloc(sayi2Boyut*sizeof(uint8_t));
        int j = sayi2Boyut;
        for (size_t i = sayi1Boyut -1; i > 0; i--)
        {
            *(yeniSayiArray+j)= *(sayi1+i);
            j--;
        }
    }
    int n = cevapBoyut - 1; // toplama işlemi için birler basamağından başlıyoruz.
    while(n>=0){//cevap arrayinin ilk indexine kadar dönüyoruz.
        if((*(sayi1+n) + *(yeniSayiArray+n)) > 9){
            *(cevap + n - 1) =  1;
            *(cevap + n) += *((sayi1 + n) + *(yeniSayiArray + n))%10;
        }
        else
            *(cevap + n) += *(sayi1 + n) + *(yeniSayiArray + n);

        n--;
}
void cikarmaIslemi(uint8_t *sayi1, uint8_t *sayi2, int sayi1Boyut, int sayi2Boyut, uint8_t *cevapArray, int cevapBoyut){
    int n = cevapBoyut - 1; // toplama işlemi içib birler basamağından başlıyoruz.
    int i = sayi1Boyut - 1; // birinci arrayin index sayısı.
    int j = sayi2Boyut - 1; //ikinci arrayin index sayısı.
    int cevap = 0;
    int elde = 0;
    while(cevapBoyut>=0){
        if(j<=0){
            cevap = *(sayi1+i) - *(sayi2+i) - elde ;
            if(cevap < 0){
                cevap *= -1;
                elde = 1;
            }
            else
                elde = 0;
            cevapArray[n] = cevap;
        }
        else if (j==-1){
            cevap = *(sayi1+i+1) - *(sayi2+i+1) - elde ;
            if(cevap<0) 
                cevapArray[n] = *(sayi1+i) - 1 ;
            else 
                cevapArray[n] = *(sayi1+i);
        }
        else 
            cevapArray[n] = *(sayi1+i);

        cevapBoyut--;
        i--;
        j--;
    }   
}

//renkli çıktı kodları
void red() {
  printf("\033[0;31m");
}
void green() {
  printf("\033[0;32m");
}
void cyan(){
    printf("\033[0;36m");
}
void resetRenk() {
  printf("\033[0m");
}