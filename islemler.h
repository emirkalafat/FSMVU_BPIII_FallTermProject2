/*
* @file islemler.h
* @description operations with files islemler.h file
* @assignment Computer Engineering III Fallterm Project II
* @date 28.12.2021
* @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
*/
#ifndef _ISLEMLER_
#define _ISLEMLER_

void hello();
FILE *dosyaAc(FILE *file,char *dosyaAdi);
void matrisYazdir(int *matris,int boyut);
int *matrisOlustur(int matrisBoyutu);
void dosyadanOku();
void yazdir();

#endif