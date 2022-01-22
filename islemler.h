/*
* @file islemler.h
* @description operations with files islemler.h file
* @assignment Computer Engineering III Fallterm Project II
* @date 28.12.2021
* @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
*/
#ifndef _ISLEMLER_
#define _ISLEMLER_

int arrayBoyutHesapla(FILE *acilmisDosya);
void charToUint(char *charArray,uint8_t *sayiArray);
uint8_t *arrayOlustur(int matrisBoyutu);
void arrayDoldur(FILE *file, char *array);
void arrayYazdir(uint8_t *array);
void arrayBoyutuIleYazdir(uint8_t *array, int boyut);
int buyukBoyutuDondur(int boyut1,int boyut2);
void toplamaIslemi(uint8_t *sayi1,uint8_t *sayi2,int boyut1, int boyut2,uint8_t *sonuc);
void cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2);
#endif