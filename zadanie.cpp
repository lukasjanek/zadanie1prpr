#include <stdio.h>
#define max 999
char n();
//int v();
//int u();
//int s();
//int d();
//int h();
//int c();
//int k();

int main() //telo
{
	int znak;
	printf("Stlac znak pre:\n n- nacitanie sifrovanej spravy\n v- vypis sifrovanej spravy\n u- uprava spravy\n s- vypis sifry\n d- vypis vsetkych slov x dlzky\n h histogram sifry\n c- cezarova sifra\n k- ukoncit program\n");
	znak = getchar();
	
	switch (znak)
	{
		case 'n': n();
			break;
		/*case 'v': v();
			break;
		case 'u': u();
			break;
		case 's': s();
			break;
		case 'd': d();
			break;
		case 'h': h();
			break;
		case 'c': c();
			break;
		case 'k': k();
			break;*/ 
	}
	return 0;
}

char n()
{
	FILE *fr;
	int povodnytext[max],pismeno;
	if ((fr = fopen("sifra.txt","r"))==NULL)
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	for (int pocetznakov=0; pocetznakov <=max; pocetznakov++)
	{
		pismeno = getc(fr);
		povodnytext[pocetznakov]=pismeno;
	}
	if (fclose(fr)==EOF)
	{
		printf("Subor sa nepodarilo zatvorit");
	}
}








