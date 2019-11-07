#pragma once
#ifndef _UTILS_
#define _UTILS_

#include "config.h"
#include "command.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


template <typename T>
void print(vector<T> arr, int num = 10)
{
	cout << "Ket qua du lieu truy xuat: co " << arr.size() << " ban ghi \n";
	int i = 0;
	for (const auto& item : arr)
	{
		if (i >= num)
			break;
		cout << "\nBan ghi thu " << ++i << "\n";
		item->print();
	}
	cout << "\n";
	system("pause");
}

template <typename T>
void deletevector(vector<T> arr)
{
	int len = arr.size();
	for (int i = 0; i < len; i++)
	{
		delete arr[i];
		arr[i] = nullptr;
	}
	arr.clear();
}

void openNotepad();
int displaymenu();
vector<command> readfile();

#endif // !_UTILS_
