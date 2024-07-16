#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;
//init function
void DisplayTableHeading();
//init line function
void DisplayOneLine(string title, string author, float rating, float price, int year);

//main function to open file, read it, and display information
int main() 
{
   
    ifstream myIn("library.dat"); //open file
	assert(myIn);//check errors

    DisplayTableHeading();//display heading

    //init variables
	int year;
	string title;
	string author;
	float rating;
	float price;
    int count = 0;

	// Write a while loop here to read information for one book at a time
    while (getline(myIn, title)){
        getline(myIn, author);
        myIn >> rating;
        myIn.ignore(100, '\n');//ignore the whitespace
        int day;
        int month;
        myIn >> day >> month >> year;//reads exactly hows its entered
        myIn.ignore(100, '\n');//skip rest of line after year
        myIn >> price;
        myIn.ignore(100, '\n');//ignore the whitespace
  
        // Once a record is read, it calls function "DisplayOneLine" to display the  information in the required format
        DisplayOneLine(title, author, rating, price, year);
        count++;// + book count

        };
    
	myIn.close(); //close file
    cout << "\n\tThere are a total of " << count << " books." << endl;//end statement

	return 0;
}

// Description: This function prints the heading of the output table of information
void DisplayTableHeading()
{
	cout << left;
	cout << fixed << showpoint << setprecision(2);
	cout << setw(25) << "TITLE" << setw(25) << "AUTHOR" << "\t"
		<< "RATING" << "\t" << "PRICE" << "\t" << "YEAR"<< endl << endl; 
	
}

// Description: This function prints one line of information for one book formatted
void DisplayOneLine(string title, string author, float rating, float price, int year)
{
	cout << setw(25) << title << setw(25) << author << "\t" << rating << "\t" 
	<< price << "\t" << year << endl;
	
}
