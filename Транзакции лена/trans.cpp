#include "trans.h"

template <class T1>
Trans<T1>&Trans<T1>::operator =(const Trans<T1> &obj)
{
	if(this!=obj)
	{
		delete that;
		that = new T1(*(obj.that));
	}
	return *this;
}

template <class T1>
T1* Trans<T1>::operator->()
{
	return that;
}

template<class T1>
int Trans<T1>::begin()
{
	delete prev;
	prev = that;
	that = new T1(*prev);
	if(!that)
		return 0;
	return 1;
}

template <class T1>
void Trans<T1>::commit()
{
	if(prev)
	{
		delete prev;
		prev = NULL;
	}
}

template<class T1>
void Trans<T1>::del()
{
	if(prev != NULL)
	{
		delete that;
		that = prev;
		prev = NULL;		
		cout << "Действие отменено." <<endl;
	}
	else
		cout << "Последнее действие уже было отменено!" << endl;
}