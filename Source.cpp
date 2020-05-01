#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <functional>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <map>
#include "AppClass.h"
#include "statemap.h"

using namespace std;
using namespace statemap;

int Input(); 
int Read();  
int Show();  

#define SIZE 4
static const std::array<string, SIZE> msgs = { "1. Input", "2. Read from file", "3. Show statistic", "4. Exit" };
static const std::array<function<bool()>, SIZE> func = { Input, Read, Show };

int getInt(int&);

int main()
{
	int c;
	const char* msg = "";
	do
	{
		system("cls");
		for (int i = 0; i < SIZE; i++)
		{
			cout << msgs[i].c_str() << endl;
		}
		cout << "Your choice:------>";
		do
		{
			cout << msg;
			getInt(c);
			msg = "Error! Repeat, please!";

		} while (c > 4);
		if (c != 4) func[c-1]();
		msg = "";
	} while (c != 4);

	cout << "\n\n" << endl;
	cout << "--------------That's all! Bye!--------------------------";
	return 0;
}

int Input()
{
	 AppClass thisContext;
	cout << "Enter string:" << endl;
	string str;
	cin.ignore();
	getline(cin, str);
	if (thisContext.CheckString(str)) 
	{
		cout << "Right!" << thisContext.get() << endl; 
		ofstream f = ofstream("statistic.txt", ofstream::app);
		f << thisContext.get() << endl; 
		f.close();
	}
	else
	{
		cout << "Wrong!" << endl;
	}
	system("pause");
	return 1;
}



int Read()
{
	fstream fi;
	fi.open("input.txt", ios::in);
	if (fi.good()) 
	{
		while (!fi.eof()) 
		{
			AppClass thisContext;
			string str;
			string result;
			getline(fi, str); 
			cout << "string: " << str << " -> ";
			if (thisContext.CheckString(str))
			{
				result = thisContext.get();
				cout << "Right! " << result << endl; 
				ofstream
					f = ofstream("statistic.txt", ofstream::app);
				f << result << endl; 
				f.close();
			}
			else
			{
				cout << "Wrong!" << endl;
			}
		}
		cout << "file ended" << endl;
	}
	else
	{
		cout << "file input.txt not found" << endl;
	}
	fi.close();
	system("pause");
	return 1;
}


int Show()
{
	map<string, int> stat; 
	fstream i;
	i.open("statistic.txt", ios::in);
	if (i.good())
	{
		while (!i.eof())
		{
			string str;
			getline(i, str);
			if (str.empty()) 
				continue;
			if (stat.find(str) != stat.end())
				stat[str]++; 
			else
				stat.insert(pair<string, int>(str, 1)); 
		}
		for (const auto& it : stat)
			cout << it.first << " : " << it.second << endl; 
	}
	else
	{
		cout << "file statistic.txt not found" << endl;
	}
	system("pause");
	return 1;
}

int getInt(int& a)
{
	cin >> a;
	if (!cin.good())
		return -1;
	return 1;
}