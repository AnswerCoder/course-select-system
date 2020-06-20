/*****************************
*文件名：interface.cpp
*****************************/
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
#include"global.h"
using namespace std;
/*** 函数add():老师添加课程   ***/
void Teacher::addCour(){
	char ch;
	Courses newcourse;
	while (1){
		system("cls");
		printf("◎★★★★★★★★【发布课程】★★★★★★★★◎\n");
		printf("* 请发布课程，您需要输入课程名和最大选课人数 *\n");
		printf("*============================================*\n");
		printf("*      请输入课程名：                        *\n");
		printf("*                                            *\n");
		printf("*                                            *\n");
		printf("*============================================*\n");
		printf("*                                            *\n");
		printf("*                                            *\n");
		printf("**********************************************\n");
		gotoxy(23, 4);
		while (1){
			HideCursor(1);
			scanf("%s", newcourse.courseName);
			if (checkCourse(newcourse.courseName)){
				gotoxy(15, 5);
				printf("课程已存在，是否退出？");
				HideCursor(0);
				gotoxy(14, 6);printf("1(继续输入)  0(我要退出)");
				while (1){
					ch = getch();
					if (ch == '1' || ch == '0') break;
				}
				if (ch == '0'){
					gotoxy(19, 8);
					printf("添加失败！");
					Sleep(1500);
					return;
				}
				gotoxy(14, 6);printf("                       ");
				gotoxy(15, 5);printf("                       ");
				gotoxy(23, 4); printf("                      ");
				gotoxy(23, 4);
			}
			else break;
		}
		gotoxy(19, 5);printf("                       ");
		gotoxy(9, 5);
		printf("请输入课程人数：");
		scanf("%d", &newcourse.allp);
		gotoxy(9, 6);
		HideCursor(0);
		printf("请选择：1(确认添加)   0(取消添加)");
		while (1) {
			ch = getch();
			if (ch == '1' || ch == '0') break;
		}
		if (ch == '1'){
			int tot = countcourse();
			++tot;
			ofstream fout("courses.txt", ios_base::out | ios_base::app);
			fout << tot << ' ' << newcourse.courseName << ' ' << newcourse.allp << ' ' << 0 << ' ' << newcourse.allp << '\n';
			fout.close();
			fout.clear();
			HideCursor(1);
			gotoxy(11, 8);printf("添加课程成功，是否继续添加？");
			HideCursor(0);
			gotoxy(12, 9);printf("1(继续添加)    0(返回)");
			while (1){
				ch = getch();
				if (ch == '1' || ch == '0') break;
			}
			if (ch == '1') continue;
			else break;
		}
		else{
			gotoxy(19, 8);
			printf("添加失败！");
			Sleep(1500);
			break;
		}
	}
	return;
}
/*** 函数Delete():老师删除课程  ***/
void Teacher::deleteCour(){
	char ch[2];
	char c;
	while (1){
		int isquit = 0;
		system("cls");
		HideCursor(0);
		int tot = showcourses();
		while (!isquit){
			gotoxy(6, 8 + 2 * tot);
			HideCursor(1);
			printf("请输入您想删除的课程编号：");scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			gotoxy(6, 9 + 2 * tot);
			if (id >= 1 && id <= tot){
				printf("您确定要删除课程 %d 吗：1(确认)  0(取消)", id);
				HideCursor(0);
				while (1){
					c = getch();
					if (c == '1'){
						deletecourse(id);
						gotoxy(6, 10 + 2 * tot);
						printf("删除成功,是否继续删除：1(继续)  0(退出)");
						HideCursor(0);
						while (1){
							c = getch();
							if (c == '0' || c == '1') break;
						}
						if (c == '1') { isquit = 1;break; }
						else return;
					}
					else if (c == '0'){
						gotoxy(19, 10 + 2 * tot);
						printf("删除课程失败！");
						Sleep(1500);
						return;
					}
				}
			}
			else{
				printf("错误的课程号，请重新输入。");
				gotoxy(16, 8 + 2 * tot);printf("                  ");
				continue;
			}
		}
	}
	return;
}
/*** 函数revise():老师修改课程 ***/
void Teacher::reviseCour(){
	char ch[2], newname[50], c;
	int newp;
	while (1){
		int isquit = 0;
		system("cls");
		HideCursor(0);
		int tot = showcourses();
		while (!isquit){
			gotoxy(6, 8 + 2 * tot);
			HideCursor(1);
			printf("请输入您想修改的课程编号：");
			scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			gotoxy(6, 9 + 2 * tot);
			if (id >= 1 && id <= tot){
				printf("                               ");
				gotoxy(6, 9 + 2 * tot);
				printf("请输入新的课程名称：");scanf("%s", newname);
				gotoxy(6, 10 + 2 * tot);
				printf("请输入新的选课人数：");scanf("%d", &newp);
				gotoxy(6, 11 + 2 * tot);
				HideCursor(0);
				printf("您确定要修改课程 %d 吗：1(确认)  0(取消)", id);
				while (1){
					c = getch();
					if (c == '1'){
						revisecourse(id, newname, newp);
						gotoxy(6, 11 + 2 * tot);
						printf("                                          ");
						gotoxy(6, 11 + 2 * tot);
						printf("修改课程成功，是否继续修改？1(继续) 0(退出)");
						HideCursor(0);
						while (1){
							c = getch();
							if (c == '0' || c == '1') break;
						}
						if (c == '1') { isquit = 1;break; }
						else return;
					}
					else if (c == '0'){
						gotoxy(6, 11 + 2 * tot);
						printf("                                          ");
						gotoxy(19, 11 + 2 * tot);
						printf("修改课程失败！");
						Sleep(1500);
						return;
					}
				}
			}
			else{
				printf("错误的课程号，请重新输入。");
				gotoxy(16, 8 + 2 * tot);printf("                         ");
				continue;
			}
		}
	}
}
/*** 函数viewCour():查看选课情况 ***/
void Teacher::viewCour(){
	char ch[2];
	while (1){
		system("cls");
		int isquit = 0;
		int tot = showcourses();
		while (!isquit){
			HideCursor(1);
			gotoxy(6, 8 + 2 * tot);
			printf("请输入您想查看的课程的课程编号："); scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			if (id >= 1 && id <= tot)  isquit = 1, viewinfo(id);
			else{
				gotoxy(6, 9 + 2 * tot);
				printf("错误的课程号，请重新输入！");
				gotoxy(6, 8 + 2 * tot);
				printf("                                   ");
				continue;
			}
		}
	}
}
/*** 函数display():显示教师个人信息 ***/
void Teacher::display(char* id){
	ifstream fin("teachers.txt", ios_base::in);
	Teacher newtea;
	string tmp;
	int p1, p2;
	while (getline(fin, tmp)){
		p1 = tmp.find(' ');
		if (strcmp(id, tmp.substr(0, p1).c_str()) == 0){
			strcpy(newtea.Id, id);
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			strcpy(newtea.Name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
			p2 = tmp.find(' ', p1 + 1);
			strcpy(newtea.major,tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			p1 = tmp.find(' ', p2 + 1);
			strcpy(newtea.title, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		}
	}
	fin.close();
	fin.clear();
	system("cls");
	printf("◎★★★★★★【个人信息】★★★★★★◎\n");
	printf("*                                     *\n");
	printf("*        工号：%-10s             *\n",newtea.Id);
	printf("*        姓名：%-8s               *\n",newtea.Name);
	printf("*        专业：%-12s           *\n",newtea.major);
	printf("*        职称：%-6s                 *\n",newtea.title);
	printf("*                                     *\n");
	printf("*=====================================*\n");
	printf("*             按任意键返回            *\n");
	printf("***************************************\n");
	HideCursor(0);
	char ch = getch();
	return;
}
/*** 函数teacherMenu(char*):教师主界面 ***/
void Teacher::teacherMenu(char* id){
	Teacher tea;
	Person &p=tea;
	while (1){
		system("cls");
		char ch;
		HideCursor(0);
		printf("◎★★★★★★★【教师端】★★★★★★★◎\n");
		printf("*                                       *\n");
		printf("*              0.返回                   *\n");
		printf("*              1.添加课程               *\n");
		printf("*              2.删除课程               *\n");
		printf("*              3.修改课程               *\n");
		printf("*              4.查看选课情况           *\n");
		printf("*              5.查看个人信息           *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		ch = getch();
		if (ch == '0') break;
		else if (ch == '1') tea.addCour();
		else if (ch == '2') tea.deleteCour();
		else if (ch == '3') tea.reviseCour();
		else if (ch == '4') tea.viewCour();
		else if (ch == '5') p.display(id);
		else continue;
	}
	return;
}

/*** 函数select(char*):学生选课 ***/
void Student::select(char *id){
	char ch;
	char s[10];
	char name[20];
	checkname(id, name);
	int courseid;
	Courses newc;
	while (1){
		system("cls");
		printf("◎★★★★★★★★★★【选课】★★★★★★★★★★◎\n");
		printf("* %8s同学你好，请选择对应的课程或者输入0退出 *\n", name);
		printf("*=================================================*\n");
		printf("*      --------------------------------------     *\n");
		printf("*     | 课程编号 |     课程名     | 剩余人数 |    *\n");
		printf("*      --------------------------------------     *\n");
		int tot = countcourse();
		ifstream fin("courses.txt", ios_base::in);
		string tmp;
		for (int i = 1;i <= tot;i++){
			getline(fin, tmp);
			char name[50];
			int p1 = tmp.find(' ');
			int p2 = tmp.find(' ', p1 + 1);
			newc.courseId = atoi(tmp.substr(0, p1).c_str());
			strcpy(newc.courseName, tmp.substr(p1, p2 - p1).c_str());
			p1 = tmp.find(' ', p2 + 1);
			p2 = tmp.find(' ', p1 + 1);
			newc.leftp = atoi(tmp.substr(p2 + 1).c_str());
			printf("*     | %-8d | %-14s | %-8d |    *\n", newc.courseId, newc.courseName, newc.leftp);
			printf("*      --------------------------------------     *\n");
		}
		fin.close();
		fin.clear();
		printf("*=================================================*\n");
		printf("*                                                 *\n");  //line:8+2*tot;
		printf("*                                                 *\n");  //line:9+2*tot
		printf("*                                                 *\n");  //line:10+2*tot
		printf("*                                                 *\n");  //line:11+2*tot
		printf("***************************************************\n");
		while (1){
			gotoxy(14, 8 + 2 * tot);
			printf("请输入待选择的课程号：");
			HideCursor(1);
			scanf("%s", s);
			courseid = atoi(s);
			if (courseid == 0) return;
			else if (courseid >= 1 && courseid <= tot){
				if (checkSelCourse(id, courseid)){
					gotoxy(12, 9 + 2 * tot);printf("                            ");
					gotoxy(20, 9 + 2 * tot);
					printf("请勿重复选课！");
					HideCursor(0);
					Sleep(1000);
					gotoxy(15, 9 + 2 * tot);
					printf("                    ");
					gotoxy(20, 8 + 2 * tot);
					printf("                       ");
					continue;
				}
				else if (checkFull(courseid)){
					gotoxy(12, 9 + 2 * tot);printf("                            ");
					gotoxy(20, 9 + 2 * tot);
					printf("课程名额不足！");
					HideCursor(0);
					Sleep(1000);
					gotoxy(15, 9 + 2 * tot);
					printf("                    ");
					gotoxy(20, 8 + 2 * tot);
					printf("                       ");
					continue;
				}
				else break;
			}
			else{
				gotoxy(12, 9 + 2 * tot);
				printf("错误的课程号，请重新输入。");
				gotoxy(20, 8 + 2 * tot);
				printf("                       ");
				continue;
			}
		}
		gotoxy(8, 9 + 2 * tot);
		printf("您确定要选择课程 %d 吗：1(确定)  0(取消)", courseid);
		HideCursor(0);
		while (1){
			ch = getch();
			if (ch == '0'){
				gotoxy(21, 10 + 2 * tot);
				printf("选课失败！");
				Sleep(1500);
				return;
			}
			else if (ch == '1') break;
		}
		HideCursor(1);
		reviseSelCourse(id, courseid, 1);
		gotoxy(14, 10 + 2 * tot);
		printf("选课成功，是否继续选课？");
		HideCursor(0);
		gotoxy(16, 11 + 2 * tot);
		printf("1(继续选课) 0(退出)");
		while (1){
			ch = getch();
			if (ch == '0') return;
			else if (ch == '1') break;
		}
	}
	return;
}

/***  函数drop(char*):学生退课  ***/
void Student::drop(char *id){
	char name[20], cname[20];
	char ch, s[10];
	checkname(id, name);
	int courseid;
	while (1){
		system("cls");
		printf("◎★★★★★★★★★★【退课】★★★★★★★★★★◎\n");
		printf("*  %8s同学你好，请选择对应的课程或者输入0退出*\n", name);
		printf("*=================================================*\n");
		printf("*      --------------------------------------     *\n");
		printf("*     | 课程编号 |     课程名     | 选课状态 |    *\n");
		printf("*      --------------------------------------     *\n");
		int tot = countcourse();
		ifstream fin("courses.txt", ios_base::in);
		string tmp;
		for (int i = 1;i <= tot;i++){
			getline(fin, tmp);
			int p1 = tmp.find(' ');
			int p2 = tmp.find(' ', p1 + 1);
			strcpy(cname, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			int isSel = checkSelCourse(id, i);
			printf("*     | %-8d | %-14s | %-8c |    *\n", i, cname, isSel ? 'Y' : 'N');
			printf("*      --------------------------------------     *\n");
		}
		fin.close();
		fin.clear();
		printf("*=================================================*\n");
		printf("*                                                 *\n");  //line:8+2*tot;
		printf("*                                                 *\n");  //line:9+2*tot
		printf("*                                                 *\n");  //line:10+2*tot
		printf("*                                                 *\n");  //line:11+2*tot
		printf("*=================================================*\n");
		while (1){
			gotoxy(14, 8 + 2 * tot);
			printf("请输入待选择的课程号：");
			HideCursor(1);
			scanf("%s", s);
			courseid = atoi(s);
			if (courseid == 0) return;
			else if (courseid >= 1 && courseid <= tot){
				if (!checkSelCourse(id, courseid)){
					gotoxy(12, 9 + 2 * tot);printf("                            ");
					gotoxy(19, 9 + 2 * tot);
					printf("请选择已选的课！");
					HideCursor(0);
					Sleep(1000);
					gotoxy(15, 9 + 2 * tot);
					printf("                    ");
					gotoxy(20, 8 + 2 * tot);
					printf("                       ");
					continue;
				}
				else break;
			}
			else{
				gotoxy(12, 9 + 2 * tot);
				printf("错误的课程号，请重新输入。");
				gotoxy(20, 8 + 2 * tot);
				printf("                       ");
				continue;
			}
		}
		gotoxy(8, 9 + 2 * tot);
		printf("您确定要退选课程 %d 吗：1(确定)  0(取消)", courseid);
		HideCursor(0);
		while (1){
			ch = getch();
			if (ch == '0'){
				gotoxy(21, 10 + 2 * tot);
				printf("退课失败！");
				Sleep(1500);
				return;
			}
			else if (ch == '1') break;
		}
		HideCursor(1);
		reviseSelCourse(id, courseid, -1);
		gotoxy(14, 10 + 2 * tot);
		printf("退课成功，是否继续退课？");
		HideCursor(0);
		gotoxy(16, 11 + 2 * tot);
		printf("1(继续退课) 0(退出)");
		while (1){
			ch = getch();
			if (ch == '0') return;
			else if (ch == '1') break;
		}
	}
}
/***  函数viewallsel(char*):学生查看当前选课情况   ***/
void Student::viewAllSel(char *id){
	system("cls");
	int totalLenRow;         
	int courseLen[20] = { 0 };
	int totalSel[20] = { 0 };
	int cntcourse = countcourse();
	char name[20] = { 0 };
	char blank[200] = { 0 }, blankt[200] = { 0 };
	char border[200] = { 0 };
	checkname(id, name);
	ifstream finc("courses.txt", ios_base::in);
	ifstream fins("students.txt", ios_base::in);
	string tmp;
	int p1, p2, cnt = 0;
	int aSel, borderL;
	while (getline(finc, tmp)){
		cnt++;
		p1 = tmp.find(' ');
		p2 = tmp.find(' ', p1 + 1);
		courseLen[cnt] = strlen(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		p1 = tmp.find(' ', p2 + 1);
		p2 = tmp.find(' ', p1 + 1);
		totalSel[cnt] = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
	}
	finc.close();
	finc.clear();
	while (getline(fins, tmp)){
		p1 = tmp.find(' ');
		p2 = tmp.find(' ', p1 + 1);
		p1 = tmp.find(' ', p2 + 1);
		p2 = tmp.find(' ', p1 + 1);
		p1 = tmp.find(' ', p2 + 1);
		aSel = atoi(tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
		for (int i = 1;i <= aSel;i++){
			p2 = tmp.find(' ', p1 + 1);
			int cSel = atoi(tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
			p1 = p2;
		}
	}
	fins.close();
	fins.clear();
	totalLenRow = 8 + cntcourse;        
	for (int i = 1;i <= cntcourse;i++)
		totalLenRow += 2 + courseLen[i];
	for (int i = 0;i < totalLenRow;i++) strcat(border, "=");
	borderL = strlen(border);

	finc.open("courses.txt", ios_base::in);
	printf("*==========%s==========*\n", border);
	for (int i = 0;i < borderL / 2 - 5;i++) blank[i] = ' '; blank[borderL / 2 - 5] = 0;
	for (int i = 0;i < borderL - borderL / 2 - 5;i++) blankt[i] = ' '; blankt[borderL - borderL / 2 - 5] = 0;
	printf("*%s%8s同学你好，你的选课如下%s*\n", blank, name, blankt);
	printf("*==========%s==========*\n", border);
	printf("*          --------");
	for (int i = 1;i <= cntcourse;i++) {
		for (int j = 0;j < courseLen[i];j++) blank[j] = '-';
		blank[courseLen[i]] = 0;
		printf("--%s-", blank);
	}
	printf("          *\n");
	printf("*         |  姓名  |");
	for (int i = 1;i <= cntcourse;i++) {
		getline(finc, tmp);
		p1 = tmp.find(' ');
		p2 = tmp.find(' ', p1 + 1);
		char coursename[50];
		strcpy(coursename, tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		printf(" %s |", coursename);
	}
	finc.close();
	finc.clear();
	printf("         *\n");
	printf("*          --------");
	for (int i = 1;i <= cntcourse;i++) {
		for (int j = 0;j < courseLen[i];j++) blank[j] = '-';
		blank[courseLen[i]] = 0;
		printf("--%s-", blank);
	}
	printf("          *\n");
	printf("*         |%-8s|", name);
	for (int i = 1;i <= cntcourse;i++) {
		int isSel = checkSelCourse(id, i);
		for (int j = 0;j < courseLen[i] / 2;j++) blank[j] = ' '; blank[courseLen[i] / 2] = 0;
		printf(" %s%c", blank, isSel ? 'Y' : 'N');
		for (int j = 0;j < courseLen[i] - courseLen[i] / 2;j++)
			blank[j] = ' '; blank[courseLen[i] - courseLen[i] / 2] = 0;
		printf("%s|", blank);
	}
	printf("         *\n");
	printf("*          --------");
	for (int i = 1;i <= cntcourse;i++) {
		for (int j = 0;j < courseLen[i];j++) blank[j] = '-';
		blank[courseLen[i]] = 0;
		printf("--%s-", blank);
	}
	printf("          *\n");
	printf("*==========%s==========*\n", border);
	for (int i = 0;i < borderL / 2 + 4;i++) blank[i] = ' ';
	blank[borderL / 2 + 4] = 0;
	for (int i = 0;i < 4 + borderL - borderL / 2;i++) blankt[i] = ' ';
	blankt[4 + borderL - borderL / 2] = 0;
	printf("*%s按任意键退出%s*\n", blank, blankt);
	printf("*==========%s==========*\n", border);
	HideCursor(0);
	char ch = getch();
}
/***  函数display():显示学生个人信息   ***/
void Student::display(char* id){
	ifstream fin("students.txt", ios_base::in);
	Student newstu;
	string tmp;
	int p1, p2;
	while (getline(fin, tmp)){
		p1 = tmp.find(' ');
		if (strcmp(id, tmp.substr(0, p1).c_str()) == 0){
			strcpy(newstu.Id, id);
			p2 = tmp.find(' ', p1 + 1);
			p1 = tmp.find(' ', p2 + 1);
			strcpy(newstu.Name, tmp.substr(p2 + 1, p1 - p2 - 1).c_str());
			p2 = tmp.find(' ', p1 + 1);
			strcpy(newstu.major,tmp.substr(p1 + 1, p2 - p1 - 1).c_str());
		}
	}
	fin.close();
	fin.clear();
	system("cls");
	printf("◎★★★★★★【个人信息】★★★★★★◎\n");
	printf("*                                     *\n");
	printf("*        学号：%-10s             *\n",newstu.Id);
	printf("*        姓名：%-8s               *\n",newstu.Name);
	printf("*        专业：%-12s           *\n",newstu.major);
	printf("*                                     *\n");
	printf("*=====================================*\n");
	printf("*             按任意键返回            *\n");
	printf("***************************************\n");
	HideCursor(0);
	char ch = getch();
	return;
}
/***  函数studentMenu():学生主界面   ***/
void Student::studentMenu(char *id){
	Student stu;
	Person &p=stu;
	while (1){
		system("cls");
		char ch;
		HideCursor(0);
		char name[50];
		checkname(id, name);
		printf("◎★★★★★★★【学生端】★★★★★★★◎\n");
		printf("*       %8s同学您好，请选择！      *\n", name);
		printf("*=======================================*\n");
		printf("*               0.返回                  *\n");
		printf("*               1.选课                  *\n");
		printf("*               2.退课                  *\n");
		printf("*               3.查看个人信息          *\n");
		printf("*               4.查看个人选课信息      *\n");
		printf("*****************************************\n");
		ch = getch();
		if (ch == '0') break;
		else if (ch == '1') stu.select(id);
		else if (ch == '2') stu.drop(id);
		else if (ch == '3') p.display(id);
		else if (ch == '4') stu.viewAllSel(id);
		else continue;
	}
	return;
}
