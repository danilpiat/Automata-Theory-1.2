#include "AppClass.h"
#include <cctype>
#include <iostream>
#include <regex>

using namespace std;

int isletter(char a)
{
	regex re("[a-zA-Z]");
	string c(1, a);
	if (!regex_match(c, re)) return 0;
	return 1;
}

int isnumber(int a) {
	regex re("[0-9]");
	string c(1, a);
	if (!regex_match(c, re)) return 0;
	return 1;
}

bool AppClass::CheckString(string str)
{
	_fsm.enterStartState();
	isAcceptable = true;
	
	for (const auto& c : str)
	{
		temp = c;
		if (!isAcceptable)
		{
			bool ret = isAcceptable;
			Refresh();
			return false;
		}
		if (isletter(c))
			_fsm.Letter();
		else if (isnumber(c))
			_fsm.Number();
		else if (c == ' ' || c == '\t' )
			_fsm.Devider();
		else if (c == ':')
			_fsm.Colon();
		else if (c == '/')
			_fsm.Slash();
		else if (c == '.')
			_fsm.Dot();
		

		else
			_fsm.Unknown();
	}
	_fsm.EOS();
	bool ret = isAcceptable;
	Refresh();
	return ret;
}

void AppClass::add() {
	
		buf += temp;
}

void AppClass::less(int number)
{
	if (count <= number) Acceptable();
	else Unacceptable();
		

}

void AppClass::print(std::string message)
{
	cout << message << endl;
}

void AppClass::check()
{
	regex re("(http|www)");
	
	if (!regex_match(type,re)) Unacceptable();
}

