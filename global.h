/*****************************
*�ļ�����global.h
*����һЩ���ó�Ա�ͺ���������
*****************************/
#include"interface.h"
struct user {			//�û�
	char type;			//��ʦ��ѧ��
	char username[20];	//�û���
	char pw[20];		//����
};
void gotoxy(int, int);		//��궨λ
void HideCursor(int);		//�������

void menu(void);			//������
void regis();				//ע��
void login(char);			//��¼
int checkUser(char*);		//����û��Ƿ��Ѵ���
int checkLogin(char*, char*, char);//��¼��֤

void checkname(char*, char*);	//�ҵ���Ӧid������
void updateSelp(int, int);		//����ѡ��������Ϣ
int checkFull(int);				//���ѡ�������Ƿ�����
int checkSelCourse(char*, int);	//����Ƿ���ѡ���ÿγ�
void reviseSelCourse(char*, int, int);//�޸�ѧ��ѡ����Ϣ

int checkCourse(char*);		//�������Ŀγ��Ƿ��Ѵ���
int countcourse(void);		//ͳ�Ƶ�ǰ����ӵĿγ�����
void deleteinfo(int);		//ɾ��ѧ��ѡ����Ϣ
void deletecourse(int);		//ɾ����ǰ�γ�
void revisecourse(int, char*, int);//�޸ĵ�ǰ�γ�
int showcourses(void);		//��ʾ��ǰ���пγ���Ϣ
void viewinfo(int);			//�鿴�γ���Ϣ
