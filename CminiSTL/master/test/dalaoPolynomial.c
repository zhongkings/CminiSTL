#pragma once
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "ZUCC_DataStructs.h"
#define points 20
#define row 15
#define column points
//points代表采样点数 
//row 和 column 代表图像的大小 
double poly1(double x);
double poly2(double x);
void One(double duration[][points]); //归一化运行时间 
double FindMax(double duration[][points]);
void PrintList(double duration[][points]);
void PrintGraph(double duration[][points]);

int dalaorun() {
	double x;
	scanf("%lf", &x);
	clock_t start, stop;
	double duration[2][points];
	int i, cnt;
	int times = 100000;


	printf(" 运行次数  秦九韶    普通\n");
	for (cnt = 0; cnt < points; ++cnt) {
		start = clock();
		for (i = 0; i < times; ++i) {
			poly1(x);
		}
		stop = clock();
		duration[0][cnt] = (double)(stop - start) / CLK_TCK;
		//      printf("%f\n", poly1(x));
		printf("| %d | %f |", i, duration[0][cnt]);

		start = clock();
		for (i = 0; i < times; ++i) {
			poly2(x);
		}
		stop = clock();
		duration[1][cnt] = (double)(stop - start) / CLK_TCK;
		//      printf("%f\n", poly2(x));
		printf(" %f |\n", duration[1][cnt]);

		times += 10000;
	}

	PrintGraph(duration);
	return 0;
}

double poly1(double x)
{
	int i;
	double sum = 0;
	for (i = 100; i >= 1; --i) {
		sum += 1 / (double)(i);
		sum *= x;
	}
	++sum;
	return sum;
}

double poly2(double x)
{
	double sum = 1;
	int i;
	for (i = 1; i <= 100; ++i) {
		sum += pow(x, i) / i;
	}
	return sum;
}

void PrintGraph(double duration[][points])
{
	One(duration);
	int graph[row][column];
	int i, j;
	for (i = 0; i < row; ++i) {
		for (j = 0; j < column; ++j) {
			graph[i][j] = 0;
		}
	}

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < points; ++j) {
			if (i == 0) {
				graph[(int)(duration[i][j] * row)][j] = 1;
			}
			else {
				graph[(int)(duration[i][j] * row)][j] = 2;
			}

		}
	}

	for (i = row - 1; i >= 0; --i) {
		for (j = 0; j < column; ++j) {
			if (graph[i][j] == 0) {
				printf("   ");
			}
			else if (graph[i][j] == 1) {
				printf(" * ");
			}
			else if (graph[i][j] == 2) {
				printf(" + ");
			}
		}
		putchar('\n');
	}
}

void One(double duration[][points])
{
	double max;
	max = FindMax(duration);

	int i, j;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < points; ++j) {
			duration[i][j] /= max;
		}
	}
}

double FindMax(double duration[][points])
{
	int i, j;
	double max = duration[0][0];
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < points; ++j) {
			if (duration[i][j] > max) {
				max = duration[i][j];
			}
		}
	}
	return max;
}

void PrintList(double duration[][points])
{
	int i, j;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < points; ++j) {
			printf("%f ", duration[i][j]);
		}
		putchar('\n');
	}
}