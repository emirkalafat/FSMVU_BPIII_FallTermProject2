/*
 * @file islemler.h
 * @description operations with files islemler.h file
 * @assignment Computer Engineering III Fallterm Project II
 * @date 28.12.2021
 * @author Ahmet Emir Kalafat ahmetemir.kalafat@stu.fsm.edu.tr
 */
#ifndef _ISLEMLER_
#define _ISLEMLER_
void dosyaKapa(FILE *dosya);
int arrayBoyutHesapla(FILE *acilmisDosya);
uint8_t *int8ArrayOlustur(int matrisBoyutu);
void arrayDoldur(FILE *acilmisDosya, uint8_t *sayiArray);
void arrayYazdir(uint8_t *array, int boyut);
int buyukBoyutuDondur(int boyut1, int boyut2);
void toplamaIslemi();

//renki çıktı kodları
void red();
void green();
void cyan();
void resetRenk();
#endif