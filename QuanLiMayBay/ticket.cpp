#include "ticket.h"

Ticket::Ticket(string _id, float _price, string _seat, string _idPlane, string _flighthour, string _flightdate)
	   :id(_id), 
	    price(_price), 
	    seat(_seat), 
	    idPlane(_idPlane), 
	    flightHour(_flighthour),
		flightDate(_flightdate){}

void Ticket::input()
{
	cout << "Nhap ID: ";
	cin >> id;
	cout << "Nhap cho ngoi:  ";
	cin >> seat;
	cout << "Nhap Plane Id: ";
	cin >> idPlane;
	cout << "Nhap Gio bay: ";
	cin >> flightHour;
	cout << "Nhap Ngay bay: ";
	cin >> flightDate;
	cout << "Nhap gia ve: ";
	cin >> price;
}

string Ticket::makeaquery()
{ 
	input();
	return "INSERT VE VALUES('" + id + "'," + to_string(price) + ",'" + seat + "','" + idPlane + "','" + flightHour + "','" + flightDate + "')";
}


void Ticket::print()
{
	cout << "Ticket ID      : " << id << "\n"
		 << "Seat           : " << seat << "\n"
		 << "Plane ID       : " << idPlane << "\n"
		 << "Flight hour    : " << flightHour << "\n"
		 << "Flight date    : " << flightDate << "\n"
		 << "Price          : " << price << "\n";
}



string Ticket::getId() const
{
	return id;
}
void Ticket::setId(string id)
{
	if (id.length())
		this->id = id;
}

float Ticket::getPrice() const
{
	return price;
}
void Ticket::setPrice(float price)
{
	if (price)
		this->price = price;
}

string Ticket::getSeat() const
{
	return seat;
}
void Ticket::setSeat(string seat)
{
	if (seat.length())
		this->seat = seat;
}

string Ticket::getIdPlane() const
{
	return idPlane;
}
void Ticket::setIdPlane(string idPlane)
{
	if (idPlane.length())
		this->idPlane = idPlane;
}

string Ticket::getFlightHour() const
{
	return flightHour;
}
void Ticket::setFlightHour(string flighthour)
{
	if (flighthour.length())
		this->flightHour = flighthour;
}

string Ticket::getFlightDate() const
{
	return flightHour;
}
void Ticket::setFlightDate(string flightdate)
{
	if (flightdate.length())
		this->flightHour = flightdate;
}