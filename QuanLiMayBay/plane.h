#pragma once
#ifndef _PLANE_
#define _PLANE

#include <iostream>
#include <string>
using namespace std;

class Plane
{
	string id;
	string name;
private:
	void input();
public:
	Plane() = default;
	Plane(string _id, string _name);

	string makeaquery();

	string getIdPlane() const;
	void setIdPlane(string);

	string getName() const;
	void setName(string);

	void print();
};

#endif // !_PLANE_
