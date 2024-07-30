#pragma once
#include <iostream>
#include <string>
using namespace std;


class BeansBag
{
public:
	string supplier;
	int bagno;
	BeansBag* next;

public:
	BeansBag()
	{
		next = NULL;
	}
};

class Stack
{
	int counter;
	BeansBag* head;

public:
	Stack()
	{
		counter = 0;
		head = NULL;
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void push(string s)
	{
		BeansBag* n = new BeansBag;
		n->bagno = ++counter;
		n->supplier = s;

		if (isEmpty())
		{
			head = n;
			return;
		}
		n->next = head;
		head = n;
	}

	string pop()
	{
		if (isEmpty())
		{
			return "Empty";
		}
		string s = head->supplier;
		BeansBag* temp = head;
		head = head->next;
		delete temp;
		--counter;
		return s;
	}

	void display()
	{
		if (isEmpty())
		{
			return;
		}
		BeansBag* temp = head;
		while (temp != NULL)
		{
			cout << "Bag " << temp->bagno << " from " << temp->supplier << endl;
			temp = temp->next;
		}
	}

	int peek()
	{
		return head->bagno;
	}

	void beansMenu()
	{
		int num;
		string s;
		cout << "Enter number of bean bags in this batch: ";
		cin >> num;
		cout << "Enter name of supplier: ";
		cin >> s;

		string* arr = new string[counter];
		int n = counter;
		while (!isEmpty())
		{
			arr[counter] = pop();
		}

		for (int i = 0; i < num; i++)
		{
			push(s);
		}

		for (int i = 0; i < n; i++)
		{
			push(arr[i]);
		}
		cout << "Batch added succesfully." << endl;
	}
};
