#pragma once
#include "QueuePriority.h"
#include <iostream>
using namespace std;

template <typename T, typename P>
QueuePriority<T,P>::QueuePriority(int size)
{
	maxSize = size;
	currentSize = 0;

	items = new T[maxSize];
	priorityArray = new P[maxSize];
}

template <typename T, typename P>
QueuePriority<T,P>::~QueuePriority()
{
	delete[] priorityArray;
	delete[] items;
}

template <typename T, typename P>
void QueuePriority<T,P>::Add(const T& item, const P& priority)
{
	if (!isFull()) {
		items[currentSize] = item;
		priorityArray[currentSize] = priority;
		currentSize++;
	}
}

template <typename T, typename P>
T QueuePriority<T,P>::Extract()
{
	if (!isEmpty()) {
		P maxPri = priorityArray[0];
		int maxPriPos = 0;
		for (int i = 0; i < currentSize; i++) {
			if (maxPri < priorityArray[i]) {
				maxPri = priorityArray[i];
				maxPriPos = i;
			}
		}
		T item = items[maxPriPos];
		for (int i = maxPriPos; i < currentSize - 1; i++) {
			items[i] = items[i + 1];
			priorityArray[i] = priorityArray[i + 1];
		} 
		currentSize--;
		return item;
	}
}

template <typename T, typename P>
void QueuePriority<T,P>::Clear()
{
	currentSize = 0;
	delete[] priorityArray;
	priorityArray = new P[maxSize] {0};
}

template <typename T, typename P>
bool QueuePriority<T,P>::isEmpty()
{
	return currentSize == 0;
}

template <typename T, typename P>
bool QueuePriority<T, P>::isFull()
{
	return currentSize == maxSize;
}

template <typename T, typename P>
int QueuePriority<T, P>::getCount()
{
	return currentSize;
}

template <typename T, typename P>
void QueuePriority<T, P>::Print()
{
	cout << "Current size: " << currentSize << endl;
	cout << "(priority|item): " << endl;
	for (int i = 0; i < currentSize; i++) {
		cout << "(" << priorityArray[i] << "|" << items[i] << ")";
		cout << endl;
	}
}
