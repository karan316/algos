#include<iostream>
using namespace std;

class Node
{
private:
	int info;
	Node *next;
public:
	void insertBeg();
	void insertEnd();
	void printList(Node *start);
	Node *start = NULL;
};

void Node::printList(Node *start)
{
	Node *temp = new Node(); //temporary node to traverse
	temp = start;
	cout << "Elements in the list are\n";
	while (temp != NULL)
	{
		cout << temp->info << "\t";
		temp = temp->next;
	}
}

void Node::insertBeg()
{
	Node *new_node = new Node(); //creating a new node

	cout << "Enter the element to be inserted at the beginning\n";
	cin >> new_node->info;

	if (start == NULL)
	{
		start = new_node;
		new_node->next == NULL;

		printList(start);
		return;
	}

	new_node->next = start;
	start = new_node;
	//display list
	printList(start);
}

void Node::insertEnd()
{
	Node *new_node = new Node(); //creating a new node
	Node *cur = new Node(); //pointer to traverse the list

	cout << "Enter the element to be inserted at the end\n";
	cin >> new_node->info;

	cur = start;
	if (cur == NULL)
	{
		cur = new_node;
		start = new_node;
		new_node->next = NULL;
		printList(start);
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next; //reach the end of the list
	}

	cur->next = new_node; //assign next of last node to temp
	new_node->next = NULL; //next of temp should be NULL since it is last element

	//display list
	printList(start);
}

int main()
{
	Node n;
	int ch;
	char choice;
	do
	{
		cout << "1. Insert at the beginning\n2. Insert at the end\n";
		cin >> ch;
		switch (ch)
		{
		case 1: n.insertBeg();
			break;
		case 2:
			n.insertEnd();
			break;
		default:
			cout << "Invalid Option!\n";
		}
		cout << "\nDo you want to continue(y/n)?\n";
		cin >> choice;
	} while (choice == 'y');
}
