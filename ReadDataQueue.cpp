#include <iostream>
using namespace std;
#include "ReadDataQueue.h"
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <string>

//-|---------------------------------------
//-|Read Data from File into a Queue
//-|---------------------------------------
void ReadDataQueue:: ReadInData()
{
	//Declare Variables
	ifstream inF;      //Variable for Reading in a File
	char inFName[80];  //Variable for Reading in a File Name
	string Text = "";  //Variable to hold the word read from the file
    string temp = "";
	WordCounter = 0;
	
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

			//Call The EnQueue(Insert) Function 
			EnQueue(Text);
			WordCounter++;
		}//while
		
		//Close The File
		inF.close();
		//Call Print Function to Print the Elements in The Queue
		Print();
	}//else
}//ReadInData

//-|-------------------------------------------
//-|Add A Word To The End Of The List
//-|-------------------------------------------
void ReadDataQueue:: EnQueue(string Word2)
{
	QueueNode *NewNode = NULL;
	NewNode = new QueueNode(Word2, NULL);
		
    // If queue is empty, then the new node is assigned to the front and rear 
    // of the QueueNode
	if(Front == NULL && Rear == NULL)
	{
		Front = Rear = NewNode;
		Rear->next = NULL;
	}//if
	//Else, add value to the end of the List & Change Rear
	else
	{
		Rear->next = NewNode;
		Rear = NewNode;
		Rear->next = NULL;
	}//else
}//EnQueue

//-|---------------------------------------
//-|Determine if Queue Is Empty
//-|---------------------------------------
bool ReadDataQueue:: IsEmpty()
{
	if(Front == NULL)
		return true;
	else
		return false;
}//IsEmpty
		
//-|-----------------------------------------------------
//-|Remove & Return The First Element From The Queue
//-|-----------------------------------------------------
string ReadDataQueue:: DeQueue()
{
	
	string Data = "";  //Hold Data of Front element
	QueueNode *temp = NULL;
	temp = new QueueNode();
	
	// If Queue is empty, return NULL
	if(IsEmpty() == true)
	{
		cout << "Queue is empty" << endl;
		return "";
	}//if	
	// If Front == Rear, then change Rear & Front to NULL
    if(Front == Rear)
	{
		Data = Front->Word;
		Front = Rear = NULL;
		temp = Front;
	}//if
	else
	{
		//Store previous front and move front one node ahead
		//Assign the Front Number to Data
		temp = Front;
		Data = Front->Word;
		Front = Front->next;
	}//else
	delete temp;
	return Data;
}//DeQueue

//-|---------------------------------------------
//-|Print Queue Elements To a File
//-|---------------------------------------------
void ReadDataQueue:: Print()
{
	//Declare Variables
	QueueNode* temp = new QueueNode();
	temp = Front;
	ofstream OutF;
	string tempWord = ""; //Hold Current Word
	int WordLen = 0;
	
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
		while(temp != NULL) 
		{
			tempWord = temp->Word;
			WordLen += tempWord.length();
			OutF << left << setw(45) << DeQueue();
			OutF << right << setw(45) << tempWord.length() << right << endl;
			temp = temp->next;
		}//while
		OutF << endl;
		OutF << "Average Word Length: " << WordLen << '/' << WordCounter << " = "
			 << (WordLen/WordCounter) << " Characters" << endl;
	}//else
	OutF.close();
}//Print