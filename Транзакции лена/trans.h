#include <iostream>
#include <locale.h>

using namespace std;

template <class T1>
class Trans
{
	T1 *that;
	T1 *prev;
public:
	Trans(){prev = NULL; that = new T1;}
	Trans(const Trans &obj): that(new T1(*(obj.that))), prev(NULL){}
	~Trans(){delete that; delete prev; }
	Trans& operator=(const Trans &obj);
	T1* operator->();
	int begin();
	void del();
	void commit();
};