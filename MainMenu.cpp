//------------------------------------------------------------------
// File name:   MainMenu.cpp
// Due Date:    1/30/2018 at 12:30 pm
//
// Purpose:     Write a C++ program to implement a Stack and a Queue.
//              The program will be menu driven.
// 
// Author:      Tishauna Wilson
//------------------------------------------------------------------

#include "ReadDataStack.cpp"
#include "ReadDataQueue.cpp"

//-|----------------------------------------------------------------
//-|Display The Main Menu Commands
//-|----------------------------------------------------------------
void ShowCommands()
{
	//Show The Commands
	cout << "Main Menu" << endl << endl 
		 << "1) Stack" << endl
		 << "2) Queue" << endl
		 << "3) Quit" << endl;
	    cout << endl;
}//ShowCommands

//-|----------------------------------------------------------------
//-|Perform The User Commands To Manipulate The Program
//-|----------------------------------------------------------------
void PerformCommand(int Command)
{
	//Declare Variables
    ReadDataStack DataS;  
    ReadDataQueue DataQ;
	
	switch(Command)
	{
		case 1: //Implement a Stack
			    cout << "Stack Option: 1" << endl << endl;
			    DataS.ReadInData();
			    break;
		case 2: //Implement a Queue
			     cout << "Queue Option: 2" << endl << endl;
			     DataQ.ReadInData();
			    break;
		case 3: //Quit the Program
			    cout << "Quit Option: 3" << endl << endl;
			    cout << "TERMINATING PROGRAM." << endl;
			    cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl;
			    exit(1);
			    break;
		default:break;	
	}//switch
}//PerformCommand

int main()
{
   //----------------------------------------------------------------------
   //  Declare variables
   //----------------------------------------------------------------------
   int Command = 0; 
   const int Quit = 3;    //Command Number For The Program To Quit
   bool isCommand = true;
   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 


   //-| ----------------------------------------------------------------------
   //-| 1. Show The Commands of the Menu and Choose Perform A Command
   //-| ----------------------------------------------------------------------
   ShowCommands();
    
   cout << "Enter Option: ";
   cin >> Command;
	
   do
   {
	   //Check For Commands That Are Out Of Boundaries
	   if((Command < 1) || (Command > 3))
	   {
		   cout << "Error <Re-Enter Valid Option>: ";
		   cin >> Command;
	   }//if
	  
	   //If Previous If Statements Are False, Proceed To Implement A Stack Or Queue
	   else
	   {
		   PerformCommand(Command);
	   }//else
	   
	   //Enter In Another Command
	   cout << endl;
	   cout << "Enter Option: ";
       cin >> Command;
   }while(isCommand == true);//do-while

   return 0;
}//main
