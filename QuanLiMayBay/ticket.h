#pragma once
#ifndef _TICKET_
#define _TICKET_

#include <iostream>
#include <string>
using namespace std;


class Ticket
{
	string id;
	float price;
	string seat;
	string idPlane;
	string flightHour;
	string flightDate;
private:
	void input();
public:
	Ticket() = default;
	Ticket(string _id, float _price, string _seat, string _idPlane, string _flighthour, string _flightdate);

	string makeaquery();

	string getId() const;
	void setId(string);

	float getPrice() const;
	void setPrice(float);

	string getSeat() const;
	void setSeat(string);

	string getIdPlane() const;
	void setIdPlane(string);

	string getFlightHour() const;
	void setFlightHour(string);

	string getFlightDate() const;
	void setFlightDate(string);

	void print();

};

#endif // !_TICKET_
