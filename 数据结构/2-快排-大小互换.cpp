#include<iostream>
#include<stack>
using namespace std;

int partition(int arr[], int start_index, int end_index) {
	//第一个元素为基准元素pivot
	int pivot = arr[start_index];
	int left = start_index;
	int right = end_index;
	while (left < right) {
		//
		while (left < right&&arr[right] >pivot) {
			right--;
		}
		//必须是<=,这样才能保证pivot在最后与指针重合点交换
		while (left < right&&arr[left] <= pivot) {
			left++;
		}
		//交换left和right指向的元素
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	//pivot和指针重合点交换,指针重合点一定<=pivot
	arr[start_index] = arr[right];
	arr[right] = pivot;
	return right;
}
void quick_sort(int arr[], int start_index, int end_index) {
	if (start_index >= end_index) {
		return;
	}
	int mid_index = partition(arr, start_index, end_index);
	quick_sort(arr, start_index, mid_index - 1);
	quick_sort(arr, mid_index + 1, end_index);
}
//非递归快排
void quick_sort2(int arr[], int start_index, int end_index) {
	if (start_index >= end_index) {
		return;
	}
	int indexs[2] = { start_index ,end_index };
	stack<int*> index_stack;
	index_stack.push(indexs);
	while (!index_stack.empty()) {
		int * index_temp; 
		// 栈顶元素出栈，得到起止下标
		index_temp = index_stack.top();
		int start_index_tmp = index_temp[0];
		int end_index_tmp= index_temp[1];
		index_stack.pop();
		// 根据基准元素分成两部分, 把每一部分的起止下标入栈
		int mid_index = partition(arr, start_index_tmp, end_index_tmp);
		if (mid_index - 1 > start_index_tmp) {
			int temp[2];
			temp[0] = start_index_tmp;
			temp[1] = mid_index - 1;
			index_stack.push(temp);
		}
		if (mid_index + 1 < end_index_tmp) {
			int temp[2];
			temp[0] = mid_index + 1;
			temp[1] = end_index_tmp;
			index_stack.push(temp);
		}
	}
}
int main() {
	int arr[8] = { 4,5,3,8,1,2,7,6 };
	quick_sort2(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << endl;
	}
	int end;
	cin >> end;
	return 0;
}