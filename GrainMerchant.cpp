#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
class Bill
{
private:
	string username, password;
	string username1, password1;
	class customer
	{
		public:
		bool isMandi;
		string name, date, grainType, contact,city;
		int rstNo, hammali, kataCharges,  weight;
		float cash, kataFarak, price;
	};
	vector<customer> customerList;

public:
		int totalCashDistributed ;
		int totalHammaliCharges ;
		int totalKataCharges ;
	Bill()
	{
		 this->totalCashDistributed = 0;
		 this->totalHammaliCharges = 0;
		 this->totalKataCharges = 0;
	}
	void choice();
	void start();
	void signUp();
	void login();
	void Data();
	void show();
	void update();
	void search();
	void showTotalValues();
	void del();
};
int main()
{
	Bill b;
	b.start();
	b.signUp();
	b.login();
	return 0;
}
void Bill::start()
{
	char arr[] = {'B', 'I', 'L', 'L', ' ', 'G', 'E', 'N', 'E', 'R', 'A', 'T', 'I', 'N', 'G', ' ', 'S', 'Y', 'S', 'T', 'E', 'M'};
	cout << "\n\n\n\n\n\t\t\t";
	for (int i = 0; i < 24; i++)
	{
		cout << arr[i];
		Sleep(30);
	}
	Sleep(1000);
	system("CLS");
}
void Bill::signUp()
{
	cout << "\n\n\t\tBill Generating System" << endl;
	cout << "\n\t\t  SIGN UP" << endl;
	cout << "\t\tEnter Username: ";
	cin >> username;
	cout << "\t\tEnter Password: ";
	cin >> password;
	cout << "\t\tYour new id is creating please wait";
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(100);
	}
}
void Bill::login()
{
	system("CLS");
	cout << "\n\n\t\t LOGIN" << endl;
	cout << "\t\tEnter Username: ";
	cin >> username1;
	cout << "\t\tEnter Password: ";
	cin >> password1;
	if (username == username1 && password == password1)
	{
		system("CLS");
		choice();
	}
	else if (username != username1 && password == password1)
	{
		cout << "\t\t\aInvalid username please try again";
		Sleep(3000);
		login();
	}
	else if (username == username1 && password != password1)
	{
		cout << "\t\t\aInvalid password please try again";
		Sleep(3000);
		login();
	}
	else
	{
		cout << "\t\t\aInvalid username and password please try again";
		Sleep(3000);
		login();
	}
}
void Bill::choice()
{
	int ch;
	while (true)
	{
		cout << "\n\nPRESS..!!" << endl;
		cout << "1. Create new Bill" << endl;
		cout << "2. View customers list" << endl;
		cout << "3. Update information of existing Customer" << endl;
		cout << "4. Check the details of an existing Customer" << endl;
		cout << "5. For transactions" << endl;
		cout << "6. Remove existing Customer" << endl;
		cout << "7. Exit" << endl;
		cin >> ch;
		system("CLS");
		switch (ch)
		{
		case 1:
			Data();
			break;
		case 2:
			show();
			break;
		case 3:
			update();
			break;
		case 4:
			search();
			break;
		case 5:
			showTotalValues();
			break;
		case 6:
			del();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "\aInvalid input" << endl;
			break;
		}
	}
}
void Bill::Data()
{
	cout << "\nEnter data of Customer" << endl
		 << endl;
	customer newCustomer;
	cout << "Enter Date: ";
	cin >> newCustomer.date;
	cout << "Enter Name of Customer: ";
	cin >> newCustomer.name;
	cout << "Enter city of Customer: ";
	cin >> newCustomer.city;
	cout << "Enter RST_NO. : ";
	cin >> newCustomer.rstNo;
	cout << "Enter Contact: ";
	cin >> newCustomer.contact;
	cout << "Enter grainType: ";
	cin >> newCustomer.grainType;
	cout << "Enter Weight";
	cin >> newCustomer.weight;
	cout << "Enter Price";
	cin>>newCustomer.price;
	int mandiChoice;
	cout << "Is Mandi? (1 for Yes, 0 for No): ";
	cin >> mandiChoice;
	newCustomer.isMandi = (mandiChoice == 1);
	newCustomer.kataFarak = 0;
	newCustomer.hammali = 0;
	newCustomer.kataCharges = 0;
	if (!newCustomer.isMandi)
	{
		float temp = (newCustomer.weight / 100);
		newCustomer.kataFarak = temp * (0.5);
		newCustomer.weight -= newCustomer.kataFarak;
		cout << "Enter Kata Charges :" << endl;
		cin >> newCustomer.kataCharges;
		cout << "Enter Hammali Charges :" << endl;
		cin >> newCustomer.hammali;
		newCustomer.hammali = temp * (newCustomer.hammali);
	}
	totalKataCharges += newCustomer.kataCharges;
	totalHammaliCharges += newCustomer.hammali;
	newCustomer.cash = newCustomer.price * newCustomer.weight;
	newCustomer.cash -= newCustomer.hammali;
	newCustomer.cash -= newCustomer.kataCharges;
	customerList.push_back(newCustomer);
	totalCashDistributed += newCustomer.cash;
	cout<<"\n\nYour Final Amount is : "<<newCustomer.cash<<endl;
}
void Bill::show()
{
	if (customerList.size() == 0)
	{
		cout << "EMPTY RECORD..!!";
		return;
	}
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "\nData of Customer " << i + 1 << endl;
		cout << "Date : " << customerList[i].date<<endl;
		cout << "name : " << customerList[i].name<<endl;
		cout << "city : " << customerList[i].city<<endl;
		cout << "contact :" << customerList[i].contact<<endl;
		cout << "rstNo : " << customerList[i].rstNo<<endl;
		cout << "grainType : " << customerList[i].grainType<<endl;
		cout << "isMandi :" << customerList[i].isMandi<<endl;
		cout << "weight : " << customerList[i].weight<<endl;
		cout << "price : " << customerList[i].price<<endl;
		cout << "hammali : " << customerList[i].hammali<<endl;
		cout << "kataCharges : " << customerList[i].kataCharges<<endl;
		cout << "cash : " << customerList[i].cash<<endl;
	}
}
void Bill::update()
{
	if (customerList.size() == 0)
	{
		cout << "EMPTY RECORD..!!";
		return;
	}
	int input;
	cout << "\nEnter RstNO. of Customer whose data you want to update " << endl;
	cin >> input;
	for (int i = 0; i < customerList.size(); i++)
	{
		if (customerList[i].rstNo == input)
		{
			cout << "Date : ";
			cin >> customerList[i].date;
			cout << "name : ";
			cin >> customerList[i].name;
			cout << "city : ";
			cin >> customerList[i].city;
			cout << "contact :";
			cin >> customerList[i].contact;
			cout << "rstNo : ";
			cin >> customerList[i].rstNo;
			cout << "grainType : ";
			cin >> customerList[i].grainType;
			cout << "isMandi :";
			cin >> customerList[i].isMandi;
			cout << "weight : ";
			cin >> customerList[i].weight;
			cout << "price : ";
			cin >> customerList[i].price;
			cout << "hammali : ";
			cin >> customerList[i].hammali;
			cout << "kataCharges : ";
			cin >> customerList[i].kataCharges;
			customerList[i].cash = customerList[i].price * customerList[i].weight;
			customerList[i].cash -= customerList[i].hammali;
			customerList[i].cash -= customerList[i].kataCharges;
			cout << "Your updated Data of customer is : " << endl
				 << endl;
			cout << "rstNo : " << customerList[i].rstNo<<endl;
			cout << "Date : " << customerList[i].date<<endl;
			cout << "name : " << customerList[i].name<<endl;
			cout << "city : " << customerList[i].city<<endl;
			cout << "contact :" << customerList[i].contact<<endl;
			cout << "grainType : " << customerList[i].grainType<<endl;
			cout << "isMandi :" << customerList[i].isMandi<<endl;
			cout << "weight : " << customerList[i].weight<<endl;
			cout << "price : " << customerList[i].price<<endl;
			cout << "hammali : " << customerList[i].hammali<<endl;
			cout << "kataCharges : " << customerList[i].kataCharges<<endl;
			cout << "cash : " << customerList[i].cash<<endl;
			break;
		}
		if (i == customerList.size() - 1)
		{
			cout << "NO SUCH RECORD FOUND " << endl;
		}
	}
}
void Bill::search()
{
	if (customerList.size() == 0)
	{
		cout << "EMPTY RECORD..!!";
		return;
	}
	int input;
	cout << "\nEnter RstNO. of Customer whose data you want to search " << endl;
	cin >> input;
	for (int i = 0; i < customerList.size(); i++)
	{
		if (customerList[i].rstNo == input)
		{
			cout << "rstNo : " << customerList[i].rstNo<<endl;
			cout << "Date : " << customerList[i].date<<endl;
			cout << "name : " << customerList[i].name<<endl;
			cout << "city : " << customerList[i].city<<endl;
			cout << "contact :" << customerList[i].contact<<endl;
			cout << "grainType : " << customerList[i].grainType<<endl;
			cout << "isMandi :" << customerList[i].isMandi<<endl;
			cout << "weight : " << customerList[i].weight<<endl;
			cout << "price : " << customerList[i].price<<endl;
			cout << "hammali : " << customerList[i].hammali<<endl;
			cout << "kataCharges : " << customerList[i].kataCharges<<endl;
			cout << "cash : " << customerList[i].cash<<endl;
			break;
		}
		if (i == customerList.size() - 1)
		{
			cout << "NO SUCH RECORD FOUND " << endl;
		}
	}
}
void Bill ::showTotalValues()
{
	int Labour = 0, KataAmount = 0, CashDistributed = 0;
	int input;
	string type;
	cout << "Press 1 if you want to see grain type specific totals " << endl;
	cout << "Press 2 if you want to see overall totals " << endl;
	cin >> input;
	switch (input){
	case 2:
		cout << "Total labour Charges : " << totalHammaliCharges << endl;
		cout << " Total Kata Charges : " << totalKataCharges << endl;
		cout << "Total Cash Distributed : " << totalCashDistributed << endl;
		break;
	case 1:
	cout << "Enter grain Type " << endl;
	cin >> type;
	for (int i = 0; i < customerList.size(); i++)
	{
		if (customerList[i].grainType == type)
		{
			Labour += customerList[i].hammali;
			KataAmount += customerList[i].kataCharges;
			CashDistributed += customerList[i].cash;
		}
	}
	cout << "Total labour Charges : " << Labour << endl;
	cout << " Total Kata Charges : " << KataAmount << endl;
	cout << "Total Cash Distributed : " << CashDistributed << endl;
	break;
	default:
	cout << "INVALID INPUT";
	}
}
void Bill::del()
{
	if (customerList.size() == 0)
	{
		cout << "EMPTY RECORD..!!" << endl;
		return;
	}
	int ch;
	cout << "Press 1 to remove specific record" << endl;
	cout << "Press 2 to remove full record" << endl;
	cin >> ch;
	if (ch == '1')
	{
		cout << "Enter Rst No. of person which you want to remove" << endl;
		cin >> ch;
		for (int i = 0; i < customerList.size(); i++)
		{
			if (ch == customerList[i].rstNo)
			{
				customerList.erase(customerList.begin() + i);
				cout << "Your Record has been deleted" << endl;
				break;
			}
			if (i == customerList.size() - 1)
			{
				cout << "No such record found" << endl;
			}
		}
	}
	else if (ch == '2')
	{
		customerList.clear();
		cout << "All record is deleted" << endl;
	}
	else
	{
		cout << "\aInvalid Input" << endl;
	}
}
