/*****************************
*文件名：interface.h
*包含基类、教师和学生类的声明
*****************************/
#include<iostream>
using namespace std;
/*******基类********/
class Person {
public:
	Person(){}
	virtual void display(char*)=0;	//显示个人信息
public:
	char Id[20];	//学号或工号
	char pw[20];	//密码
	char Name[20];	//姓名
	char major[50];	//专业
};
/*******学生类********/
class Student:public Person{
public:
	Student(){}
	void display(char*);    //学生查看个人信息
	void select(char*);		//学生选课
	void drop(char*);		//学生退课
	void viewAllSel(char*);	//查看个人选课信息
	void studentMenu(char*);//学生操作主界面
	int totalSelected;		//选课数量
};
/*******教师类********/
class Teacher :public Person {
public:
	Teacher(){}
	void addCour(void);		//发布课程
	void deleteCour(void);	//老师删除课程
	void reviseCour(void);	//老师修改课程
	void viewCour(void);	//查看选课情况
	void display(char*);    //显示个人信息
	void teacherMenu(char*);	//教师操作主界面
	char title[20];		//职称
};
/*******课程类********/
class Courses {
public:
	int courseId;
	char courseName[50];
	int allp;		//课容量
	int selectp;	//已选量
	int leftp;		//剩余量
};
