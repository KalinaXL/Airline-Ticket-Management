#include "plane.h"

Plane::Plane(string _id, string _name) 
	  :id(_id),
	   name(_name) {}


void Plane::input()
{
	cout << "Nhap Id: ";
	cin >> id;
	cin.ignore(1, '\n');
	cout << "Nhap ten: ";
	getline(cin, name);
}

string Plane::makeaquery()
{
    input();
	return "INSERT MAYBAY VALUES('" + id + "','" + name + "')";
}

void Plane::print()
{
	cout << "Id:   " << id << "\n"
		<< "Name: " << name << "\n";
}


string Plane::getIdPlane() const
{
	return id;
}
void Plane::setIdPlane(string _id)
{
	if (_id.length())
		id = _id;
}
string Plane::getName() const
{
	return name;
}
void Plane::setName(string _name)
{
	if (_name.length())
		name = _name;
}