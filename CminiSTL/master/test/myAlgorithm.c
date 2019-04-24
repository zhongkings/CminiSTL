#pragma once
#include "ZUCC_DataStructs.h"

int BinarySearch(void *obj, int value) {
	int *arr = (int*)obj;

	int low = 1;
	int high = arr[0] - 1;
	int mid = (low + high) / 2;
	while (low != high) {
		if (arr[mid] == value)
			return mid;
		else if (arr[mid] > value) {
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else {
			low = mid + 1;
			mid = (low + high) / 2;
		}
	}

	return -1;
}