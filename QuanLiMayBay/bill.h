#pragma once
#ifndef _BILL_
#define _BILL_
#include <iostream>
#include <string>
using namespace std;
class Bill
{
	string id;
	string cardId;
	string idTicket;
	string date;
	float money;
private:
	void input();
public:
	Bill() = default;
	Bill(string _id, string _cardid, string _idticket, string _date, float _money);

	string makeaquery();

	string getId() const;
	void setId(string);

	string getCardId() const;
	void setCardId(string);

	string getIdTicket() const;
	void setIdTicket(string);

	string getDate() const;
	void setDate(string);
	float getMoney() const;
	void setMoney(float);

	void print();
};
#endif // !_BILL_
