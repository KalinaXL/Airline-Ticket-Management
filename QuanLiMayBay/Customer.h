#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <string>
#include <iostream>
using namespace std;

enum Gender
{
	FEMALE,
	MALE,
};

class Customer
{
	string cardId;
	string name;
	string phoneNumber;
	Gender gender;
private:
	////////////////////////////////////
	// Phương thức khởi trị các 'field'
	// từ bàn phím
	// Arguments: No
	// No Return
	////////////////////////////////////
	void input();
public:
	////////////////////////////
	// Hàm khởi tạo mặc định
	// Hàm khởi tạo có tham số
	////////////////////////////
	Customer() = default;
	Customer(string _id, string _name, string _phone, Gender _gender);

	//////////////////////////////////////////////////////
	// Tạo ra 1 lệnh QUERY để INSERT vào TABLE tương ứng
	// với các thông tin được nhập hàm 'input'
	// Arguments: No
	// Return: string - câu lệnh query trong SQL Server
	/////////////////////////////////////////////////////
	string makeaquery();

	/////////////////////////////
	// Phương thức get & set 
	// cho thuộc tính 'cardId'
	////////////////////////////
	string getCardId() const;
	void setCardId(string);

	/////////////////////////////
	// Phương thức get & set
	// cho thuộc tính 'name'
	////////////////////////////
	string getName() const;
	void setName(string);

	/////////////////////////////
	// Phương thức get & set
	// cho thuộc tính 'phoneNumber'
	////////////////////////////
	string getPhoneNumber() const;
	void setPhoneNumber(string);

	/////////////////////////////
    // Phương thức get & set
    // cho thuộc tính 'gender'
    ////////////////////////////
	Gender getGender() const;
	void setGender(Gender);

	void print();
};
#endif // _CUSTOMER_
