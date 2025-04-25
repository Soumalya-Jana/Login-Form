#include<iostream>
#include<string>
#include<vector>
using namespace std;
class User{
	private:
		string username,password;
	public:
		User(string name,string pass){
			username = name;
			password = pass;
	}	
	string getUsername(){
		return username;
	}
	string getPassword(){
		return password;
	}
};
class UserManager{
	private:
		vector<User> users; //create object of vector
	public:
		void RegiserUser(){
			string username,password;
			cout<<"\t\tEnter User Name : ";
			getline(cin, username);
			cout<<"\t\tEnter Password : ";
			getline(cin, password);
			
			User newUser(username,password);
			users.push_back(newUser);
			
			cout<<"\t\t User Register Successfully ....."<<endl;		
		}
		bool LoginUser(string name,string pass){
			for(int i = 0; i<users.size();i++){
				if(users[i].getUsername()==name && users[i].getPassword() == pass){
					cout<<"\t\tLogin Successfully...."<<endl;
					return true;
					
				}
			}
			cout<<"\t\tInvalid User Name or Password..."<<endl;
			return false;			
		}
		void showUser(){
			cout<<"\t\t---Users List---"<<endl;
			for(int i = 0; i<users.size(); i++){
				cout<<"\t\t"<<users[i].getUsername()<<endl;
			}
		}
		void searchUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername() == username){
					cout<<"\t\t User Found"<<endl;
				}
			}
		}
		void deleteUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername()==username){
					users.erase(users.begin() + i);
					cout<<"\t\tUser Remove Successfully...."<<endl;
				}
			}
		}
	
};
main(){
	UserManager usermanage;
	
	int op;
	char choice;
	do{
		system("cls");
		cout<<"\n\n\t\t1. Register User "<<endl;
		cout<<"\t\t2. Login "<<endl;
		cout<<"\t\t3. Show User List "<<endl;
		cout<<"\t\t4. Search User "<<endl;
		cout<<"\t\t5. Delete User"<<endl;
		cout<<"\t\t6. Exit"<<endl;
		cout<<"\t\tEnter Your Choice : ";
		cin>>op;
		cin.ignore();
	switch(op){
		case 1:{
			usermanage.RegiserUser();
			break;
			
		}
		case 2:{
			string username,password;
			cout<<"\t\tEnter User :";
			getline(cin, username);
			cout<<"\t\tEnter Password :";
			getline(cin, password);
			usermanage.LoginUser(username,password);
			break;
		}
		case 3:{
			usermanage.showUser();
			break;
		}	
		case 4:{
			string username;
			cout<<"\t\tEnter User Name :";
			getline(cin, username);
			usermanage.searchUser(username);
			break;
		}
		case 5:{
			string username;
			cout<<"\t\tEnter User Name :";
			getline(cin, username);
			usermanage.deleteUser(username);
			break;
		}
		case 6:
			exit(1);
	}	
	cout<<"\t\tDo You Want to Continue [Yes/ No] ? :";
	cin>>choice;	
   }while(choice == 'y' ||choice == 'Y');
}
