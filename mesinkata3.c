#include "boolean.h"
#include "mesinkata3.h"
#include "mesinkar.h"
#include <stdio.h>

Kata CKata;

void Ignore_Blank()
/* Mengabaikan satu atau beberapa BLANK 
 I.S. : CC sembarang 
 F.S. : CC ≠ BLANK atau CC = MARK */
{
	while(CC==BLANK && CC!=MARK)
	{
		ADV();
	}
}

void INITAKSES()
/* 	Mengabaikan satu atau beberapa BLANK pada awal pita 
	I.S. : CC sembarang 
	F.S. : CC = MARK; atau CC = karakter pertama dari kata yang akan
	diakuisisi */
{
	START();
	Ignore_Blank();
}

void ADVKATA()
/* 	I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
	F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
	CC adalah karakter pertama dari kata berikutnya,
	mungkin MARK 
	Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	SalinKata();
	Ignore_Blank();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata }
{ I.S. : CC adalah karakter pertama dari kata }
{ F.S. : CKata berisi kata yang sudah diakuisisi; CC = BLANK atau CC =
MARK; CC adalah karakter */
{
	int i=1;
	
	while((CC!=BLANK) && (CC!=MARK) && (i<=NMax))
	{
		CKata.TabKata[i] = CC;
		ADV();
		i++;
	}
	CKata.Length = i-1;
	Ignore_Blank();
}
