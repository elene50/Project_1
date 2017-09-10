#include "classes.h"
//#include "clist.h"

Clock::Clock(const Clock &obj)
{
	this->country = new char[strlen(obj.country) + 1];
	strcpy(this->country, obj.country);
	this->year = obj.year;
}

Clock &Clock::operator=(const Clock &obj)
{
	if(this!=&obj)
	{
		if(obj.country!=NULL)
		{
			delete country;
			this->country = new char[strlen(obj.country) + 1];
			strcpy(this->country, obj.country);
		}
		if(obj.year != 0)
			this->year = obj.year;
	}
	return *this;
}

Clock Clock::set_Clock(char *COUNTRY, int YEAR)
{
	country = new char[strlen(COUNTRY) + 1];
	strcpy(country, COUNTRY);
	year = YEAR;
	return *this;		
}

void Clock::get_Clock()
{
	cout << "|" << setw(10) << left << this->country << "|" << setw(5) << left << this->year << "|";
}

Clock Clock::change_country(char *COUNTRY)
{
	this->country = new char[strlen(COUNTRY) + 1];
	strcpy(this->country, COUNTRY);
	return *this;
}

Clock Clock::change_year(int YEAR)
{
	this->year = YEAR;
	return *this;
}

istream &operator>>(istream &stream, Clock &obj)
{
	char COUNTRY[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	return stream;
}

ostream &operator<<(ostream &stream, Clock &obj)
{
	obj.get_Clock();
	return stream;
}

Mechanical::Mechanical(const Mechanical &obj)
{
	this->name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	this->material_body = new char[strlen(obj.material_body) + 1];
	strcpy(material_body, obj.material_body);
}

Mechanical &Mechanical::operator=(Mechanical &obj)
{
	if(this!=&obj)
	{
		delete name;
		delete material_body;
		this->name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		this->material_body = new char[strlen(obj.material_body) + 1];
		strcpy(material_body, obj.material_body);
	}
	return *this;
}

Mechanical Mechanical::set_Mechanical(char *MATERIAL_BODY, char *NAME)
{	
	name = new char[strlen(NAME) + 1];
	strcpy(name, NAME);
	material_body = new char[strlen(MATERIAL_BODY) + 1];
	strcpy(material_body, MATERIAL_BODY);
	return *this;
}

void Mechanical::get_Mechanical()
{
	cout << setw(10) << left << this->name <<"|" << setw(8) << left << this->material_body << "|";

}

Mechanical Mechanical::change_material(char *MATERIAL_BODY)
{
	this->material_body = new char[strlen(MATERIAL_BODY) + 1];
	strcpy(material_body, MATERIAL_BODY);
	return *this;
}

Mechanical Mechanical::change_name(char *NAME)
{
	this->name = new char[strlen(NAME) + 1];
	strcpy(name, NAME);
	return *this;
}

int Mechanical::find_name(char *NAME)
{
	if(strcmp(this->name, NAME) == 0)
		return 1;
	else 
		return 0;
}

Electronic::Electronic(const Electronic &obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	material_body = new char[strlen(obj.material_body) + 1];
	strcpy(material_body, obj.material_body);
}

Electronic &Electronic::operator =(const Electronic &obj)
{
	if(this!=&obj)
	{
		if(obj.name != NULL)
		{
			delete name;
			this->name = new char[strlen(obj.name) + 1];
			strcpy(name, obj.name);
		}
		if(obj.material_body != NULL)
		{
			delete material_body;
			this->material_body = new char[strlen(obj.material_body) + 1];
			strcpy(material_body, obj.material_body);
		}
	}
	return *this;
}

Electronic Electronic::set_Electronic(char *MATERIAL_BODY, char *NAME)
{	
	name = new char[strlen(NAME) + 1];
	strcpy(name, NAME);
	material_body = new char[strlen(MATERIAL_BODY) + 1];
	strcpy(material_body, MATERIAL_BODY);
	return *this;
}

void Electronic::get_Electronic()
{
	cout << setw(10) << left << this->name <<"|" << setw(8) << left << this->material_body << "|";
}

Electronic Electronic::change_material(char *MATERIAL_BODY)
{
	this->material_body = new char[strlen(MATERIAL_BODY) + 1];
	strcpy(material_body, MATERIAL_BODY);
	return *this;
}

Electronic Electronic::change_name(char *NAME)
{
	if(name)
		delete [] name;
	this->name = new char[strlen(NAME) + 1];
	strcpy(this->name, NAME);
	return *this;
}


int Electronic::find_name(char *NAME)
{
	if(strcmp(this->name, NAME) == 0)
		return 1;
	else 
		return 0;
}

istream &operator>>(istream &stream, Electronic &obj)
{
	char COUNTRY[20],MATERIAL_BODY[20], NAME[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	return stream;
	cout << "¬ведите название часов: ";
	cin >> NAME;
	cout << "¬ведите материал корпуса: ";
	cin >> MATERIAL_BODY;
	obj.set_Electronic(MATERIAL_BODY, NAME);
	return stream;
}

ostream &operator<<(ostream &stream, Electronic &obj)
{ 
	obj.get_Clock();
	obj.get_Electronic();
	return stream;
}

Table_Mechanical::Table_Mechanical(const Table_Mechanical &obj)
{
	this->accuracy = obj.accuracy;
}

bool Table_Mechanical::operator ==(Table_Mechanical &obj)
{
	if(!strcmp(this->name, obj.name))
		return true;
	else
		return false;
}

Table_Mechanical &Table_Mechanical::operator=(const Table_Mechanical &obj)
{
	if(this!=&obj)
	{
		delete country;
		delete material_body;
		delete name;
		country = new char[strlen(obj.country)+1];
		material_body = new char [strlen(obj.material_body) + 1];
		name = new char[strlen(obj.name)+1];
		strcpy(this->country, obj.country);
		this->year = obj.year;
		strcpy(this->material_body, obj.material_body);
		strcpy(this->name,obj.name);
		this->accuracy = obj.accuracy;
	}
	return *this;
}

Table_Mechanical Table_Mechanical::set_Table(int ACCURACY)
{
	this->accuracy = ACCURACY;
	return *this;
}

void Table_Mechanical::get_Table()
{
	cout << setw(11) << left << this->accuracy << "|" << endl;
}

Table_Mechanical Table_Mechanical::change_accuracy(int ACCURACY)
{
	this->accuracy = ACCURACY;
	return *this;
}

istream &operator>>(istream &stream,  Table_Mechanical &obj)
{
	int ACCURACY;
	char COUNTRY[20],MATERIAL_BODY[20], NAME[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	cout << "¬ведите название часов: ";
	cin >> NAME;
	cout << "¬ведите материал корпуса: ";
	cin >> MATERIAL_BODY;
	obj.set_Mechanical(MATERIAL_BODY, NAME);
	cout << "¬ведите погрешность(в процентах):  ";		
	cin >> ACCURACY;
	obj.set_Table(ACCURACY);
	return stream;
}

ostream &operator<<(ostream &stream, Table_Mechanical &obj)
{
	obj.get_Clock();
	obj.get_Mechanical();
	obj.get_Table();
	return stream;
}

Hand::Hand(const Hand &obj)
{
	this->material_strap = new char[strlen(obj.material_strap) + 1];
	strcpy(material_strap, obj.material_strap);
	this->water_protected = obj.water_protected;
}

bool Hand::operator ==(Hand &obj)
{
	if(!strcmp(this->name, obj.name))
		return true;
	else
		return false;
}

Hand &Hand::operator=(const Hand &obj)
{
	if(this!=&obj)
	{
		delete country;
		delete material_body;
		delete name;
		country = new char[strlen(obj.country)+1];
		material_body = new char [strlen(obj.material_body) + 1];
		name = new char[strlen(obj.name)+1];
		strcpy(this->country, obj.country);
		this->year = obj.year;
		strcpy(this->material_body, obj.material_body);
		strcpy(this->name,obj.name);
		this->material_strap = new char[strlen(obj.material_strap) + 1];
		strcpy(material_strap, obj.material_strap);
		this->water_protected = obj.water_protected;
	}
	return *this;
}

Hand Hand::set_Hand(bool WATER_PROTECTED, char *MATERIAL_STRAP)
{
	this->material_strap = new char[strlen(MATERIAL_STRAP) + 1];
	strcpy(material_strap, MATERIAL_STRAP);
	this->water_protected = WATER_PROTECTED;
	return *this;
}

void Hand::get_Hand()
{
	cout << setw(7) << left << this->material_strap << "|" << setw(9) << left << this->water_protected << "|" << endl;
}

Hand Hand::change_material_strap(char *MATERIAL_STRAP)
{
	delete [] material_strap;
	this->material_strap = new char[strlen(MATERIAL_STRAP) + 1];
	strcpy(material_strap, MATERIAL_STRAP);
	return *this;
}

Hand Hand:: change_water_protected(bool WATER_PROTECTED)
{
	this->water_protected = WATER_PROTECTED;
	return *this;
}

istream &operator>>(istream &stream,  Hand &obj)
{
	bool WATER_PROTECTED;
	char COUNTRY[20],MATERIAL_BODY[20], NAME[20], MATERIAL_STRAP[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	cout << "¬ведите название часов: ";
	cin >> NAME;
	cout << "¬ведите материал корпуса: ";
	cin >> MATERIAL_BODY;
	obj.set_Mechanical(MATERIAL_BODY, NAME);
	cout << "¬ведите материал ремешка:  ";
	cin >> MATERIAL_STRAP;
	cout << "„асы водонепроницаемые?(1/0) ";
	cin >> WATER_PROTECTED;
	obj.set_Hand(WATER_PROTECTED, MATERIAL_STRAP);
	return stream;
}

ostream &operator<<(ostream &stream, Hand &obj)
{
	obj.get_Clock();
	obj.get_Mechanical();
	obj.get_Hand();
	return stream;
}

Table_Electronic::Table_Electronic(const Table_Electronic &obj)
{
	this->backlight = obj.backlight;
}

Table_Electronic &Table_Electronic::operator =(const Table_Electronic &obj)
{
	if(this!=&obj)
	{
		delete country;
		delete material_body;
		delete name;
		country = new char[strlen(obj.country)+1];
		material_body = new char [strlen(obj.material_body) + 1];
		name = new char[strlen(obj.name)+1];
		strcpy(this->country, obj.country);
		this->year = obj.year;
		strcpy(this->material_body, obj.material_body);
		strcpy(this->name,obj.name);
		this->backlight = obj.backlight;
	}
	return *this;
}
	
Table_Electronic Table_Electronic::set_Table(bool BACKLIGHT)
{
	this->backlight = BACKLIGHT;
	return *this;
}

void Table_Electronic::get_Table()
{
	if(this->backlight == 1)
		cout << setw(9) << left << "+" << "|" << endl;
	else 
		cout << setw(9) << left << "-" << "|" << endl;
}

Table_Electronic Table_Electronic::change_backlight(bool BACKLIGHT)
{
	this->backlight = BACKLIGHT;
	return *this;
}

bool Table_Electronic::operator ==(Table_Electronic &obj)
{
	if(!strcmp(this->name, obj.name))
		return true;
	else
		return false;
}

istream &operator>>(istream &stream,  Table_Electronic &obj)
{
	bool BACKLIGHT;
	char COUNTRY[20],MATERIAL_BODY[20], NAME[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	cout << "¬ведите название часов: ";
	cin >> NAME;
	cout << "¬ведите материал корпуса: ";
	cin >> MATERIAL_BODY;
	obj.set_Electronic(MATERIAL_BODY, NAME);
	cout << "„асы имеют подсветку?(1/0) ";
	cin >> BACKLIGHT;
	obj.set_Table(BACKLIGHT);
	return stream;
}

ostream &operator<<(ostream &stream, Table_Electronic &obj)
{
	obj.get_Clock();
	obj.get_Electronic();
	obj.get_Table();
	return stream;
}

Alarm::Alarm(const Alarm &obj)
{
	this->kick_protected = obj.kick_protected;
}

Alarm &Alarm::operator =(const Alarm &obj)
{
	if(this!=&obj) 
	{
		delete country;
		country = new char[strlen(obj.country)+1];
		strcpy(this->country, obj.country);
		delete material_body;
		material_body = new char [strlen(obj.material_body) + 1];
		strcpy(this->material_body, obj.material_body);
		delete name;
		name = new char[strlen(obj.name)+1];
		strcpy(this->name,obj.name);
		this->year = obj.year;
		this->kick_protected = obj.kick_protected;
	}
	return *this;
}

bool Alarm::operator ==(Alarm &obj)
{
	if(!strcmp(this->name, obj.name))
		return true;
	else
		return false;
}

Alarm Alarm::set_Alarm(bool KICK_PROTECTED)
{
	this->kick_protected = KICK_PROTECTED;
	return *this;
}

void Alarm::get_Alarm()
{
	if(this->kick_protected == 1)
		cout << setw(10) << left << "+" << "|" << endl;
	else 
		cout << setw(10) << left << "+" << "|" << endl;
}

Alarm Alarm::change_kick_protected(bool KICK_PROTECTED)
{
	this->kick_protected = KICK_PROTECTED;
	return *this;
}

istream &operator>>(istream &stream, Alarm &obj)
{
	bool KICK_PROTECTED;
	char COUNTRY[20],MATERIAL_BODY[20], NAME[20];
	int YEAR;
	cout << "¬ведите страну-производитель: ";
	cin >> COUNTRY;
	cout << "¬ведите год выпуска: ";
	cin >> YEAR;
	obj.set_Clock(COUNTRY, YEAR);
	cout << "¬ведите название часов: ";
	cin >> NAME;
	cout << "¬ведите материал корпуса: ";
	cin >> MATERIAL_BODY;
	obj.set_Electronic(MATERIAL_BODY, NAME);
	cout << "„асы €вл€ютс€ противоударными?(1/0) ";
	cin >> KICK_PROTECTED;
	obj.set_Alarm(KICK_PROTECTED);
	return stream;
}

ostream &operator<<(ostream &stream, Alarm &obj)
{
	obj.get_Clock();
	obj.get_Electronic();
	obj.get_Alarm();
	return stream;
}
