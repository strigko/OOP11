#pragma once
template <typename T, typename P = int>
class PrinterQueue
{
	T* items;
	P* priorityArray;
	int maxSize;
	int currentSize;
public:
	PrinterQueue(int size);
	~PrinterQueue();

	void Add(const T& item, const P& priority = 0);
	T Extract();
	void Clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void Print() const;
};
