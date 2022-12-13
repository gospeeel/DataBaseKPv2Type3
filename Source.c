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
	float dlina;//3 ���� ������
	float shirota;
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
		printf("�� ����� �� ���������� ������ ��� ������ ���������");

	}
	for (int a = 0; a < shet; a++)
	{
		printf("������� �������� �������������:");
		scanf("%s", &comp[a].manufacturer);
		printf("������� ����-������ �����:");
		scanf("%s", &comp[a].formfactor);
		printf("������� ���������� �������:");
		scanf("%s", &comp[a].typesize);
		printf("������� ������ �������:");
		scanf("%d", &comp[a].height);
		printf("������� ����� �������:");
		scanf("%f", &comp[a].dlina);
		printf("������� ������ �������:");
		scanf("%f", &comp[a].shirota);
		printf("������� ���� �������:");
		scanf("%s", &comp[a].color);
		printf("������� ������� ���������/���� � ��.:");
		scanf("%s", &comp[a].availability);
		printf("\n");
	}
}

void output(PC* comp, int shet)
{
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|| �������� �������������  ||  ����-������ ||  ���������� ||  ������  ||    �����  ||   ������  ||  ����  ||  ������� ���������  ||\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	for (int b = 0; b < shet; b++)
	{
		printf("||      %s              ||      %s      ||       %s       ||   %d��   || %f�� || %f�� ||  %s   ||   %s   ||\n", comp[b].manufacturer, comp[b].formfactor, comp[b].typesize, comp[b].height, comp[b].dlina, comp[b].shirota, comp[b].color, comp[b].availability);
		printf("---------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");
	return 0;
}

void displayN2(PC* comp, int shet)
{
	printf("||%s|%s||%s||%d��||%f��||%f��||%s||%s||\n", (comp + shet)->manufacturer, (comp + shet)->formfactor, (comp + shet)->typesize, (comp + shet)->height, (comp + shet)->dlina, (comp + shet)->shirota, (comp + shet)->color, (comp + shet)->availability);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
}

void display()
{
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| �������� �������������  ||  ����-������ ||  ���������� ||  ������  ||   �����  ||  ������  || ����  ||  ������� ���������  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
}

PC poisk(PC* comp, int shet)
{
	char krit[10];
	int vibor, krit2, krit3, krit4, krit5, krit6, ukaz2 = 1;
	printf("�������� �������� ������\n");
	printf("1.�������� �������������\n");
	printf("2.����-������\n");
	printf("3.����������\n");
	printf("4.������\n");
	printf("5.����\n");
	printf("6.��������� � ��.\n");
	printf("7.�����\n");
	printf("8.������\n");
	scanf("%d", &vibor);
	if (vibor == 1)
	{
		printf("������� �������� �������������\n");
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
		printf("������� ����-������\n");
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
		printf("������� ���������� �������\n");
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
		printf("������\n");
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
		printf("����\n");
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
		printf("���������\n");
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
		printf("�����\n");
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
		printf("������\n");
		scanf("%f", &krit3);
		display();
		for (int c = 0; c < shet; c++)
		{
			if ((comp + c)->shirota == krit3)
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
		fprintf(stderr, "���� ������ ������� ��� ������ ��������� \n");
		system("pause");
		return -1;
	}
	else
	{
		fprintf(data, "-----------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(data, "|| �������� �������������  ||  ����-������ ||  ���������� ||  ������  || �����  || ������  || ����  ||  ������� ���������  ||\n");
		fprintf(data, "-----------------------------------------------------------------------------------------------------------------------------\n");
		for (c = 0; c < shet; c++)
		{
			fprintf(data, "||%s||%s|%s||%d||%f||%f||%s||%s||\n", comp[c].manufacturer, comp[c].formfactor, comp[c].typesize, comp[c].height, comp[c].dlina, comp[c].shirota, comp[c].color, comp[c].availability);
			fprintf(data, "--------------------------------------------------------------------------------------------------------------\n");
		}
		fclose(data);
		printf("������ ������� ��������");
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
		printf("���� ������� ������\n");
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
		printf("���� �� ������� �������\n");
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
	float dlina1, shirota1;
	for (int � = 1; � < shet; �++) {
		for (int j = 0; j < shet - �; j++)
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

				shirota1 = comp[j].shirota;
				comp[j].shirota = comp[j + 1].shirota;
				comp[j + 1].shirota = shirota1;

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
	puts("���������� �������������:");
	scanf("%d", &size);
	comp = (struct PC*)malloc(size * sizeof(PC));
	int ukaz = 1, vibor, viborr, compl;
	char nazvaniefaila[100];
	printf("________________________________________\n");
	printf("|             ���� ������              |\n");
	printf("|             ������ ��                |\n");
	printf("|�������: ����������� ������ ����������|\n");
	printf("|������:  ����-221                     |\n");
	printf("|______________________________________|\n");
	system("pause");
	while (ukaz)
	{
		system("cls");
		printf("�������� �������\n1.���� ��������.\n2.����� ��������\n3.����� ��������� �� ��������� ��������\n4.���������� ������\n5.������ ������ � ����\n6.������ ������ �� �����\n0.����� �� ���������\n");
		scanf("%d", &vibor);
		system("cls");
		switch (vibor)
		{
		case 1:
			printf("������� ���-�� ������� (������ 50)\n");
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
			printf("������� �������� �����\n");
			scanf("%s", &nazvaniefaila);
			vstavit(nazvaniefaila, comp, kolichestvo);
			break;

		case 6:
			printf("������� �������� �����\n");
			scanf("%s", &nazvaniefaila);
			prochitat(nazvaniefaila);
			system("pause");
			break;

		case 0:
			ukaz = 0;
			printf("���������� ������ ���������\n");
			break;

		default:
			puts("��������� ������� ������ ���������");

		}

	}
	free(comp);
	system("pause");
}
