
#ifndef __MESINKATA3_H__
#define __MESINKATA3_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define MARK '.'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern Kata CKata;

/***** Primitif-Primitif Mesin Kata *****/

void Ignore_Blank();
/* Mengabaikan satu atau beberapa BLANK 
 I.S. : CC sembarang 
 F.S. : CC ≠ BLANK atau CC = MARK */
void INITAKSES();
/* 	Mengabaikan satu atau beberapa BLANK pada awal pita 
	I.S. : CC sembarang 
	F.S. : CC = MARK; atau CC = karakter pertama dari kata yang akan
	diakuisisi */
void ADVKATA();
/* 	I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
	F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
	CC adalah karakter pertama dari kata berikutnya,
	mungkin MARK 
	Proses : Akuisisi kata menggunakan procedure SalinKata */
void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi; CC = BLANK atau CC =
MARK; CC adalah karakter */

#endif
