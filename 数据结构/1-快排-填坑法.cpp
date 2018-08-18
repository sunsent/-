#include<iostream>
using namespace std;

int partition(int arr[], int start_index, int end_index) {

	// �ӵ�λ�ã���ʼ����pivot��λ��
	int index = start_index;
	//��һ��Ԫ��Ϊ��׼Ԫ��
	int pivot = arr[start_index];
	int left = start_index;
	int right = end_index;

	while (left < right) {
		while (left < right) {
			if (pivot > arr[right]) {
				arr[left] = arr[right];
				left++;
				break;
			}
			//��׼Ԫ��С���ұߵıȽϵ�Ԫ��
			right--;
		}
		while (left < right) {
			if (arr[left] > pivot) {
				arr[right] = arr[left];
				right--;
				break;
			}
			left++;
		}

	}
	index = left;
	arr[index] = pivot;
	return index;
}

void quick_sort(int arr[], int start_index, int end_index) {
	if (start_index >= end_index) {
		return;
	}
	int  mid_index = partition(arr, start_index, end_index);
	quick_sort(arr, start_index, mid_index - 1);
	quick_sort(arr, mid_index + 1, end_index);	
}


int main() {
	int arr[8] = {4,5,3,8,1,2,7,6};
	quick_sort(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i]<<endl;
	}
	int end;
	cin >> end;
	return 0;
}