#pragma once

#include<iostream>
#include"数据库依赖文件/mysql.h"
#include<string>
#include<vector>
using namespace std;

struct Student
{
	int student_id;
	string student_name;
	string class_id;
};


class studentManger
{
	studentManger();
	~studentManger();

public:
	static studentManger* GetInstance()
	{
		static studentManger studentManger;
		return &studentManger;
	}


public:
	bool insert_student(Student& t);
	bool update_student(Student& t);
	bool dalete_student(int student_id);
	char get_student(int student_id);
	void zhengjia();
	void shuanchu();
	void gengxin();
	void chanxun();


private:
	MYSQL* con = mysql_init(NULL);
	const char* host = "localhost";
	const char* name = "root";
	const char* pw = "root";
	const char* database_name = "student";
	const int port = 3306;
};

