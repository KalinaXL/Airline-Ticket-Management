#include "SQLServerManager.h"

bool SQLServerManager::initEnv()
{
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) != SQL_SUCCESS)
		return false;
	return true;
}

bool SQLServerManager::initConnection()
{
	if (SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle) != SQL_SUCCESS)
		return false;
	if (SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0) != SQL_SUCCESS)
		return false;
	return true;
}

void SQLServerManager::showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if (SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL) == SQL_SUCCESS)
	{
		cout << "SQL driver message: " << message
			<< "\nSQL State: " << SQLState << ".\n";
		system("pause");
	}


}

bool SQLServerManager::connectToSQLServer()
{
	string configuration = "DRIVER={SQL Server}; SERVER=" + SERVER + "; DATABASE=" + DATABASENAME + "; UID=" + LOGINNAME + "; PWD=" + PASSWORD + ";";
	SQLCHAR retConString[1024];
	switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)configuration.data(), SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
	{
	case SQL_NO_DATA_FOUND:
	case SQL_INVALID_HANDLE:
	case SQL_ERROR:
		showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
		return false;
	}
	return true;
}

void SQLServerManager::querynoreturn(string command)
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return;
	}
	if (SQLExecDirect(SQLStatementHandle, (SQLCHAR*)command.data(), SQL_NTS) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return;
	}
	cout << "Successfully!!!\n";
	system("pause");
}
void SQLServerManager::queryNoReturn(string command)
{
	querynoreturn(command);
}

vector<Plane*> SQLServerManager::querytableplane(string command)
{
	vector<Plane*> arr;

	if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	if (SQLExecDirect(SQLStatementHandle, (SQLCHAR*)command.data(), SQL_NTS) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	
	char idPlane[256]{};
	char namePlane[256]{};
	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
	{
		SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &idPlane,   sizeof(idPlane),   NULL);
		SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &namePlane, sizeof(namePlane), NULL);
		arr.push_back(new Plane(idPlane, namePlane));

		// Gán lại 256 bit đều là 0
		memset(idPlane, 0, 256);
		memset(namePlane, 0, 256);
	}
	return arr;
}
vector<Plane*> SQLServerManager::queryTablePlane(string command)
{
	return querytableplane(command);
}



vector<Ticket*> SQLServerManager::querytableticket(string command)
{
	vector<Ticket*> arr;

	if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	if (SQLExecDirect(SQLStatementHandle, (SQLCHAR*)command.data(), SQL_NTS) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	
	char idTicket[256]{};
	float price;
	char seat[256]{};
	char idPlane[256]{};
	char flighthour[256]{};
	char flightdate[256]{};

	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
	{
		SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &idTicket,		sizeof(idTicket),	 NULL);
		SQLGetData(SQLStatementHandle, 2, SQL_C_FLOAT,   &price,		32,		 NULL);
		SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &seat,			sizeof(seat),		 NULL);
		SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &idPlane,		sizeof(idPlane),	 NULL);
		SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &flighthour,	sizeof(flighthour),  NULL); 
		SQLGetData(SQLStatementHandle, 6, SQL_C_DEFAULT, &flightdate,   sizeof(flightdate), NULL);
		arr.push_back(new Ticket(idTicket, price, seat, idPlane, flighthour, flightdate));

		// Gán lại 256 bit đều là 0
		memset(seat, 0, 256);
		memset(idPlane, 0, 256);
		memset(flighthour, 0, 256);
		memset(flightdate, 0, 256);
	}
	return arr;
}

vector<Ticket*> SQLServerManager::queryTableTicket(string command)
{
	return querytableticket(command);
}

vector<Bill*> SQLServerManager::querytablebill(string command)
{
	vector<Bill*> arr;

	if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	if (SQLExecDirect(SQLStatementHandle, (SQLCHAR*)command.data(), SQL_NTS) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	
	char idBill[256]{};
	char cardId[256]{};
	char idTicket[256]{};
	char date[256]{};
	float money;

	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
	{
		SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &idBill,   sizeof(idBill),   NULL);
		SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &cardId,   sizeof(cardId),   NULL);
		SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &idTicket, sizeof(idTicket), NULL);
		SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &date,     sizeof(date),     NULL);
		SQLGetData(SQLStatementHandle, 5, SQL_C_FLOAT, &money,      32,               NULL);
		arr.push_back(new Bill(idBill, cardId, idTicket, date, money));

		// Gán lại 256 bit đều là 0
		memset(idBill, 0, 256);
		memset(cardId, 0, 256);
		memset(idTicket, 0, 256);
		memset(date, 0, 256);
	}
	return arr;
}

vector<Bill*> SQLServerManager::queryTableBill(string command)
{
	return querytablebill(command);
}

vector<Customer*> SQLServerManager::querytablecustomer(string command)
{
	vector<Customer*> arr;

	if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}
	if (SQLExecDirect(SQLStatementHandle, (SQLCHAR*)command.data(), SQL_NTS) != SQL_SUCCESS)
	{
		showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
		return arr;
	}

	char cardId[256]{};
	char phone[256]{};
	char name[256]{};
	char gender[256]{};

	while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
	{
		SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &cardId, sizeof(cardId), NULL);
		SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name,	  sizeof(name),   NULL);
		SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &phone,  sizeof(phone),  NULL);
		SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &gender, sizeof(gender), NULL);

		string temp = string(gender);
		//chuyển chữ thường sang chữ hoa
		for (int i = 0; i < temp.length(); i++)
			if ('a' <= temp[i] && temp[i] <= 'z')
				temp[i] -= 32;
		arr.push_back(new Customer(cardId, name, phone, (Gender)(temp != "NAM")));


		// Gán lại 256 bit đều là 0
		memset(cardId, 0, 256);
		memset(phone, 0, 256);
		memset(name, 0, 256);
		memset(gender, 0, 256);
	}
	return arr;
}

vector<Customer*> SQLServerManager::queryTableCustomer(string command)
{
	return querytablecustomer(command);
}


void SQLServerManager::_close()
{
	isClosed = true;
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}
void SQLServerManager::close()
{
	this->_close();
}

SQLServerManager::SQLServerManager()
{
	SQLEnvHandle = SQLConnectionHandle = SQLStatementHandle = NULL;
	isClosed = false;
	retCode = 0;
	try
	{
		if (!initEnv())
			throw "FAILED TO INITIALIZE ENVIRONMENT";
		if (!initConnection())
			throw "FAILED TO INITIALIZE CONNECTION";
		if (!connectToSQLServer())
			throw "FAILED TO CONNECT TO SQL SERVER";
	}
	catch (const char* msg)
	{
		cout << msg << "\n";
		exit(-100);
	}
}

SQLServerManager::~SQLServerManager()
{
	if (!isClosed)
		this->close();
}