#pragma once

template <typename T, typename P = int>
class QueuePriority
{
	T* items;
	P* priorityArray;
	int maxSize;
	int currentSize;
public:
	QueuePriority(int size);
	~QueuePriority();

	void Add(const T& item, const P& priority = 0);
	T Extract();
	void Clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void Print();
};

#include "QueuePriority.cpp"

