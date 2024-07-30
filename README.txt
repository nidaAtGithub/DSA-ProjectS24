************ COFFEE SHOP MANAGEMENT SYSTEM ************

The project is designed in two modules, an employee menu and a manager system. The whole project makes use of four data structures: a heap for storing milk expiry dates, a stack for storing beans, a queue for holding orders, and a binary search tree to store employee data and the staff hierarchy. 

How to use the system:

Employee menu:
	The employee menu presents the following options:
	1. Add an order to queue.
	2. Serve an order.
	3. Add new batch of beans.
	4. Add new batch of milk.
	5. View pantry.
	6. View customer queue.
	7. Return to main menu.

		1: A menu is opened for the customer to choose their drink and its size. A ticket is then generated and the order is pushed to the queue.
		2: If there are orders in the queue, the pantry is checked to see if both milk and beans are available. If there are, a milk is popped off the heap and a bean bag is popped off the stack to make a coffee. The order at the front of the queue is then dequeued and served. If there are not sufficient ingredients, a notice is sent to the employee and the order remains unserved.
		3: Allows the user to add a new batch of beans. If there are beans from a previous batch still in the stack, those beans are moved to the top.
		4: Allows the user to add a new batch of milk, placing the packs with the shortest expiry date at the top.
		5: Shows the beans stack and the milk heap.
		6: Shows the unserved orders in the queue.
		7: Returns to the menu that allows user to pick between employee and manager menu.

Manager menu:
	The manager menu requires the manager to establish their account. It then presents the following options:
	1. Find employee by id for further actions like adding salary, bonus, and supervision.
	2. Display details of all employees.
	3. Remove the data of any employee.
	4. Insert new Employee.
	5. See the total Revenue of the day.
	6. Move to main menu.

		1: Requires user to enter a valid employee ID. Then it presents the following menu:
		1. Update salary.
 		2. Add bonus.
 		3. View staff members under supervision of this employee.
 		4. Go to previous menu.

			1 and 2: Updates salary/ bonus.
			3: Displays descendants of the node.
			4: Returns to manager menu.

		2: Displays entire tree in order.
		3: Deletes an employee based on valid ID.
		4: Adds a new employee.
		5: Returns to the menu that allows user to pick between employee and manager menu.