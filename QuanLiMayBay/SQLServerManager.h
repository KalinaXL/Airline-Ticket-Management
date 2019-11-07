#pragma once
#ifndef _SQLSERVERMANAGER_
#define _SQLSERVERMANAGER_
////////////////////////////////////////////////////////
// Line 9 - 12: Thư viện hỗ trợ kết nối với SQL (ODBC)
// Line 13: Thư viện để xứ lí ngoại lệ
// Line 15 - 18: các class tự định nghĩa
////////////////////////////////////////////////////////
#include <windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <exception>
#include "config.h"
#include "customer.h"
#include "plane.h"
#include "ticket.h"
#include "bill.h"
#include <iostream>
#include <vector>

class SQLServerManager
{
	SQLHANDLE SQLEnvHandle;
	SQLHANDLE SQLConnectionHandle;
	SQLHANDLE SQLStatementHandle;
	SQLRETURN retCode;
	bool isClosed;

	//////////////////////////////////////////////////////
	// Khởi tạo môi trường
	// Arguments: No
	// Return   : bool
	// Trả về true nếu thành công, ngược lại thì false
	/////////////////////////////////////////////////////
	bool initEnv();

	//////////////////////////////////////////////////////
	// Khởi tạo kết nối
	// Arguments: No
	// Return   : bool
	// Trả về true nếu thành công, ngược lại thì false
	/////////////////////////////////////////////////////
	bool initConnection();

	//////////////////////////////////////////////////////
	// Thông báo lỗi ra màn hình
	// Return: Không có giá trị trả về
	/////////////////////////////////////////////////////
	void showSQLError(unsigned int, const SQLHANDLE&);
	//////////////////////////////////////////////////////
	// Kết nối tới SQL Server
	// Arguments: No
	// Return   : bool
	// Trả về true nếu thành công, ngược lại thì false
	/////////////////////////////////////////////////////
	bool connectToSQLServer();

	//////////////////////////////////////////////////////
	// Đóng kết nối
	// Arguments: No
	// Return   : Không có giá trị trả về
	/////////////////////////////////////////////////////
	void _close();

	//////////////////////////////////////////////////////
	// Các query không trả về dữ liệu như: INSERT, CREATE,
	// UPDATE, ALTER, DELETE, DROP, ...
	// Arguments: 
	//   + Argument 1: string command - A command of SQL Server
	// Return   : bool 
	// Trả về true nếu thành công, ngược lại thì false
	/////////////////////////////////////////////////////
	void				querynoreturn(string);

	vector<Plane*>		querytableplane(string);
	vector<Ticket*>		querytableticket(string);
	vector<Bill*>		querytablebill(string);
	vector<Customer*>	querytablecustomer(string);
	

public:
	/////////////////////////////////////////////////
	// Constructor is responsible for initializing 
	// first state of variables
	/////////////////////////////////////////////////
	SQLServerManager();

	////////////////////////////////////////////////
	// Destructor of class
	// Nếu chúng ta không gọi hàm 'close', 
	// thì phương thức hủy sẽ gọi
	////////////////////////////////////////////////
	~SQLServerManager();


	void				queryNoReturn(string);
	vector<Plane*>		queryTablePlane(string);
	vector<Ticket*>		queryTableTicket(string);
	vector<Bill*>		queryTableBill(string);
	vector<Customer*>	queryTableCustomer(string);
	void close();
};

#endif // !_SQLSERVERMANAGER_
