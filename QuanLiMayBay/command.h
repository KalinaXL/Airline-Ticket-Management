#pragma once
#ifndef _COMMAND_
#define _COMMAND_
#include <string>
using namespace std;
enum table
{
	NONE,
	MAYBAY,
	VE,
	HOADON,
	KHACHHANG
};
/////////////////////////////////////////////////
// struct gồm:
// + type: Loại bảng là câu lệnh sẽ thực thi
// + com: câu lệnh trong SQL Server
/////////////////////////////////////////////////
struct command
{
	table type;
	string query;
};
#endif // !_COMMAND_
