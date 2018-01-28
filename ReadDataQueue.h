#ifndef READDATAQUEUE_H
#define READDATAQUEUE_H


class ReadDataQueue
{
	public:
		//Read Data from File into a Queue
		void ReadInData();
		
		//Add A Word To The End Of The List
		void EnQueue(string Word2);

		//Determine if Queue Is Empty
		bool IsEmpty();
		
		//Remove & Return The First Element From The Queue
		string DeQueue();
		
		//Print Queue Elements To a File
		void Print();
	
	   //Destructor for Queue
		~ReadDataQueue()
		{
			QueueNode *temp = new QueueNode();
			while(Front != NULL)
			{
				temp = Front;
				Front = Front->next;
				delete temp;
			}//while
			Rear = NULL;
		}//Destructor
		
    private:
		struct QueueNode
		{
			string Word;
			QueueNode *next;
			QueueNode(){};
			QueueNode(string Word1, QueueNode *next1 = NULL)
			{
				Word = Word1;
				next = next1;
			}//StackNode 2nd Constructor
		};//struct QueueNode
		QueueNode *Front = NULL;
		QueueNode *Rear = NULL;
		int WordCounter;
};//ReadDataQueue Class
#endif