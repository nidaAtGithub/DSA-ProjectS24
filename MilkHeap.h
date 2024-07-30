#pragma once
#include <iostream>
using namespace std;

class Heap
{
	int* arr;
	int size;
	int counter;

public:

	Heap(int s = 30)
	{
		counter = 0;
		size = s;
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = -1;
		}
	}

	bool isEmpty()
	{
		return counter == 0;
	}

	bool isFull()
	{
		return counter == size-1;
	}

	void swap(int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void minHeapify(int index)
	{
		if (index > 0 && index < size)
		{
			if (arr[index] == -1)
			{
				return;
			}
			int smallest = index;

			if (arr[index * 2] < arr[smallest] && index * 2 <= counter)
			{
				smallest = index * 2;
			}
			if (arr[index * 2 + 1] < arr[smallest] && (index * 2) + 1 <= counter)
			{
				smallest = index * 2 + 1;
			}

			if (smallest != index)
			{
				swap(index, smallest);
				minHeapify(smallest);
			}
		}
	}

	void insertion(int d)
	{
		if (isFull())
		{
			cout << "Fridge is full!" << endl;
			return;
		}
		if (d <= 0)
		{
			cout << "Sorry, we cannot insert expired milk." << endl;
			return;
		}
		++counter;
		arr[counter] = d;
		int index = counter;

		while (index != 1 && arr[index / 2] > arr[index])
		{
			swap(index, index/2);
			index /= 2;
		}
	}

	void display()
	{
		int max = 1;
		int l = 0;

		for (int i = 1; i <= counter; i++)
		{
			for (int j = 0; j <= counter/max; j++)
			{
				cout << " ";
			}
			cout << arr[i];
			++l;
			if (l == max)
			{
				max *= 2;
				l = 0;
				cout << endl;
			}
		}
	}

	int deletion()
	{
		if (isEmpty())
		{
			return -1;
		}
		swap(1, counter);
		--counter;
		minHeapify(1);
		return arr[counter + 1];
	}

	void MilkMenu()
	{
		int num = -1;
		int val = -1;
		cout << "Enter the number of milk cartons you wish to add to fridge." << endl;
		cout << "Fridge currently has capacity for " << size - counter << " milks." << endl;

		cin >> num;

		if (counter + num > size)
		{
			num -= (counter + num) - size;
			cout << "Fridge will only take " << num << " more cartons." << endl;
		}

		cout << "Enter number of days until expiry for each carton." << endl;

		for (int i = 0; i < num; i++)
		{
			cin >> val;
			insertion(val);
		}
	}
};