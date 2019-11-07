#include "QueryManager.h"

void QueryManager::_handleonequery(int type, string command)
{
	
		switch (type)
		{
		case 2:
			sql.queryNoReturn(command);
			break;
		case 3:
			deletevector(listOfPlane);
			listOfPlane = sql.queryTablePlane(command);
			break;
		case 4:
			deletevector(listOfTicket);
			listOfTicket = sql.queryTableTicket(command);
			break;
		case 5:
			deletevector(listOfBill);
			listOfBill = sql.queryTableBill(command);
			break;
		case 6:
			deletevector(listOfCustomer);
			listOfCustomer = sql.queryTableCustomer(command);
			break;
		}
	
}

void QueryManager::_query(int type)
{
	if (type == 1)
	{
		openNotepad();
		vector<command> vect = readfile();
		for (const auto& i : vect)
		{
			switch (i.type)
			{
			case NONE:
				sql.queryNoReturn(i.query);
				break;
			case MAYBAY:
				deletevector(listOfPlane);
				listOfPlane = sql.queryTablePlane(i.query);
				break;
			case VE:
				deletevector(listOfTicket);
				listOfTicket = sql.queryTableTicket(i.query);
				break;
			case HOADON:
				deletevector(listOfBill);
				listOfBill = sql.queryTableBill(i.query);
				break;
			case KHACHHANG:
				deletevector(listOfCustomer);
				listOfCustomer = sql.queryTableCustomer(i.query);
				break;
			}
		}
	}
	else if (type < 7)
	{
		string query;
		cout << "Nhap truy van:  ";
		cin.ignore(1, '\n');
		getline(cin, query);
		_handleonequery(type, query);
	}
	else if (type < 11)
	{
		int num;
		cout << "Nhap so luong ban ghi muon hien thi: ";
		cin >> num;
		switch (type)
		{
		case 7:
			print(listOfPlane, num);
			break;
		case 8:
			print(listOfTicket, num);
			break;
		case 9:
			print(listOfBill, num);
			break;
		case 10:
			print(listOfCustomer, num);
			break;
		}
	}
	else
	{
		string query = "";
		switch (type)
		{
			case 11:
			{
				Plane p;
				query = p.makeaquery();
			}
				break;
			case 12:
			{
				Ticket t;
				query = t.makeaquery();
			}
				break;
			case 13:
			{
				Bill b;
				query = b.makeaquery();
			}
				break;
			case 14:
			{
				Customer c;
				query = c.makeaquery();
			}
				break;
		}
		sql.queryNoReturn(query);
	}
}

bool QueryManager::query(int type)
{
	
	try
	{
		_query(type);
	}
	catch (exception)
	{
		return false;
	}
	return true;
}

QueryManager::~QueryManager()
{
	deletevector(listOfPlane);
	deletevector(listOfBill);
	deletevector(listOfTicket);
	deletevector(listOfCustomer);
}