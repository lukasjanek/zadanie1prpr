#include <stdio.h>
#define MAX 999
#define ABECEDA 'Z' - 'A' + 1
#define VELKEPISMENO 32
#define MINPOCETZNAKOV 1
#define MAXPOCETZNAKOV 100
void n(int povodnyText[],int *dlzkaSuboru) 
{   	
	FILE *fsifra;	
	if ((fsifra = fopen("sifra.txt","r"))!=NULL)
	{ 
		int pismeno,pocetZnakov;
		pocetZnakov=0;
		while ((pismeno=getc(fsifra))!=EOF)
		{
			povodnyText[pocetZnakov]=pismeno;
			pocetZnakov++;
		}
		*dlzkaSuboru = pocetZnakov;
		if (fclose(fsifra)==EOF)
		{
			printf("Subor sa nepodarilo zatvorit\n");	
		}
	}
	else
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	
}
void v(int povodnyText[], int dlzkaSuboru)
{
	int iteracia;
	for (iteracia=0;iteracia< dlzkaSuboru;iteracia++)
	{
		printf("%c",povodnyText[iteracia]);
	}
	putchar('\n');
}
void u(int povodnyText[],int upravenyText[],int *velkePismena,int dlzkaSuboru)
{
	int velke, pismeno, pocetZnakov;
	int upravenyPocetZnakov=0;

	for(pocetZnakov=0; pocetZnakov<=dlzkaSuboru; pocetZnakov++)
	{	
		
		pismeno = povodnyText[pocetZnakov];
		if ((pismeno >= 'a' && pismeno <= 'z') || (pismeno >= 'A' && pismeno <= 'Z'))
		{				
				if(pismeno >= 'a' && pismeno <= 'z')
				{
					velke = pismeno-32;
					upravenyText[upravenyPocetZnakov] = velke;
				}
				else 
				{
					upravenyText[upravenyPocetZnakov] = povodnyText[pocetZnakov];
				}
				upravenyPocetZnakov++;
		}
	*velkePismena=upravenyPocetZnakov;
	}
}
void s(int upravenyText[], int velkePismena)
{
	int pocetZnakov;
	for (pocetZnakov=0;pocetZnakov<=velkePismena;pocetZnakov++)
	{
		printf("%c",upravenyText[pocetZnakov]);
	}
	putchar('\n');	
}
void d(int povodnyText[], int dlzkaSuboru)
{
	int dlzkaSlova,drzac=0,pocetZnakov,zaciatok=0,medzera=0;
	scanf("%d",&dlzkaSlova);
	if (dlzkaSlova >=MINPOCETZNAKOV && dlzkaSlova <= MAXPOCETZNAKOV)
	{
		
		for (pocetZnakov = 0; pocetZnakov < dlzkaSuboru; pocetZnakov++)
		{
			if (povodnyText[pocetZnakov] != ' ')
			{
				drzac++;
			}
			if (povodnyText[pocetZnakov] == ' ')
			{
				if (drzac == dlzkaSlova)
				{
					while(zaciatok < drzac + medzera)
					{
					printf("%c",povodnyText[zaciatok]);
          			zaciatok++;
          			}
          			putchar('\n');
          			zaciatok = pocetZnakov+1;
          			medzera = zaciatok;
          			drzac=0;	
				}
				else
				{
					zaciatok=pocetZnakov+1;
					medzera = zaciatok;
					drzac = 0;
				}
			}
		}
	}
}
void h(int upravenyText[], int velkePismena)
{
	int histogram[ABECEDA], zaciatok, znak, pismeno, tridsatPercentaViac, tridsatPercent, dvadsatPercent, desatPercent, raz;
	for (zaciatok=0; zaciatok<ABECEDA; zaciatok++)
	{
	  histogram[zaciatok] = 0;
	}
    for (znak = 0; znak < velkePismena; znak++) 
	{
      	if((upravenyText[znak] >= 'A') && (upravenyText[znak] <= 'Z'))
      	{
			histogram[upravenyText[znak] - 'A']++;
		}
	}
	pismeno = 100 / velkePismena; //vydelime a urobime si percenta
	for (tridsatPercentaViac = 0; tridsatPercentaViac < ABECEDA; tridsatPercentaViac++)
	{
		if (((histogram[tridsatPercentaViac])*pismeno) > 30) //ak sa pismeno nachadza viac ako 30% v poli
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (tridsatPercent = 0; tridsatPercent < ABECEDA; tridsatPercent++)
	{
		if (((histogram[tridsatPercent])*pismeno) > 20) //ak sa pismeno nachadza do 30%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
	 	}	
	}
	putchar('\n');
	for (dvadsatPercent = 0; dvadsatPercent < ABECEDA; dvadsatPercent++)
	{
		if (((histogram[dvadsatPercent])*pismeno) > 10) //ak sa pismeno nachadza do 20%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (desatPercent = 0; desatPercent < ABECEDA; desatPercent++)
	{
		if (((histogram[desatPercent])*pismeno) > 0) //ak sa pismeno nachadza do 10%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (raz = 0; raz < ABECEDA; raz++)
	{
	putchar('A'+ raz); //ak sa to nachadza raz
	}
	putchar ('\n');
}
void c(int upravenyText[], int velkePismena)
{
	int iteracia,posun,sifra,cezarka,velke;
	scanf("%d", &posun);
	if ((posun >= 1) && (posun <=25))
	{
		for (iteracia=0; iteracia < velkePismena; iteracia++)
		{
			sifra = upravenyText[iteracia] - posun;
			if (sifra < 'A')
			{
				cezarka = sifra + ABECEDA;
				printf("%c",cezarka);
			}	
			else 
			{
				printf("%c",sifra);
			}
							
		}
		putchar('\n');	
	}
		
}
	
		
int main() //telo
{
	int znak, dlzkaSuboru=MAX,velkePismena=MAX; 
	int povodnyText[MAX]={0},upravenyText[MAX]={0};
	while ((znak =getchar()) !='k')
	{
		switch (znak)
		{
			case 'n': n(povodnyText, &dlzkaSuboru);
				break;
			case 'v': v(povodnyText, dlzkaSuboru);
				break;
			case 'u': u(povodnyText,upravenyText, &velkePismena,dlzkaSuboru);
				break;
			case 's': s(upravenyText, velkePismena);
				break;
			case 'd': d(povodnyText, dlzkaSuboru);
				break;
			case 'h': h(upravenyText,velkePismena);
				break;
			case 'c': c(upravenyText, velkePismena);
				break;
			case 'k':  return 0;
		}
	}
	return 0;
}
