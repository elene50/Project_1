#include <locale.h>
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Clock
{
protected:
	char *country;
	int year;
public:
	Clock(char *COUNTRY, int YEAR)
	{
		this->country = new char[strlen(COUNTRY) + 1];
		strcpy(country, COUNTRY);
		this->year = YEAR;
	}
	Clock(){this->country = NULL;this->year = 0;}
	Clock(const Clock &obj);
	~Clock()
	{
		if(country)
			delete []country;
	}
	Clock set_Clock(char *COUNTRY, int YEAR);
	void get_Clock();
	Clock change_country(char *COUNTRY);
	Clock change_year(int YEAR);
	friend istream &operator>>(istream &stream, Clock &obj);
	friend ostream &operator<<(ostream &stream, Clock &obj);
	Clock &operator=(const Clock&);
};

class Mechanical:public Clock
{
protected:
	char *name;
	char *material_body;
public:
	Mechanical(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY):Clock(COUNTRY, YEAR)
	{
		this->name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);
		this->material_body = new char[strlen(MATERIAL_BODY) + 1];
		strcpy(material_body, MATERIAL_BODY);
	}
	Mechanical(){this->name = NULL; this->material_body = NULL;}
	~Mechanical()
	{
		if(material_body)
			delete [] material_body;
		if(name)
			delete [] name;
	}
	Mechanical(const Mechanical &obj);
	Mechanical set_Mechanical(char *MATERIAL_BODY, char *NAME);
	void get_Mechanical();
	Mechanical change_material(char *MATERIAL_BODY);
	Mechanical change_name(char *NAME);
	int find_name(char *NAME);
	Mechanical &operator=(Mechanical &);
};

class Electronic: public Clock
{
protected:
	char *material_body;
	char *name;
public:
	Electronic(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY):Clock(COUNTRY, YEAR)
	{
		this->name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);
		this->material_body = new char[strlen(MATERIAL_BODY) + 1];
		strcpy(material_body, MATERIAL_BODY);
	}
	Electronic(){this->material_body = NULL; this->name=NULL;}
	~Electronic()
	{
		if(material_body)
			delete [] material_body;
		if(name)
			delete [] name;
	}
	Electronic(const Electronic &obj);
	Electronic set_Electronic(char *MATERIAL_BODY, char *NAME);
	void get_Electronic();
	Electronic change_material(char *MATERIAL_BODY);
	Electronic change_name(char *NAME);
	int find_name(char *NAME);
	friend istream &operator>>(istream &stream, Electronic &obj);
	friend ostream &operator<<(ostream &stream, Electronic &obj);
	Electronic &operator=(const Electronic &);
};

class Table_Mechanical:public Mechanical
{
	int accuracy;
public:
	Table_Mechanical(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY, int ACCURACY):Mechanical(COUNTRY, YEAR, NAME, MATERIAL_BODY)
	{
		this->accuracy = ACCURACY;
	}
	Table_Mechanical(){}
	~Table_Mechanical(){}
	Table_Mechanical(const Table_Mechanical &obj);
	Table_Mechanical set_Table(int ACCURACY);
	void get_Table();
	Table_Mechanical change_accuracy(int ACCURACY);
	friend istream &operator>>(istream &stream,  Table_Mechanical &obj);
	friend ostream &operator<<(ostream &stream, Table_Mechanical &obj);
	Table_Mechanical &operator=(const Table_Mechanical &);
	bool operator ==(Table_Mechanical &obj);
};

class Hand:public Mechanical
{
protected:
	bool water_protected;
	char *material_strap;
public:
	Hand(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY, bool WATER_PROTECTED, char *MATERIAL_STRAP):Mechanical(COUNTRY, YEAR, NAME, MATERIAL_BODY)
	{
		material_strap = new char[strlen(MATERIAL_STRAP) + 1];
		strcpy(material_strap, MATERIAL_STRAP);
		water_protected = WATER_PROTECTED;
	}
	Hand(){this->material_strap = NULL;}
	~Hand()	
	{
		if(material_strap)
			delete [] material_strap;
	}
	Hand(const Hand &obj);
	Hand set_Hand(bool WATER_PROTECTED, char *MATERIAL_STRAP);
	void get_Hand();
	Hand change_material_strap(char *MATERIAL_STRAP);
	Hand change_water_protected(bool WATER_PROTECTED);
	friend istream &operator>>(istream &stream,  Hand &obj);
	friend ostream &operator<<(ostream &stream, Hand &obj);
	Hand &operator=(const Hand &);
	bool operator ==(Hand &obj);
};

class Table_Electronic: public Electronic
{
	bool backlight;
public:
	Table_Electronic(){}
	Table_Electronic(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY, bool BACKLIGHT):Electronic(COUNTRY, YEAR, NAME, MATERIAL_BODY)
	{
		this->backlight = BACKLIGHT;
	}
	~Table_Electronic(){}
	Table_Electronic(const Table_Electronic &obj);
	Table_Electronic set_Table(bool BACKLIGHT);
	void get_Table();
	Table_Electronic change_backlight(bool BACKLIGHT);
	friend istream &operator>>(istream &stream,  Table_Electronic &obj);
	friend ostream &operator<<(ostream &stream, Table_Electronic &obj);
	Table_Electronic &operator=(const Table_Electronic &);
	bool operator ==(Table_Electronic &obj);
};

class Alarm: public Electronic
{
	bool kick_protected;
public:
	Alarm(){this->kick_protected = 0;}
	Alarm(char *COUNTRY, int YEAR, char *NAME, char *MATERIAL_BODY, bool KICK_PROTECTED):Electronic(COUNTRY, YEAR, NAME, MATERIAL_BODY)
	{
		this->kick_protected = KICK_PROTECTED;
	}
	~Alarm(){}
	Alarm(const Alarm &obj);
	Alarm set_Alarm(bool KICK_PROTECTED);
	void get_Alarm();
	Alarm change_kick_protected(bool KICK_PROTECTED);
	friend istream &operator>>(istream &stream, Alarm &obj);
	friend ostream &operator<<(ostream &stream, Alarm &obj);
	Alarm &operator=(const Alarm &);
	bool operator ==(Alarm &obj);
};