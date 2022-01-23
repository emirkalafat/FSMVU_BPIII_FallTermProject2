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
void dosyaKapa(FILE *dosya)
{
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
uint8_t *int8ArrayOlustur(int arrayBoyutu)
{
    uint8_t *array = malloc(arrayBoyutu * sizeof(uint8_t));
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
            continue;                  // array e enter girmemsi icin
        else if (c >= '0' && c <= '9') // dosyadan gelen deger sayi ise arraye yazilir
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
        printf("%d ", *(array + i));
    puts("");
}
void toplamaIslemi(uint8_t *sayi1, uint8_t *sayi2, int sayi1Boyut, int sayi2Boyut, uint8_t *cevap, int cevapBoyut)
{
    int k = cevapBoyut - 1; // toplama işlemi için birler basamağından başlıyoruz.
    int n = sayi1Boyut - 1;
    int m = sayi2Boyut - 1; 
    while (k > 0)
    { // cevap arrayinin ilk indexine kadar dönüyoruz.
        *cevap = 0;
        
        if(m>=0){
        *(cevap + k) = *(sayi1 + n) + *(sayi2 + m);
        if(*(cevap + k) > 9 ){
            *(sayi1 + n - 1) += 1;
            *(cevap + k) -= 10; 
        }
        else{
            *(cevap + k) = *(sayi1 + n);
        }
        if(*sayi1>9){
            *cevap = 1;
        }
        k--;
        n--;
        m--;
    }
    }
    
}
void cikarmaIslemi(uint8_t *sayi1, uint8_t *sayi2, int sayi1Boyut, int sayi2Boyut, uint8_t *cevap, int cevapBoyut){
    int k = cevapBoyut - 1; // toplama işlemi için birler basamağından başlıyoruz.
    int n = sayi1Boyut - 1;
    int m = sayi2Boyut - 1; 
    int gecici;
    while (k > 0)
    { // cevap arrayinin ilk indexine kadar dönüyoruz.
        *cevap = 0;
        
        if(m>=0){
        if(*(sayi1+n) < *(sayi2+m)){
            *(sayi1+n) += 10;
            gecici = *(sayi1 + n) - *(sayi2 + m);
            int geri = 1;
            while(*(sayi1+n-geri)==0){
                *(sayi1+n-geri)=9;
                geri++; 
            }
            *(sayi1+n-geri) -= 1;
            
        }
        else{
            gecici = *(sayi1 + n) - *(sayi2 + m); 
        }
        *(cevap + k) = gecici;
        }
        else{
            *(cevap + k) = *(sayi1 + n);
        }
        
        k--;
        n--;
        m--;
    }
}
    

// renkli çıktı kodları
void red()
{
    printf("\033[0;31m");
}
void green()
{
    printf("\033[0;32m");
}
void cyan()
{
    printf("\033[0;36m");
}
void resetRenk()
{
    printf("\033[0m");
}