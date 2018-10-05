/*
����㷨������L�͵����ã�������ԭ������Ŀռ�ʵ�����á�
*/
#include<windows.h>
#include<iostream>
#include<queue>
using namespace std;
class node {
public:
	int val;
	node * next;
};
node * turn(node * src) {
	if (src == nullptr || src->next == nullptr) {
		return src;
	}
	node * first;
	node * sec;
	node * third;
	first = src;
	sec = first->next;
	third = sec->next;
	src->next = nullptr;
	while (sec!= nullptr) {
		sec->next = first;
		first = sec;
		sec = third;
		if (third == nullptr) {
			continue;
		}
		third = third->next;
	}

	return first;
}

node * turn2(node * src) {
	if (src == nullptr || src->next == nullptr) {
		return src;
	}
	node* first = NULL;
	node * sec = src;
	while (sec != nullptr) {
		node * third = sec->next;
		sec->next = first;
		first = sec;
		sec = third;
	}
	return first;
}
int main() {
	DWORD start_time = GetTickCount();
	node * src;
	node * tmp;
	src = new node;
	src->val = 0;
	tmp = src;
	for (int i = 1; i<10; i++) {
		node * temp = new node;
		temp->val = i;
		temp->next = nullptr;
		tmp->next = temp;
		tmp = temp;

	}
	node * point = src;
	while (point != nullptr) {
		cout << point->val << " ->";
		point = point->next;
	}
	cout << endl;
	src = turn2(src);
	node * point2 = src;
	while (point2!= nullptr) {
		cout << point2->val << " ->";
		point2 = point2->next;
	}
	DWORD end_time = GetTickCount();
	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
	int end;
	cin >> end;
	return 0;
}