#pragma once
template <typename T>
class Queue
{
	int size;
	T* arr;
	int current_size;
public:
	Queue(int size);
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	~Queue();

	void Print() const;
	void Clear();
	T Dequeue();
	void Enqueue(const T& value);
	bool isEmpty() const;
	int getSize() const;
	void MoveFront();
};
