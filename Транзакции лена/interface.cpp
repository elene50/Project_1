#include "interface.h"

template <class T>
int Interface<T>::check()
{
		int check;
		cout << "������� ����������?(1/0) ";
		cin >> check;
		return check;	
}

template <class T>
void Interface<T>::menu()
{
		int choise;
		do{
			system("cls");
			cout << "1. ������������ ���������� ����" << endl;
			cout << "2. ������������ �������� ����" << endl;
			cout << "3. ����������� ���������� ����" << endl;
			cout << "4. ����������� ���������" << endl;
			cout << "0. �����" << endl;
			cout << "�������� ��� �����: ";
			cin >> choise;
			switch(choise)
			{
				case 1:
				{
					Interface <Table_Mechanical> obj;
					obj.menu1();
					choise = obj.check();
					break;}
				case 2:
				{
					Interface <Hand> obj;
					obj.menu1();
					choise = obj.check();
					break;}
				case 3:
				{
					Interface <Table_Electronic> obj;
					obj.menu1();
					obj.check();
					break;}
				case 4:
				{
					Interface <Alarm> obj;
					obj.menu1();
					obj.check();
					break;}
			}
		} while(choise != 0);
}

template <class T>
void Interface<T>::menu1()
{
		int choise = 1;
		T find_obj, ob1;
		char name[20];
		Trans<Circle<T> > tr;
		while(choise != 0)
		{
			system("cls");
			cout << "1. ���������� ��������" << endl;
			cout << "2. �������������� ��������" << endl;
			cout << "3. ����� ���������� � ��������� �����" << endl;
			cout << "4. ��������" << endl;
			cout << "5. ����� ��������" << endl;
			cout << "6. ������ ���������� ��������" << endl;
			cout << "0. �����" << endl;
			cout << "�������� ��� �����: ";
			cin >> choise;
			system("cls");
			switch(choise)
			{
				case 1:
					if(tr.begin()) 
					{
						cin >> ob;
						tr->add(ob);	
					}
					choise = check();
					break;
				case 2:
					cout << "������� �������� �����, ������� �� ������ �������������: ";
					cin >> name;
					ob.change_name(name);
					if(tr->find(ob, 0))
					{
						ob = tr->ob;
						menu_change(ob, tr);
					}
					choise = check();
					break;
				case 3:
					print(ob);
					tr->print();
					choise = check();
					break;
				case 4:
					menu_del(tr);
					choise = check();
					break;
				case 5:
					cout << "������� �������� �����, ������� ������� �����: ";
					cin >> name;
					ob.change_name(name);
					if(tr.begin()) 
					{
						print(ob);
						tr->find(ob, 1);
					}
					choise = check();
					break;
				case 6:
					tr.del();
					choise = check();
					break;
				case 0:
					choise = 0;
					break;
			}
		} 
}

template <class T>
void Interface <T>::menu_change(Table_Mechanical &find_obj, Trans<Circle<T> > &tr)
{
		T name_obj;
		char str[20];
		int pick, s;
		cout << "1. ������" << endl;
		cout << "2. ��� �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. �������� �������" << endl;
		cout << "5. �����������" << endl;
		cout << "�������� ����, ������� ������� ��������: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "������� ����� �������� ������: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "������� ����� ��� �������: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "������� ����� ��������: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin())
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "������� ����� �������� �������: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "������� ����� �����������: ";
				cin >> s;
				find_obj.change_accuracy(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
		}
}

template <class T>
void Interface <T>::menu_change(Hand &find_obj, Trans<Circle<T> > &tr)
{
		T name_obj;
		char str[20];
		int pick, s;
		cout << "1. ������" << endl;
		cout << "2. ��� �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. �������� �������" << endl;
		cout << "5. �������� �������" << endl;
		cout << "6. �������������������" << endl;
		cout << "�������� ����, ������� ������� ��������: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "������� ����� �������� ������: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "������� ����� ��� �������: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "������� ����� ��������: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "������� ����� �������� �������: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "������� ����� �������� �������: ";
				cin >> str;
				find_obj.change_material_strap(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 6:
				cout << "���� �����������������?(1/0) ";
				cin >> s;
				find_obj.change_water_protected(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
		}
}

template <class T>
void Interface <T>::menu_change(Table_Electronic &find_obj, Trans<Circle<T> > &tr)
{
		T name_obj;
		char str[20];
		int pick, s;
		cout << "1. ������" << endl;
		cout << "2. ��� �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. �������� �������" << endl;
		cout << "5. ���������" << endl;
		cout << "�������� ����, ������� ������� ��������: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "������� ����� �������� ������: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "������� ����� ��� �������: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "������� ����� ��������: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "������� ����� �������� �������: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "���� ����� ���������?(1/0) ";
				cin >> s;
				find_obj.change_backlight(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
		}
}

template <class T>
void Interface <T>::menu_change(Alarm &find_obj, Trans<Circle<T> > &tr)
{
		char str[20];
		int s, pick;
		T name_obj;
		cout << "1. ������" << endl;
		cout << "2. ��� �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. �������� �������" << endl;
		cout << "5. ����������������" << endl;
		cout << "�������� ����, ������� ������� ��������: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "������� ����� �������� ������: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "������� ����� ��� �������: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "������� ����� ��������: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "������� ����� �������� �������: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "���� �������� ���������������?(1/0) ";
				cin >> s;
				find_obj.change_kick_protected(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
		}
}

template <class T>
void Interface <T>::menu_del(Trans<Circle<T> > &tr)
{
		int pick;
		char name[20];
		T obj_name;
		cout << "1. �������� �� �������� �����" << endl;
		cout << "2. �������� ����� ������" << endl;
		cout << "�������� ��� �����: ";
		cin >> pick;
		switch(pick)
		{
			case 1:
				cout << "������� �������� �����, ������� �� ������ �������: ";
				cin >> name;
				obj_name = ob;
				obj_name.change_name(name);
				if(tr.begin()) 
					tr->del_obj(obj_name);
				break;
			case 2:
				if(tr.begin())
				tr->del_all();
				break;
		}
}

template <class T>
void Interface <T>::print(Table_Mechanical &obj)
{
		cout << "������������ ���������� ����" << endl;
		cout << "|" << setw(10) <<left<< "������" << "|" << setw(5) << left << "���" << "|" << setw(10) << left << "��������" << "|" << "��������" << "|" << "�����������" << "|"<<endl;
		cout << "|__________|_____|__________|________|___________|" << endl;
}

template <class T>
void Interface <T>::print(Hand &obj)
{
		cout << "������������ �������� ����" << endl;
		cout << "|" << setw(10) <<left<< "������" << "|" << setw(5) << left << "���" << "|" << setw(10) << left << "��������" << "|" << "��������" << "|" << "�������" << "|" << "��������." << "|" << endl;
		cout << "|__________|_____|__________|________|_______|_________|" << endl;
}

template <class T>
void Interface <T>::print(Table_Electronic &obj)
{
		cout << "����������� ���������� ����" << endl;
		cout << "|" << setw(10) <<left<< "������" << "|" << setw(5) << left << "���" << "|" << setw(10) << left << "��������" << "|" << "��������" << "|" << "���������" << "|" << endl;
		cout << "|__________|_____|__________|________|_________|" << endl;
}

template <class T>
void Interface <T>::print(Alarm &obj)
{
		cout << "����������� ���������" << endl;
		cout << "|" << setw(10) <<left<< "������" << "|" << setw(5) << left << "���" << "|" << setw(10) << left << "��������" << "|" << "��������" << "|" << "���������." << "|" << endl;
		cout << "|__________|_____|__________|________|__________|" << endl;
}