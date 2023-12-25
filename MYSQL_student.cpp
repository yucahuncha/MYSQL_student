// ConsoleApplication9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<string>
using namespace std;
#include"studentManger.h"
#include"Login.h"



int main()
{

	//cout << "--------学生信息管理系统--------" << endl;
	//cout << "-------------按下回车键继续-------------" << endl;
	//while (100)
	/* {
		int a = 0;
		cout << "---------------1.增加学生---------------" << endl;
		cout << "---------------2.删除学生---------------" << endl;
		cout << "---------------3.更新学生---------------" << endl;
		cout << "---------------4.查询学生---------------" << endl;
		cin >> a;
		if (a == 1)
		{
			studentManger::GetInstance()->zhengjia();
		}
		if (a == 2)
		{
			studentManger::GetInstance()->shuanchu();
		}
		if (a == 3)
		{
			studentManger::GetInstance()->gengxin();
		}
		if (a == 4)
		{
			studentManger::GetInstance()->chanxun();
		}
		if (a > 4)
		{
			cout << "输入错误" << endl;
		}

	}*/



	/*
	string ID;
	int pw;
	cout << "测试注册" << endl;
	cout << "输入用户名和密码" << endl;
	cin >> ID >> pw;
	Login_aaa stu{ ID,pw };
	Login::GetInstance()->ZhuChe(stu);*/

	/*string ID;
	int pw;
	cout << "测试登录" << endl;
	cout << "输入用户名和密码" << endl;
	cin >> ID >> pw;
	if (Login::GetInstance()->DengLu(ID, pw) == true)
	{
		cout << "登录成功" << endl;
	}
	else
	{
		cout << "登录失败" << endl;
	}*/
	int a;
	cout << "------------学生信息管理系统------------" << endl;
	cout << "-------------按下回车键继续-------------" << endl;
	cout << "--------------1.登录 2.注册--------------" << endl;
	cin >> a;
	if (a == 1)
	{
		string ID;
		int pw;
		cout << "输入用户名和密码" << endl;
		cin >> ID >> pw;
		if (Login::GetInstance()->DengLu(ID, pw) == true)
		{
			cout << "登录成功" << endl;
			while (100)
			{
				int b = 0;
				cout << "---------------1.增加学生---------------" << endl;
				cout << "---------------2.删除学生---------------" << endl;
				cout << "---------------3.更新学生---------------" << endl;
				cout << "---------------4.查询学生---------------" << endl;
				cin >> b;
				if (b == 1)
				{
					studentManger::GetInstance()->zhengjia();
				}
				if (b == 2)
				{
					studentManger::GetInstance()->shuanchu();
				}
				if (b == 3)
				{
					studentManger::GetInstance()->gengxin();
				}
				if (b == 4)
				{
					studentManger::GetInstance()->chanxun();
				}
				if (b < 1 && b >4)
				{
					cout << "输入错误" << endl;
				}

			}
		}
		else
		{
			cout << "密码错误，登录失败" << endl;
		}
	}
	if (a == 2)
	{
		string ID;
		int pw;
		cout << "输入用户名和密码" << endl;
		cin >> ID >> pw;
		Login_aaa stu{ ID,pw };
		Login::GetInstance()->ZhuChe(stu);
	}
	if (a != 1 && a != 2)
	{
		cout << "输入错误" << endl;
		exit(1);
	}


	return 0;
}
