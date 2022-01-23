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
void toplamaIslemi()
{

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