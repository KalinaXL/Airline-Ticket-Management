#pragma once
#ifndef _QUERYMANAGER_
#define _QUERYMANAGER_

#include "command.h"
#include "utils.h"
#include "SQLServerManager.h"

class QueryManager
{
	SQLServerManager sql;
	vector<Plane*> listOfPlane;
	vector<Ticket*> listOfTicket;
	vector<Bill*> listOfBill;
	vector<Customer*> listOfCustomer;
private:
	void _handleonequery(int , string);
	void _query(int);
public:
	bool query(int type);
	~QueryManager();

};
#endif // !_QUERYMANAGER
