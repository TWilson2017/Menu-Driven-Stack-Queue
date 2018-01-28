#ifndef READDATASTACK_H
#define READDATASTACK_H

class ReadDataStack
{
	public:
	
		//Read Data from File into a Stack
		void ReadInData();
		
		//Add A Word To The Head/Top Of The Stack
		void Push(string Word2);
		
		//Return The First Element From The Top Of The Stack
		string Peek();
		
		//Determine if Stack Is Empty
		bool IsEmpty();
		
		//Delete The First Element From The Stack
		void Pop();
		
		//Print Stack Elements To a File
		void Print();
	
	        //Destructor for Stack
		~ReadDataStack()
		{
		    StackNode *ptr;
                    for (ptr = Top; Top; ptr = Top)
                    {
                       Top = Top->next;
                       delete ptr;
                    }//for
		}//Destructor
		
    private:
		struct StackNode
		{
			string Word;
			StackNode *next;
			StackNode(){};
			StackNode(string Word1, StackNode *next1 = NULL)
			{
				Word = Word1;
				next = next1;
			}//StackNode 2nd Constructor
		};//struct StackNode
		StackNode *Top = NULL;
};//ReadData Class
#endif
