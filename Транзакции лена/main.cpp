#include <iostream>
#include "interface.cpp"
#include <locale.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	Interface <int> obj;
	obj.menu();
	return 0;
}
	
