/*
设计算法将两个递增有序的带头结点的单链表A、B合并为一个递增/减有序的带头结点的单链表，
并要求算法的时间复杂度为两个表长之和的数量级
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
//将scr2片段链表插入src1中
node * combine(node  * src1, node * src2) {
	node * first1 = src1;
	node * sec1 = src1->next;
	node * first2 = src2;
	node * sec2 = src2->next;
	while (sec1 != nullptr&&sec2 != nullptr) {
		if (sec1->val > sec2->val) {
			first1->next = sec2;
			while (sec2 != nullptr&&sec1->val >= sec2->val) {
				sec2 = sec2->next;
				first2 = first2->next;
			}
			first1 = first2;
			first2->next = sec1;
		}
		if (sec1 == nullptr && sec2 == nullptr) {
			break;
		}
		if (sec1->val <= sec2->val) {
			while (sec1 != nullptr&&sec1->val < sec2->val) {
				sec1 = sec1->next;
				first1 = first1->next;

			}
			first2 = sec2;
			sec2 = sec2->next;
			first1->next = first2;
			first1 = first1->next;
			first2->next = sec1;
			first2 = new node;
			first2->next = sec2;
			//1的尾巴小于2的剩余片段,将2的剩余片段加到1的尾巴后
			if (sec1 == nullptr&&sec2 != nullptr) {
				first1->next = sec2;
			}
		}
	}
	return src1;
}

int main() {
	DWORD start_time = GetTickCount();
	node * src1;
	node * tmp;
	src1 = new node;
	tmp = src1;
	for (int i = 1; i<10; i++) {
		node * temp = new node;
		temp->val = i;
		temp->next = nullptr;
		tmp->next = temp;
		tmp = temp;

	}
	node * src2;
	node * tmp2;
	src2 = new node;
	tmp2 = src2;
	for (int i = 1; i<10; i++) {
		node * temp = new node;
		temp->val = i+5;
		temp->next = nullptr;
		tmp2->next = temp;
		tmp2 = temp;

	}
	//--
	cout << "src1: ";
	node * point = src1->next;
	while (point != nullptr) {
		cout << point->val << " ->";
		point = point->next;
	}
	cout << endl;
	cout << "src2: ";
	node * point2 = src2->next;
	while (point2 != nullptr) {
		cout << point2->val << " ->";
		point2 = point2->next;
	}
	cout << endl;
	cout << "combine: ";
	combine(src1, src2);
	node * point3 = src1->next;
	while (point3 != nullptr) {
		cout << point3->val << " ->";
		point3 = point3->next;
	}
	DWORD end_time = GetTickCount();
	cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
	int end;
	cin >> end;
	return 0;
}