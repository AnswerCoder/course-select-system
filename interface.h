/*****************************
*�ļ�����interface.h
*�������ࡢ��ʦ��ѧ���������
*****************************/
#include<iostream>
using namespace std;
/*******����********/
class Person {
public:
	Person(){}
	virtual void display(char*)=0;	//��ʾ������Ϣ
public:
	char Id[20];	//ѧ�Ż򹤺�
	char pw[20];	//����
	char Name[20];	//����
	char major[50];	//רҵ
};
/*******ѧ����********/
class Student:public Person{
public:
	Student(){}
	void display(char*);    //ѧ���鿴������Ϣ
	void select(char*);		//ѧ��ѡ��
	void drop(char*);		//ѧ���˿�
	void viewAllSel(char*);	//�鿴����ѡ����Ϣ
	void studentMenu(char*);//ѧ������������
	int totalSelected;		//ѡ������
};
/*******��ʦ��********/
class Teacher :public Person {
public:
	Teacher(){}
	void addCour(void);		//�����γ�
	void deleteCour(void);	//��ʦɾ���γ�
	void reviseCour(void);	//��ʦ�޸Ŀγ�
	void viewCour(void);	//�鿴ѡ�����
	void display(char*);    //��ʾ������Ϣ
	void teacherMenu(char*);	//��ʦ����������
	char title[20];		//ְ��
};
/*******�γ���********/
class Courses {
public:
	int courseId;
	char courseName[50];
	int allp;		//������
	int selectp;	//��ѡ��
	int leftp;		//ʣ����
};
