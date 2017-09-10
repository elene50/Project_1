#include "classes.h"

template <class T> class Circle;

template <class T>
struct CircleNode
{
	T data;
	CircleNode *next, *prev;
};

template <class T>
class Circle
{
	int length;
	CircleNode <T> *Head;
	CircleNode <T> *Curr;
public:
	Circle()
	{
		Head = NULL;
		Curr = NULL; 
		length = 0;
	}
	Circle(T obj)
	{
		Head = NULL;
		Curr = NULL;
		length = 0;
		add(obj);
	}
	T ob;
	~Circle()
	{
		del_all();
	}
	Circle(const Circle <T> &obj);
	void add(T &obj);
	void print();
	void change(T &obj, T &obj_change);
	int find(T &obj, int choise);
	T pop () ;
	void del_obj(T &obj) ;
	void del_all();
};

 