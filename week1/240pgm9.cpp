/***************************************************************
CSCI 240         Program 9    Spring 2024

Name: Jamari Haskins
Section:1

Due Date: 4 / 26/ 2024

Purpose:For this assignment, build on the PiggyBank class by adding some additional methods and constructors.
***************************************************************/

#include <iostream>
#include<iomanip>

using namespace std;

class PiggyBank 
{
private:
    int numPennies;
    int numNickels;
    int numDimes;
    int numQuarters;

public:
   
    // Constructors 

    PiggyBank() : numPennies(0), numNickels(0), numDimes(0), numQuarters(0) {}

    PiggyBank(int pennies, int nickels, int dimes, int quarters) 
	{
        emptyTheBank();
        addCoins(pennies, nickels, dimes, quarters);
    }

    PiggyBank(const PiggyBank &otherBank) 
	{
        numPennies = otherBank.numPennies;
        
        numNickels = otherBank.numNickels;
        
        numDimes = otherBank.numDimes;
        
        numQuarters = otherBank.numQuarters;
    }

    // Methods

    void print(string label)
	 const
	 {
        cout << label << endl;
        
        printBank();
        
        cout << "$" << fixed << setprecision(2) << calcBankValue() << endl;
    }

    void addCoins(int morePennies, int moreNickels, int moreDimes, int moreQuarters) 
	{
        addPennies(morePennies);
        
        addNickels(moreNickels);
        
        addDimes(moreDimes);
        
        addQuarters(moreQuarters);
    }

    PiggyBank addBanks(const PiggyBank &otherBank) 
	const
	
	{
        PiggyBank newBank(*this);
        
        newBank.addCoins(otherBank.numPennies, otherBank.numNickels, otherBank.numDimes, otherBank.numQuarters);
        
        return newBank;
    }

    bool isEqual(const PiggyBank &otherBank)
	 const 
	{
        return numPennies == otherBank.numPennies and numNickels == otherBank.numNickels and
        
               numDimes == otherBank.numDimes and numQuarters == otherBank.numQuarters;
    }

    bool isLessThan(const PiggyBank &otherBank) 
	const 
	{
        return calcBankValue() < otherBank.calcBankValue();
    }

    int getCoin(int coinIndex) 
	const 
	{
        switch (coinIndex) 
		{
            case 0:
                return numPennies;
            case 1:
                return numNickels;
            case 2:
                return numDimes;
            case 3:
                return numQuarters;
            default:
                return -1;
        }
    }
/////////


private:
    double calcBankValue() 
	const 
	{
        return numPennies * 0.01 + numNickels * 0.05 + numDimes * 0.1 + numQuarters * 0.25;
    }

    void addPennies(int morePennies) 
	{
        if (morePennies >= 0)
        
            numPennies += morePennies;
        else
            cout << "*** Error: cannot add a negative number of pennies ***" << endl;
    }

    void addNickels(int moreNickels) 
	{
        if (moreNickels >= 0)
        
            numNickels += moreNickels;
        else
            cout << "*** Error: cannot add a negative number of nickels ***" << endl;
    }

    void addDimes(int moreDimes) 
    {
	
        if (moreDimes >= 0)
        
        numDimes += moreDimes;
        else
            cout << "*** Error: cannot add a negative number of dimes ***" << endl;
    }

    void addQuarters(int moreQuarters) 
	{
        if (moreQuarters >= 0)
        
        numQuarters += moreQuarters;
            
        else
            cout << "*** Error: cannot add a negative number of quarters ***" << endl;
    }

    void emptyTheBank() 
	{
        numPennies = 0;
        numNickels = 0;
        numDimes = 0;
        numQuarters = 0;
    }

    void printBank() 
	const 
	{
        cout << "Pennies " << numPennies << " Nickels " << numNickels << " Dimes " << numDimes << " Quarters " << numQuarters << endl;
    }
};
///////////////// 


void printSectionTitle(string title) 
{
    cout << "---------------------------------------------------------------" << endl;
    cout << title << endl;
}

int main() 
{
    PiggyBank bank1(12, 34, 56, 78);
    
    PiggyBank bank2(23, 0, 0, 31);
    
    PiggyBank bank3 = bank1;
    
 	///
 	
    printSectionTitle("Initial values in the bank objects");
    cout << endl;
    
    bank1.print("bank1 object") ;
    cout << endl;
    
    bank2.print("bank2 object");
    cout << endl;
    
    bank3.print("bank3 object");
	cout << endl << endl;
	
    printSectionTitle("Using the addBanks method with 4 arguments");
    cout << endl;
    
    PiggyBank bank4;
    cout << endl;
    
    bank4.print("initial bank4 value");
    cout << endl;
    
    bank4 = bank2.addBanks(bank1);
    cout << endl;
    
	bank2.print("bank2 values after using addBanks method");
    cout << endl;
    
    bank4.print("bank4 values after using addBanks method");
	cout << endl << endl;
	
    printSectionTitle("Using the addBanks method with PiggyBank object");

	cout << endl;
    
    PiggyBank bank5;
    cout << endl;
    
    bank5.print("initial bank5 value");
    cout << endl;
    
    bank1.print("bank1 values before using addBanks method");
    cout << endl;
    
    bank5 = bank1.addBanks(bank2);
    cout << endl;
    
    bank1.print("bank1 values after using addBanks method");
    cout << endl;
    
    bank5.print("bank5 values after using addBanks method");
    cout << endl;
// if & else statement needed // 

    printSectionTitle("Using the isEqual method with 4 arguments");
    
    if (bank1.isEqual(bank2))
    
        cout << "Test 1: banks are equal" << endl;
    else
        cout << "Test 1: banks are not equal" << endl;

///////

    if (bank4.isEqual(bank2))
        cout << "Test 2: banks are equal" << endl;
    else
        cout << "Test 2: banks are not equal" << endl;
//////

    printSectionTitle("Using the isEqual method with PiggyBank object");
    if (bank1.isEqual(bank3))
        cout << "Test 3: banks are equal" << endl;
    else
        cout << "Test 3: banks are not equal" << endl;

///////

    if (bank1.isEqual(bank4))
        cout << "Test 4: banks are equal" << endl;
    else
        cout << "Test 4: banks are not equal" << endl;

///////

    printSectionTitle("Current values in the bank objects");
    cout << endl;
    
    bank1.print("bank1 object");
    cout << endl;
    
    bank2.print("bank2 object");
    cout << endl;
    
    bank3.print("bank3 object");
    cout << endl;
    
    bank4.print("bank4 object");
    cout << endl;
    
    bank5.print("bank5 object");
	cout << endl;
	////////////
	
    printSectionTitle("Using the isLessThan method with PiggyBank object");
    
    if (bank1.isLessThan(bank2))
        cout << "Test 5: bank1 is less than bank2" << endl;
    else
        cout << "Test 5: bank1 is not less than bank2" << endl;
	///////////
    if (bank2.isLessThan(bank4))
        cout << "Test 6: bank2 is less than bank4" << endl;
    else
        cout << "Test 6: bank2 is not less than bank4" << endl;
////////////



    printSectionTitle("Using the getCoin method");
    for (int i = 0; i < 4; ++i) 
	{
        int coinValue = bank1.getCoin(i);
        
		if (coinValue != -1)
            cout << "bank1 contains " << coinValue << " of coin type " << i << endl;
        else
            cout << "getCoin returned -1 with invalid index" << endl;
    }

    return 0;
}
