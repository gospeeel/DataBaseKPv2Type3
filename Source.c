#define _CRT_SECURE_NO_WARNINGS
#define N 50
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>



struct pc {
	char manufacturer[50];
	char formfactor[50];
	char typesize[50];
	int height;
	float dlina;//3 òèïà äàííûõ
	float shirina;
	char color[50];
	char availability[50];
}*comp;

typedef struct pc PC;
void dobavit(PC* comp, int shet);
void output(PC* comp, int shet);
void display();
void displayN2(PC* comp, int shet);
PC poisk(PC* comp, int shet);
void sortirovka(PC* comp, int shet);
int vstavit(char* nazvaniefaila, PC* comp, int shet);
int prochitat(char* nazvaniefaila);

void dobavit(PC* comp, int shet)
{
	if (shet > 50)
	{
		printf("Íà äèñêå íå äîñòàòî÷íî ïàìÿòè äëÿ çàïèñè äîêóìåíòà");

	}
	for (int a = 0; a < shet; a++)
	{
		printf("Ââåäèòå íàçâàíèå ïðîèçâîäèòåëÿ:");
		scanf("%s", &comp[a].manufacturer);
		printf("Ââåäèòå ôîðì-ôàêòîð ïëàòû:");
		scanf("%s", &comp[a].formfactor);
		printf("Ââåäèòå òèïîðàçìåð êîðïóñà:");
		scanf("%s", &comp[a].typesize);
		printf("Ââåäèòå âûñîòó êîðïóñà:");
		scanf("%d", &comp[a].height);
		printf("Ââåäèòå äëèíó êîðïóñà:");
		scanf("%f", &comp[a].dlina);
		printf("Ââåäèòå øèðîòó êîðïóñà:");
		scanf("%f", &comp[a].shirina);
		printf("Ââåäèòå öâåò êîðïóñà:");
		scanf("%s", &comp[a].color);
		printf("Ââåäèòå íàëè÷èå ïîäñâåòêè/îêíà è ïð.:");
		scanf("%s", &comp[a].availability);
		printf("\n");
	}
}

void output(PC* comp, int shet)
{
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|| Íàçâàíèå ïðîèçâîäèòåëÿ  ||  Ôîðì-ôàêòîð ||  Òèïîðàçìåð ||  Âûñîòà  ||    Äëèíà  ||   Øèðîòà  ||  Öâåò  ||  Íàëè÷èå ïîäñâåòêè  ||\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	for (int b = 0; b < shet; b++)
	{
		printf("||      %s              ||      %s      ||       %s       ||   %dñì   || %fñì || %fñì ||  %s   ||   %s   ||\n", comp[b].manufacturer, comp[b].formfactor, comp[b].typesize, comp[b].height, comp[b].dlina, comp[b].shirina, comp[b].color, comp[b].availability);
		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");
	return 0;
}

void displayN2(PC* comp, int shet)
{
	printf("||%s|%s||%s||%dñì||%fñì||%fñì||%s||%s||\n", (comp + shet)->manufacturer, (comp + shet)->formfactor, (comp + shet)->typesize, (comp + shet)->height, (comp + shet)->dlina, (comp + shet)->shirina, (comp + shet)->color, (comp + shet)->availability);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
}

void display()
{
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Íàçâàíèå ïðîèçâîäèòåëÿ  ||  Ôîðì-ôàêòîð ||  Òèïîðàçìåð ||  Âûñîòà  ||   Äëèíà  ||  Øèðîòà  || Öâåò  ||  Íàëè÷èå ïîäñâåòêè  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
}

PC poisk(PC* comp, int shet)
{
	char krit[10];
	int vibor, krit2, krit3, krit4, krit5, krit6, ukaz2 = 1;
	printf("Âûáåðèòå êðèòåðèé ïîèñêà\n");
	printf("1.Íàçâàíèå Ïðîèçâîäèòåëÿ\n");
	printf("2.Ôîðì-ôàêòîð\n");
	printf("3.Òèïîðàçìåð\n");
	printf("4.Âûñîòà\n");
	printf("5.Öâåò\n");
	printf("6.Ïîäñâåòêà è ïð.\n");
	printf("7.Äëèíà\n");
	printf("8.Øèðîòà\n");
	scanf("%d", &vibor);
	if (vibor == 1)
	{
		printf("Ââåäèòå íàçâàíèå ïðîèçâîäèòåëÿ\n");
		scanf("%s", krit);
		display();
		for (int c = 0; c < shet; c++)
		{
			if (strcmp((comp + c)->manufacturer, krit) == 0)
			{
				displayN2(comp, c);
			}
		}
	}
	if (vibor == 2)
	{
		printf("Ââåäèòå ôîðì-ôàêòîð\n");
		scanf("%s", &krit2);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->formfactor == krit2)
			{
				displayN2(comp, c);
			}


		}
		comp++;
	}
	if (vibor == 3)
	{
		printf("Ââåäèòå òèïîðàçìåð êîðïóñà\n");
		scanf("%s", &krit4);
		display();
		for (int c = 0; c < comp; c++)
		{
			if ((comp + c)->typesize == krit4)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	if (vibor == 4)
	{
		printf("Âûñîòà\n");
		scanf("%d", &krit3);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->height == krit3)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	if (vibor == 5)
	{
		printf("Öâåò\n");
		scanf("%s", &krit5);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->color == krit5)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	if (vibor == 6)
	{
		printf("Ïîäñâåòêà\n");
		scanf("%s", &krit6);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->availability == krit6)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	if (vibor == 7)
	{
		printf("Äëèíà\n");
		scanf("%f", &krit3);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->dlina == krit3)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	if (vibor == 8)
	{
		printf("Øèðîòà\n");
		scanf("%f", &krit3);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->shirina == krit3)
			{
				displayN2(comp, c);
			}

		}
		comp++;
	}
	return *comp;
}

int vstavit(char* nazvaniefaila, PC* comp, int shet)
{
	FILE* data;
	int c;
	if ((data = fopen(nazvaniefaila, "wt")) == NULL)
	{
		fprintf(stderr, "Ôàéë íåëüçÿ îòêðûòü äëÿ çàïèñè äîêóìåíòà \n");
		system("pause");
		return -1;
	}
	else
	{
		fprintf(data, "-----------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(data, "|| Íàçâàíèå ïðîèçâîäèòåëÿ  ||  Ôîðì-ôàêòîð ||  Òèïîðàçìåð ||  Âûñîòà  || Äëèíà  || Øèðîòà  || Öâåò  ||  Íàëè÷èå ïîäñâåòêè  ||\n");
		fprintf(data, "-----------------------------------------------------------------------------------------------------------------------------\n");
		for (c = 0; c < shet; c++)
		{
			fprintf(data, "||%s||%s|%s||%d||%f||%f||%s||%s||\n", comp[c].manufacturer, comp[c].formfactor, comp[c].typesize, comp[c].height, comp[c].dlina, comp[c].shirina, comp[c].color, comp[c].availability);
			fprintf(data, "--------------------------------------------------------------------------------------------------------------\n");
		}
		fclose(data);
		printf("Äàííûå óñïåøíî çàïèñàíû");
		system("pause");
	}
	return 0;
}

int prochitat(char* nazvaniefaila)
{
	FILE* open;
	char file[200];
	open = fopen(nazvaniefaila, "r");
	if (open != NULL)
	{
		printf("Ôàéë óñïåøíî îòêðûò\n");
		while (!feof(open))
		{
			fgets(file, 200, open);
			if (!feof(open))
			{
				puts(file);
			}
		}
		return 1;
	}
	else
	{
		printf("Ôàéë íå óäàëîñü îòêðûòü\n");
		system("pause");
		return -1;
	}
	fclose(open);
	return 1;
}

void sortirovka(PC* comp, int shet)
{
	char str[50];
	int height1;
	float dlina1, shirina1;
	for (int ñ = 1; ñ < shet; ñ++) {
		for (int j = 0; j < shet - ñ; j++)
			if (strcmp(comp[j].color, comp[j + 1].color) > 0) {
				strcpy(str, comp[j].manufacturer);
				strcpy(comp[j].manufacturer, comp[j + 1].manufacturer);
				strcpy(comp[j + 1].manufacturer, str);

				strcpy(str, comp[j].formfactor);
				strcpy(comp[j].formfactor, comp[j + 1].formfactor);
				strcpy(comp[j + 1].formfactor, str);

				strcpy(str, comp[j].typesize);
				strcpy(comp[j].typesize, comp[j + 1].typesize);
				strcpy(comp[j + 1].typesize, str);


				strcpy(str, comp[j].color);
				strcpy(comp[j].color, comp[j + 1].color);
				strcpy(comp[j + 1].color, str);

				strcpy(str, comp[j].availability);
				strcpy(comp[j].availability, comp[j + 1].availability);
				strcpy(comp[j + 1].availability, str);

				height1 = comp[j].height;
				comp[j].height = comp[j + 1].height;
				comp[j + 1].height = height1;

				dlina1 = comp[j].dlina;
				comp[j].dlina = comp[j + 1].dlina;
				comp[j + 1].dlina = dlina1;

				shirina1 = comp[j].shirina;
				comp[j].shirina = comp[j + 1].shirina;
				comp[j + 1].shirina = shirina1;

			}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Rus");
	int kolichestvo = 0;
	PC p;
	PC* comp = &p;
	int size;
	puts("Êîëè÷åñòâî ïîëüçîâàòåëåé:");
	scanf("%d", &size);
	comp = (struct PC*)malloc(size * sizeof(PC));
	int ukaz = 1, vibor, viborr, compl;
	char nazvaniefaila[100];
	printf("________________________________________\n");
	printf("|             Áàçà äàííûõ              |\n");
	printf("|             Êîðïóñ ÏÊ                |\n");
	printf("|Ñòóäåíò: Îñòðîâåðõîâ Äàíèëà Åâãåíüåâè÷|\n");
	printf("|Ãðóïïà:  áÈÑÒ-221                     |\n");
	printf("|______________________________________|\n");
	system("pause");
	while (ukaz)
	{
		system("cls");
		printf("Âûáåðèòå ôóíêöèþ\n1.Ââîä çíà÷åíèé.\n2.Âûâîä çíà÷åíèé\n3.Ïîèñê ñòðóêòóðû ïî çàäàííîìó êðèòåðèþ\n4.Ñîðòèðîâêà äàííûõ\n5.Çàïèñü äàííûõ â ôàéë\n6.×òåíèå äàííûõ èç ôàéëà\n0.Âûõîä èç ïðîãðàììû\n");
		scanf("%d", &vibor);
		system("cls");
		switch (vibor)
		{
		case 1:
			printf("Ââåäèòå êîë-âî çàïèñåé (ìåíüøå 50)\n");
			scanf("%d", &kolichestvo);
			dobavit(comp, kolichestvo);
			break;

		case 2:
			output(comp, kolichestvo);
			break;

		case 3:
			poisk(comp, kolichestvo);
			system("pause");
			break;

		case 4:
			sortirovka(comp, kolichestvo);
			break;

		case 5:
			printf("Ââåäèòå íàçâàíèå ôàéëà\n");
			scanf("%s", &nazvaniefaila);
			vstavit(nazvaniefaila, comp, kolichestvo);
			break;

		case 6:
			printf("Ââåäèòå íàçâàíèå ôàéëà\n");
			scanf("%s", &nazvaniefaila);
			prochitat(nazvaniefaila);
			system("pause");
			break;

		case 0:
			ukaz = 0;
			printf("Çàâåðøåíèå ðàáîòû ïðîãðàììû\n");
			break;

		default:
			puts("Âûáðàííûé âàðèàíò íåëüçÿ âûïîëíèòü");

		}

	}
	free(comp);
	system("pause");
}
