//2023 update skalkaproject, definice jsou v SkalkaTools.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
//Makro na "vycisteni" bufferu - pouzivej kdyz volas scanf() nekolikrat za sebou fesaku ;-)
#define clear_buffer() getchar()

//Bude se pokouset nacist hodnotu ze vstupu v rozmezi min - max
int get_from_to(int min, int max);

//Porovna stringy, vraci 1 v pripade shody
int compare_str(const char *str1, const char *str2);

//Vygeneruje nahodne hodnoty v rozmezi 0 - range do pole
void array_rng(int *array, int size, int range);

//Vygeneruje a vrati nahodnou hodnotu v rozmezi 0 < range
int rng(int range);

//Vypise pole od 0. indexu
void array_print(int *array, int size);

//Vypise pole od posledniho indexu
void array_print_reverse(int *array, int size);

//Vrati sumu prvku pole
int array_sum(const int *array, int size);

//Vrati nejmensi prvek pole
int array_min(int *array, int size);

//Vrati nejvetsi prvek pole
int array_max(int *array, int size);

//Spravne zapsany bubblesort (-i)
void bubble_sort(int *array, int size);

//V pripade ze je parametr sude cislo vraci 1
int is_even(int number);

//Vraci faktorial cisla
int factorial(int number);

//Vraci aritmeticky prumer cisel v poli
float average_value(const int *array, int size);

//Prevede binarni pole do desitkove soustavy a vrati ho
int bin_to_dec(const int *array, int size);

//Prevede binarni pole do sestnactkove soustavy a vypise
void bin_to_hex(const int *array, int size);

//Prevede cislo v desitkove soustave na binarni soustavu a vypise
void dec_to_bin(int number);

//Prevede cislo v desitkove soustave na sestnactkovou soustavu a vypise
void dec_to_hex(int number);

//Prevede cislo v sestnactkove soustave a vrati ho
int hex_to_dec(const char *array, int size);

//Prevede cislo v sestnactkove soustave na binarni soustavu a vypise
void hex_to_bin(const char *array, int size);

//Prekopiruje prvni pole do druheho. Je mozne kopirovat od n-teho indexu pomoci offsetu.
// V pripade ze bude mensi jak 0 nebo vetsi jak velikost pole, funkce se ukonci.
void array_copy(const int *current_array, int current_size, int *new_array, int new_size, int offset);

//Vrati pocet samohlasek ve stringu
int samohlasky(char *string);

//Vrati pocet souhlasek ve stringu
int souhlasky(char *string);

//Vrati pocet slov ve vete (pocita samostatna pismena jako slova)
int words_in_sentence(char *string);

//Vypise ctverec x*x ze zvoleneho znaku
void square(int x, char c);

//Vypise obdelnik x * y ze zvoleneho znaku
void rectangle(int x, int y, char c);

//Vypise rovnoramenny trojuhelnik ze zvoleneho znaku
void triangle(int x, char c);

//Vrati hodnotu BMI
float bmi(int vyska, int vaha);

//Rozebere rodne cislo ve formatu 000000 na rok mesic den
void rodne_cislo(int number);


