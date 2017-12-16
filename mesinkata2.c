#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>

Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while(CC==BLANK && CC!=MARK)
	{
		ADV();
	}
}

void STARTKATA()
/* 	I.S. : CC sembarang 
	F.S. : CKata.Length = 0, dan CC = Mark; 
	atau CKata.Length ≠ 0, CKata adalah kata yang sudah
	diakuisisi, CC karakter pertama sesudah karakter terakhir
	kata */
{
	START();
	IgnoreBlank();
	SalinKata();
}

void ADVKATA()
/* 	I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
	F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
	CC adalah karakter pertama dari kata berikutnya,
	mungkin MARK 
	Proses : Akuisisi kata menggunakan procedure SalinKata */

{
	IgnoreBlank();
	SalinKata();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	int i=0;
	
	while((CC!=BLANK) && (CC!=MARK) && (i<=NMax))
	{
		CKata.TabKata[i] = CC;
		ADV();
		i++;
	}
	CKata.Length = i;
	IgnoreBlank();
}

