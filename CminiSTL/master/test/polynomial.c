#pragma once
#include "ZUCC_DataStructs.h"
#define vaEND -0.1314
static double Mypow(double value, int power) {
	double result = value;
	while (--power)
		result *= value;

	return result;
}

double fun1(int n, double arr[], double x) {
	double p = arr[0];
	for (int i = 1; i <= n; i++) {
		p += (arr[i] * Mypow(x, i));
	}

	return p;
}

double fun2(int n, double arr[], double x) {
	double p = arr[n];
	for (int i = n; i > 0; i--) {
		p = arr[i - 1] + (x * p);
	}

	return p;
}