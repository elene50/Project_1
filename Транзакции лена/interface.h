#include "clist.cpp"
#include "trans.cpp"

template <class T>
class Interface
{
	T ob;
	Circle <T> circle;
public:
	int check();
	void menu();
	void menu1();
	void menu_change(Table_Mechanical &find_obj, Trans<Circle<T> > &tr);
	void menu_change(Hand &find_obj, Trans<Circle<T> > &tr);
	void menu_change(Table_Electronic &find_obj, Trans<Circle<T> > &tr);
	void menu_change(Alarm &find_obj, Trans<Circle<T> > &tr);
	void menu_del(Trans<Circle<T> > &tr);
	void print(Table_Mechanical &obj);
	void print(Hand &obj);
	void print(Table_Electronic &obj);
	void print(Alarm &obj);
};

