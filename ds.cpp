#include <iostream>
using namespace std;
struct node
{
	int id{};
	string name{};
	string manger{};
	node* next{};
};

struct node1
{
	int id1{};
	string name1{};
	string address{};
	int balance{};
	node1* next1{};

};

node* head = NULL;
node1* head1 = NULL;

char menu();
void insert_branch(int id, string name, string manger);
int search_branch(int id);
void insert_holder(int id1, string name1, string address, int balance);
void display_branch();
void display_holder();
int search_holder(string name1);
void remove_branch(int id);
void remove_holder(int id1);


char menu()
{
	char choice;
	cout << "\n\t\t\t\t\t\tThe Opthions Of The Bank System \n";
	cout << "\n\t\t\t\t\t1-Add New Branch \n";
	cout << "\n\t\t\t\t\t2-Remove Branch \n";
	cout << "\n\t\t\t\t\t3-Display The Branch Information \n";
	cout << "\n\t\t\t\t\t4-Add New Holder \n";
	cout << "\n\t\t\t\t\t5-Remove holder \n";
	cout << "\n\t\t\t\t\t6-Display The Holder Information \n";
	cout << "\n\t\t\t\t\t7-Search About Branch Information  \n";
	cout << "\n\t\t\t\t\t8-Search About Holder Information \n";


	cout << "\n\t\t\t\t\t********************************************\n\n";

	cout << "\t\t\t\t\tYour Choice Is : ";
	cin >> choice;
	return choice;
}


void insert_branch(int id, string name, string manger)
{

	node* temp = new node;
	temp->id = id;
	temp->name = name;
	temp->manger = manger;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		node* last = head;
		while (last->next != NULL)
		{

			last = last->next;
		}

		last->next = temp;
		temp->next = NULL;
	}
}

int search_branch(int id)
{
	node* search = head;
	while (search != NULL)
	{
		if (search->id == id)
		{
			cout << "The Id : " << search->id << "\nThe Branch's Name : " << search->name << "\nThe manger's name: " << search->manger << "\n";
		}
		search = search->next;

	}
	return -1;

}
void insert_holder(int id1, string name1, string address, int balance)
{
	node1* temp1 = new node1;
	temp1->id1 = id1;
	temp1->name1 = name1;
	temp1->address = address;
	temp1->balance = balance;
	temp1->next1 = NULL;

	if (head1 == NULL)
	{
		head1 = temp1;

	}
	else
	{
		node1* last1 = head1;
		while (last1->next1 != NULL)
		{
			last1 = last1->next1;
		}

		last1->next1 = temp1;
		temp1->next1 = NULL;
	}
}

void display_branch()
{

	node* current;
	current = head;

	while (current != NULL)
	{
		cout << "\nThe Account Information: \n";
		cout << "The Id : " << current->id << "\nThe Branch's Name : " << current->name << "\nThe manger's name: " << current->manger << "\n";
		current = current->next;
	}
	if (head == NULL)
	{
		cout << "\t\nNo Information to display\n";
	}

	cout << endl;
}


void display_holder()
{
	node1* current1;
	current1 = head1;

	while (current1 != NULL)
	{
		cout << "The Holder Information: \n";
		cout << "\nThe Id : " << current1->id1 << "\nThe Holder's Name : " << current1->name1 << "\nThe Holder's Address: " << current1->address << "\nThe Balance : " << current1->balance << "\n";
		current1 = current1->next1;
	}
	if (head1 == NULL)
	{
		cout << "No Information to display";
	}


}


int search_holder(string name1)
{
	node1* search1 = head1;

	while (search1 != NULL)
	{
		if (search1->name1 == name1)
		{
			cout << "\nThe Id : " << search1->id1 << "\nThe Holder's Name : " << search1->name1 << "\nThe Holder's Address: " << search1->address << "\nThe Balance : " << search1->balance << "\n";
		}
		search1 = search1->next1;
	}
	if (head == NULL)
	{
		cout << "\t\nPlease Enter a Correct Name \n" << endl;
	}

	return -1;

}


void remove_branch(int id)
{
	node* remove, * cont;
	remove = cont = head;

	if (remove->id == NULL)
	{
		cout << "There No Any Branchs Information To Remove. \n" << endl;
		return;
	}

	if (head->id == id)
	{
		delete head;
		head = head->next;

		remove = NULL;
	}
	while (head->id != id)
	{
		cont = remove;
		remove = remove->next;
		cont->next = remove->next;
		delete remove;

	}

}





void remove_holder(int id1)
{

	node1* remove1, * cont1;
	remove1 = cont1 = head1;

	if (remove1->id1 = id1)
	{

		head1 = remove1->next1;
		delete head1;
		head1 = NULL;
		remove1 = NULL;
	}
	while (remove1 != NULL && remove1->id1 != id1)
	{
		cont1 = remove1;
		remove1 = remove1->next1;
	}
	if (remove1 == NULL)
	{
		return;
	}
	else
	{
		cont1->next1 = remove1->next1;
		delete remove1;
	}

	if (head1 == NULL)
	{
		cout << "There Is No Any Branchs Information To Remove. " << endl;
		return;
	}
}


int main()
{
	node* head = NULL;
	node* last = NULL;
	node1* head1 = NULL;
	node1* last1 = NULL;
	char choice;
	int id, id1, balance;
	string name, name1, address, manger;



	do {
		choice = menu();

		switch (choice)
		{
		case '1': {cout << "\tPlease Enter ID : ";
			cin >> id;
			cout << "\tPlease Enter The Name : ";
			cin >> name;
			cout << "\tPlease Enter The Name Of The Manger : ";
			cin >> manger;
			insert_branch(id, name, manger);
			break; }
		case '2': {cout << "\t\nPlease Enter The ID Of The Branch That You  Want To Remove : \n";
			cin >> id;
			cout << "\n";
			remove_branch(id);
			cout << "\t\nThe Branch Has Been Successfully deleted ";
			break; }
		case '3': { display_branch();
			break; }
		case'4': {cout << "\tPlease Enter ID : ";
			cin >> id1;
			cout << "\tPlease Enter The Name : ";
			cin >> name1;
			cout << "\tPlease Enter The Address : ";
			cin >> address;
			cout << "\tPlease Enter The Balance : ";
			cin >> balance;
			insert_holder(id1, name1, address, balance);
			break; }
		case'5': {cout << "\t\nPlease Enter The ID Of The Holder That You  Want To Remove ";
			cin >> id1;
			cout << "\n";
			remove_holder(id1);
			cout << "\t\nThe Holder Has Been Successfully deleted \n";
			break; }
		case'6': {display_holder();
			break; }
		case'7': {cout << "\t\nEnter The Branch ID For Serach : \n";
			cin >> id;
			search_branch(id);
			break; }
		case'8': {cout << "\t\nEnter The Holder Name For Serach : \n";
			cin >> name;
			search_holder(name);
			break; }

		default: cout << "System Exit. \n";
		}
	} while (choice != '10');
	return 0;
}

