#include "utils.h"
#include "command.h"
#include <fstream>


////////////////////////////////////////////////////////////////////////
// Mở Notepad để gõ COMMAND với tên file là giá trị trong biến NOPADFILENAME
// và lưu lại dưới dạng file '.txt'
// No Arguments, No Return
////////////////////////////////////////////////////////////////////////
void openNotepad()
{
	string filename = "notepad \"" + NOTEPADFILENAME + "\"";
	system(filename.data());
}

/////////////////////////////////////////////////////////////////////////
// Đọc lại file '.txt' được lưu lại ở hàm 'openNotepad'
// Arguments: No
// Return: vector<command> là vector chứa các câu lệnh
/////////////////////////////////////////////////////////////////////////
vector<command> readfile()
{
	vector<command> arr;
	ifstream filein("../QuanLiMayBay/" + NOTEPADFILENAME + ".txt");
	if (!filein)
		return arr;
	string str;
	command c;
	while (!filein.eof())
	{
		getline(filein, str, ',');
		if (str  == "NONE")
			c.type = NONE;
		else if (str == "MAYBAY")
			c.type = MAYBAY;
		else if (str == "VE")
			c.type = VE;
		else if (str == "HOADON")
			c.type = HOADON;
		else if (str == "KHACHHANG")
			c.type = KHACHHANG;
		else
			break;
		getline(filein, str);
		c.query = str;
		arr.push_back(c);
	}
	filein.close();
	return arr;

}

////////////////////////////////////////////
// Hiển thị danh sách lựa chọn ra CONSOLE
// Arguments: No, NO Return
///////////////////////////////////////////
int displaymenu()
{
	int choice;

error_input:
	system("cls");
	cout << "------------------------------MENU------------------------------\n";
	cout << "     1.  Nhap lenh tu Notepad\n";
	cout << "     2.  Truy van khong tra ve ket qua\n";
	cout << "     3.  Truy van ket qua TABLE MAYBAY\n";
	cout << "     4.  Truy van ket qua TABLE VE\n";
	cout << "     5.  Truy van ket qua TABLE HOADON\n";
	cout << "     6.  Truy van ket qua TABLE KHACHHANG\n";
	cout << "     7.  Xuat ket qua truy van cua TABLE MAYBAY\n";
	cout << "     8.  Xuat ket qua truy van cua TABLE VE\n";
	cout << "     9.  Xuat ket qua truy van cua TABLE HOADON\n";
	cout << "     10. Xuat ket qua truy van cua TABLE KHACHHANG\n";
	cout << "     11. Them 1 record vao TABLE MAYBAY\n";
	cout << "     12. Them 1 record vao TABLE VE\n";
	cout << "     13. Them 1 record vao TABLE HOADON\n";
	cout << "     14. Them 1 record vao TABLE KHACHHANG\n";
	cout << "     15. Thoat\n";
	cout << "----------------------------------------------------------------\n";
	cout << "Lua chon: ";
	cin >> choice;
	if (cin.fail()) //// Nếu giá trị không phải là số
	{
		cin.clear(); // xóa đi các cờ lỗi
		cin.ignore(1024, '\n'); // xóa đi buffer chứa các bit lỗi
		cout << "Loi ! Dau vao khong xac dinh !\n";
		system("pause");
		goto error_input;
	}
	else if (choice < 1 || choice > 15)
	{
		cout << "Nam ngoai pham vi !";
		system("pause");
		goto error_input;
	}
	return choice;
}
