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
        // getch不从输入缓冲区中读取
		//在getch中，把回车按键输入，识别为回车符'\r'
        //在getchar中，把回车按键输入，识别为换行符'\n'
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
		cout << "请输入账号: ";
		cin >> name;
		cout << "请输入密码: ";
		//cin >> pwd;
		//实现密码输入
		inputPwd(pwd,sizeof(pwd));

		if(name == "123qw" && !strcmp(pwd,"123456")){		
			//break;
			return;
		}else{
			cout <<"用户名或密码错误"<< endl;
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
	cout<<"1.网站404攻击"<<endl;
	cout<<"2.网站篡改攻击"<<endl;
	cout<<"3.网站攻击记录"<<endl;
	cout<<"4.网站攻击修复"<<endl;
	cout<<"5.退出"<<endl;
	*/
	string menu[] ={
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击记录",
		"4.网站攻击修复",
		"5.退出"
	};

	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);
	for(int i = 0; i < menuCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}	
	}
	//打印标题
	printInMiddle("---黑客攻击系统---");

	int leftSpace = (WIDTH - max)/2;
	for(int i = 0; i< menuCount;i++){
		for(int i = 0; i < leftSpace;i++){
			cout << " ";	
		}
		cout << menu[i] << endl;
	}
}

int menuChoise(void){
	//输入功能编号
	
	int n = 0;
	while(1){
		cout << "请选择: ";
		cin >> n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "无效输入,请重新输入." << endl;
			system("pause");
		}else{
			break;
		}
	}

	return n;
}

void attack404(void){
	char id[32];	//网站id
	char response[MAXSIZE];//攻击后,从服务器返回的结果
	system("cls");
	//int hk_404(char *id, char *response);
	printInMiddle("---网站404攻击---");


	cout <<"请输入准备攻击的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout << "正在执行404攻击..." << endl;

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
	
	//网页篡改攻击，para表示填充内容
	
	cout <<"请输入准备攻击的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout << "请输入你要写入的内容.";
	cin >> attackText;

	
	cout << "正在执行网站篡改攻击..."<< endl;
	GBKToUTF8(attackText);//转码
	hk_tamper(id, (char*)attackText.c_str(), response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attackRecord(void){
	//cout<<"查看攻击记录..."<<endl;	
	char id[64];
	char response[MAXSIZE];

	system("cls");

	printInMiddle("---查看网站攻击记录---");


	cout <<"请输入准备查看网站攻击记录的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout << "正在执行查看网站攻击..."<< endl
		
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

	printInMiddle("---网站攻击修复---");


	cout <<"请输入准备攻击修复的网站ID:";
	scanf_s("%s",id,sizeof(id));

	cout << "正在执行攻击修复..." << endl;

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void init(void){
	//设置终端窗口的大小
	//mode con cols=40 lines=15
	char cmd[128];

	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH ,HEIGHT );
	system(cmd);
}

int main(void){
	init();	 //初始化窗口
	login(); //实现登录功能.

	while(1){

		menuShow(); //实现显示菜单

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
			cout <<"无效输入,请重新输入."<<endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}