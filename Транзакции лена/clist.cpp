#include "clist.h"

template <class T>
Circle<T>::Circle(const Circle <T> &obj)
{
		this->Head = NULL;
		this->Curr = NULL;
		this->length = 0;
		CircleNode <T> *p = obj.Curr;
		for(int i = 0; i < obj.length; i++)
		{
			add(p->data);
			p = p->next;
		}
}

template <class T>
void Circle<T>::add(T &obj)
{	
		CircleNode <T> *p = new CircleNode <T>;
		p->data = obj;
		if (Curr == NULL) 
		{
			Head = p;
			Curr = p; 
			Curr->next = p; 
			Curr->prev = p; 
		}
		else 
		{
			p->next = Curr->next; 
			p->next->prev = p;	
			Curr->next = p;  
			p->prev = Curr;  
		}
		length++; 
		Curr = p; 
}

template <class T>
void Circle<T>::print()
{
		if (Curr != NULL) 
		{
			CircleNode <T> *p = Head; 
			for (int i=0; i < length; i++) 
			{ 
				cout << p->data; 
				p = p->next ; 
			} 
		}
		else 
		{
			system("cls");
			cout<< "Кольцо не содержит данных!" << endl ;     
		}
}

template <class T>
void Circle<T>::change(T &obj, T &obj_change)
{
		if(Curr != NULL)
		{
			CircleNode <T> *p = Head; 
			for(int i=0; i < length; i++)  
			{
				if(p->data == obj)
					p->data = obj_change;
				p = p->next; 
			}
		}
		
}

template <class T>
int Circle<T>::find(T &obj, int choise)
{
		int check = 0;
		if(Curr != NULL)	
		{
			CircleNode <T> *p = Head; 
			for(int i=0; i < length; i++)  
			{
				if(p->data == obj)
				{
					if(choise == 1)
						cout << p->data;
					check++;
					ob = p->data;
				}
				p = p->next;
			}
		}
		if(check == 0)
		{
			system("cls");
			cout << "Часов с таким названием не существует!" << endl;	
		}
		return check;
}

template <class T>
T Circle<T>::pop() 
{
		T obj; 
		CircleNode <T> *p = Curr; 
		obj = p->data; 
		if (length==1) 
		{
			Head=NULL;
			Curr=NULL; 
		}
		else 
		{
			Curr->next->prev = Curr->prev; 
			Curr->prev->next = Curr->next; 
			Curr = Curr->next; 
		}
		if(p == Head) 
			Head = Head->next; 
		length--;  
		delete p; 
		return obj; 
}

template <class T>
void Circle<T>::del_obj(T &obj) 
{
	if(Curr != NULL)
		{
			CircleNode <T> *p = Curr;
			for(int i=0; i < length; i++)  
			{
				if(Curr->data == obj) 
				{
					if(Curr == p)
						p = p->next;
					pop(); 
				}
				if(Curr!=NULL)
				Curr = Curr->next; 
			}
			
		}
}

template <class T>
void Circle<T>::del_all()
{
		for(int i = 0; i < length;)
			pop();
}

