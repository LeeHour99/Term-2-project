// finish project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//GROUP IT SD M8
//NAME: LEANG LYHOUR


#include <iostream>
#include <fstream> 
#include <string> 
#include <windows.h>//for the use of sleep
#include <cstdlib> // to generate random numbers
#include <ctime>
#include <conio.h>
#include<algorithm>
#include<map>
//#include<iterator>
//the code aint good enough and unreadable, uncleannnnn
// with all these lines of codes im really not in the mood to do file seperating lol;
using namespace std;

class Login
{
protected:
	string username, password;
public:
	Login()
	{
		username = "";
		password = "";
	}
	Login(string username, string password)
	{
		this->username = username;
		this->password = password;
	};
	//virtual int choice() {};

	//All these mothods like Login can perform different tasks one for admin and one for player 
	//It's the use of dynamically polymorphism when functions are delcalred as virtual  
	//and a pure virtual function in class made abstract class

	virtual void login() = 0;// pure virtual function. Must be override
	virtual void createAcc() {};//can be override 
	virtual void existAcc() {};
	virtual void choice() {};
};

class Admin :public Login
{
private:
	string password;// string newpass;
public:
	//vector<Login> AdminPass;
	char a = 0;
	Admin()
	{
		password = "";
		//newpass = "";
	}
	Admin(/*string newpassword*/ string pass)
	{
		this->password = password;
		//this->newpass = newpass;
	}
	/*	string getNewpass(string newpass) const
		{
			return newpass;
		}
		*/
	string getPass(string password) const
	{
		return password;
	}
	void setPass(string password)
	{
		cin >> password;
		this->password = password;
	}
	/*void setNewpass(string newpass)
	{
		cin >> newpass;
		this->newpass = newpass;
	}*/
	//login function for admin;
	void login()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 2+2 is? ";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Password: ";
		//getch wont respond to loop for login attempt function and if it does 
		//the previous value won't get deleted so user only have one attempt with 
		//this password login as asterisk
		while (a != '\r') //Loop until 'Enter' is pressed
		{
			a = _getch();// getch for cin and hold the value of "a" and display as asterisk "*" in cout
			//If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
			if (a <= '9' && a >= '0' || a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
			{
				password += a;
				cout << "*";
			}
		}

		if (getPass(password) == "4")
		{
			system("cls");
		}

		else
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong Password.. Do The Math!  ";
			//	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPhone No. 078 123 456 ";
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tReturning to Main Menu.." << endl;
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t";
			Sleep(1000);
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t";
			exit(0);
		}
	}
	//	void display();
};

class Player :public Login
{
private:
	string username, password, newuser, newpass, name;
	int age;
public:
	Player()
	{
		username = ""; password = ""; newpass = ""; newpass = ""; name = "";
		age = 0;
	}
	Player(string newuser, string newpass, string name, int age) :Login(username, password)//username and password inherite from login constuctor
	{
		this->age = age;
		this->name = name;
		this->newuser = newuser;
		this->newpass = newpass;
	};
	int getAge() const {
		return age;
	}
	void setAge(int age)//age validation
	{
		cin >> age;
		if (age < 18)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer must be 18 or older";
			exit(0);
		}
		this->age = age;
	}
	string getName() const
	{
		return name;
	}
	void setName(string name)
	{
		cin.ignore();
		getline(cin, name);
		this->name = name;
	}
	string getPass() const
	{
		return password;
	}
	string getUser() const
	{
		return username;
	}
	void setPass(string password)
	{
		cin >> password;
		this->password = password;
	}
	void setUser(string username)
	{
		cin >> username;
		this->username = username;
	}
	string getNewuser() const
	{
		return newuser;
	}
	string getNewpass() const
	{
		return newpass;
	}
	void setNewuser(string newuser)
	{
		cin >> newuser;
		this->newuser = newuser;
	}
	void setNewpass(string newpass)
	{
		cin >> newpass;
		this->newpass = newpass;
	}
	void choice()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 1. CREATE A NEW ACCCOUNT";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 2. USE AN EXISTING ACCOUNT " << endl << "\n";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t OPTION :  ";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			createAcc();
			break;
		case 2:
			existAcc();
			break;
			//	case 3:
				//		MainMenu();
		default:
			cout << "Invalid!";
			break;
		}
	}

	void createAcc() //login function for player
	{
		system("cls");
		ofstream inData;
		// Takes and stores users login information, username and password
		inData.open("Account.txt", ios::app);//*open file,

		// The display
		//drawline(120, '_');
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t*CREATE AN ACCOUNT*\n\n\n";
		//	drawline(120, '_');
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t(USE _ AS SPACE FOR THE NAME)";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer's name: ";
		setName(name);
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tPlayer's age: ";
		setAge(age);

		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tnew username: ";
		setNewuser(newuser);

		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tnew password: ";
		setNewpass(newpass);
		//save data in Account.txt
		inData << newuser << " " << newpass << "\n" << name << " " << age << endl;

		inData.close();//close file

		// To process the account after creating
		system("cls");// To clear screen
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tRegistering your new account.";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t*";
		for (int a = 1; a < 28; a++)
		{
			cout << "*";
			Sleep(30);
		}
		cin.sync();

		// Another loop
		system("cls");// To clear screen
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tRegistered successfully.";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t*";
		for (int a = 1; a < 24; a++)
		{
			cout << "*";
			Sleep(40);
		}
		cin.sync(); cin.ignore();
		login();
		gameMode();
		//	main();
	}

	void login()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t*LOG INTO ACCOUNT*\n\n\n";
		char a = 0;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tUsername: ";
		setUser(username);
		//getUser(username);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tPassword: ";
		while (a != '\r') //Loop until 'Enter' is pressed
		{
			a = _getch();
			//If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
			if (a <= '9' && a >= '0' || a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
			{
				password += a;
				cout << "*";
			}
			else
				break;
		}
		//check(getUser(username), newuser, getPass(password), newpass);
		//getPass(password);
		if (getUser() == getNewuser() && getPass() == getNewpass())
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tLOGIN SUCCESS!";
			//Sleep(100);
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tWrong Password.. Call Administrator";
			cout << "\n\t\t\t";
			Sleep(1000);
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress Enter to Continue.";
			cout << "\n\t\t\t";
			exit(0);
		}
		approve();

	}

	void existAcc()
	{
		//char a=0;
		int loginAttempt = 0;
		string userAndPass, line; // For the read data from the file
		bool found = false;
		fstream RData;
		system("cls");
		//system("cls");
		//drawline(120, '_');
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t*LOG INTO ACCOUNT*\n\n\n";
		//drawline(120, '_');
		// Player has 5 times login attempt
		while (loginAttempt < 5)
		{
			RData.open("Account.txt", ios::in);// Open saved file
			if (RData.is_open())
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tusername: ";
				setUser(username);
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tpassword: ";
				setPass(password);

				userAndPass = getUser() + " " + getPass();
				while (getline(RData, line) && !found)
				{
					if (line.compare(userAndPass) == 0)  //match strings exactly!
					{
						found = true; // found is true => break loop
					}
				}
				RData.close(); //close the file before recursivly opening it again later
				if (found)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tLOGIN SUCCESS!.\n";
					break;
				}
				else
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tYour username or password is incorrect. Please try again.\n" << '\n';
					loginAttempt++;
				}found = false;
			}
			if (loginAttempt == 5)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tToo many login attempts! The program will now terminate.\n\n";
				exit(1);
			}
		}
		approve();
		gameMode();
		//main();
	}
	/*	void Delete()
		{
			system("cls");
			cout << "\n\t\t\tPLAYER NAME TO DELETE: " << endl;
			string user;
			cin >> user;

			//Player acc;
			ifstream inAcc;
			ofstream delAcc;
			inAcc.open("Account.txt", ios::in);
			if (!inAcc)
			{
				cout << "File could not be open !! Press any Key...";
				return;
			}
			delAcc.open("Temp.txt", ios::out | ios::app);
			//inAcc >> accUser.getUser();

			inAcc.seekg(0, ios::beg);
			while (inAcc >> newuser >> newpass >> name >> age)
			{
				if (newuser != user)
				{
					delAcc << newuser << newpass << name << age;
				}
				//getData();
			}
			inAcc.close();
			delAcc.close();
			remove("Account.txt");
			rename("Temp.txt", "Account.txt");
			cout << "\n\nRecord Deleted ..";
			system("cls");
			choice2();
		}
		*/
	void approve()
	{
		char appr;
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tOkeh?? (y/n)";
		cin >> appr;
		switch (appr)
		{
		case'y':
			break;
		case'n':
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t You have been kicked out since youre not okeh!!\n\t\t\t\t\t\t\t\t\t\t\t\t\tcome back later";
			exit(0);// Program will terminate if the user is a robot
		}
	}
	void gameMode()
	{
		//to save the amount it would be 2 of this function. one for continuation of the game with the previous game amount
		//Debugging this part is really stressful for me and not enough time
		//so i decided to drop. player can reset the amount as please
		int amount;
		int bettingAmount;
		int guess;
		int dice;
		char choice;
		system("cls");
		rules();
		//cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t" << name;
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDeposit Your Amount to play : $";// player inputs the amount to play
		cin >> amount;
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tYour current balance is $  " << amount << "\n\n";
		do
		{

			// Get player's betting amount
			do
			{
				// Start with the name of plyer
				cout << "\t\t\t\t\t\t\t\t\t\t\t" << name; cout << " ,You ready to play?" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tPlease enter bid amout : $";// Start with bid amount
				cin >> bettingAmount;
				if (bettingAmount > amount)
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tYou can not bid more than your current balance\n\n"
					<< "\n\t\t\t\t\t\t\t\t\t\t\tRe-enter Amount\n ";
			} while (bettingAmount > amount);

			// Get player's numbers
			do
			{
				// Starts guessing number
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tBet the number between 1 to 5: "; cin >> guess; cout << endl;
				if (guess <= 0 || guess > 5)
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tPlease check the number!! should be between 1 to 5\n"
					<< "\n\t\t\t\t\t\t\t\t\t\t\tRe-enter Number\n ";
			} while (guess <= 0 || guess > 5);

			dice = rand() % 5 + 1; // hold the randomly generated integer between 1 and 5

			// Checks if the numbers are matched
			if (dice == guess)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tHurray!! You won Rs." << bettingAmount * 10 << endl;
				amount = amount + bettingAmount * 5;
			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tBad Luck this time!! You lost $ " << bettingAmount << "\n";
				amount = amount - bettingAmount;
			}

			// Suprise time for player
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tThe winning number was : " << dice << "\n";
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << name; cout << ",Your remaining money is $ " << amount << "\n";

			// Lets see if the player out of money
			if (amount == 0)
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t"; system("pause");
				// A friendly reminder from the game creator
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tGo home!! And bring more money\n\n ";
				break;
			}
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t-->You still want to play/lose again (y/n)?\n\n";
			cin >> choice;
		} while (choice == 'Y' || choice == 'y');
	}
	void rules()
	{
		//cout << "Congratulation!! Since You Are A Humnan Now You Can Access To The Game. ENJOY";
		cout << "\n\n";
		drawline(237, '_');
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tRULES OF THE GAME\n";// The display
		drawline(237, '_');
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Choose any number between 1 to 5\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t2. If you win you will get 10 times of money you bet\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\tt3. If you bet on wrong number you will lose your betting amount\n";
		drawline(237, '_');
	}

	void drawline(int n, char s)
	{
		for (int i = 0; i < n; i++)
			cout << s;
		cout << "\n";
	}

	void display()
	{
		system("cls");
		ifstream d;
		d.open("Account.txt", ios::in);
		int count = 0;
		if (d.fail())
		{
			cerr << "Error Opening File" << endl;
			exit(1);
		}
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    ALL PLAYER\n";
		//	cout << "Name              Age" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t _________________________________________\n\n";
		while (d.good())
		{
			if (d >> newuser >> newpass >> name >> age)
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t Name: " << name << "\t\tAge: " << age;
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t _________________________________________\n\n";
			}
			count++;
		}
		d.close();
		cin.ignore();
		cin.get();
		choice2();
	}
	void searchPlayer()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t PLAYER'S NAME: ";
		string sname;
		cin >> sname;
		int count = 0;
		ifstream s;
		//bool found = false;
		s.open("Account.txt", ios::in);
		//	while (s.good()) {
		while (s.good())
		{
			if (s >> newuser >> newpass >> name >> age)
			{
				if (name == sname)
				{
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t " << sname << "EXISTS IN THIS PROGRAM AND HIS/HER AGE IS........." << age;;
					break;
				}
				else
				{
					cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t WHO IS " << sname << " ???";
				};
				break;
			}
			//	found = true;
			count++;
			//break;
		}
		s.close();
		cin.ignore();
		cin.get();
		choice2();
	}
	//i might use unordered multimap and multimap for view,search, sort and delete 
	//but since there isnt much time to deal with bunches of errors, map will be used for just sort function.
	//------------THE PROCESS BELOW-----------
	//to sort multimap container will be used since the key value can hold multiples variable
	//(the key value is age player can have different name but the same age
	//since multimap is sorted container and the key value in accending order 
	//so it will display the age is sorted in accending order whe using this function
	//And that's pretty much it
	//P.s: firstly read date from file then map it in multimap
	template<class k, class t>
	void printMap(const multimap<k, t>& mmap)
	{
		for (auto it = mmap.begin(); it != mmap.end(); it++)
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Name: " << it->second << "\t\tAge: " << it->first;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t _________________________________________\n\n";
		}
	}

	void sortBy_age()
	{
		ifstream sortt;
		string b;
		int a;
		int count = 0;
		sortt.open("Account.txt", ios::in);
		if (sortt.fail())
		{
			cerr << "Error Opening File" << endl;
			exit(1);
		}
		multimap<int, string> sort_p;
		while (sortt.good())
		{
			if (sortt >> newuser >> newpass >> name >> age)
			{
				a = age;
				b = name;
				sort_p.insert({ a,b });
			}
			count++;
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t PLAYER SORT BY AGE";
		printMap(sort_p);
		sortt.close();
		cin.ignore();
		cin.get();
		choice2();
	};


	void deletePlayer() {
		system("cls");
		string a, b;
		int count = 0;

		ifstream d;
		ofstream delAcc;
		d.open("Account.txt", ios::in);
		if (d.fail())
		{
			cerr << "Error Opening File" << endl;
			exit(1);
		}
		delAcc.open("Temp.txt", ios::out | ios::app);
		multimap<string, string> delete_p;
		while (d.good())
		{
			if (d >> newuser >> newpass >> name >> age) {
				{
					a = newuser;
					b = name;
					delete_p.insert({ a,b });
					//  	delete_p.erase(a);
				}
				count++;
			}
			//	else if()
		}
		for (auto it = delete_p.begin(); it != delete_p.end(); it++)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t USERNAME: " << it->first << "\t\tNAME: " << it->second;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t _________________________________________\n\n";
		}
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t BAN PLAYER\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t PLAYER'S USERNAME: ";
		cin >> a;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t PLAYER'S NAME: ";
		cin >> b;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t player wont get deleted and i have no idea why\n\n";
		delete_p.erase(a);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t" << b << " IS BAN \n";
		for (auto it = delete_p.begin(); it != delete_p.end(); it++)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t USERNAME: " << it->first << "\t\tNAME: " << it->second;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t _________________________________________\n\n";
		}
		while (delAcc.good())
		{
			delAcc << newuser << " " << newpass << "\n" << name << " " << age << endl;
			count++;
		}
		d.close();
		delAcc.close();
		remove("Account.txt");
		rename("Temp.txt", "Account.txt");
		cin.ignore();
		cin.get();
		choice2();
	}
	void choice2()
	{
		//GotoXY(50, 1);
		system("cls");
		int x = 0;;
		cout << "\n\n\n\n";
		//art();
		cout << endl;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  1. VIEW PLAYER";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  2. SEARCH PLAYER";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  3. SORT PLAYER";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  4. BAN PLAYER";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  5. EXIT";
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  OPTION :  ";
		cin >> x;
		switch (x)
		{
		case 1:
			display();
			break;
		case 2:
			searchPlayer();
			break;
			//	case 3:
			//		system("cls");
			//		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tUNDONE FUNCTION\n";
			//		break;
		case 3:
			system("cls");
			sortBy_age();
			break;
		case 4:
			deletePlayer();
			//	case 5:
			//		system("cls");
			//		MainMenu();
		case 5:
			exit(0);
		default:
			cout << "invalid";
			break;
		}
	}
};

//source: internet
void current_time()
{
	char dateStr[9];
	char timeStr[9];
	//http://msdn.microsoft.com/en-us/library/585kfedd(VS.80).aspx
	_strdate_s(dateStr);
	//http://msdn.microsoft.com/en-us/library/yb2bth04(VS.80).aspx
	_strtime_s(timeStr);

	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tDATE: " << dateStr << "\tTIME:" << timeStr << endl;
}

//source: google
void GotoXY(int x, int y)
{
	HANDLE a;
	COORD b;
	fflush(stdout);
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, b);
}
//source: google
void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void art()//using text to ascii art convertor. simply search on google
{
	//GotoXY(130, 30);
	ifstream ifs("Ascii_art.txt");
	string Lines = "";

	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n\t\t\t\t\t\t\t";

			Lines += TempLine;
		}

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t" << Lines;
	}

	ifs.close();
}

void MainMenu()
{
	fullscreen();

	//srand(time(0)); // "Seed" the random generator/ random numbers

	Login* l; //base class pointer
	Admin a;

	Player p;
	art();
	GotoXY(20, 30);
	current_time();
	cout << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  1. ADMIN";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  2. PLAYER";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  3. EXIT" << endl << "\n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t OPTION :  ";
	int y;
	cin >> y;
	switch (y)
	{

	case 1:
		l = &a;//assinging derived class object's address
		l->login();//point to derived class method from base class object
		p.choice2();
		break;
	case 2:
		l = &p;
		l->choice();
		break;

	case 3:
		// Sleep(1000); Zzzzzzzzzzz
		exit(0);
	default:
		cout << "invalid";
		break;
	}


}

int main()
{
	MainMenu();
	return 0;
}