#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#include"hacker.h"

using namespace std;

#define WIDTH 60
#define HEIGHT 30

void inputPwd(char pwd[],int max_len){
	char c;
	int i = 0;
		
	while (1) {
		c = getch();
        // getch�������뻺�����ж�ȡ
		//��getch�У��ѻس��������룬ʶ��Ϊ�س���'\r'
        //��getchar�У��ѻس��������룬ʶ��Ϊ���з�'\n'
		if (c == '\r' || i >= max_len) {  
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		//printf("*", c);
		printf("*");
	}
	printf("\n");

}

void login(void){
	string name;
	//string pwd;
	char pwd[32];

	while(1){
		system("cls");
		cout << "�������˺�: ";
		cin >> name;
		cout << "����������: ";
		//cin >> pwd;
		//ʵ����������
		inputPwd(pwd,sizeof(pwd));

		if(name == "123qw" && !strcmp(pwd,"123456")){		
			//break;
			return;
		}else{
			cout <<"�û������������"<< endl;
			system("pause");
		}
	}
}

void printInMiddle(string msg){
	int leftSpace = (WIDTH - msg.length())/2;
	
	for(int i = 0; i < leftSpace;i++){
		cout << " ";	
	}

	cout << msg << endl;
}



void menuShow(void){
	system("cls");
	/*
	cout<<"1.��վ404����"<<endl;
	cout<<"2.��վ�۸Ĺ���"<<endl;
	cout<<"3.��վ������¼"<<endl;
	cout<<"4.��վ�����޸�"<<endl;
	cout<<"5.�˳�"<<endl;
	*/
	string menu[] ={
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ������¼",
		"4.��վ�����޸�",
		"5.�˳�"
	};

	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);
	for(int i = 0; i < menuCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}	
	}
	//��ӡ����
	printInMiddle("---�ڿ͹���ϵͳ---");

	int leftSpace = (WIDTH - max)/2;
	for(int i = 0; i< menuCount;i++){
		for(int i = 0; i < leftSpace;i++){
			cout << " ";	
		}
		cout << menu[i] << endl;
	}
}

int menuChoise(void){
	//���빦�ܱ��
	
	int n = 0;
	while(1){
		cout << "��ѡ��: ";
		cin >> n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "��Ч����,����������." << endl;
			system("pause");
		}else{
			break;
		}
	}

	return n;
}

void attack404(void){
	char id[32];	//��վid
	char response[MAXSIZE];//������,�ӷ��������صĽ��
	system("cls");
	//int hk_404(char *id, char *response);
	printInMiddle("---��վ404����---");


	cout <<"������׼����������վID:";
	scanf_s("%s",id,sizeof(id));

	cout << "����ִ��404����..." << endl;

	hk_404(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void siteEdit(void){
	char id[64];
	char response[MAXSIZE];
	string attackText;

	system("cls");
	
	//��ҳ�۸Ĺ�����para��ʾ�������
	
	cout <<"������׼����������վID:";
	scanf_s("%s",id,sizeof(id));

	cout << "��������Ҫд�������.";
	cin >> attackText;

	
	cout << "����ִ����վ�۸Ĺ���..."<< endl;
	GBKToUTF8(attackText);//ת��
	hk_tamper(id, (char*)attackText.c_str(), response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(void){
	//cout<<"�鿴������¼..."<<endl;	
	char id[64];
	char response[MAXSIZE];

	system("cls");

	printInMiddle("---�鿴��վ������¼---");


	cout <<"������׼���鿴��վ������¼����վID:";
	scanf_s("%s",id,sizeof(id));

	cout << "����ִ�в鿴��վ����..."<< endl
		
		;

	hk_record(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRepair(void){
	char id[64];
	char response[MAXSIZE];

	system("cls");

	printInMiddle("---��վ�����޸�---");


	cout <<"������׼�������޸�����վID:";
	scanf_s("%s",id,sizeof(id));

	cout << "����ִ�й����޸�..." << endl;

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void init(void){
	//�����ն˴��ڵĴ�С
	//mode con cols=40 lines=15
	char cmd[128];

	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH ,HEIGHT );
	system(cmd);
}

int main(void){
	init();	 //��ʼ������
	login(); //ʵ�ֵ�¼����.

	while(1){

		menuShow(); //ʵ����ʾ�˵�

		int n = menuChoise();
		switch(n){
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			attackRepair();
			break;
		case 5:			
			return 0;
		default:
			cout <<"��Ч����,����������."<<endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}