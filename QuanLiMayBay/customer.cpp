#include "customer.h"



Customer::Customer(string _id, string _name, string _phone, Gender _gender)
					:cardId(_id), 
					 name(_name), 
					 phoneNumber(_phone), 
					 gender(_gender) {}

void Customer::input()
{
	cout << "Nhap Card ID: ";
	cin >> cardId;
	cin.ignore(1, '\n');
	cout << "Nhap ho ten: ";
	getline(cin, name);
	cout << "Nhap so dien thoai: ";
	cin >> phoneNumber;

	string temp;
	cout << "Nhap gioi tinh: ";
	cin >> temp;

	//// chuyển chữ thường sang chữ hoa
	for (int i = 0; i < temp.length(); i++)
		if ('a' <= temp[i] && temp[i] <= 'z')
			temp[i] -= 32;
	gender = (temp == "NAM") ? MALE : FEMALE;
	
}

string Customer::makeaquery()
{
	input();

	string query = "INSERT KHACHHANG VALUES('" + cardId + "','" + name + "','" + phoneNumber + "','";
	query += (gender == MALE) ? "Name" : "Nu";
	query += "')";
	return query;
}

void Customer::print()
{
	cout << "CARD ID   : " << cardId << "\n"
		 << "Name      : " << name << "\n"
		 << "Phone     : " << phoneNumber << "\n"
	     << "Gender    : ";
	if (gender == MALE)
		cout << "Nam";
	else
		cout << "Nu";
	cout << "\n";
}


string Customer::getCardId() const
{
	return cardId;
}
void Customer::setCardId(string id)
{
	if (id.length())
		cardId = id;
}
string Customer::getName() const
{
	return name;
}
void Customer::setName(string name)
{
	if (name.length())
		this->name = name;
}
string Customer::getPhoneNumber() const
{
	return phoneNumber;
}
void Customer::setPhoneNumber(string phonenumber)
{
	if (phonenumber.length())
		phoneNumber = phonenumber;
}
Gender Customer::getGender() const
{
	return gender;
}
void Customer::setGender(Gender _gender)
{
	gender = _gender;
}
