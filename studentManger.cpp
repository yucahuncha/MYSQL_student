#include "studentManger.h"

studentManger::studentManger()
{
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con,host,name,pw,database_name,port,NULL,0))
	{
		std::cout << "failed to connect" << std::endl;
		exit(1);
	}
}

studentManger::~studentManger()
{
	mysql_close(con);
}

bool studentManger::insert_student(Student& stu)					//增加
{
	//char sql[1024];
	string sql = "INSERT INTO students(student_id,student_name,class_id) VALUES (" + to_string(stu.student_id) + ",'" + stu.student_name + "','" + stu.class_id + "');";
	const char* str = sql.c_str();
	if (mysql_query(con,str))
	{
		cout << "failed to insert data:ERROR:" << mysql_error(con);
		return false;
	}
	else
	{
		cout << "插入成功" << endl;
	}
	return false;
}

bool studentManger::update_student(Student& stu)	//修改
{
	string sql = "UPDATE students SET student_name = '"+stu.student_name +"', class_id = '"+stu.class_id+"' where student_id = " + to_string(stu.student_id);
	const char* str = sql.c_str();
	if (mysql_query(con,str))
	{
		cout << "failed to update date:ERROR:" << mysql_error(con);
		return false;
	}
	else
	{
		cout << "修改成功" << endl;
	}

	return true;
}

bool studentManger::dalete_student(int student_id)
{
	string sql = "DELETE FROM students WHERE student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con,str))
	{
		cout << "failed to datele date:ERROR:" << mysql_error(con);
	}
	else
	{
		cout << "删除成功"<<endl;
	}
	return true;
}

char studentManger::get_student(int student_id)
{
	string sql = "select * from students where student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con, str))																							//判断是否出错，并打印错误信息
	{
		fprintf(stderr, "failed to select data: Error:%s\n", mysql_error(con));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;															//创建存放信息的数组
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.class_id = row[2];
		cout << stu.student_id << ":" << stu.student_name << ":" << stu.class_id << endl;					//打印信息
	}

}

void studentManger::zhengjia()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "请输入学生的id和姓名，班级" << endl;
	cin >> ID >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->insert_student(stu);
}

void studentManger::shuanchu()
{
	int ID;
	cout << "请输入要删除的ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->dalete_student(ID);
}

void studentManger::gengxin()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "请输入要更新的ID，然后输入名字，班级" << endl;
	cin >> ID;
	cin >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->update_student(stu);
};

void studentManger::chanxun()
{
	int ID;
	cout << "请输入要查询的ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->get_student(ID);
};

