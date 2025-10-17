#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
Queue<T>::Queue(int size)
{
	this->size = size;
	arr = new T[size];
	current_size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	this->size = other.size;
	arr = new T[other.size];
	for (int i = 0; i < other.current_size; i++) {
		arr[i] = other.arr[i];
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this == &other) return *this;
	if (arr != nullptr) delete[] arr;
	this->size = other.size;
	arr = new T[other.size];
	for (int i = 0; i < other.current_size; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	delete[] arr;
}

template <typename T>
void Queue<T>::Print() const
{
	cout << "Queue: ";
	for (int i = 0; i < current_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Queue<T>::Clear()
{
	current_size = 0;
}

template <typename T>
T Queue<T>::Dequeue()
{
	T first = arr[0];

	for (int i = 0; i < current_size - 1; i++) {
		arr[i] = arr[i + 1];
	}

	arr[current_size - 1] = first;
	return first;
}

template <typename T>
void Queue<T>::Enqueue(const T& value)
{
	arr[current_size++] = value;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return current_size == 0;
}

template <typename T>
int Queue<T>::getSize() const
{
	return current_size;
}

template <typename T>
void Queue<T>::MoveFront()
{
	T first = arr[0];
	for (int i = 0; i < current_size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[current_size - 1] = first;
}