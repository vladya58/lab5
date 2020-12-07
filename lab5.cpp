#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <iostream>
#pragma warning (disable : 4996)
int* num;
int** arr;

void BFS(int v, int a) {
	std::queue <int> qu;
	qu.push(v);
	num[v] = 1;
	while (!qu.empty()) {
		v = qu.front();
		printf(" %d  ", v + 1);
		qu.pop();
		for (int i = 0; i < a; i++) {
			if ((arr[v][i] == 1) && (num[i] == 0)) {
				qu.push(i);
				num[i] = 1;
			}
		}
	}
}

void main()

{
	int begin;
	int n;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	printf("Введите порядок массива - ");
	scanf("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}

	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				arr[i][j] = rand() % 2;
				arr[j][i] = arr[i][j];
			}
			else if (i == j) arr[i][j] = 0;
		}
	}

	printf(" ");

	for (int k = 1; k <= n; k++) printf(" %d", k);
	printf("\n   -----------\n");
	for (int i = 0; i < n; i++) {

		printf("%d |", i + 1);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("Введите вершину с которой хотите начать обход - ");
	scanf("%d", &begin);
	BFS(begin - 1, n);
	system("pause");
}
