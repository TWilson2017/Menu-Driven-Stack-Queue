#include <iostream>
using namespace std;
#include "ReadDataStack.h"
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <string>

//-|---------------------------------
//-|Read Data from File into a Stack
//-|---------------------------------
void ReadDataStack:: ReadInData()
{
	//Declare Variables
	ifstream inF;      //Variable for Reading in a File
	char inFName[80];  //Variable for Reading in a File Name
	string Text = "";  //Variable to hold the word read from the file
        string temp = "";
	
	
	//Prompt for the Input File Name
	cout << "Enter FileName: ";
	cin >> inFName;
	
	//Open the File
	inF.open(inFName);
	
	//Test File For Error
	if(inF.fail())
	{
		cout << "FATAL ERROR: Can not open file " << "'" << inFName << "'" << endl;
        exit(1);
	}//if
	
    //Else, read in the Data into a variable, MAKE sure to not include numbers or punctuation marks
	else
	{						
		while(inF >> Text)
		{
			//Remove Numbers & Punctuation From Input
			string::iterator it = Text.begin();
                        while (it != Text.end())
			{
				 while(it != Text.end() && isdigit(*it) || it != Text.end() && ispunct(*it))
				 {
					 it = Text.erase(it);
				 }//while
				 if (it != Text.end())
					 ++it;
			}//while
			
			//Check For Empty String
			if(Text.empty() == true)
				continue;

			//Call The Push(Insert) Function 
			Push(Text);
			Text.clear();
		}//while
		
		//Close The File
		inF.close();
		//Call Print Function to Print the Elements in The Stack
		Print();
	}//else
}//ReadInData

//-|------------------------------------------
//-|Add A Word To The Head/Top Of The Stack
//-|------------------------------------------
void ReadDataStack:: Push(string Word2)
{
	StackNode *temp = NULL;
	temp = new StackNode(Word2,Top);
	Top = temp;
}//Push

//-|-----------------------------------------------------
//-|Return The First Element From The Top Of The Stack
//-|-----------------------------------------------------
string ReadDataStack:: Peek()
{
	//Check To Make Sure Stack Is Not Empty
	if(IsEmpty() == true)
		return " ";
	//Else, Return The Top Element
	else
		return Top->Word;
}//Peek

//-|---------------------------------------
//-|Determine if Stack Is Empty
//-|---------------------------------------
bool ReadDataStack:: IsEmpty()
{
	if(Top == NULL)
		return true;
	else
		return false;
}//IsEmpty
		
//-|-------------------------------------------
//-|Delete The First Element From The Stack
//-|-------------------------------------------
void ReadDataStack:: Pop()
{
	StackNode *temp = new StackNode();
	
	if(IsEmpty() == true)
		cout << "Stack is empty.\n";
	else
	{
		temp = Top;
		Top = Top->next;
		delete temp;
	}//else
}//Pop

//Print Stack Elements To a File
void ReadDataStack:: Print()
{
	//Declare Variable
	ofstream OutF;
	
	//Open Out File
	OutF.open("report_out.txt");
	
	//Test Out File For Error
	if(OutF.fail())
	{
           cout << endl << "FATAL ERROR: UNABLE TO OPEN FILE \"report_out.txt\". TERMINATING..."
                << endl << endl;
           exit (1);
	}//if
	
	else
	{
		while(IsEmpty() == false)
		{
			OutF << Peek() << endl;
			Pop();
		}//while
	}//else
	
	//Close The File
	OutF.close();
}//Print
