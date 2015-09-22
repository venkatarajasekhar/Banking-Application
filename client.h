#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <stdio.h>
using namespace std;
class client
{
public:
	client(); //Constructor
	~client(){} //Destructor
	//Setters
	void setChequing(double chequing);
		void setSavings(double saving);
		void setId(int cid);
		void setFirstName(string name);
		void setLastName(string name);
		void setCredLimit(double credL);
		void setPin(int PIN);
		void setFrozen(bool setit);
		void setPayInFull(bool set);
		void setInterest(double inter);
	//Getters
	double getSavings();		// return amount under savings account
	double getChequing();	// Return amount under chequing account
	int getId();					// Return user Id;
	string getFirstName();			// Return first name;
	string getLastName();			// Return last name;
	double getCredLimit();
	bool isFrozen();
	int getPin();
	int getSizeOfPurchases();
	void purchase(double ammount);
	double getPurchase(int i);
	double getAmmountOwing();
	double payDay();
	bool getPayInFull();
	double getInterest();
	double getAmmountOwed();
private:
	int id, pin;
	double chequingAcc, savingsAcc, cred, limit, interest;
	string name1, name2;
	bool frozen, payInFull;
	vector<double> purchases;
};

// The Customer class
namespace BankMenuGUI{
//Manager Menus and Functions
void managerMenu(vector<client>& clients);					 // Brings user to the manager screen
bool openAccount(vector<client>& clients, int accID, string firstName, string lastName);
bool deleteAccount(vector<client>& clients, int accID); //
void printManMenu(void);    //Prints manager menu

//Maintenance Menus and Functions
void maintenanceMenu(void);		 // Brings user to the maintenance screen
void toggleExecutionTraces(void);   // Sets execution traces from on --> off or from off --> on.
void setExecutionTraces(bool);   // Turns execution traces on or off depending on x. (true = on, false = off)
void writeToET(string &str);  // Writes str to the file execution_traces.txt 
void printExecutionTraces(void);
void clearExecutionTracesLog(void);
void saveExternals(Manager &manager, Mperson &maintain);

//Client Menus and Functions
void clientMenu(client& theClient, vector<client>& clients); //Brings user to the screen for clients
void printClientMenu(client& theClient, bool cheq, bool sav);// Prints the options available to the client
void purchaseMenu(client& theClient);
void savePurchases(vector<client>& clients);
void viewPurchases(client& theClient);
void saveVendor(client& theClient, double price);
void deposit(client& theClient);
void withdraw(client& theClient);
void withdrawChequing(client& theClient);
void withdrawSavings(client& theClient);
void transfer(client& theClient);
void transferChequing(client& theClient);
void transferSavings(client& theClient);
void chequing(client& theClient, bool cheq, bool sav);
void savings(client& theClient, bool sav, bool cheq);
void updateMonth(vector<client>& clients);
void payInFullMenu(client& theClient);
void writeFailedPayments(client& theClient);
//Helper functions
int getNumber();        // Retrieves an int value from the user
double getDouble();     // Retrieves a double value from the user
void saveClients(vector<client>& clients);					 // Writes client data to text file/ saves the changes
int getAccountIndex(vector<client>& clients, int targetAccNum, int low, int high);
bool compareAccountLastName(client &a, client &b);
bool compareAccountNums(client &a, client &b);
bool existsInDatabase(vector<client>& clients, int targetAccID);
void sortByAccountNumber(vector<client>& clients);
vector<client> sortByLastName(vector<client> clients);
bool penalty(client& theClient, double amount);
};
