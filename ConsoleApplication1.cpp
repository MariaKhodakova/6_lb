#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
int N, j, i, m ;
int* dist; // дистанция
bool* visited = new bool[m]; //выделяем память под булевы значения для матрицы
int** graph;
queue<int>Q; //очередь
int start;

void BFSD(int vertex, int N, int** graph) { // алгоритм

	Q.push(vertex); //вносим в очередь вершину
	dist[vertex] = 0; // обозначаем расстояние до нее
	while (!Q.empty()) {
		vertex = Q.front(); // вершину переносим в начало очереди
		printf(" %d", vertex + 1);
		Q.pop(); // выносим из очереди
		for (int i = 0; i < N; i++) {
			if ((graph[vertex][i] == 1) && (dist[i] == -1)) {
				Q.push(i);//вносим удовлетворяющую условию вершину в очередь
				dist[i] = dist[vertex] + 1;//считаем дистанцию до вершины
			}
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	int min = 10000;
	printf("Ведите размер матрицы: ");
	scanf_s("%d", &N);

	srand(time(NULL));
	graph = new int* [N];//выделяем память под матрицу
	dist = new int[N]; // выделяем память для значений дистанции вершин друг от друга

	for (int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}
	for (int i = 0; i < N; i++) { //задаем изначальные значения дистанций
		dist[i] = -1;
	}

	printf("\n");

	for (i = 0; i < N; ++i) //заполняем матрицу
	{
		for (j = i; j < N; ++j)
		{
			graph[i][j] = graph[j][i] = rand() % 2;
			graph[i][i] = graph[j][j] = 0; // чтобы петля(узел) не создавалась
		}

	}
	printf("   ");

	for (j = 0; j < N; j++)
	{
		printf("%4d ", j + 1); //горизонтальные нумерация сверху матрицы
	}
	printf("\n\n");
	for (i = 0; i < N; i++) {

		printf(" %d ", i + 1); // вертикальная нумерация слева матрицы

		for (j = 0; j < N; j++)
		{
			printf("%4d ", graph[i][j]);
		}
		printf("\n\n");
	}

	printf("\n Введите начальную вершину: ");
	scanf_s("%d", &start);
	printf(" Результат обхода в ширину: ");
	BFSD(start - 1, N, graph);
	printf("\n\n Вершины: ");
	printf("   ");
	for (int i = 1; i <= N; i++) {
		printf(" %d ", i);
	}
	printf("\n Расстояние: ");
	for (int i = 0; i < N; i++) {
		printf(" %d ", dist[i]);
	}
	printf("\n\n");
}
