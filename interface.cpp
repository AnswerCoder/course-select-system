/*****************************
*�ļ�����interface.cpp
*****************************/
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
#include"global.h"
using namespace std;
/*** ����add():��ʦ��ӿγ�   ***/
void Teacher::addCour(){
	char ch;
	Courses newcourse;
	while (1){
		system("cls");
		printf("��������������γ̡�����������\n");
		printf("* �뷢���γ̣�����Ҫ����γ��������ѡ������ *\n");
		printf("*============================================*\n");
		printf("*      ������γ�����                        *\n");
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
				printf("�γ��Ѵ��ڣ��Ƿ��˳���");
				HideCursor(0);
				gotoxy(14, 6);printf("1(��������)  0(��Ҫ�˳�)");
				while (1){
					ch = getch();
					if (ch == '1' || ch == '0') break;
				}
				if (ch == '0'){
					gotoxy(19, 8);
					printf("���ʧ�ܣ�");
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
		printf("������γ�������");
		scanf("%d", &newcourse.allp);
		gotoxy(9, 6);
		HideCursor(0);
		printf("��ѡ��1(ȷ�����)   0(ȡ�����)");
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
			gotoxy(11, 8);printf("��ӿγ̳ɹ����Ƿ������ӣ�");
			HideCursor(0);
			gotoxy(12, 9);printf("1(�������)    0(����)");
			while (1){
				ch = getch();
				if (ch == '1' || ch == '0') break;
			}
			if (ch == '1') continue;
			else break;
		}
		else{
			gotoxy(19, 8);
			printf("���ʧ�ܣ�");
			Sleep(1500);
			break;
		}
	}
	return;
}
/*** ����Delete():��ʦɾ���γ�  ***/
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
			printf("����������ɾ���Ŀγ̱�ţ�");scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			gotoxy(6, 9 + 2 * tot);
			if (id >= 1 && id <= tot){
				printf("��ȷ��Ҫɾ���γ� %d ��1(ȷ��)  0(ȡ��)", id);
				HideCursor(0);
				while (1){
					c = getch();
					if (c == '1'){
						deletecourse(id);
						gotoxy(6, 10 + 2 * tot);
						printf("ɾ���ɹ�,�Ƿ����ɾ����1(����)  0(�˳�)");
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
						printf("ɾ���γ�ʧ�ܣ�");
						Sleep(1500);
						return;
					}
				}
			}
			else{
				printf("����Ŀγ̺ţ����������롣");
				gotoxy(16, 8 + 2 * tot);printf("                  ");
				continue;
			}
		}
	}
	return;
}
/*** ����revise():��ʦ�޸Ŀγ� ***/
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
			printf("�����������޸ĵĿγ̱�ţ�");
			scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			gotoxy(6, 9 + 2 * tot);
			if (id >= 1 && id <= tot){
				printf("                               ");
				gotoxy(6, 9 + 2 * tot);
				printf("�������µĿγ����ƣ�");scanf("%s", newname);
				gotoxy(6, 10 + 2 * tot);
				printf("�������µ�ѡ��������");scanf("%d", &newp);
				gotoxy(6, 11 + 2 * tot);
				HideCursor(0);
				printf("��ȷ��Ҫ�޸Ŀγ� %d ��1(ȷ��)  0(ȡ��)", id);
				while (1){
					c = getch();
					if (c == '1'){
						revisecourse(id, newname, newp);
						gotoxy(6, 11 + 2 * tot);
						printf("                                          ");
						gotoxy(6, 11 + 2 * tot);
						printf("�޸Ŀγ̳ɹ����Ƿ�����޸ģ�1(����) 0(�˳�)");
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
						printf("�޸Ŀγ�ʧ�ܣ�");
						Sleep(1500);
						return;
					}
				}
			}
			else{
				printf("����Ŀγ̺ţ����������롣");
				gotoxy(16, 8 + 2 * tot);printf("                         ");
				continue;
			}
		}
	}
}
/*** ����viewCour():�鿴ѡ����� ***/
void Teacher::viewCour(){
	char ch[2];
	while (1){
		system("cls");
		int isquit = 0;
		int tot = showcourses();
		while (!isquit){
			HideCursor(1);
			gotoxy(6, 8 + 2 * tot);
			printf("����������鿴�Ŀγ̵Ŀγ̱�ţ�"); scanf("%s", ch);
			int id = atoi(ch);
			if (id == 0) return;
			if (id >= 1 && id <= tot)  isquit = 1, viewinfo(id);
			else{
				gotoxy(6, 9 + 2 * tot);
				printf("����Ŀγ̺ţ����������룡");
				gotoxy(6, 8 + 2 * tot);
				printf("                                   ");
				continue;
			}
		}
	}
}
/*** ����display():��ʾ��ʦ������Ϣ ***/
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
	printf("�������������Ϣ����������\n");
	printf("*                                     *\n");
	printf("*        ���ţ�%-10s             *\n",newtea.Id);
	printf("*        ������%-8s               *\n",newtea.Name);
	printf("*        רҵ��%-12s           *\n",newtea.major);
	printf("*        ְ�ƣ�%-6s                 *\n",newtea.title);
	printf("*                                     *\n");
	printf("*=====================================*\n");
	printf("*             �����������            *\n");
	printf("***************************************\n");
	HideCursor(0);
	char ch = getch();
	return;
}
/*** ����teacherMenu(char*):��ʦ������ ***/
void Teacher::teacherMenu(char* id){
	Teacher tea;
	Person &p=tea;
	while (1){
		system("cls");
		char ch;
		HideCursor(0);
		printf("����������ʦ�ˡ����������\n");
		printf("*                                       *\n");
		printf("*              0.����                   *\n");
		printf("*              1.��ӿγ�               *\n");
		printf("*              2.ɾ���γ�               *\n");
		printf("*              3.�޸Ŀγ�               *\n");
		printf("*              4.�鿴ѡ�����           *\n");
		printf("*              5.�鿴������Ϣ           *\n");
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

/*** ����select(char*):ѧ��ѡ�� ***/
void Student::select(char *id){
	char ch;
	char s[10];
	char name[20];
	checkname(id, name);
	int courseid;
	Courses newc;
	while (1){
		system("cls");
		printf("�����������ѡ�Ρ�������������\n");
		printf("* %8sͬѧ��ã���ѡ���Ӧ�Ŀγ̻�������0�˳� *\n", name);
		printf("*=================================================*\n");
		printf("*      --------------------------------------     *\n");
		printf("*     | �γ̱�� |     �γ���     | ʣ������ |    *\n");
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
			printf("�������ѡ��Ŀγ̺ţ�");
			HideCursor(1);
			scanf("%s", s);
			courseid = atoi(s);
			if (courseid == 0) return;
			else if (courseid >= 1 && courseid <= tot){
				if (checkSelCourse(id, courseid)){
					gotoxy(12, 9 + 2 * tot);printf("                            ");
					gotoxy(20, 9 + 2 * tot);
					printf("�����ظ�ѡ�Σ�");
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
					printf("�γ�����㣡");
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
				printf("����Ŀγ̺ţ����������롣");
				gotoxy(20, 8 + 2 * tot);
				printf("                       ");
				continue;
			}
		}
		gotoxy(8, 9 + 2 * tot);
		printf("��ȷ��Ҫѡ��γ� %d ��1(ȷ��)  0(ȡ��)", courseid);
		HideCursor(0);
		while (1){
			ch = getch();
			if (ch == '0'){
				gotoxy(21, 10 + 2 * tot);
				printf("ѡ��ʧ�ܣ�");
				Sleep(1500);
				return;
			}
			else if (ch == '1') break;
		}
		HideCursor(1);
		reviseSelCourse(id, courseid, 1);
		gotoxy(14, 10 + 2 * tot);
		printf("ѡ�γɹ����Ƿ����ѡ�Σ�");
		HideCursor(0);
		gotoxy(16, 11 + 2 * tot);
		printf("1(����ѡ��) 0(�˳�)");
		while (1){
			ch = getch();
			if (ch == '0') return;
			else if (ch == '1') break;
		}
	}
	return;
}

/***  ����drop(char*):ѧ���˿�  ***/
void Student::drop(char *id){
	char name[20], cname[20];
	char ch, s[10];
	checkname(id, name);
	int courseid;
	while (1){
		system("cls");
		printf("������������˿Ρ�������������\n");
		printf("*  %8sͬѧ��ã���ѡ���Ӧ�Ŀγ̻�������0�˳�*\n", name);
		printf("*=================================================*\n");
		printf("*      --------------------------------------     *\n");
		printf("*     | �γ̱�� |     �γ���     | ѡ��״̬ |    *\n");
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
			printf("�������ѡ��Ŀγ̺ţ�");
			HideCursor(1);
			scanf("%s", s);
			courseid = atoi(s);
			if (courseid == 0) return;
			else if (courseid >= 1 && courseid <= tot){
				if (!checkSelCourse(id, courseid)){
					gotoxy(12, 9 + 2 * tot);printf("                            ");
					gotoxy(19, 9 + 2 * tot);
					printf("��ѡ����ѡ�ĿΣ�");
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
				printf("����Ŀγ̺ţ����������롣");
				gotoxy(20, 8 + 2 * tot);
				printf("                       ");
				continue;
			}
		}
		gotoxy(8, 9 + 2 * tot);
		printf("��ȷ��Ҫ��ѡ�γ� %d ��1(ȷ��)  0(ȡ��)", courseid);
		HideCursor(0);
		while (1){
			ch = getch();
			if (ch == '0'){
				gotoxy(21, 10 + 2 * tot);
				printf("�˿�ʧ�ܣ�");
				Sleep(1500);
				return;
			}
			else if (ch == '1') break;
		}
		HideCursor(1);
		reviseSelCourse(id, courseid, -1);
		gotoxy(14, 10 + 2 * tot);
		printf("�˿γɹ����Ƿ�����˿Σ�");
		HideCursor(0);
		gotoxy(16, 11 + 2 * tot);
		printf("1(�����˿�) 0(�˳�)");
		while (1){
			ch = getch();
			if (ch == '0') return;
			else if (ch == '1') break;
		}
	}
}
/***  ����viewallsel(char*):ѧ���鿴��ǰѡ�����   ***/
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
	printf("*%s%8sͬѧ��ã����ѡ������%s*\n", blank, name, blankt);
	printf("*==========%s==========*\n", border);
	printf("*          --------");
	for (int i = 1;i <= cntcourse;i++) {
		for (int j = 0;j < courseLen[i];j++) blank[j] = '-';
		blank[courseLen[i]] = 0;
		printf("--%s-", blank);
	}
	printf("          *\n");
	printf("*         |  ����  |");
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
	printf("*%s��������˳�%s*\n", blank, blankt);
	printf("*==========%s==========*\n", border);
	HideCursor(0);
	char ch = getch();
}
/***  ����display():��ʾѧ��������Ϣ   ***/
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
	printf("�������������Ϣ����������\n");
	printf("*                                     *\n");
	printf("*        ѧ�ţ�%-10s             *\n",newstu.Id);
	printf("*        ������%-8s               *\n",newstu.Name);
	printf("*        רҵ��%-12s           *\n",newstu.major);
	printf("*                                     *\n");
	printf("*=====================================*\n");
	printf("*             �����������            *\n");
	printf("***************************************\n");
	HideCursor(0);
	char ch = getch();
	return;
}
/***  ����studentMenu():ѧ��������   ***/
void Student::studentMenu(char *id){
	Student stu;
	Person &p=stu;
	while (1){
		system("cls");
		char ch;
		HideCursor(0);
		char name[50];
		checkname(id, name);
		printf("��������ѧ���ˡ����������\n");
		printf("*       %8sͬѧ���ã���ѡ��      *\n", name);
		printf("*=======================================*\n");
		printf("*               0.����                  *\n");
		printf("*               1.ѡ��                  *\n");
		printf("*               2.�˿�                  *\n");
		printf("*               3.�鿴������Ϣ          *\n");
		printf("*               4.�鿴����ѡ����Ϣ      *\n");
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
