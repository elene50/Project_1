#include "interface.h"

template <class T>
int Interface<T>::check()
{
		int check;
		cout << "Желаете продолжить?(1/0) ";
		cin >> check;
		return check;	
}

template <class T>
void Interface<T>::menu()
{
		int choise;
		do{
			system("cls");
			cout << "1. Механические настольные часы" << endl;
			cout << "2. Механические наручные часы" << endl;
			cout << "3. Электронные настольные часы" << endl;
			cout << "4. Электронный будильник" << endl;
			cout << "0. Выход" << endl;
			cout << "Сделайте ваш выбор: ";
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
			cout << "1. Добавление элемента" << endl;
			cout << "2. Редактирование элемента" << endl;
			cout << "3. Вывод информации в табличной форме" << endl;
			cout << "4. Удаление" << endl;
			cout << "5. Поиск элемента" << endl;
			cout << "6. Отмена последнего действия" << endl;
			cout << "0. Выход" << endl;
			cout << "Сделайте ваш выбор: ";
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
					cout << "Введите название часов, которые вы хотите редактировать: ";
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
					cout << "Введите название часов, которых желаете найти: ";
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
		cout << "1. Страна" << endl;
		cout << "2. Год выпуска" << endl;
		cout << "3. Название" << endl;
		cout << "4. Материал корпуса" << endl;
		cout << "5. Погрешность" << endl;
		cout << "Выберите поле, которое желаете изменить: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "Введите новое название страны: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "Введите новый год выпуска: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "Введите новое название: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin())
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "Введите новый материал корпуса: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "Введите новую погрешность: ";
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
		cout << "1. Страна" << endl;
		cout << "2. Год выпуска" << endl;
		cout << "3. Название" << endl;
		cout << "4. Материал корпуса" << endl;
		cout << "5. Материал ремешка" << endl;
		cout << "6. Водонепроницаемость" << endl;
		cout << "Выберите поле, которое желаете изменить: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "Введите новое название страны: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "Введите новый год выпуска: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "Введите новое название: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "Введите новый материал корпуса: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "Введите новый материал ремешка: ";
				cin >> str;
				find_obj.change_material_strap(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 6:
				cout << "Часы водонепроницаемые?(1/0) ";
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
		cout << "1. Страна" << endl;
		cout << "2. Год выпуска" << endl;
		cout << "3. Название" << endl;
		cout << "4. Материал корпуса" << endl;
		cout << "5. Подсветка" << endl;
		cout << "Выберите поле, которое желаете изменить: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "Введите новое название страны: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "Введите новый год выпуска: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "Введите новое название: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "Введите новый материал корпуса: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "Часы имеют подсветку?(1/0) ";
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
		cout << "1. Страна" << endl;
		cout << "2. Год выпуска" << endl;
		cout << "3. Название" << endl;
		cout << "4. Материал корпуса" << endl;
		cout << "5. Противоударность" << endl;
		cout << "Выберите поле, которое желаете изменить: ";
		cin >> pick;
		system("cls");
		switch(pick)
		{
			case 1:
				cout << "Введите новое название страны: ";
				cin >> str;
				find_obj.change_country(str);
				name_obj = find_obj;
				if(tr.begin())
					tr->change(name_obj, find_obj);
				break;
			case 2:
				cout << "Введите новый год выпуска: ";
				cin >> s;
				find_obj.change_year(s);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);									
				break;
			case 3:
				cout << "Введите новое название: ";
				cin >> str;
				name_obj = find_obj;
				find_obj.change_name(str);
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 4:
				cout << "Введите новый материал корпуса: ";
				cin >> str;
				find_obj.change_material(str);
				name_obj = find_obj;
				if(tr.begin()) 
					tr->change(name_obj, find_obj);	
				break;
			case 5:
				cout << "Часы являются противоударными?(1/0) ";
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
		cout << "1. Удаление по названию часов" << endl;
		cout << "2. Удаление всего списка" << endl;
		cout << "Сделайте ваш выбор: ";
		cin >> pick;
		switch(pick)
		{
			case 1:
				cout << "Введите название часов, который вы хотите удалить: ";
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
		cout << "МЕХАНИЧЕСКИЕ НАСТОЛЬНЫЕ ЧАСЫ" << endl;
		cout << "|" << setw(10) <<left<< "Страна" << "|" << setw(5) << left << "Год" << "|" << setw(10) << left << "Название" << "|" << "Материал" << "|" << "Погрешность" << "|"<<endl;
		cout << "|__________|_____|__________|________|___________|" << endl;
}

template <class T>
void Interface <T>::print(Hand &obj)
{
		cout << "МЕХАНИЧЕСКИЕ НАРУЧНЫЕ ЧАСЫ" << endl;
		cout << "|" << setw(10) <<left<< "Страна" << "|" << setw(5) << left << "Год" << "|" << setw(10) << left << "Название" << "|" << "Материал" << "|" << "Ремешок" << "|" << "Водонепр." << "|" << endl;
		cout << "|__________|_____|__________|________|_______|_________|" << endl;
}

template <class T>
void Interface <T>::print(Table_Electronic &obj)
{
		cout << "ЭЛЕКТРОННЫЕ НАСТОЛЬНЫЕ ЧАСЫ" << endl;
		cout << "|" << setw(10) <<left<< "Страна" << "|" << setw(5) << left << "Год" << "|" << setw(10) << left << "Название" << "|" << "Материал" << "|" << "Подсветка" << "|" << endl;
		cout << "|__________|_____|__________|________|_________|" << endl;
}

template <class T>
void Interface <T>::print(Alarm &obj)
{
		cout << "ЭЛЕКТРОННЫЙ БУДИЛЬНИК" << endl;
		cout << "|" << setw(10) <<left<< "Страна" << "|" << setw(5) << left << "Год" << "|" << setw(10) << left << "Название" << "|" << "Материал" << "|" << "Противоуд." << "|" << endl;
		cout << "|__________|_____|__________|________|__________|" << endl;
}