#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>
#include <string.h>
#include <conio.h>
using namespace std;
const char *fileName = "file.dat";

int mainmenu();
bool validateInput();
bool isEmpty(ifstream &file);

void deleteExistingFile(){
    remove("file.dat");
}

class login
{
protected:
	char login_un[20];
	char login_pw[20];
	char username[20];
	char password[20];
	int c;
public:
	void if_user()
	{
		ifstream uin;
		uin.open("user.txt");
		uin.getline(username, 50);
		while (strcmp("neenad",login_un)!=0)
			{

				cout<<"\nENTER USERNAME:-";
				cin>>login_un;
				if (strcmp(login_un,"neenad") ==0)
					{
						break;
					}
				else
					{
						cout<<"\n"<<login_un<<" "<<" Invalid Username.\n";
						cout<<"\nPress any key to try again...";
						getche();
						system("cls");
						cout<<"\n  *********  LOGIN WINDOW  *********  \n";
					}
		}
		uin.close();
	}


	void if_pass()
	{
		ifstream pin;
		pin.open("pass.txt");
		pin.getline(password,50);
		while(strcmp("neenad123",login_pw)!=0)
			{
				cout<<"\n";
				cout<<"\nENTER PASSWORD:-";
                cin>>login_pw;
                cout<<login_pw;
				if(strcmp(login_pw, "neenad123") ==0)
					{
						cout<<"\n"<<login_pw<<"\t"<<" Welcome!";
						system("cls");

					}
				else
					{
						cout<<"\n"<<login_pw<<"\t"<<"is Invalid Password.\n";
					}
			}
		pin.close();
	}

	void display()
	{
		if_user();
		if_pass();
	}
};

class Employee
{
private:
    int id;
    char name[100], post[100], department[100];
    double salary;

public:
    Employee()
    {
        id = 0;
        strcpy(name, "no name");
        strcpy(name, "no post");
        strcpy(name, "no department");
        salary = 0;
    }

    void getData();
    void writeFile();
    void readFile();
    void showData();
    void searchData(int input);
    void updateData(int input);
    void deleteData(int input);
};

void Employee::getData()
{
    bool flag = false;

label1:
    cout << "\tEnter Employee Name : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(name, 100);
    flag = validateInput();
    if (flag)
        goto label1;


label2:
    cout << "\tEnter Employee Unique ID : ";
    cin >> id;
    flag = validateInput();
    if (flag)
        goto label2;


label3:
    cout << "\tEnter Employee Post : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(post, 100);
    flag = validateInput();
    if (flag)
        goto label3;


label4:
    cout << "\tEnter Employee Department : ";
    cin.getline(department, 100);
    flag = validateInput();
    if (flag)
        goto label4;


label5:
    cout << "\tEnter Employee Salary : ";
    cin >> salary;
    flag = validateInput();
    if (flag)
        goto label5;
}

void Employee::writeFile()
{
    if (name == "no name" && id == 0)
    {
        cout << "\tEmployee Record is not initalized" << endl;
    }
    else
    {
        fstream file;
        file.open(fileName, ios::out | ios::app | ios::binary);

        file.write((char *)this, sizeof(*this));

        file.close();

        if (!file.good()) {
            cout << "\tError occurred at writing time!" << endl;
        }
    }
}

void Employee::readFile()
{
    ifstream file;
    file.open(fileName, ios::in | ios::binary);

    if (!file)
    {
        cout << "\tFile can not Open";
    }
    else
    {
        if (isEmpty(file))
        {
            cout << "\n\tYour File is Empty! No Record is Avialable to Show\n";
        }
        else
        {
            file.read((char *)this, sizeof(*this));

            while (!file.eof())
            {
                showData();
                file.read((char *)this, sizeof(*this));
            }

            file.close();
        }
    }
}

void Employee::showData()
{
    cout << "\n\tEmployee Name is : ";
    cout << name << endl;

    cout << "\tEmployee ID is : ";
    cout << id << endl;

    cout << "\tEmployee post is : ";
    cout << post << endl;

    cout << "\tEmployee Department is : ";
    cout << department << endl;

    cout << "\tEmployee Salary is : ";
    cout << salary << endl;
}

void Employee::searchData(int input)
{
    bool flag = false;

    fstream file;
    file.open(fileName, ios::in | ios::binary);

    if (!file)
    {
        cout << "\tFile Cannot be Open";
    }
    else
    {
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            if (input == id)
            {
                showData();
                flag = true;
            }
            file.read((char *)this, sizeof(*this));
        }

        file.close();

        if (!flag)
        {
            cout << "\tRecord For This ID Does Not Exist";
        }
    }
}

void Employee::updateData(int input)
{
    bool flag = false;
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::ate | ios::binary);

    if (!file)
    {
        cout << "\tFile Cannot Open Successfully!";
    }
    else
    {
        file.seekg(0, ios::beg);
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            if (input == id)
            {
                showData();
                cout << "\n\tEnter Updated Record :- \n\n";
                getData();
                int position = (-1) * static_cast<int>(sizeof(*this));
                file.seekp(position, ios::cur);
                file.write((char *)this, sizeof(*this));
                flag = true;
            }
            file.read((char *)this, sizeof(*this));
        }

        if (!flag)
        {
            cout << "\tRecord For This ID Does Not Exist";
        }
        else
        {
            cout << "\n\tNew Records Has Been Updated Successfully\n";
        }
    }
}

void Employee::deleteData(int input)
{
    int c1, c2;
    bool flag = true;
    ofstream fout;
    ifstream fin;
    fin.open(fileName, ios::in | ios::binary);

    if (!fin)
    {
        cout << "\tFile Cannot Open Successfully!";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        fout.open("tempfile.dat", ios::out | ios::binary);
        while (!fin.eof())
        {
            if (input != id)
            {
                fout.write((char *)this, sizeof(*this));
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();

        fstream f1, f2;
        f1.open(fileName, ios::in | ios::binary);
        f2.open("tempfile.dat", ios::in | ios::binary);

        while (true)
        {
            c1 = f1.get();
            c2 = f2.get();
            if (c1 != c2)
            {
                flag = false;
                break;
            }
            if ((c1 == EOF) || (c2 == EOF))
                break;
        }

        f1.close();
        f2.close();

        if (flag)
        {
            cout << "\tRecord For This ID Does Not Exist";
        }
        else
        {
            label:
            fstream file;
            file.open(fileName, ios::in | ios::binary);
            int choice;
            while (file.read((char *)this, sizeof(*this)))
            {
                if (input == id)
                {
                    showData();
                }
            }
            file.close();
            cout << "\n\tAre Your Sure to Delete The Above Record\n";
            cout << "\t1 : Yes\n";
            cout << "\t2 : No\n";
            cout << "\tEnter Your Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                remove(fileName);
                rename("tempfile.dat", fileName);
                cout << "\n\n\tRecord is Deleted Successfully";
            }
            else if (choice == 2)
            {
                remove("tempfile.dat");
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tError : Invalid Choice Detected! Please Enter Valid Choice";
                goto label;
            }
        }
    }
}

int mainmenu()
{
    system("cls");
    int choice;
    bool flag;
    cout << "\n\n <================= Employee Managment System =================>\n\n";
    cout << "\tPlease Select Your Choice :- \n";
    cout << "\t1 : Insert Employees Records\n";
    cout << "\t2 : View All Employees Records\n";
    cout << "\t3 : Search Employees Records\n";
    cout << "\t4 : Update Employee Records\n";
    cout << "\t5 : Delete Employee Records\n";
    cout << "\t6 : Exit Application\n";
label:
    cout << "\tEnter Your Choice : ";
    cin >> choice;

    flag = validateInput();
    if (flag)
        goto label;
    else
        return choice;
}

bool validateInput()
{

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\tError : inValid Value Detected! Please Enter Valid Value Again\n\n";

        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(ifstream &file)
{

    return (file.peek() == ifstream::traits_type::eof());
}

int main()
{
    system("color f0");
    login obj;
    cout<<"\n  *********  LOGIN WINDOW  *********  \n";
    cout<<"\n";
    obj.display();
    cout<<"\n";
    cout<<"\t\t\t\tHello, Welcome to Employee Management System";
	getch();
	deleteExistingFile();
    bool check = true;
    int search;
    int size;
    bool flag;
    Employee *ptr = NULL;
    Employee filedata;

    while (check)
    {
        system("cls");
        switch (mainmenu())
        {
        case 1:
            label:
            cout << "\tHow Many Employees Records that You Want to Store : ";
            cin >> size;

            flag = validateInput();

            if (flag)
            {
                goto label;
            }
            else
            {
                ptr = new Employee[size];

                for (int i = 0; i < size; i++)
                {
                    cout << "\n\n\tEnter the Details For the Employee # " << i + 1 << endl;
                    ptr[i].getData();
                }

                for (int i = 0; i < size; i++)
                {
                    ptr[i].writeFile();
                }

                delete [] ptr;

                cout << "\n\tNew Records Has Been Added Successfully\n";
                break;
            }
        case 2:
            cout << "\n\n\t=============== Employee Details ==================\n\n";
            filedata.readFile();
            break;
        case 3:
            cout << "\tPlease Enter Employee Unique ID That you Want to Search its Record : ";
            cin >> search;
            filedata.searchData(search);
            break;
        case 4:
            cout << "\tPlease Enter Employee Unique ID That you Want to Update its Record : ";
            cin >> search;
            filedata.updateData(search);
            break;
        case 5:
            cout << "\tPlease Enter Employee Unique ID you Want to Delete its Record : ";
            cin >> search;
            filedata.deleteData(search);
            break;
        case 6:
            cout << "\n\tThank You For Using This Application\n";
            check = false;
            break;
        default:
            cout << "\tInvalid Choice! Please Select Valid Choice.";
            break;
        }
        cout << "\n";
        cout << "\t" << system("pause");
    }
}
