/*****************************
*文件名：global.cpp
*****************************/
#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include<string>
#include"global.h"
/*** 函数HideCursor(int):光标定位 ***/
void gotoxy(int x, int y){
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*** 函数HideCursor(int):光标隐藏 ***/
void HideCursor(int mark){
	CONSOLE_CURSOR_INFO cursor_info = { 1, mark };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/*** 函数welcome():主界面 ***/
void menu(void){
	char ch;
	while (1){
		system("cls");
		cout << "◎★★★★【欢迎进入学生选课系统】★★★★◎\n";
		cout << "*                                          *\n";
		cout << "*              0  退出系统                 *\n";
		cout << "*              1  注册                     *\n";
		cout << "*              2  教师端                   *\n";
		cout << "*              3  学生端                   *\n";
		cout << "*                                          *\n";
		cout << "********************************************\n";
		ch = getch();
		if (ch == '0') break;
		else if (ch == '1') regis();
		else if (ch == '2') login('1');
		else if (ch == '3') login('0');
	}
	return;
}
/*** 函数regis():为老师或学生注册账号 ***/
void regis(){
	system("cls");
	char ch, type;
	user newid;
 	Teacher newtea;
	Student newstu;
	printf("◎ ★★★★★★★★★★★【注册】★★★★★★★★★★★ ◎\n");
	printf("*      接下来请选择您的身份，并输入用户名和密码         *\n");
	printf("*               用户名和密码不超过20个字符              *\n");
	printf("*=======================================================*\n");
	printf("*        选择您的身份：1(教师)      0(学生)             *\n"); //line 5
	printf("*                                                       *\n"); //line 6
	printf("*                                                       *\n"); //line 7
	printf("*                                                       *\n"); //line 8
	printf("*                                                       *\n"); //line 9
	printf("*                                                       *\n"); //line 10
	printf("*=======================================================*\n");
	printf("*                                                       *\n"); //line 12
	printf("*                                                       *\n"); //line 13
	printf("*********************************************************\n");
	HideCursor(0);
	while (1) {
		ch = getch();
		if (ch == '1' || ch == '0') { newid.type = ch;break; }
	}
	type = ch;
	HideCursor(1);
	gotoxy(11,6);
	if (ch == '1')printf("输入您的工号：");
	else printf("输入您的学号：");
	while (1){
		HideCursor(1);
		scanf("%s", &newid.username);
		if (ch == '0') strcpy(newstu.Id, newid.username);
		if (ch == '1') strcpy(newtea.Id, newid.username);
		if (checkUser(newid.username)) {
			gotoxy(16,7);
			printf("        账号已存在！");
			HideCursor(0);
			Sleep(1000);
			gotoxy(16,7);
			printf("                         ");
			gotoxy(25,6);
			printf("                         ");
			gotoxy(25,6);
		}
		else break;
	}
	gotoxy(11,7);
	printf("                                       ");
	gotoxy(11,7);
	printf("输入您的密码：");
	scanf("%s", &newid.pw);
	if (ch == '1') {
		strcpy(newtea.pw, newid.pw);
		gotoxy(11,8);
		printf("输入您的姓名：");
		scanf("%s", &newtea.Name);
		gotoxy(11,9);
		printf("输入您的专业：");
		scanf("%s", &newtea.major);
		gotoxy(11,10);
		printf("输入您的职称：");
		scanf("%s", &newtea.title);
	}
	if (ch == '0') {
		strcpy(newstu.pw, newid.pw);
		gotoxy(11,8);
		printf("输入您的姓名：");
		scanf("%s", &newstu.Name);
		gotoxy(11,9);
		printf("输入您的专业：");
		scanf("%s", &newstu.major);
	}
	HideCursor(0);
	gotoxy(13,12);
	printf("请确认您的输入：1(确认)  0(取消)");
	while (1) {
		char ch = getch();
		if (ch == '1'){
			ofstream fout("users.txt", ios_base::app | ios_base::out);
			fout << newid.type << ' ' << newid.username << ' ' << newid.pw << "\n";
			if (type == '0'){
				fout.clear();
				fout.close();
				fout.open("students.txt", ios_base::app | ios_base::out);
				fout << newstu.Id << ' ' << newstu.pw << ' ' << newstu.Name << ' ' << newstu.major << ' ' << 0 << ' ' << '\n';
			}
			if (type == '1'){
				fout.clear();
				fout.close();
				fout.open("teachers.txt", ios_base::app | ios_base::out);
				fout << newtea.Id << ' ' << newtea.pw << ' ' << newtea.Name << ' ' << newtea.major << ' ' << newtea.title << ' ' << '\n';
			}
			fout.clear();
			fout.close();
			gotoxy(25,13);
			printf("注册成功！\n");
			Sleep(1500);
			return;
		}
		else if (ch == '0') {
			gotoxy(25,13);
			printf("注册失败！");
			Sleep(1500);
			return;
		}
	}
}
/*** 函数login(char):登录 ***/
void login(char type){
	Teacher tea;
	Student stu;
	system("cls");
	char id[20], pw[30];
	printf("◎★★★★★★★★【登录】★★★★★★★◎\n");
	printf("*    用户您好！请输入您的账号和密码     *\n");
	printf("*=======================================*\n");
	printf("*        输入您的账号：                 *\n");
	printf("*        输入您的密码：                 *\n");
	printf("*=======================================*\n");
	printf("*                                       *\n");
	printf("*                                       *\n");
	printf("*****************************************\n");
	while (1){
		HideCursor(1);
		gotoxy(25,4);scanf("%s",id);
		gotoxy(25,5);scanf("%s",pw);
		if (checkLogin(id, pw, type)) break;
		else {
			gotoxy(4,7);
			printf("账号不存在或账号密码不匹配，是否退出？");
			gotoxy(10,8);
			printf("1(选择退出)  0(重新输入)");
			HideCursor(0);
			char ch = getch();
			if (ch == '1') return;
			else {
				gotoxy(10,8);printf("                         ");
				gotoxy(3,7);printf("                                       ");
				gotoxy(25,5);printf("               ");
				gotoxy(25,4);printf("               ");
			}
		}
	}
	gotoxy(10,8);
	printf("登陆成功！即将进入页面！");
	HideCursor(0);
	Sleep(1500);
	if (type == '1') tea.teacherMenu(id);
	else stu.studentMenu(id);
	return;
}

/*** 函数checkUser(char*):检查用户是否已存在 ***/
int checkUser(char *s){
	ifstream fin("users.txt", ios_base::in);
	int isfound = 0;
	string tmp;
	char t[50];
	while (getline(fin, tmp)){
		int p1 = tmp.find(' ');
		int p2 = tmp.find(' ', p1 + 1);
		strcpy(t, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		if (strcmp(t, s) == 0) { isfound = 1;break; }
	}
	if (fin.eof()) fin.clear();
	if (isfound) return 1;
	else return 0;
}
/*** 函数checkLogin(char*,char *,char):登录验证 ***/
int checkLogin(char *id, char *pw, char type){
	ifstream fin("users.txt", ios_base::in);
	int isfound = 0;
	string tmp;
	char idt[25], pwt[25], typet;
	while (getline(fin, tmp)){
		typet = tmp[0];
		if (typet != type) continue;
		int p1 = tmp.find(' ');
		int p2 = tmp.find(' ', p1 + 1);
		strcpy(idt, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		if (strcmp(idt, id)) continue;
		strcpy(pwt, tmp.substr(p2 + 1).c_str());
		if (strcmp(pwt, pw)) continue;
		else { isfound = 1;break; }
	}
	if (fin.eof()) fin.clear();
	if (isfound) return 1;
	else return 0;
}
/*** 函数checkname(char*,char*):找到对应id的姓名 ***/
void checkname(char *id, char *name){
	ifstream fin("students.txt", ios_base::in);
	string tmp;
	int p1, p2;
	while (getline(fin, tmp)){
		p1 = tmp.find(' ');
		if (strcmp(id, tmp.substr(0, p1).c_str()) == 0){
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			strcpy(name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
			fin.close();
			return;
		}
	}
}
/*** 函数updateSelp(int,int):更新选课人数信息 ***/
void updateSelp(int courseid, int type){
	//type==1 means a new selection while -1 a deletion of courseid
	ifstream fin("courses.txt", ios_base::in);
	Courses newc[20];
	int cnt = 0;
	int p1, p2;
	string tmp;
	while (getline(fin, tmp)){
		cnt++;
		p1 = tmp.find(' ');
		newc[cnt].courseId = atoi(tmp.substr(0, p1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		strcpy(newc[cnt].courseName, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		newc[cnt].allp = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		newc[cnt].selectp = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		newc[cnt].leftp = atoi(tmp.substr(p2 + 1).c_str());
		if (newc[cnt].courseId == courseid){
			if (type == 1){
				newc[cnt].leftp--;
				newc[cnt].selectp++;
			}
			else{
				newc[cnt].leftp++;
				newc[cnt].selectp--;
			}
		}
	}
	fin.close();
	fin.clear();
	ofstream fout("courses.txt", ios_base::out | ios_base::trunc);
	for (int i = 1;i <= cnt;i++)
		fout << newc[i].courseId << ' ' << newc[i].courseName << ' ' << newc[i].allp << ' ' << newc[i].selectp << ' ' << newc[i].leftp << '\n';
	fout.close();
	fout.clear();
	return;
}
/*** 函数checkFull(int):检查选课人数是否已满 ***/
int checkFull(int courseid){
	ifstream fin("courses.txt", ios_base::in);
	string tmp;
	int p1, p2;
	while (getline(fin, tmp)){
		p1 = tmp.find(' ');
		if (atoi(tmp.substr(0, p1).c_str()) == courseid){
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			p2 = tmp.find(' ', p1 + 1);
			if (atoi(tmp.substr(p2 + 1).c_str()) <= 0) return 1;
			else return 0;
		}
	}
}
/*** 函数checkSelCourse(char*,int):检查是否已选过该课程 ***/
int checkSelCourse(char *id, int courseid){
	ifstream fin("students.txt", ios_base::in);
	string tmp;
	char idt[20];
	int p1, p2;
	while (getline(fin, tmp)){
		p1 = tmp.find(' ');
		strcpy(idt, tmp.substr(0, p1).c_str());
		if (strcmp(idt, id) == 0){
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			int seln = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
			for (int i = 1;i <= seln;i++)
			{
				p2 = tmp.find(' ', p1 + 1);
				int cid = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
				if (cid == courseid) return 1;
				p1 = p2;
			}
			return 0;
		}
	}
	return 0;
}
/*** 函数reviseSelCourse(char*,int,int):修改学生选课信息 ***/
void reviseSelCourse(char *id, int courseid, int type){
	updateSelp(courseid, type);
	//type==1 means new selection of courseid, while -1 means a new deletion of courseid
	ifstream fin("students.txt", ios_base::in);
	string tmp;
	Student newstu[100];
	int p1, p2, cnt = 0;
	int sels[100][20];
	while (getline(fin, tmp)){
		cnt++;
		p1 = tmp.find(' ');
		strcpy(newstu[cnt].Id, tmp.substr(0, p1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		strcpy(newstu[cnt].pw, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		strcpy(newstu[cnt].Name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		strcpy(newstu[cnt].major,tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		newstu[cnt].totalSelected = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		for (int i = 1;i <= newstu[cnt].totalSelected;i++){
			p2 = tmp.find(' ', p1 + 1);
			sels[cnt][i] = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			p1 = p2;
		}
		if (strcmp(id, newstu[cnt].Id) == 0){
			if (type == 1)
				sels[cnt][++newstu[cnt].totalSelected] = courseid;
			else{
				int i = 1, j = 1;
				while (i <= newstu[cnt].totalSelected){
					if (sels[cnt][i] != courseid) sels[cnt][j] = sels[cnt][i], j++, i++;
					else i++;
				}
				newstu[cnt].totalSelected--;
			}
		}
	}
	fin.close();
	fin.clear();
	ofstream fout("students.txt", ios_base::out | ios_base::trunc);
	for (int i = 1;i <= cnt;i++){
		fout << newstu[i].Id << ' ' << newstu[i].pw << ' ' << newstu[i].Name << ' ' << newstu[i].major << ' '
			<< newstu[i].totalSelected << ' ';
		for (int j = 1;j <= newstu[i].totalSelected;j++)
			fout << sels[i][j] << ' ';
		fout << '\n';
	}
	fin.close();
	fin.clear();
}
/*** 函数checkCourse(char*):检查输入的课程是否已存在 ***/
int checkCourse(char *s){
	ifstream fin("courses.txt", ios_base::in);
	if (!fin.is_open()) return 0;
	string tmp;
	int isfound = 0;
	char coursename[50];
	while (getline(fin, tmp)){
		int p1 = tmp.find(' ');
		int p2 = tmp.find(' ', p1 + 1);
		strcpy(coursename, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		if (strcmp(s, coursename) == 0) { isfound = 1;break; }
		else continue;
	}
	if (isfound) return 1;
	else return 0;
}
/*** 函数coursecount():统计当前已添加的课程总数 ***/
int countcourse(){
	int cnt = 0;
	string tmp;
	ifstream fin("courses.txt", ios_base::in);
	while (getline(fin, tmp)) cnt++;
	fin.close();
	fin.clear();
	return cnt;
}
/*** 函数deleteinfo(int): 删除学生选课信息 ***/
void deleteinfo(int id){
	//查看所有学生信息，对已选课程_id_的学生进行修改
	ifstream fin("students.txt", ios_base::in);
	string tmp;
	Student newstu[100];
	int cnt = 0;
	int sels[100][20];
	while (getline(fin, tmp)){
		cnt++;
		sels[cnt][0] = 0;
		int p1 = tmp.find(' ');
		strcpy(newstu[cnt].Id, tmp.substr(0, p1).c_str());
		int p2 = tmp.find(' ', p1 + 1);
		strcpy(newstu[cnt].pw, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		strcpy(newstu[cnt].Name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		strcpy(newstu[cnt].major,tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		newstu[cnt].totalSelected = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		for (int i = 1;i <= newstu[cnt].totalSelected;i++){
			p2 = tmp.find(' ', p1 + 1);
			int cid = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			if (cid == id) sels[cnt][0] = 1;
			sels[cnt][i] = cid;
			p1 = p2;
		}
	}
	fin.close();
	fin.clear();
	ofstream fout("students.txt", ios_base::out | ios_base::trunc);
	for (int i = 1;i <= cnt;i++){
		fout << newstu[i].Id << ' ' << newstu[i].pw << ' ' << newstu[i].Name << ' ' << newstu[i].major << ' '
			<< newstu[i].totalSelected - sels[i][0] << ' ';
		for (int j = 1;j <= newstu[i].totalSelected;j++){
			if (sels[i][j] < id) fout << sels[i][j] << ' ';
			else if (sels[i][j] > id) fout << sels[i][j] - 1 << ' ';
		}
		fout << '\n';
	}
	fout.close();
	fout.clear();
	return;
}
/*** 函数deletecourse(int): 删除当前课程  ***/
void deletecourse(int id){
	//除了要删除的课程之外全部重新写入
	deleteinfo(id);
	Courses cs[20];
	ifstream fin("courses.txt", ios_base::in);
	int cnt = 0;
	int idt;
	string tmp;
	while (getline(fin, tmp)){
		int p1 = tmp.find(' ');
		idt = atoi(tmp.substr(0, p1).c_str());
		if (idt == id) continue;
		else{
			cnt++;
			cs[cnt].courseId = cnt;
			int p2 = tmp.find(' ', p1 + 1);
			strcpy(cs[cnt].courseName, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			p1 = tmp.find(' ', p2 + 1);
			cs[cnt].allp = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
			p2 = tmp.find(' ', p1 + 1);
			cs[cnt].selectp = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			cs[cnt].leftp = atoi(tmp.substr(p2 + 1).c_str());
		}
	}
	fin.close();
	fin.clear();
	ofstream fout("courses.txt", ios_base::out | ios_base::trunc);
	for (int i = 1;i <= cnt;i++)
		fout << cs[i].courseId << ' ' << cs[i].courseName << ' '
		<< cs[i].allp << ' ' << cs[i].selectp << ' ' << cs[i].leftp << '\n';
	fout.close();
	fout.clear();
	return;
}
/***  函数revisecourse(int,char*,int): 修改当前课程 ***/
void revisecourse(int id, char *newname, int newp){
	Courses cs[20];
	ifstream fin("courses.txt", ios_base::in);
	int idt;
	int cnt = 0;
	string tmp;
	while (getline(fin, tmp)){
		cnt++;
		int p1 = tmp.find(' ');
		idt = atoi(tmp.substr(0, p1).c_str());
		cs[cnt].courseId = idt;
		int p2 = tmp.find(' ', p1 + 1);
		strcpy(cs[cnt].courseName, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		cs[cnt].allp = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		cs[cnt].selectp = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		cs[cnt].leftp = atoi(tmp.substr(p2 + 1).c_str());
		if (idt == id){
			strcpy(cs[cnt].courseName, newname);
			cs[cnt].allp = newp;
			cs[cnt].leftp = newp - cs[cnt].selectp;
		}
	}
	fin.close();
	fin.clear();
	ofstream fout("courses.txt", ios_base::out | ios_base::trunc);
	for (int i = 1;i <= cnt;i++)
		fout << cs[i].courseId << ' ' << cs[i].courseName << ' '
		<< cs[i].allp << ' ' << cs[i].selectp << ' ' << cs[i].leftp << '\n';
	fout.close();
	fout.clear();
	return;
}
/***  函数showcourses():显示当前所有课程信息  ***/
int showcourses(){
	printf("◎★★★★★★★★★【课程信息】★★★★★★★★★◎\n");
	printf("*           请选择对应课程编号或者按0退出         *\n");
	printf("*=================================================*\n");
	printf("*     ---------------------------------------     *\n");
	printf("*    | 课程编号 |     课程名     | 已选/全部 |    *\n");
	printf("*     ---------------------------------------     *\n");
	int tot = countcourse();
	ifstream fin("courses.txt", ios_base::in);
	string tmp;
	for (int i = 1;i <= tot;i++){
		getline(fin, tmp);
		int id, allp, selp;
		char name[50];
		int p1 = tmp.find(' ');
		int p2 = tmp.find(' ', p1 + 1);
		id = atoi(tmp.substr(0, p1).c_str());
		strcpy(name, tmp.substr(p1, p2 - p1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		allp = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		selp = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		printf("*    | %-8d | %-14s | %4d/%-4d |    *\n", id, name, selp, allp);
		printf("*     ---------------------------------------     *\n");
	}
	fin.close();
	fin.clear();
	printf("*=================================================*\n");
	printf("*                                                 *\n");  //line:8+2*tot;
	printf("*                                                 *\n");  //line:9+2*tot
	printf("*                                                 *\n");  //line:10+2*tot
	printf("*                                                 *\n");  //line:11+2*tot
	printf("***************************************************\n");
	return tot;
}
/***  函数viewinfo(int):查看某一课程信息  ***/
void viewinfo(int id)
{
	system("cls");
	ifstream fin("courses.txt", ios_base::in);
	int cnt = 0;
	char coursename[50];
	string tmp;
	while (getline(fin, tmp)){
		int p1 = tmp.find(' ');
		int idt = atoi(tmp.substr(0, p1).c_str());
		if (idt == id){
			int p2 = tmp.find(' ', p1 + 1);
			strcpy(coursename, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			break;
		}
	}
	fin.close();
	fin.clear();
	printf("◎★★★★★★★★★★★★★【课程信息】★★★★★★★★★★★★◎\n");
	printf("*           %20s的选课情况如下                  *\n", coursename);
	printf("*===============================================================*\n");
	printf("*      ---------------------------------------------------      *\n");
	printf("*      |序号|    学号    |   姓名   |        专业        |      *\n");
	printf("*      ---------------------------------------------------      *\n");
	fin.open("students.txt", ios_base::in);
	Student newstu;
	while (getline(fin, tmp)){
		int p1 = tmp.find(' ');
		strcpy(newstu.Id, tmp.substr(0, p1).c_str());
		int p2 = tmp.find(' ', p1 + 1);
  		p1 = tmp.find(' ', p2 + 1);
		strcpy(newstu.Name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		p2 = tmp.find(' ', p1 + 1);
		strcpy(newstu.major,tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		newstu.totalSelected = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		if (newstu.totalSelected == 0) continue;
		else{
			int isfound = 0, q;
			for (int i = 1;i <= newstu.totalSelected;i++){
				q = tmp.find(' ', p1 + 1);
				int sel = atoi(tmp.substr(p1 + 1, q - p1 - 1).c_str());
				if (sel == id){
					isfound = 1;
					break;
				}
				p1 = q;
			}
			if (isfound){
				cnt++;
				printf("*      |%-4d|%-12s|%-10s|%-20s|      *\n", cnt, newstu.Id, newstu.Name, newstu.major);
				printf("*      ---------------------------------------------------      *\n");
			}
		}
	}
	printf("*===============================================================*\n");
	printf("*                         按任意键返回                          *\n");
	printf("*****************************************************************\n");
	HideCursor(0);
	char ch = getch();
	return;
}
/*** 主函数 ***/
int main(){
	menu();
	return 0;
}

