#include <iostream>
#include <string>
using namespace std;
#include "BeansStack.h"
#include "MilkHeap.h"
#include "CustomerQueue.h"
#include "Staff.h"

void viewPantry(Heap* heap, Stack* stack)
{
	if (stack->isEmpty())
	{
		cout << "No beans in pantry." << endl;
	}
	else
	{
		cout << "Beans: " << endl;
		stack->display();
	}

	if (heap->isEmpty())
	{
		cout << "No milk in pantry." << endl;
	}
	else
	{
		cout << "Milk expiry dates: " << endl;
		heap->display();
	}
	
}

void serveOrder(CustomerQueue* queue, Heap* heap, Stack* stack)
{
	if (queue->isEmpty())
	{
		cout << "No orders to serve!" << endl;
		return;
	}

	int milk = heap->deletion();
	if(milk== -1)
	{
		cout << "Pantry has run out of milk! Please add a new batch first." << endl;
		return;
	}

	string beans = stack->pop();

	if (beans == "Empty")
	{
		cout << "Pantry has run out of beans! Please add a new batch first." << endl;
		return;
	}

	cout << "Used " << beans << " beans and milk with expiry date " << milk << " to make coffee." << endl;
	queue->dequeue();
}

void employeeMenu(CustomerQueue* queue, Heap* heap, Stack* stack)
{
	int option = 0;

	while(option != 7)
	{
		cout << endl << "What would you like to do?" << endl;
		cout << "1. Add an order to queue." << endl;
		cout << "2. Serve an order." << endl;
		cout << "3. Add new batch of beans." << endl;
		cout << "4. Add new batch of milk." << endl;
		cout << "5. View pantry." << endl;
		cout << "6. View customer queue." << endl;
		cout << "7. Return to main menu." << endl;

		cin >> option;

		switch (option)
		{
			case 1: queue->takeOrder(); break;
			case 2: serveOrder(queue, heap, stack); break;
			case 3: stack->beansMenu(); break;
			case 4: heap->MilkMenu(); break;
			case 5: viewPantry(heap, stack); break;
			case 6: queue->display(); break;
			case 7: return;
			default: cout << "Please enter a valid value." << endl;
		}

	}
}

void mainFunc(BinaryTree* staff, CustomerQueue* queue, Heap* heap, Stack* stack)
{
	int choice = 0;

	while (choice != 3)
	{
		cout << "What would you like to do today?" << endl;
		cout << "1. Open employee menu.\n";
		cout << "2. Open manager menu.\n";
		cout << "3. Exit program.\n";

		cin >> choice;
		if (choice == 1)
		{
			employeeMenu(queue, heap, stack);
		}
		else if (choice == 2)
		{
			staff->managerMenu();
		}
		else if (choice == 2)
		{
			return;
		}
	}
}

void intro()
{
	cout << endl;
	cout << "                                 ||    ||    ||" << endl;
	cout << "                                  ||    ||    ||" << endl;
	cout << "                                 ||    ||    ||" << endl;
	cout << "                                  ||    ||    ||" << endl;
	cout << endl;
	cout << "                              ||||||||||||||||||||||" << endl;
	cout << "                              ||                ||||||" << endl;
	cout << "                              ||                ||  ||" << endl;
	cout << "                              ||                ||  ||" << endl;
	cout << "                              ||                ||||||" << endl;
	cout << "                                ||            ||" << endl;
	cout << "                            |||||||||||||||||||||||||" << endl;
	cout << "                             ||                   ||" << endl;
	cout << "                              ||||||||||||||||||||" << endl;
	cout << endl << endl;

	cout << "Welcome to the Coffee Shop Management System!" << endl;
}

int main()
{
	BinaryTree* staff = new BinaryTree;
	CustomerQueue* queue = new CustomerQueue;
	Heap* heap = new Heap;
	Stack* stack = new Stack;

	intro();
	mainFunc(staff, queue, heap, stack);
}
