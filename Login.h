#pragma once
#include<iostream>
#include"数据库依赖文件/mysql.h"
#include<string>
using namespace std;
struct Login_aaa
{
	string Login_ID;
	int Login_pw;
};

class Login
{
	Login();
	~Login();
public:
	static Login* GetInstance()
	{
		static Login Login;
		return &Login;
	}
public:
	bool ZhuChe(Login_aaa& t);
	bool DengLu(string Login_ID,int Login_pw);


private:
	MYSQL* connect = mysql_init(NULL);
	const char* host = "localhost";
	const char* name = "root";
	const char* pw = "root";
	const char* database_name = "login";
	const int port = 3306;


};

