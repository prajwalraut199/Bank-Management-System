  #include<iostream>

#include<conio.h>

#include<windows.h>

using namespace std;

class Bank{

	private: 

	    int total_;

	    string id;

	    struct user{

	    	string name,ID,address;

	    	int contact,cash;

		}user[100];

	public:

		Bank(){

			total_=0;

		}

		void choice();

		void perData();

		void show();

		void update();

		void search();

		void transactions();

		void del();

};

int main(){

	Bank b;

	b.choice();

	return 0;

}

void Bank::choice(){

	char ch;

	while(1){

	cout<<"\n\nPRESS..!!"<<endl;

	cout<<"1. Create new account"<<endl;

	cout<<"2. View customers list"<<endl;

	cout<<"3. Update information of existing account"<<endl;

	cout<<"4. Check the details of an existing account"<<endl;

	cout<<"5. For transactions"<<endl;

	cout<<"6. Remove existing account"<<endl;

	cout<<"7. Exit"<<endl;

	ch=getch();

	system("CLS");

	switch(ch){

		case '1':

			Bank::perData();

			break;

		case '2':

			if(total_==0){

				cout<<"No data is entered"<<endl;

			}else{

			Bank::show();

		   }

			break;

		case '3':

			if(total_==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::update();

			break;

		case '4':

			if(total_==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::search();

			break;

		case '5':

			if(total_==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::transactions();

			break;

		case '6':

			if(total_==0)

			cout<<"No data is entered"<<endl;

			else

			Bank::del();

			break;

		case '7':

			exit(0);

			break;

		default:

			cout<<"Invalid input"<<endl;

			break;

	}

    }

}

void Bank::perData(){

	cout<<"Enter data of user "<<total_+1<<endl;

	cout<<"Enter name: ";

	cin>>user[total_].name;

	cout<<"ID: ";

	cin>>user[total_].ID;

	cout<<"Address: ";

	cin>>user[total_].address;

	cout<<"Contact: ";

	cin>>user[total_].contact;

	cout<<"total_ Cash: ";

	cin>>user[total_].cash;

	total_++;

}

void Bank::show(){

	for(int i=0;i<total_;i++){

		cout<<"Data of user "<<i+1<<endl;

		cout<<"Name: "<<user[i].name<<endl;

		cout<<"ID: "<<user[i].ID<<endl;

		cout<<"Address: "<<user[i].address<<endl;

		cout<<"Contact: "<<user[i].contact<<endl;

		cout<<"Cash: "<<user[i].cash<<endl;

	}

}

void Bank::update(){

	cout<<"Enter id of student those data you want to update"<<endl;

	cin>>id;

	for(int i=0;i<total_;i++){

		if(id==user[i].ID){

		cout<<"Previous data"<<endl;

		cout<<"Data of user "<<i+1<<endl;

		cout<<"Name: "<<user[i].name<<endl;

		cout<<"ID: "<<user[i].ID<<endl;

		cout<<"Address: "<<user[i].address<<endl;

		cout<<"Contact: "<<user[i].contact<<endl;

		cout<<"Cash: "<<user[i].cash<<endl;

		cout<<"\nEnter new data"<<endl;

		cout<<"Enter name: ";

	cin>>user[i].name;

	cout<<"ID: ";

	cin>>user[i].ID;

	cout<<"Address: ";

	cin>>user[i].address;

	cout<<"Contact: ";

	cin>>user[i].contact;

	cout<<"total_ Cash: ";

	cin>>user[i].cash;

	break;

		}

		if(i==total_-1){

			cout<<"No such record found"<<endl;

		}

	}

}

void Bank::search(){

cout<<"Enter id of student those data you want to search"<<endl;

cin>>id;

for(int i=0;i<total_;i++){

	if(id==user[i].ID){

		cout<<"Name: "<<user[i].name<<endl;

		cout<<"ID: "<<user[i].ID<<endl;

		cout<<"Address: "<<user[i].address<<endl;

		cout<<"Contact: "<<user[i].contact<<endl;

		cout<<"Cash: "<<user[i].cash<<endl;

		break;

	}

	if(i==total_-1){

		cout<<"No such record found"<<endl;

	}

}

}

void Bank::transactions(){

	int cash;

	char ch;

	cout<<"Enter id of student those data you want to transaction"<<endl;

     cin>>id;

     for(int i=0;i<total_;i++){

     	if(id==user[i].ID){

     		cout<<"Name: "<<user[i].name<<endl;

     	     cout<<"Address: "<<user[i].address<<endl;

		     cout<<"Contact: "<<user[i].contact<<endl;

		     cout<<"\nExisting Cash "<<user[i].cash<<endl;

		     cout<<"Press 1 to deposit"<<endl;

		     cout<<"Press 2 to withdraw"<<endl;

		     ch=getch();

		     switch(ch){

		     	case '1':

		     		cout<<"How much cash you want to deposit??"<<endl;

		     		cin>>cash;

		     		user[i].cash+=cash;

		     		cout<<"Your new cash is "<<user[i].cash<<endl;

		     		break;

		     	case '2':

		     		back:

		     		cout<<"How much cash you want to withdraw??"<<endl;

		     		cin>>cash;

		     		if(cash>user[i].cash){

		     			cout<<"Your existing cash is just "<<user[i].cash<<endl;

		     			Sleep(3000);

		     			goto back;

					 }

					 user[i].cash-=cash;

					 cout<<"Your new cash is "<<user[i].cash<<endl;

					 break;

				default:

					cout<<"Invalid input"<<endl;

					break;

			 }

			 break;

		 }

		 if(i==total_-1){

		 	cout<<"No such record found"<<endl;

		 }

	 }

}

void Bank::del(){

	char ch;

	cout<<"Press 1 to remove specific record"<<endl;

	cout<<"Press 2 to remove full record"<<endl;

	ch=getch();

	switch(ch){

		case '1':

	cout<<"Enter id of student those data you want to remove"<<endl;

     cin>>id;

     for(int i=0;i<total_;i++){

     	if(id==user[i].ID){

     		for(int j=i;j<total_;j++){

     		user[j].name=user[j+1].name;

     		user[j].ID=user[j+1].ID;

     		user[j].address=user[j+1].address;

     		user[j].contact=user[j+1].contact;

     		user[j].cash=user[j+1].cash;

     		total_--;

     		cout<<"Your required data is deleted"<<endl;

     		break;

			 }

		 }

		 if(i=total_-1){

		cout<<"No such record found"<<endl;

		 }

	 }

	 break;

	 case '2':

	 	total_=0;

	 	cout<<"All record is deleted"<<endl;

	 	break;

	default:

		cout<<"Invalid Input"<<endl;

		break;

	}

}