#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>
#include<sstream>
using namespace std;


struct Node {
	Node(int sid, string major, double gpa, string ad_type, int adi) : sid(sid), major(major), gpa(gpa), ad_type(ad_type), adi(adi), left(NULL), right(NULL) {}
	int sid, adi;
	string major, ad_type;
	double gpa;

	Node* left;
	Node* right;
};

class BST
{
private:
	Node* root;
	void insert(Node* treenode, int sid, string major, double gpa, string ad_type, int adi)
	{
		if (!treenode)
		{
			treenode = new Node(sid, major, gpa, ad_type, adi);
			root = treenode;
		}
		else
		{
			if (sid < treenode->sid)
			{
				if (!treenode->left)
				{
					Node* treeTemp = new Node(sid, major, gpa, ad_type, adi);
					treenode->left = treeTemp;
				}
				else
					insert(treenode->left, sid, major, gpa, ad_type, adi);
			}
			else
			{
				if (!treenode->right)
				{
					Node* treeTemp = new Node(sid, major, gpa, ad_type, adi);
					treenode->right = treeTemp;
				}
				else
					insert(treenode->right, sid, major, gpa, ad_type, adi);
			}
		}
	}
	void search(Node* treenode, int sid)
	{
			if (treenode == NULL)
            {
                cout << "This ID does not exist" << endl;
                return;
            }
			if(treenode->sid == sid)
            {
                std::cout << std::fixed;
                std::cout << std::setprecision(2);
                cout << "The student with ID " << sid << " has the following information: " << treenode->major << " " << treenode->gpa << " " << treenode->ad_type << " " << treenode->adi << endl;
                return;
            }

		if (treenode->sid < sid)
			search(treenode->right, sid);
        else
            search(treenode->left, sid);
	}
    
    int exist(Node* treenode, int sid)
    {
        int e_xist = 0;
            if (treenode == NULL)
                return 0 + e_xist;
            if(treenode->sid == sid)
                return 1 + e_xist;

        if (treenode->sid < sid)
            exist(treenode->right, sid);
        else
            exist(treenode->left, sid);
        
        return e_xist;
    }
    
    
public:
	void insert(int sid, string major, double gpa, string ad_type, int adi)
	{
		insert(root, sid, major, gpa, ad_type, adi);
	}
	void search(int sid)
	{
		search(root, sid);
	}
    int exist(int sid)
    {
        return exist(root, sid);
    }
	BST()
	{
		root = NULL;
	}
};


int main()
{
	BST myBST;
	int sid, adi;
	string major, ad_type;
	double gpa;
	string v;
	string fileName;
	cout << "Please input the file name: " << endl;
	cin >> fileName;
	// TODO: store the record in the hash table
	ifstream inFile("/Users/seunggyukim/Documents/C language/EE2331/Q3-student-record.txt");
//    ifstream inFile(fileName);

	if (!inFile.is_open()) {
		cout << "Error: cannot open data file" << endl;
		exit(0); //terminate the program
	}


	while (!inFile.eof()) {
		inFile >> sid;
		inFile >> major;
		inFile >> gpa;
		inFile >> ad_type;
		inFile >> adi;


		if (!inFile.fail())
		{
			myBST.insert(sid, major, gpa, ad_type, adi); //insert into the linked list
//			cout << sid << " " << major << " " << gpa << " " << ad_type << " " << adi << endl;
		}
		else
			break;
	}
	inFile.close();
	cout << "Database indexing finished" << endl;
	string choice;
	while (1)
	{
		cout << "*****Please input one of the following operations: search, insert, over *****" << endl;
		cin >> choice;
		cout << "Your input is <" << choice << "> ";
		if (choice == "search")
		{
			int search;
			cout << "What is the Student ID : ";
			cin >> search;
			myBST.search(search);
		}
        if (choice == "insert")
        {
            string insert_record;
            while(1)
            {
                cout << "Please input the student's record" << endl;
                while(getchar() != '\n');
                getline(cin, insert_record);
                stringstream ss(insert_record);
                
                if(!(ss >> sid >> major >> gpa >> ad_type >> adi) || !ss.eof())
                {
                    cout << "wrong format" << endl;
                    continue;
                }
                if(ss.fail())
                {
                    cout << "wrong format" << endl;
                    continue;
                }
                if(myBST.exist(sid) != 0)
                {
                    cout << "You can't insert existing SID" << endl;
                    break;
                }
                break;
            }
            
            
            
            myBST.insert(sid, major, gpa, ad_type, adi);
        }
        if (choice == "over")
        {
            cout << "Bye." << endl;
            break;
        }
	}




	return 0;
}
