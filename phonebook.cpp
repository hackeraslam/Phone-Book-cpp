#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;




string Upper_Case(string s)
{
	for (int i = 0; i <= s.length(); i++) {

		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] = s[i] - 32;
		}

	}
	return s;
}

class Person
{

	string first_name;
	string last_name;
	string memory;
	string group;
	string org;
	long long int number;
public:
	void set_fname(string);
	void set_lname(string);
	void set_memory(string);
	void set_group(string);
	void set_org(string);
	void set_number(long long int);
	Person();
	string get_fname();
	string get_lname();
	string get_memory();
	string get_group();
	string get_org();
	long long int get_num();
};


class Node
{
public:
	Person data;
	Node* next;
	Node* prev;
	bool block;
	bool favorite;
	Node();

};

Node::Node()
{

	next = NULL;
	prev = NULL;
	block = false;
	favorite = false;
}



class List
{
public:
	Node* root;
	List();
	bool Node_exist(long long int);// Check if Mobile Number Already Exist..
	void Create_contact(Node*); // Add New Contact 
	void Delete_number(long long int); // Delete Contact using Number..
	void Delete_name(string, string);// Delete Contact using Name 
	void Group_List(string); // Show all contact having same group
	void Org_List(string);// Show all contact having same organization
	void Display_list();// Dispaly All Contact in List
	void Show_memory(string); // Show All Contact in Same Memory
	void Search_name(string); // Find numbers using first name or last name
	void Search_char(string);// Find number using some characters of name;
	void Search_number(long long int);// Find using number
	void Modify_name(string, string);// find and Modify using Name
	void Modify_number(long long int); // find and modify
	void Add_fav_block(Node*); // This function will add number to block list or Favorite
	void Display_favorite();
	void Display_block();

};

class Data
{
public:
	int key;
	string name;
	Data* next;
	Data()
	{
		key = 0;
		name = "";
		next = NULL;
	}
};

class Group
{
public:
	Data* head;
	Group()
	{
		head = NULL;
	}
	void Create_Group(Data*);
	void Delete_Group(int);
	void Display_Groups();
	string Get_name(int);
};

class Organization
{
public:
	Data* start;
	Organization()
	{
		start = NULL;
	}
	void Add_Organization(Data*);
	void Display_Organization();
	string Get_name(int);
};


int Adjust_key(Group g);
int Adjust_org_key(Organization o);
long long int Digit_counter();
void Project();


int main()
{

	system("color 3");

	Project();
	Sleep(4000);
	system("cls");

	List L;
	long long int num;
	string fname;
	string lname;
	string org;
	string group;
	string memory;
	int ch, op;
	Group G;
	Organization O;
	int o_key = Adjust_org_key(O);
	int g_key = Adjust_key(G);
	while (true)
	{
		cout << "\t\t\t\t--------------------------------" << endl;
		cout << "\t\t\t\t| 1  = CREATE CONTACT          |" << endl;
		cout << "\t\t\t\t| 2  = DELETE                  |" << endl;
		cout << "\t\t\t\t| 3  = SEARCH                  |" << endl;
		cout << "\t\t\t\t| 4  = MODIFY                  |" << endl;
		cout << "\t\t\t\t| 5  = LIST                    |" << endl;
		cout << "\t\t\t\t| 6  = CREATE GROUP            |" << endl;
		cout << "\t\t\t\t| 7  = CREATE ORGANIZATION     |" << endl;
		cout << "\t\t\t\t| 0  = EXIT                    |" << endl;
		cout << "\t\t\t\t--------------------------------" << endl;
		int k;
		cout << "\t\t\t\tENTER CHOICE =  ";
		Node* n = new Node();
		Person* p = new Person();
		cin >> ch;
		Data* D = new Data;
		system("cls");
		cin.ignore();
		switch (ch)
		{
		case 0:
			Project();
			cout << endl << endl;
			Sleep(3000);
			cout << "\t\t\tEXITING IN 3 SECONDS..." << endl;

			exit(0);
			break;
		case 1:

			cout << "\t\t\t\tENTER FIRST NAME :	";
			getline(cin, fname);
			fname = Upper_Case(fname);
			cout << "\t\t\t\tENTER LAST NAME : ";
			getline(cin, lname);
			lname = Upper_Case(lname);
			do {
				cout << "\t\t\t\t\t1 : SIM MEMORY" << endl;
				cout << "\t\t\t\t\t2 : PHONE MEMORY" << endl;
				cout << "\t\t\t\t\tENTER CHOICE = ";
				cin >> op;


			} while (op < 1 || op>2);

			num = Digit_counter();
			p->set_fname(fname);
			p->set_lname(lname);

			cout << "\t\t\t\tSELECT GROUP " << endl << endl;
			cout << "\t\t\t\t0 = NULL " << endl;
			G.Display_Groups();
			do {

				cout << "\t\t\t\tENTER CHOICE : ";
				cin >> k;
				if (k == 0)
				{
					p->set_group("NULL");
					break;
				}
				group = G.Get_name(k);
				if (group == "0")
				{
					cout << "\t\t\t\tINVALID KEY OR GROUP DOES NOT EXIST..." << endl;
				}
			} while (group == "0");
			cout << "\t\t\t\tSELECT ORGANIZATION" << endl << endl;
			cout << "\t\t\t\t0 = NULL " << endl;
			p->set_group(group);
			O.Display_Organization();

			do {
				cout << "\t\t\t\tENTER CHOICE : ";
				cin >> k;
				if (k == 0)
				{
					p->set_org("NULL");
					break;
				}
				org = O.Get_name(k);
				if (org == "0" || org == "1")
				{
					cout << "\t\t\t\tINVALID KEY OR ORGANIZATION NOT EXIST.." << endl << endl;
				}


			} while (org == "0" || org == "1");
			p->set_org(org);
			p->set_number(num);
			if (op == 1)
			{
				p->set_memory("SIM");
			}
			else
			{
				p->set_memory("PHONE");
			}
			n->data = *p;
			L.Create_contact(n);


			break;

		case 2:

			do
			{

				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\t| 1  = DELETE CONTACT BY NAME         |" << endl;
				cout << "\t\t\t\t| 2  = DELETE CONTACT BY NUMBER       |" << endl;
				cout << "\t\t\t\t| 0 =  MAIN MENU                      |" << endl;
				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\tENTER CHOICE :  ";
				cin >> ch;
				cin.ignore();
				if (ch == 1)
				{
					cout << "\t\t\t\tENTER FIRST NAME : ";
					getline(cin, fname);
					fname = Upper_Case(fname);
					cout << "\t\t\t\tENTER LAST NAME : ";
					getline(cin, lname);
					lname = Upper_Case(lname);
					L.Delete_name(fname, lname);
					cin.ignore();

				}
				else if (ch == 2)
				{

					num = Digit_counter();
					L.Delete_number(num);
					cin.ignore();
				}
				else if (ch == 0)
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tINVALID CHOICE ENTERED.." << endl;
				}

			} while (ch > 2 || ch < 0);


			break;


		case 3:

			do
			{

				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\t| 1  = SEARCH CONTACT BY NAME         |" << endl;
				cout << "\t\t\t\t| 2  = SEARCH CONTACT BY NUMBER       |" << endl;
				cout << "\t\t\t\t| 3  = ADVANCE SEARCH                 |" << endl;
				cout << "\t\t\t\t| 0 =  MAIN MENU                      |" << endl;
				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\tENTER CHOICE :  ";
				cin >> ch;
				cin.ignore();
				if (ch == 1)
				{
					cout << "\t\t\t\tSEARCH BY NAME" << endl << endl;
					cout << "\t\t\t\tENTER NAME (FIRST / LAST) : ";
					getline(cin, fname);
					fname = Upper_Case(fname);
					L.Search_name(fname);
					cin.ignore();
				}
				else if (ch == 2)
				{


					num = Digit_counter();
					L.Search_number(num);
					cin.ignore();
				}
				else if (ch == 3)
				{

					cout << "\t\t\t\tENTER SOME CHARACTERS TO SEARCH : ";
					getline(cin, fname);
					fname = Upper_Case(fname);
					L.Search_char(fname);
					cin.ignore();
				}
				else if (ch == 0)
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tINVALID OPTION SELECTED..." << endl;
				}


			} while (ch > 3 || ch < 0);


			break;

		case 4:

			do
			{
				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\t| 1  = MODIFY CONTACT BY NAME         |" << endl;
				cout << "\t\t\t\t| 2  = MODIFY CONTACT BY NUMBER       |" << endl;
				cout << "\t\t\t\t| 0 =  MAIN MENU                      |" << endl;
				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\tENTER CHOICE :  ";
				cin >> ch;
				cin.ignore();
				if (ch == 1)
				{
					cout << "\t\t\t\tMODIFY USING NAME" << endl;
					cout << "\t\t\t\tENTER FIRST NAME : ";
					getline(cin, fname);
					fname = Upper_Case(fname);
					cout << "\t\t\t\ENTER LAST NAME : ";
					getline(cin, lname);
					lname = Upper_Case(lname);
					L.Modify_name(fname, lname);

					cin.ignore();
				}
				else if (ch == 2)
				{
					cout << "\t\t\t\tMODIFY USING NUMBER" << endl;

					num = Digit_counter();
					L.Modify_number(num);
				}
				else if (ch == 0)
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tINVALID CHOICE ENTERED.." << endl;
				}

			} while (ch < 0 || ch>2);

			break;


		case 5:

			do
			{

				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\t| 1  = FAVORITE                       |" << endl;
				cout << "\t\t\t\t| 2  = BLOCK LIST                     |" << endl;
				cout << "\t\t\t\t| 3  = LIST BY ORGANIZATION           |" << endl;
				cout << "\t\t\t\t| 4  = LIST BY MEMORY                 |" << endl;
				cout << "\t\t\t\t| 5  = DISPLAY ALL CONTACT            |" << endl;
				cout << "\t\t\t\t| 6  = LIST BY GROUP                  |" << endl;
				cout << "\t\t\t\t| 0 =  MAIN MENU                      |" << endl;
				cout << "\t\t\t\t---------------------------------------" << endl;
				cout << "\t\t\t\tENTER CHOICE :  ";
				cin >> ch;
				cin.ignore();
				if (ch == 1)
				{
					L.Display_favorite();
				}
				else if (ch == 2)
				{
					L.Display_block();
				}
				else if (ch == 3)
				{
					cout << "\t\t\t\tLIST BY ORGANIZATION" << endl << endl;
					O.Display_Organization();
					cout << "\t\t\t\tENTER CHOICE : ";
					cin >> op;
					org = O.Get_name(op);
					org = Upper_Case(org);// convert into uppercase
					if (org == "0")
					{
						cout << "\t\t\t\tORGANIZATION DOESNOT EXIST OR INVALID KEY ENTERED" << endl;
					}
					else
					{
						L.Org_List(org);
					}
				}
				else if (ch == 4)
				{
					cout << "\t\t\t\tLIST BY MEMORY" << endl;
					cout << "\t\t\t\t1 = SIM MEMORY" << endl;
					cout << "\t\t\t\t2 = PHONE MEMORY" << endl;
					cout << "\t\t\t\tENTER CHOICE : ";
					cin >> op;
					if (op == 1)
					{
						L.Show_memory("SIM");
					}
					else if (op == 2)
					{
						L.Show_memory("PHONE");
					}
					else
					{
						cout << "\t\t\t\tINVALID OPTION SELECTED..." << endl;
					}
				}

				else if (ch == 5)
				{
					L.Display_list();
				}
				else if (ch == 6)
				{
					cout << "\t\t\t\tLIST BY GROUPS" << endl << endl;
					G.Display_Groups();
					cout << endl;
					cout << "\t\t\t\tENTER OPTION : ";
					cin >> op;

					group = G.Get_name(op);
					group = Upper_Case(group);
					if (group == "0")
					{
						cout << "\t\t\t\tINVALID KEY INSERTED..." << endl;
					}
					else
					{
						L.Group_List(group);
					}

				}
				else if (ch == 0)
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tINVALID CHOICE ENTERED.." << endl;
				}



			} while (ch < 0 || ch>6);

			break;

		case 6:

			cout << "\t\t\t\tCREATE GROUP" << endl;

			cout << "\t\t\t\tENTER GROUP NAME : ";
			getline(cin, group);

			group = Upper_Case(group);
			D->key = g_key;
			D->name = group;
			G.Create_Group(D);
			g_key++;


			break;

		case 7:

			cout << "\t\t\t\tADD NEW ORGANIZATION" << endl << endl;
			cout << "\t\t\t\tENTER ORGANIZATION NAME : ";
			getline(cin, org);
			cin.ignore();
			org = Upper_Case(org);
			D->key = o_key;
			o_key++;
			D->name = org;
			O.Add_Organization(D);

			break;

		default:

			cout << "\t\t\t\tINVALID OPTION SELECTED, PLEASE TRY AGAIN....." << endl;
			break;
		}

		system("pause");
		system("cls");

	}


	system("pause");
}





bool List::Node_exist(long long int x)
{
	Node* temp = root;
	while (temp != NULL)
	{
		if (temp->data.get_num() == x)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;

}

List::List()
{
	root = NULL;
}


void List::Create_contact(Node* n)
{
	if (root == NULL)
	{
		root = n;

		cout << "\t\t\t\tCONTACT CREATED SUCESSFULLY.." << endl;
	}
	else if (Node_exist(n->data.get_num()))
	{
		cout << "\t\t\t\tNumber Already Exist in Contact List...	" << endl;

	}
	else
	{
		Node* temp = root;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = n;
		n->prev = temp;
		cout << "\t\t\t\tContact Created Sucessfully...	" << endl;

	}

}

void List::Display_block()
{
	Node* temp = root;
	if (root == NULL)
	{
		cout << "\t\t\t\tCONTACT LIST IS EMPTY..." << endl;
	}
	else
	{
		cout << "\t\t\t\tBLOCK CONTACTS" << endl << endl;
		while (temp != NULL)

		{
			if (temp->block)
			{
				cout << "\t\t\t\t------------------------------------------------------------" << endl;
				cout << "\t\t\t\tNAME = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\t-------------------------------------------------------------" << endl << endl;
			}
			temp = temp->next;
		}
	}
}

void List::Display_favorite()
{
	Node* temp = root;
	if (root == NULL)
	{
		cout << "\t\t\t\tCONTACT LIST IS EMPTY..." << endl;
	}
	else
	{
		cout << "\t\t\t\tFAVORITE CONTACTS" << endl << endl;
		while (temp != NULL)

		{
			if (temp->favorite)
			{
				cout << "\t\t\t\t------------------------------------------------------------" << endl;
				cout << "\t\t\t\tNAME = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\t-------------------------------------------------------------" << endl << endl;
			}
			temp = temp->next;
		}
	}

}


void List::Add_fav_block(Node* n)
{
	int ch;
	if (!(n->block) && !(n->favorite))
	{
		cout << "\t\t\t\t1 = ADD TO FAVORITE" << endl;
		cout << "\t\t\t\t2 = BLOCK CONTECT" << endl;
		cout << "\t\t\t\t0 = MAIN MENU" << endl;
		cout << "\t\t\t\tENTER CHOICE : " << endl;
		cin >> ch;
		if (ch == 1)
		{
			n->favorite = true;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY ADDED TO FAVORITE" << endl;

		}
		else if (ch == 2)
		{
			n->block = true;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY ADDED TO BLOCKLIST" << endl;
		}
		else if (ch == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "\t\t\tINVALID INPUT ENTERED.." << endl;
		}
	}
	else if (n->block && !(n->favorite))
	{
		cout << "\t\t\t\t1 = ADD TO FAVORITE" << endl;
		cout << "\t\t\t\t2 = REMOVE FROM BLOCK LIST" << endl;
		cout << "\t\t\t\t0 = MAIN MENU" << endl;
		cout << "\t\t\t\tENTER CHOICE : " << endl;
		cin >> ch;
		if (ch == 1)
		{
			n->favorite = true;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY ADDED TO FAVORITE" << endl;

		}
		else if (ch == 2)
		{
			n->block = false;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY REMOVED FROM BLOCKLIST" << endl;
		}
	}
	else if (!(n->block) && n->favorite)
	{
		cout << "\t\t\t\t1 = REMOVE FROM FAVORITE" << endl;
		cout << "\t\t\t\t2 = ADD TO BLOCK LIST" << endl;
		cout << "\t\t\t\t0 = MAIN MENU" << endl;
		cout << "\t\t\t\tENTER CHOICE : " << endl;
		cin >> ch;
		if (ch == 1)
		{
			n->favorite = false;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY REMOVED FROM FAVORITE" << endl;

		}
		else if (ch == 2)
		{
			n->block = true;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY ADDED TO  BLOCKLIST" << endl;
		}
		else if (ch == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "\t\t\tINVALID INPUT ENTERED.." << endl;
		}
	}
	else
	{
		cout << "\t\t\t\t1 = REMOVE FROM FAVORITE" << endl;
		cout << "\t\t\t\t2 = REMOVE FROM BLOCK LIST" << endl;
		cout << "\t\t\t\t0 = MAIN MENU" << endl;
		cout << "\t\t\t\tENTER CHOICE : " << endl;
		cin >> ch;
		if (ch == 1)
		{
			n->favorite = false;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY REMOVED FROM FAVORITE" << endl;

		}
		else if (ch == 2)
		{
			n->block = false;
			cout << "\t\t\t\tNUMBER IS SUCESSFULLY REMOVED FROM BLOCKLIST" << endl;
		}
		else if (ch == 0)
		{
			system("cls");
			return;
		}
		else
		{
			cout << "\t\t\tINVALID INPUT ENTERED.." << endl;
		}
	}
}

void List::Delete_number(long long int x)
{
	char ch;
	bool flag = false;
	if (root == NULL)
	{
		cout << "\t\t\t\tContact List is Empty..." << endl;
	}
	else
	{
		Node* temp = root;
		Node* ptr;
		Node* p_ptr;
		while (temp != NULL)
		{
			if (temp->data.get_num() == x)
			{
				flag = true;
				cout << "\t\t\t\tName = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNumber = " << temp->data.get_num() << endl;
				cout << "\t\t\t\tGroup = " << temp->data.get_group() << endl;
				cout << "\t\t\t\tOrganization = " << temp->data.get_org() << endl;
				cout << "\t\t\t\tMamory = " << temp->data.get_memory() << endl << endl << endl;
				cout << "\t\t\t\tDo You Want to Delete this Contact (Y/N)) : ";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					ptr = temp->next;
					p_ptr = temp->prev;
					if (p_ptr == NULL)
					{
						root = ptr;
					}
					else
					{
						p_ptr->next = ptr;
						if (ptr != NULL)
						{
							ptr->prev = p_ptr;
						}

					}
					delete temp;
					cout << "\t\t\t\tContact Deleted Sucessfully...." << endl;
					break;
				}
				else if (ch == 'N' || ch == 'n')
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tInvalid Input..." << endl;
					break;
				}
			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tContact Not Found in List..." << endl;
		}
	}
}

void List::Display_list()
{
	int i = 1;
	Node* temp = root;
	if (root == NULL)
	{
		cout << "\t\t\t\t List is Empty..." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << "\t\t\t\t-------------------------------------------------------" << endl << endl;
			cout << "\t\t\t\tCONTACT # " << i << " : " << endl;
			cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
			cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
			cout << "\t\t\t\tMAMORY : " << temp->data.get_memory() << endl << endl;
			cout << "\t\t\t\t-------------------------------------------------------" << endl << endl;
			i++;
			temp = temp->next;

		}
	}
}



void List::Show_memory(string s)
{
	bool flag = false;
	Node* temp = root;
	if (root == NULL)
	{
		cout << "\t\t\t\tContact List is Empty.." << endl;
	}
	else
	{
		cout << "\t\t\t\t" << s << " MEMORY" << endl << endl;
		while (temp != NULL)
		{
			if (temp->data.get_memory() == s)
			{
				flag = true;
				cout << "\t\t\t\t-------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
				cout << "\t\t\t\t-------------------------------------------------------" << endl << endl;

			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tNo Contact in " << s << " MEMORY" << endl;
		}
	}
}

void List::Group_List(string s)
{
	Node* temp = root;
	bool flag = false;
	if (root == NULL)
	{
		cout << "\t\t\t\tContact list is Empty..." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data.get_group() == s)
			{
				flag = true;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\tName = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNumber = " << temp->data.get_num() << endl << endl;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tNo Contacts in Group : " << s << endl;
		}
	}
}



void List::Delete_name(string first, string last)
{
	Node* temp = root;
	bool flag = false;
	char ch;
	if (root == NULL)
	{
		cout << "\t\t\t\tContact List is Empty..." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			Node* ptr = NULL;
			Node* p_ptr = NULL;
			if (temp->data.get_fname() == first && temp->data.get_lname() == last)
			{
				flag = true;
				cout << "\t\t\t\tName = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNumber = " << temp->data.get_num() << endl;
				cout << "\t\t\t\tGroup = " << temp->data.get_group() << endl;
				cout << "\t\t\t\tOrganization = " << temp->data.get_org() << endl;
				cout << "\t\t\t\tMamory = " << temp->data.get_memory() << endl << endl << endl;
				cout << "\t\t\t\tDo You Want to Delete this Contact (Y/N)) : ";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					ptr = temp->next;
					p_ptr = temp->prev;
					if (p_ptr == NULL)
					{
						root = ptr;
					}
					else
					{
						p_ptr->next = ptr;
						if (ptr != NULL)
						{
							ptr->prev = p_ptr;
						}
					}
					delete temp;


					cout << "\t\t\t\tContact Deleted Sucessfully...." << endl;
					break;
				}
				else if (ch == 'N' || ch == 'n')
				{
					break;
				}
				else
				{
					cout << "\t\t\t\tInvalid Input..." << endl;
					break;
				}
			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tContact Not Found Please Check First and Last Name...." << endl;
		}
	}
}


void List::Org_List(string s)
{
	Node* temp = root;
	bool flag = false;
	if (root == NULL)
	{
		cout << "\t\t\t\tContact list is Empty..." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data.get_org() == s)
			{
				flag = true;
				cout << "---------------------------------------------------------------" << endl << endl;
				cout << "Name = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "Number = " << temp->data.get_num() << endl << endl;
				cout << "---------------------------------------------------------------" << endl << endl;

			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tNo Contacts in Organization : " << s << endl;
		}
	}
}

void List::Search_name(string n)
{
	if (root == NULL)
	{
		cout << "\t\t\t\tCONTACT LIST IS EMPTY.." << endl;
	}
	else
	{
		Node* temp = root;
		bool flag = false;
		while (temp != NULL)
		{
			if (temp->data.get_fname() == n || temp->data.get_lname() == n)
			{
				flag = true;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\tName = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNumber = " << temp->data.get_num() << endl << endl;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tNO RECORD FOUND..." << endl << endl;
		}

	}
}

void List::Search_number(long long int x)
{
	if (root == NULL)
	{
		cout << "\t\t\t\tCONTACT LIST IS EMPTY..." << endl;
	}
	else
	{
		Node* temp = root;
		bool flag = false;
		int ch;
		while (temp != NULL)
		{
			if (temp->data.get_num() == x)
			{
				flag = true;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\tName = " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNumber = " << temp->data.get_num() << endl;
				cout << "\t\t\t\tGROUP = " << temp->data.get_group() << endl;
				cout << "\t\t\t\tORGANIZATION = " << temp->data.get_org() << endl;
				cout << "\t\t\t\tMEMEORY = " << temp->data.get_memory() << endl << endl;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

				Add_fav_block(temp);

			}
			temp = temp->next;
		}
		if (!flag)
		{
			cout << "\t\t\t\tNO RECORD FOUND.." << endl;
		}
	}
}

void List::Modify_name(string first, string last)
{
	if (root == NULL)
	{
		cout << "\t\t\t\t List is Empty..." << endl;
		cout << "\t\t\t\tContact List is Empty..." << endl;
	}
	else
	{
		string fname, lname;
		long long int num;
		bool flag = false;
		Node* temp = root;
		int op;
		while (temp != NULL)
		{
			if (temp->data.get_fname() == first && temp->data.get_lname() == last)
			{
				flag = true;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
				cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
				cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
				cout << "\t\t\t\t1 = MODIFY NAME" << endl;
				cout << "\t\t\t\t2 = MODIFY NUMBER" << endl;
				cin >> op;
				cin.ignore();
				if (op == 1)
				{

					cout << "\t\t\t\tENTER FIRST NAME : ";
					getline(cin, fname);
					fname = Upper_Case(fname);
					cout << "\t\t\t\tENTER LAST NAME : ";
					getline(cin, lname);
					lname = Upper_Case(lname);
					temp->data.set_fname(fname);
					temp->data.set_lname(lname);
					cout << "\t\t\t\tCONTACT IS SUCESSFULLY MODIFIED.." << endl;
				}
				else if (op == 2)
				{
					cout << "\t\t\t\tENTER NEW NUMBER : ";
					cin >> num;
					temp->data.set_number(num);
					cout << "\t\t\t\tCONTACT IS SUCESSFULLY MODIFIED.." << endl;
				}
				else
				{
					cout << "\t\t\t\tINVALID OPTION SELECTED..." << endl;
				}
				break;
			}
			temp = temp->next;
		}

		if (!flag)
		{
			cout << "\t\t\t\tNO RECORD FOUND.." << endl;
		}
	}

}


void List::Modify_number(long long int x)
{
	string fname, lname;
	long long int num;
	bool flag = false;
	Node* temp = root;
	int op;
	while (temp != NULL)
	{
		if (temp->data.get_num() == x)
		{
			flag = true;
			cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
			cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
			cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
			cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

			cout << "\t\t\t\t1 = MODIFY NAME" << endl;
			cout << "\t\t\t\t2 = MODIFY NUMBER" << endl;
			cin >> op;
			if (op == 1)
			{
				cout << "\t\t\t\tENTER FIRST NAME : ";
				getline(cin, fname);
				cout << "\t\t\t\tENTER LAST NAME : ";
				getline(cin, lname);
				temp->data.set_fname(fname);
				temp->data.set_lname(lname);
				cout << "\t\t\t\tCONTACT IS SUCESSFULLY MODIFIED.." << endl;
			}
			else if (op == 2)
			{
				cout << "\t\t\t\tENTER NEW NUMBER : ";
				cin >> num;
				temp->data.set_number(num);
				cout << "\t\t\t\tCONTACT IS SUCESSFULLY MODIFIED.." << endl;
			}
			else
			{
				cout << "\t\t\t\tINVALID OPTION SELECTED..." << endl;
			}
			break;
		}
		temp = temp->next;
	}

	if (!flag)
	{
		cout << "\t\t\t\tNO RECORD FOUND.." << endl;
	}
}


void List::Search_char(string s)
{
	if (root == NULL)
	{
		cout << "\t\t\t\tCONTACT LIST IS EMPTY.." << endl;
	}
	else
	{
		string x;
		bool flag = false;
		Node* temp = root;
		{
			while (temp != NULL)
			{
				// This will compare the characters with first name;
				int count = 0;
				x = temp->data.get_fname();
				for (int i = 0; i < s.length(); i++)
				{
					if (x[i] == s[i])
					{
						count++;
					}

				}
				if (count == s.length())
				{
					flag = true;
					cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
					cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
					cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
					cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

				}

				// This will compare the  entered chacter will last name
				count = 0;
				x = temp->data.get_lname();
				for (int i = 0; i < s.length(); i++)
				{
					if (x[i] == s[i])
					{
						count++;
					}

				}
				if (count == s.length())
				{
					flag = true;
					cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;
					cout << "\t\t\t\tNAME : " << temp->data.get_fname() << " " << temp->data.get_lname() << endl;
					cout << "\t\t\t\tNUMBER : " << temp->data.get_num() << endl;
					cout << "\t\t\t\t---------------------------------------------------------------" << endl << endl;

				}
				temp = temp->next;

			}

			if (!flag)
			{
				cout << "\t\t\t\tNO RECORD FOUND IN CONTACT LIST" << endl;
			}
		}
	}
}










void Person::set_fname(string n)
{
	first_name = n;
}

void Person::set_lname(string n)
{
	last_name = n;

}

void Person::set_group(string g)
{
	group = g;
}

void Person::set_memory(string m)
{
	memory = m;
}

void Person::set_org(string x)
{
	org = x;
}

void Person::set_number(long long int x)
{
	number = x;
}


Person::Person()
{
	first_name = "";
	last_name = "";
	group = "";
	memory = "";
	number = 0;
	org = "";
}

void Group::Create_Group(Data* n)
{
	if (head == NULL)
	{
		head = n;

	}
	else
	{
		Data* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;

	}
}

string Group::Get_name(int k)
{
	if (head == NULL)
	{
		return "0";
	}
	else
	{
		Data* temp = head;
		while (temp != NULL)
		{
			if (temp->key == k)
			{
				return temp->name;
			}
			temp = temp->next;

		}
		return "0";
	}

}

void Group::Delete_Group(int s)
{


	bool flag = false;
	Data* ptr = head;
	if (head == NULL)
	{
		cout << "\t\t\t\tNO GROUP IS ADDED..." << endl;
	}
	else
	{
		while (ptr != NULL)
		{
			Data* temp;
			if (ptr->next->key == s)
			{
				flag = true;
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				cout << "\t\t\t\tGROUP IS DELETED SUCESSFULLY..." << endl;

			}
			ptr = ptr->next;
		}

		if (!flag)
		{
			cout << "INVALID OPTION SELECTED" << endl;
		}
	}

}

void Group::Display_Groups()
{
	if (head == NULL)
	{
		cout << "\t\t\t\tNO GROUP EXIST..." << endl;
	}
	else
	{
		Data* temp = head;
		while (temp != NULL)
		{
			cout << temp->key << "  =  " << temp->name << endl;
			temp = temp->next;
		}
	}
}

void Organization::Add_Organization(Data* n)
{
	if (start == NULL)
	{
		start = n;

	}
	else
	{
		Data* temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;

	}

}


void Organization::Display_Organization()
{
	if (start == NULL)
	{
		return;
	}
	else
	{
		Data* temp = start;
		while (temp != NULL)
		{
			cout << temp->key << " " << temp->name << endl;
			temp = temp->next;
		}
	}
}

string Organization::Get_name(int k)
{
	if (start == NULL)
	{
		return "0";

	}
	else
	{
		Data* temp = start;
		bool flag = false;
		while (temp != NULL)
		{
			if (temp->key == k)
			{
				flag = true;
				return temp->name;
			}
			temp = temp->next;
		}
		if (!flag)
		{
			return "0";
		}
	}
}


int Adjust_key(Group g)
{
	int key = 1;
	Data* temp = g.head;
	while (temp != NULL)
	{
		temp->key = key;
		key++;
		temp = temp->next;
	}
	return key;
}

int Adjust_org_key(Organization o)
{
	int key = 1;
	Data* temp = o.start;
	while (temp != NULL)
	{
		temp->key = key;
		key++;
		temp = temp->next;
	}
	return key;
}


long long int Digit_counter()
{
	long long int num, x;
	int count = 0;
	do
	{
		count = 0;
		cout << "\t\t\t\tENTER CONTACT NUMBER (03XXXXXXXXX) (34XXXXXXXX) : ";
		cin >> num;
		x = num;
		while (x > 0)
		{
			x = x / 10;
			count++;
		}
		if (count != 10)
		{
			cout << "\t\t\t\tINVLAID NUMBER PLEASE ENTER 10 DIGIT NUMBER (03XXXXXXXXX) (3XXXXXXXXX)" << endl;
		}
	} while (count != 10);

	return num;
}


void Project()
{
	cout << "\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t|PROJECT BY:                             |" << endl;
	cout << "\t\t\t|                                        |" << endl;
	cout << "\t\t\t| NAME              |      ID            |" << endl;
	cout << "\t\t\t|                   |                    |" << endl;
	cout << "\t\t\t|NAME               |     ASLAM KHAN     |" << endl;
	cout << "\t\t\t|UNIVERSITY         |     AU ISLAMABAD   |" << endl;
	cout << "\t\t\t|DEPARTMENT         |     BSCS-F-19      |" << endl;
	
	cout << "\t\t\t------------------------------------------" << endl;






}



string Person::get_fname()
{
	return first_name;
}

string Person::get_lname()
{
	return last_name;
}

string Person::get_group()
{
	return group;
}

string Person::get_memory()
{

	return memory;
}

string Person::get_org()
{
	return org;
}

long long int Person::get_num()
{
	return number;
}



