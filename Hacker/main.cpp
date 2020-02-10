#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

int main(void){
	string name;
	string pwd;

	while(1){
		cout << "ÇëÊäÈëÕËºÅ:";
		cin >> name;
		cout << "ÇëÊäÈëÃÜÂë";
		cin >> pwd;

		if(name == "123qw" && pwd == "123456"){		
			break;
		}else{
			cout <<"ÓÃ»§Ãû»òÃÜÂë´íÎó"<< endl;
		}
	}

	cout<<"1.ÍøÕ¾404¹¥»÷"<<endl;
	cout<<"2.ÍøÕ¾´Û¸Ä¹¥»÷"<<endl;
	cout<<"3.ÍøÕ¾¹¥»÷¼ÇÂ¼"<<endl;
	cout<<"4.DNS¹¥»÷"<<endl;
	cout<<"5.·þÎñÆ÷ÖØÆô¹¥»÷"<<endl;

	system("pause");

	return 0;
}