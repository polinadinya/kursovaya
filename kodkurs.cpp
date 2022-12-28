
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>

const int maxV = 100;
int i, j, n, variant, vari;
int GR[maxV][maxV], D[maxV][maxV];

void printM(int M[][maxV]) {
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}
void copy(int M[][maxV], int M1[][maxV]) {
	for (char i = 0; i < n; i++)
	{
		for (char j = 0; j < n; j++)
		{
			M1[i][j] = M[i][j];
		}
	}
}

void FU(int R[][maxV], int V)
{
	int k;
	copy(R, D);
	for (i = 0; i < V; i++) D[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
						D[i][j] = D[i][k] + D[k][j];
}

void orgraf(int R[][maxV]) {
	printf("Введите порядок орграфа:");
	std::cin >> n;
	if (n < 0)
	{
		printf("\n Введен недопустимый символ\n");
		printf("\n");
		printf("Введите порядок орграфа:");
		std::cin >> n;
	}
	if (n > 50)
	{
		printf("\n Введенное число превышающее допустимое значение(50) \n");
		printf("\n");
		printf("Введите порядок орграфа:");
		std::cin >> n;
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
				R[i][j] = rand() % 10;
		}
	}
}

void Save1(int R[][maxV]) {
	FILE* fl;
	fl = fopen("file.txt", "w");
	if ((fl = fopen("file.txt", "w")) == NULL)
		printf("Невозможно открыть/создать для записи файл 'file.txt'\n");
	else
	{
		fprintf(fl, "Матрица весов ребер: \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fprintf(fl, " %d ", R[i][j]);
			}
			fprintf(fl, "\n ");
		}
	}
	fclose(fl);
}

void Save2(int R[][maxV]) {
	FILE* fl;
	fl = fopen("file.txt", "a");
	if ((fl = fopen("file.txt", "a")) == NULL)
		printf("Невозможно открыть/создать для записи файл 'file.txt'\n");
	else
	{
		fprintf(fl, "Матрица кратчайших путей: \n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fprintf(fl, " %d ", R[i][j]);
			}
			fprintf(fl, "\n ");
		}

	}
	fclose(fl);
}


void vvod(int R[][maxV])
{
	printf("Введите порядок орграфа:");
	std::cin >> n;
	if (n < 0)
	{
		printf("\n Введен недопустимый символ\n");
		printf("\n");
		printf("Введите порядок орграфа:");
		std::cin >> n;
	}
	if (n > 50)
	{
		printf("\n Введенное число превышающее допустимое значение(50) \n");
		printf("\n");
		printf("Введите порядок орграфа:");
		std::cin >> n;
	}
	printf("\nВведите матрицу смежности:\n");

	for (int i = 0; i < n; ++i) { 
		R[i][j] = (int)malloc(n * sizeof(int)); }
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &R[i][j]);
		}
	}
}

void vvesti(int R[][maxV]) {
	char vvesti[50];
	FILE* fil;
	scanf("%s", &vvesti);
	fil = fopen(vvesti, "r");
	if (fil == NULL)
	{
		printf("Не удалось открыть файл!\n");
		return;
	}
	fscanf(fil, "%d", &n);
	R[i][j] = (int)malloc(n * sizeof(int));
	for (int i = 0; i < (n); ++i) {
		R[i][j] = (int)malloc(sizeof(int) * (n));
	}
	for (int i = 0; i < (n); ++i) {
		for (int j = 0; j < (n); ++j)
		{
			fscanf(fil, "%d", &R[i][j]);
		}
	}
	fclose(fil);
	return;
}

void Menu() {
	system("cls"); 
	printf("Что вы хотите сделать?\n");
	printf("1. Начать алгоритм\n");
	printf("2. Сохранить в файл\n");
	printf("3. Ввести матрицу самостоятельно\n");
	printf("4. Считать с файла\n");
	printf("5. Выход\n");
	printf(">");
}

int get_vari(int count) {
	int vari;
	char s[100];
	scanf("%s", s);
	while (sscanf(s, "%d", &vari) != 1 || vari < 1|| vari > count) {
		printf("Введен недопустимый символ. Ваш ответ: ");
		scanf("%s", s);	
	}	
	return vari;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	do {
		Menu(); 
		vari = get_vari(5); 
		switch (vari) {
		case 1:
			printf("Алгоритм Флойда \n");
			printf("\n");
			printf("Создание матрицы динамически \n");
			orgraf(GR);
			std::cout << "Матрица весов ребер:\n";
			printM(GR);
			std::cout << "Матрица кратчайших путей:\n";
			FU(GR, n);
			printM(D);
			break;

		case 2:
			printf("Соранить? Ваш ответ (1 - да, 2 - нет):");
			std::cin >> variant;
			if (variant != 1 && variant != 2) {
				printf("Введен недопустимый символ. Введите ваш ответ: ");
				std::cin >> variant;
			}
			else {
				if (variant == 1) {
					Save1(GR);
					Save2(D);
					std::cout << "Сохранение выполнено успешно.\n";
				}
				break;
			}
		case 3:
			printf("Алгоритм Флойда \n");
			printf("\n");
			printf("Создание матрицы динамически \n");
			vvod(GR);
			std::cout << "Матрица кратчайших путей:\n";
			FU(GR,n);
			printM(D);
			break;

		case 4:
			printf("Алгоритм Флойда \n");
			printf("\n");
			printf("В файле должна быть информация о порядке орграфа, ниже о матрице смежности!!Пример ввода: privet.txt\nВведите название файла: ");
			vvesti(GR);
			std::cout << "Матрица весов ребер:\n";
			printM(GR);
			std::cout << "Матрица кратчайших путей:\n";
			FU(GR,n);
			printM(D);
			break;
		}
		system("pause");
		system("cls");
	} while (vari != 5);
	//Clear(root);
	return 0;
}
