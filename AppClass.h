

#include <string>
#include "Automata_sm.h"

class AppClass
{
private:

	AutomataContext _fsm;
	bool isAcceptable;
	std::string buf;  
	std::string type; 
	int count;
	char temp;
	

public:

	AppClass() : _fsm(*this), isAcceptable(true), count(0) { }
	~AppClass() {};
	bool CheckString(std::string);
	void inc() { ++count; }
	void clear() { count = 0; }
	void less(int number);
	void print(std::string message);
	void add();
	std::string get() const { return buf; }
	void pushHeadline() { type += temp; }
	void check();
	void Refresh() { count = 0; isAcceptable = true; }
	inline void Acceptable() { isAcceptable = true; };
	inline void Unacceptable() { isAcceptable = false; };
};


