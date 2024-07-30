#pragma once
#include <iostream>
#include <string>
#include "CustomerQueue.h"
using namespace std;

class TreeNode
{
public:
    TreeNode* right;
    TreeNode* left;

    int empId;
    int empSalary;
    int empBonus;
    string firstName;
    string lastName;
    string empPhone;
    string gender;
    string email;
    string password;

    TreeNode(int empId, int empSalary, int empBonus, string firstName, string secondName, string empPhone, string email, string gender)
    {
        right = NULL;
        left = NULL;
        this->empId = empId;
        this->empSalary = empSalary;
        this->empBonus = empBonus;
        this->empPhone = empPhone;
        this->firstName = firstName;
        this->lastName = secondName;
        this->email = email;
        this->gender = gender;
    }
    TreeNode(string firstName, string lastName, string phoneNum, string email, string password, string gender) //manager
    {
        right = NULL;
        left = NULL;
        this->empId = 10;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->password = password;
        this->gender = gender;
        this->empSalary = 100000;
        this->empPhone = phoneNum;
        this->empBonus = 0;
    }
};

class BinaryTree
{
    TreeNode* root;
    CustomerQueue customer;
  
public:
    BinaryTree()
    {
        root = NULL;
    }

    void managerMenu()
    {
        cout << "Make your account: " << endl;
        string name1, name2, phoneNum, mail, g, pass;
        cout << "Enter your first name: ";
        cin >> name1;
        cout << "Enter your last name: ";
        cin >> name2;
        cout << "Enter your phone number: ";
        cin >> phoneNum;
        while (!isValidPhone(phoneNum)) {
            cout << "Invalid phone number length, enter again: ";
            cin >> phoneNum;
        }
        cout << "Enter your email: ";
        cin >> mail;
        cout << "Your gender: ";
        cin >> g;
        cout << "Enter your password: ";
        cin >> pass;

        TreeNode* newNode = new TreeNode(name1, name2, phoneNum, mail, pass, g);
        root = newNode;

       
        insert(3, 11000, 0, "Aneeqa", "Zahid", "03215611221", "aneeqaZahid@cafe.com", "Female");
        insert(1, 10000, 0, "Zaid", "Ali", "03218910112", "zaidAli@cafe.com", "Male");
        insert(2, 7000, 2000, "Maria", "Saeed", "03871243910", "mariaSaeed@cafe.com", "Female");
        insert(4, 8000, 0, "Aimen", "Saleem", "03432412981", "aimenSaleem@cafe.com", "Female");
        insert(6, 20000, 0, "Ali", "Ahmad", "03004007009", "aliAhmad@cafe.com", "Male");
        insert(5, 7000, 3000, "Mustafa", "Khan", "03800900123", "mustafaKhan@cafe.com", "Male");
        
        manageStaff();
    }

    bool isValidPhone(string phone) 
    {
        return phone.length() == 11;
    }

    bool find(int id)
    {
        TreeNode* current = root;
        while (current != NULL)
        {
            if (current->empId == id)
            {
                return 1;
            }
            else if (id > current->empId)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        return 0;
    }

    void manageStaff()
    {
        bool flag = true;
        while (flag)
        {
            cout << "1. Find employee by id for further actions like adding salary, bonus, and supervision.\n";
            cout << "2. Display details of all employees.\n";
            cout << "3. Remove the data of any employee.\n";
            cout << "4. Insert new Employee.\n";
            cout << "5. Want to see the total revenue of the day.\n";
            cout << "6. Move to prev menu.\n";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Enter the employee id: ";
                int id;
                cin >> id;
                search(id);
                break;
            }
            case 2:
            {
                if(root == NULL)
                    cout << "No employees found." << endl;
                else
                inorder();
                break;
            }
            case 3:
            {
                cout << "Enter the employee id: ";
                int id;
                cin >> id;
                deleteNode(id);
                break;
            }
            case 4:
            {
                string name1, name2, phoneNum, mail, g;
                int salary, bonus, id;
                cout << "Enter id of employee:              ";
                cin >> id;
                cout << "Enter the employee salary:         ";
                cin >> salary;
                cout << "Enter employee bonus:              ";
                cin >> bonus;
                cout << "Enter employee's first name:       ";
                cin >> name1;
                cout << "Enter employee's last name:        ";
                cin >> name2;
                cout << "Enter Employee's phone number:     ";
                cin >> phoneNum;
                while (!isValidPhone(phoneNum))
                {
                    cout << "Invalid phone number length, enter again: ";
                    cin >> phoneNum;
                }
                cout << "Enter employee's email:            ";
                cin >> mail;
                cout << "Employee's gender:                 ";
                cin >> g;

                if (!find(id))
                {
                    insert(id, salary, bonus, name1, name2, phoneNum, mail, g);
                    break;
                }
                else
                {
                    cout << endl << "This ID already exists." << endl;
                    break;
                }
               
            }
            case 5: 
            {
                int get = customer.totalReveneueFunc();
                if (get != 0)
                {
                    cout << "Total Reveneue of the dya is :    " << get << endl;
                }
                else
                {
                    cout << "Revnue is 0 as no cutomer arrive\n";
                }
            }
            case 6:
                flag = false;
                
                break;
            default:
                cout << "Invalid option.\n";
                break;
            }
        }

    }
    void insert(int id, int sal, int bonus, string firstName, string lastName, string phone, string mail, string g) 
    {
        TreeNode* newNode = new TreeNode(id, sal, bonus, firstName, lastName, phone, mail, g);
        if (root == NULL) 
        {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        TreeNode* parent = NULL;

        while (true) 
        {
            parent = current;
            if (id < current->empId) 
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else if (id > current->empId)
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }

    void search(int id) 
    {
        TreeNode* current = root;
        while (current != NULL)
        {
            if (current->empId == id)
            {
                bool flag = true;
                while (flag)
                {
                    cout << "1. Update salary.\n";
                    cout << "2. Add bonus.\n";
                    cout << "3. View staff members under supervision of this employee.\n";
                    cout << "4. Go to previous menu.\n";
                    int choice;
                    cin >> choice;
                    if (choice == 1) 
                    {
                        cout << "Enter the salary increment: ";
                        int salary;
                        cin >> salary;
                        current->empSalary += salary;
                        flag = true;
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter the bonus amount: ";
                        int bonus;
                        cin >> bonus;
                        current->empBonus += bonus;
                        flag = true;
                    }
                    else if (choice == 3)
                    {
                        inorder(current);
                        flag = true;
                    }
                    else if (choice == 4) 
                    {
                        flag = false;
                        manageStaff();
                        return;
                    }
                    else 
                    {
                        cout << "Incorrect choice. Please try again.\n";
                    }
                }
                return;
            }
            else if (id > current->empId)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        cout << "Not found\n";
        manageStaff();
    }

    TreeNode* findMin(TreeNode* node)
    {
        while (node->left != NULL) node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int id)
    {
        if (root == NULL)
        {
            return root;
            cout << "Employee does not exist." << endl;
        }
          
        if (id < root->empId)
        {
            root->left = deleteNode(root->left, id);
        }
        else if (id > root->empId)
        {
            root->right = deleteNode(root->right, id);
        }
        else
        {
            if (root->left == NULL) 
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->empId = temp->empId;
            root->right = deleteNode(root->right, temp->empId);
        }
        return root;
    }

    void deleteNode(int id)
    {
        root = deleteNode(root, id);
    }

    void inorder(TreeNode* node) 
    {
        if (node == NULL) 
            return;
        inorder(node->left);
        cout << "Employee id:            " << node->empId << "\n";
        cout << "First name:             " << node->firstName << "\n";
        cout << "Last name:              " << node->lastName << "\n";
        cout << "Email:                  " << node->email << "\n";
        cout << "Gender:                 " << node->gender << "\n";
        cout << "Phone number:           " << node->empPhone << "\n";
        cout << "Salary:                 " << node->empSalary << "\n";
        cout << "Bonus:                  " << node->empBonus << "\n\n";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
    }
};

