#pragma once
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;


class QueueNode
{
public:
	QueueNode* next;
	int cost;
	int ticketNum;
	time_t arrivalTime;
	string orderName;
	QueueNode(int cost, string orderName, int ticketNum)
	{
		next = NULL;
		this->cost = cost;
		this->orderName = orderName;
		this->ticketNum = ticketNum;
		this->arrivalTime = time(NULL);
	}

};

class CustomerQueue
{
private:
	QueueNode* front;
	QueueNode* rear;
	int totalCount;
	static int totalRevenue;
	static int ticketCount;
public:
	CustomerQueue()
	{
		front = NULL;
		rear = NULL;
		totalCount = 0;
	}
	
	void customerMenu()
	{

		cout << "Customer Menu:\n";
		cout << "****************************Coffees*************************\n";
		cout << "                                R                             L\n";
		cout << "1.  Americano                   495                          550\n";
		cout << "2.  Vanilla Latte               525                          575\n";
		cout << "3.  Cafe Latte                  600                          700\n";
		cout << "4.  Cappuccino                  600                          700\n";
		cout << "5.  Matcha                       700                          800\n";
		cout << "6.  Espresso                    495                          550\n";
		cout << "****************************Iced Coffee**********************\n";
		cout << "7.  Iced Latte                  800                          900\n";
		cout << "8.  Vanilla Frappe              895                          995\n";
		cout << "9.  Caramel Frappe              950                          1000\n";
		cout << "10. Chocolate Frappe            800                          900\n";
		cout << "11. Strawberry Frappe           990\n";
		cout << "12. Matcha frappe                990\n";
	}
	void takeOrder()
	{
		int order;
		customerMenu();
		cin >> order;
		bool flag = true;
		bool flag1 = false;
		char reg;
		int ch;
		if ((order == 11 || order == 12))
		{
			while (flag1)
			{
				cout << "No large option is available for this\n";
				cout << "1. Do you want this item in regular?\n";
				cout << "2. Do not want this item.\n";
				cout << "3. Want to see menu again\n";
				flag1 = false;
			}
			cout << "No large option is avilable for this\n";
			cout << "1. Do you want this item in regular?\n";
			cout << "2. Do not want this item.\n";
			cout << "3. Want to see menu again\n";
			cin >> ch;
			if (ch == 1)
			{
				flag = true;
				ticketCount++;
			}
			else if (ch == 3)
			{
				customerMenu();
				cin >> order;
				cout << "Regular or Large:  \n";
				cin >> reg;
				ticketCount++;
			}
			else if (ch == 2)
			{
				flag = false;
			}
			else
			{
				cout << "Not a valid option.\n";
				flag1 = false;
			}
		}
		else if (order >= 1 && order <= 10)
		{
			cout << "Regular Or Large\n";
			cin >> reg;
			ticketCount++;
		}
		else
		{
			cout << "Wrong order\n";
			cout << "Choose again\n";
			cout << endl;
			return;
		}

		switch (order)
		{
		case 1:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(495, "Americano", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(550, "Americano", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 2:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(525, "Vanilla Latte", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(575, "Vanilla Latte", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order again\n";
				takeOrder();
			}
			break;
		case 3:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(600, "Cafe Latte", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(700, "Cafe Latte", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 4:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(600, "Capuccino", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(700, "Capuccino", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 5:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(700, "Macha", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')

			{
				addOrder(800, "Macha", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 6:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(495, "Espresso", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')

			{
				addOrder(550, "Espresso", ticketCount);
			}
			break;
		case 7:
			if (reg == 'R' || reg == 'r') {
				addOrder(800, "Iced Latte", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(900, "Iced Latte", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 8:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(895, "Vanlla Frappe", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(995, "Vanilla Frappe", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 9:
			if (reg == 'R' || reg == 'r')
			{
				addOrder(950, "Caramel Frappe", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')
			{
				addOrder(1000, "Caramel Frappe", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 10:
			if (reg == 'R' || reg == 'r')

			{
				addOrder(800, "Chocolate Frappe", ticketCount);
			}
			else if (reg == 'L' || reg == 'l')

			{
				addOrder(900, "Chocolate Frappe", ticketCount);
			}
			else
			{
				cout << "Not a ordinary size drink option enter order agian\n";
				takeOrder();
			}
			break;
		case 11:
			if (flag == true)
			{
				addOrder(990, "Strawberry Frappe", ticketCount);
			}
			break;
		case 12:
			if (flag == true)
			{
				addOrder(990, "Matcha Frappe", ticketCount);
			}

			break;
		default:
			cout << "No order\n";
		}

		cout << endl;
	}

	void addOrder(int cost, string orderName, int ticketNum)
	{

		QueueNode* nn = new QueueNode(cost, orderName, ticketNum);

		nn->next = NULL;
		if (front == NULL)
		{
			cout << "Your recipt\n";
			cout << "Product Name:   " << nn->orderName << endl;
			cout << "Ticket Number:  " << nn->ticketNum << endl;
			cout << "Total Cost:     " << nn->cost << endl;
			totalRevenue = totalRevenue + nn->cost;
			//For timely serve i am insertung the arrival time of the customer 
			char buffer[26];
			ctime_s(buffer, sizeof(buffer), &nn->arrivalTime);
			cout << "Arrival time:   " << buffer << endl;
			rear = nn;
			front = nn;


			totalCount++;
		}
		else
		{
			cout << "Your recipt\n";
			cout << "Product Name:   " << nn->orderName << endl;
			cout << "Ticket Number:  " << nn->ticketNum << endl;
			cout << "Total Cost:     " << nn->cost << endl;

			//For timely serve i am insertung the arrival time of the customer 
			char buffer[26];
			ctime_s(buffer, sizeof(buffer), &nn->arrivalTime);
			cout << "Arrival time:   " << buffer << endl;
			totalRevenue = totalRevenue + nn->cost;
			rear->next = nn;
			rear = nn;

			totalCount++;
		}
	}
	
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "No customers in the queue." << endl;
			return;
		}

		QueueNode* temp = front;
		int t = front->ticketNum;

			front = front->next;

			if (front == NULL)
			{
				cout << "All customers have been served.\n";
				rear = NULL;
			}

			delete temp;
			cout << "Served the customer with ticket number: " << t << endl;
	}

	// Helper function to check if the queue is empty
	bool isEmpty()
	{
		return front == NULL;
	}
	static int totalReveneueFunc()
	{
		return totalRevenue;
	}

	void display()
	{
		QueueNode* current = front;

		if (current)
		{
			cout << "************** Unserved orders: ****************" << endl;
		}

		while (current)
		{
			cout << "Order name:        " << current->orderName << endl;
			cout << "Total bill:        " << current->cost << endl;
			cout << "Ticket Number:     " << current->ticketNum << endl;

			char buffer[26];
			ctime_s(buffer, sizeof(buffer), &current->arrivalTime);
			cout << "Arrival Time:      " << buffer;
			cout << endl;
			current = current->next;
			cout << endl;
		}

	}
};
int CustomerQueue::ticketCount = 0;
int CustomerQueue::totalRevenue = 0;