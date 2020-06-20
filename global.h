/*****************************
*文件名：global.h
*包含一些公用成员和函数的声明
*****************************/
#include"interface.h"
struct user {			//用户
	char type;			//老师或学生
	char username[20];	//用户名
	char pw[20];		//密码
};
void gotoxy(int, int);		//光标定位
void HideCursor(int);		//光标隐藏

void menu(void);			//主界面
void regis();				//注册
void login(char);			//登录
int checkUser(char*);		//检查用户是否已存在
int checkLogin(char*, char*, char);//登录验证

void checkname(char*, char*);	//找到对应id的姓名
void updateSelp(int, int);		//更新选课人数信息
int checkFull(int);				//检查选课人数是否已满
int checkSelCourse(char*, int);	//检测是否已选过该课程
void reviseSelCourse(char*, int, int);//修改学生选课信息

int checkCourse(char*);		//检查输入的课程是否已存在
int countcourse(void);		//统计当前已添加的课程总数
void deleteinfo(int);		//删除学生选课信息
void deletecourse(int);		//删除当前课程
void revisecourse(int, char*, int);//修改当前课程
int showcourses(void);		//显示当前所有课程信息
void viewinfo(int);			//查看课程信息
