#include "bill.h"


Bill::Bill(string _id, string _cardid, string _idticket, string _date, float _money)
	:id(_id),
	 cardId(_cardid),
	 idTicket(_idticket),
	 date(_date),
	 money(_money) {}

void Bill::input()
{
	cout << "Nhap ID: ";
	cin >> id;
	cout << "Nhap Card Id: ";
	cin >> cardId;
	cout << "Nhap Ticket Id: ";
	cin >> idTicket;
	cout << "Nhap ngay: ";
	cin >> date;
	cout << "Nhap so tien: ";
	cin >> money;
}

string Bill::makeaquery()
{
	input();
	return "INSERT HOADON VALUES('" + id + "','" + cardId + "','" + idTicket + "','" + date + "'," + to_string(money) + ")";
}

void Bill::print()
{
	cout << "Bill ID     : " << id << "\n"
		 << "Card ID     : " << cardId << "\n"
		 << "Ticket ID   : " << idTicket << "\n"
		 << "Date        : " << date << "\n"
		 << "Money       : " << money << "\n";
}


string Bill::getId() const
{
	return id;
}
void Bill::setId(string _id)
{
	if (_id.length())
		id = _id;
}

string Bill::getCardId() const
{
	return cardId;
}
void Bill::setCardId(string _cardid)
{
	if (_cardid.length())
		cardId = _cardid;
}
string Bill::getIdTicket() const
{
	return idTicket;
}
void Bill::setIdTicket(string _idticket)
{
	if (_idticket.length())
		idTicket = _idticket;
}

string Bill::getDate() const
{
	return date;
}
void Bill::setDate(string _date)
{
	if (_date.length())
		date = _date;
}
float Bill::getMoney() const
{
	return money;
}
void Bill::setMoney(float _money)
{
	if (_money >= 0)
		money = _money;
}
