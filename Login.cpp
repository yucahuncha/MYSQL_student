#include "Login.h"
#include<string>
using namespace std;
Login::Login()
{
	mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK");
	if (!mysql_real_connect(connect,host,name,pw,database_name,port,NULL,0))
	{
		cout << "fialid to connect:ERROR:" << mysql_error(connect);
		exit(1);
	}
}

Login::~Login()
{
	mysql_close(connect);
}

bool Login::ZhuChe(Login_aaa& stu)
{
	string sql = "INSERT INTO Login_1 VALUES ('" + stu.Login_ID + "'," + to_string(stu.Login_pw) + ");";
	const char* str = sql.c_str();
	if (mysql_query(connect,str))
	{
		cout << "falied zhuche :ERROR:" << mysql_error(connect);
		exit(1);
	}
	else
	{
		cout << "ע��ɹ�" << endl;
	}
	return false;
}

bool Login::DengLu(string Login_ID, int Login_pw)
{
	string sql = "SELECT * FROM Login_1 WHERE Login_id = '" + Login_ID + "';";
	const char* str = sql.c_str();
	if (mysql_query(connect, str))																							//�ж��Ƿ��������ӡ������Ϣ
	{
		fprintf(stderr, "failed to select data: Error:%s\n", mysql_error(connect));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(connect);
	MYSQL_ROW row;
	row = mysql_fetch_row(res);
	Login_aaa stu;
	stu.Login_ID = row[0];
	stu.Login_pw = atoi(row[1]);
	if (stu.Login_pw == Login_pw)
	{
		return true;
	}
	else
	{
		return false;
	}
}
