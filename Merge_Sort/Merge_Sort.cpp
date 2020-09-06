#include <iostream>
#include <ctime>

void swap(int* arr, int idx1, int idx2);
int randInt(int upperBound);
void shuffleArr(int* arr, int length);
void printArr(int* arr, int length);
int** splitArr(int* arr, int midPoint, int length);
int* mergeSortedArr(int* arr_1, int len_1, int* arr_2, int len_2);
int* mergeSort(int* arr, int length);

static int temp{ 0 };

int main() {
	const int size = 1000;
	int* arr = new int[size];
	
	
	for (int i = 0; i < size; i++) {
		arr[i] = (i + 1);
	}

	shuffleArr(arr, size);

	int* sorted_arr = mergeSort(arr, size);
	printArr(sorted_arr, size);

	delete[] sorted_arr;
	delete[] arr;
	return 0;
}

int* mergeSort(int* arr, int length) {
	if (length <= 1) {
		return arr;
	}
	int midPoint = int(std::floor(length / 2));
	int** arr_col = splitArr(arr, midPoint, length);
	int* left = mergeSort(arr_col[0], midPoint);
	int* right = mergeSort(arr_col[1], (length - midPoint));
	delete[] arr_col;
	return mergeSortedArr(left, midPoint, right, (length - midPoint));
}

int** splitArr(int* arr, int midPoint, int length) {
	std::cout << "\nCount = " << ++temp;
	int** arr_col = new int*[2];
	int* leftArr = new int[midPoint];
	int* rightArr = new int[length - midPoint];
	for (int i = 0; i < midPoint; i++) {
		leftArr[i] = arr[i];
	}
	for (int j = midPoint; j < length; j++) {
		rightArr[j - midPoint] = arr[j];
	}
	arr_col[0] = leftArr;
	arr_col[1] = rightArr;
	return arr_col;
}

int* mergeSortedArr(int* arr_1, int len_1, int* arr_2, int len_2) {
	int* mergedArr = new int[len_1 + len_2];
	int i{ 0 }, j{ 0 }, k{ 0 };
	while (i < len_1 && j < len_2) {
		std::cout << "\nCount = " << ++temp;
		if (arr_1[i] < arr_2[j]) {
			mergedArr[k] = arr_1[i];
			i++;
		} else {
			mergedArr[k] = arr_2[j];
			j++;
		}
		k++;
	}

	if (i == len_1 && j == len_2) return mergedArr;
	if (i == len_1) {
		while (j < len_2) {
			mergedArr[k] = arr_2[j];
			j++;
			k++;
		}
	} else {
		while (i < len_1) {
			mergedArr[k] = arr_1[i];
			i++;
			k++;
		}
	}
	delete[] arr_1, arr_2;
	return mergedArr;
}

void printArr(int* arr, int length) {
	std::cout << "\n[";
	for (int i = 0; i < length; i++) {
		i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
	}
	std::cout << "]\n";
}

int randInt(int upperBound) {
	int random = std::rand() % upperBound + 1;
	return random;
}

void shuffleArr(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		swap(arr, i, randInt(length - 1));
	}
}

void swap(int* arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}