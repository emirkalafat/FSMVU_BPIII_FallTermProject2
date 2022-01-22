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
uint8_t *arrayOlustur(int matrisBoyutu);
void arrayDoldur(FILE *file, uint8_t *array);
void arrayYazdir(uint8_t *array);
uint8_t *toplamaIslemi(uint8_t *sayi1,uint8_t *sayi2,int boyut1, int boyut2);
int cikarmaIslemi(int *sayi1,int *sayi2,int boyut1, int boyut2);
#endif