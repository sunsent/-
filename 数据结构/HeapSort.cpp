/*堆排序,大根堆
*/
#include<iostream>
using namespace std;

//整理堆
void rebuildHeap(int * arr, int len, int start_index) {
	int index = 0;
	int max = 0;
	while ((start_index << 1) + 2 < len) {
		index = start_index;
		max = arr[start_index];
		if (max <arr[(start_index << 1) + 1]) {
			index = (start_index << 1) + 1;
			max = arr[(start_index << 1) + 1];
		}
		if ((start_index << 1) + 2 < len&&arr[(start_index << 1) + 2] > max) {
			index = (start_index << 1) + 2;
			max = arr[index];
		}
		if (index == start_index) {
			break;
		}
		arr[index] = arr[start_index];
		arr[start_index] = max;
		start_index = index;
	}
}
//创建堆
void createHeap(int * arr, int len) {
	int index = 0;
	int max = 0;
	for (int i = (len >> 1) - 1; i >= 0; i--) {
		index = i;
		max = arr[i];
		if (max <arr[(i << 1) + 1]) {
			index = (i << 1) + 1;
			max = arr[(i << 1) + 1];
		}
		if ((i << 1) + 2 < len&&arr[(i << 1) + 2] > max) {
			index= (i << 1) + 2;
			max = arr[index];
		}
		if (index != i) {
			arr[index] = arr[i];
			arr[i] = max;
			rebuildHeap(arr, len, index);
		}
	}
}

void heapSort(int * arr, int len) {
	createHeap(arr, len);
	for (int i = len -1 ; i >= 0; i--) {
		cout << "当前堆: ";
		for (int a=0;a<10;a++) {
			cout <<*( arr+a) << "  ";
		}
		cout << endl;
		int max = arr[0];
		arr[0] = arr[i];
		arr[i] = max;
		rebuildHeap(arr, i, 0);
	}
}
int main() {
	int arr[10] = { 5,4,17,13,15,12,10,7,11,9 };
	heapSort(arr, 10);
	int a = 6;
	a << 1;
	cout << a << endl;
	for (int i : arr) {
		cout << i<<"  ";
	}
	int end;
	cin >> end;
	return 0;
}