// M.Hamza Shahzad
// 20i-0796
// Os Assignmnet 2




#include<iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class QNode {
	public:
    int data;
    QNode* next;

    QNode()
    {
      
        next = NULL;
    }
};
 
class Queue1 {
	public:
    QNode *front, *rear;
    Queue1() { front = rear = NULL; }
 
    void enQueue(int x)
    {
 
        // Create a new LL node
        QNode* temp = new QNode;
 
        
        if (rear == NULL) {
            front = rear = temp;
            front->data=x;
            rear->data=x;
            return;
        }
 
        
        rear->next = temp;
        rear = temp;
        rear->data=x;
    }
 
    
    void deQueue()
    {
     
        if (front == NULL)
            return;
 
        
        QNode* temp = front;
        front = front->next;
 
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }
    void display()
    {
    	ofstream writer("CPU.txt", ios::app);
    	if (!writer)
	{
    		cout << "There was an error opening file for output" << endl;	
    	}
    	QNode* temp= front;
    	cout << "FCFS queue 1 Burst times: " << endl;
    	writer<<"FCFS QUEUE 1" << endl;
    	while(temp!= rear)
    	{
    		cout << temp->data << " - ";
    		writer<< temp->data << endl;
    		temp=temp->next;
    	}
    	cout << rear->data << endl;
    	writer<< rear->data<< endl;
	writer.close();
    	
    }
    
    void fcfs()
    {
    	int time_slice=3;
    	QNode* temp = new QNode;
    	temp=front;
    	while(temp != rear)
    	{
    		if(temp->data < 3)
    		{
    			temp->data=0;
    			temp=temp->next;
    		}
    		else
    		{
    			temp->data= temp->data- time_slice;
    			temp=temp->next;
    		}
    	}
    	rear->data=rear->data-time_slice;
    	
    }
    
    
    void sort()
    {
    	if(front== NULL)
	{
		return;
	}
	else
	{
		QNode *i,*j;
		i=front;
		int swap;
		for(i=front; i->next != NULL; i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->data < j->data)
				{
					swap=i->data;
					i->data=j->data;
					j->data= swap;
				}
			}
		}	
	
	
	
	}
    }
    
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Queue2 {
	public:
    QNode *front, *rear;
    Queue2() { front = rear = NULL; }
 
    void enQueue(int x)
    {
 
        // Create a new LL node
        QNode* temp = new QNode;
 
        
        if (rear == NULL) {
            front = rear = temp;
            front->data=x;
            rear->data=x;
            return;
        }
 
        
        rear->next = temp;
        rear = temp;
        rear->data=x;
    }
 
    
    void deQueue()
    {
     
        if (front == NULL)
            return;
 
        
        QNode* temp = front;
        front = front->next;
 
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }
    void display()
    {
    	ofstream writer("CPU.txt", ios::app);
    	if (!writer)
	{
    		cout << "There was an error opening file for output" << endl;	
    	}
    	QNode* temp= front;
    	cout << "FCFS queue 2 Burst times: " << endl;
    	writer<<"FCFS QUEUE 2" << endl;
    	while(temp!= rear)
    	{
    		cout << temp->data << " - ";
    		writer<< temp->data << endl;
    		temp=temp->next;
    	}
    	cout << rear->data << endl;
    	writer<< rear->data<< endl;
	writer.close();
    	
    }
    
    void fcfs()
    {
    	int time_slice=6;
    	QNode* temp = new QNode;
    	temp=front;
    	while(temp != rear)
    	{
    		if(temp->data < 6)
    		{
    			temp->data=0;
    			temp=temp->next;
    		}
    		else
    		{
    			temp->data= temp->data- time_slice;
    			temp=temp->next;
    		}
    	}
    	rear->data=rear->data-time_slice;
    	
    }
    
    
    void sort()
    {
    	if(front== NULL)
	{
		return;
	}
	else
	{
		QNode *i,*j;
		i=front;
		int swap;
		for(i=front; i->next != NULL; i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->data < j->data)
				{
					swap=i->data;
					i->data=j->data;
					j->data= swap;
				}
			}
		}	
	
	
	
	}
    }
    
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Queue3 {
	public:
    QNode *front, *rear;
    Queue3() { front = rear = NULL; }
 
    void enQueue(int x)
    {
 
        
        QNode* temp = new QNode;
 
        
        if (rear == NULL) {
            front = rear = temp;
            front->data=x;
            rear->data=x;
            return;
        }
 
        
        rear->next = temp;
        rear = temp;
        rear->data=x;
    }
 
    
    void deQueue()
    {
     
        if (front == NULL)
            return;
 
        
        QNode* temp = front;
        front = front->next;
 
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }
    void display()
    {
    	ofstream writer("CPU.txt", ios::app);
    	if (!writer)
	{
    		cout << "There was an error opening file for output" << endl;	
    	}
    	QNode* temp= front;
    	cout << "SJF queue 1 Burst times: " << endl;
    	writer<<"SJF QUEUE 3" << endl;
    	while(temp!= rear)
    	{
    		cout << temp->data << " - ";
    		writer<< temp->data << endl;
    		temp=temp->next;
    	}
    	cout << rear->data << endl;
    	writer<< rear->data<< endl;
	writer.close();
    	
    }
    
    void sdf()
    {
    	
    	QNode* temp = new QNode;
    	temp=front;
    	while(temp != rear)
    	{
    		temp->data=0;
    		temp=temp->next;
    		
    	}
    	rear->data=0;
    	
    }
    
    
    void sort()
    {
    	if(front== NULL)
	{
		return;
	}
	else
	{
		QNode *i,*j;
		i=front;
		int swap;
		for(i=front; i->next != NULL; i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->data < j->data)
				{
					swap=i->data;
					i->data=j->data;
					j->data= swap;
				}
			}
		}	
	
	
	
	}
    }
    
};





class node
{
	public:
	int data;
	int btime;
	string id;
	
	node *next;
	node *prev;
	
	
	node()
	{
		next=NULL;
		prev=NULL;
	}
	

};

class DoublyLinkedList
{
	public:
	node *head;
	
	
	
	DoublyLinkedList()
	{
		head=NULL;	
	}
	
	void insertNode(node* nodePtr,int d,string s,int b)
   	{

        	if(head==NULL)
       	{
            		head=nodePtr;
            		head->data=d;
            		head->btime=b;
            		head->id=s;
            		
        	}
        	else
        	{
            		node* current=head;
            
            		while(current->next!=NULL)
            		{
                		current=current->next;
            		}

        	    current->next=nodePtr;
        	    nodePtr->prev=current;
        	    nodePtr->data=d;
        	    nodePtr->btime=b;
        	    nodePtr->id=s;
            
        	}
    	}
    	
    	void sorting(int size)
	{
	
	if(head== NULL)
	{
		return;
	}
	else
	{
		node *i,*j;
		i=head;
		int swap;
		int swap1;
		string temp;
		for(i=head; i->next != NULL; i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->data > j->data)
				{
					swap=i->data;
					swap1=i->btime;
					temp=i->id;
					i->data=j->data;
					i->id=j->id;
					i->btime=j->btime;
					j->data= swap;
					j->id=temp;
					j->btime=swap1;
				}
			}
		}	
	
	
	
	}	
	}
	void display()
	{
		node* temp= new node;
		temp= head;
		while(temp!= NULL )
		{
			cout << temp->id << " : " <<temp->data << " : " << temp->btime << endl;
			temp= temp->next;
		}
	}
	

};


int main()
{
	// FILE READING
	string r;
	string c;
	fstream retreaves;
	retreaves.open("job.txt",ios::in); //open a file to perform read operation using file object
   	if (retreaves.is_open()) 
   	{   
      		
      		while(getline(retreaves, r))
      		{ //read data from file object and put it into string.
      			c=c+r;
      		}
        retreaves.close(); //close the file object.
       }
	else
	{
		cout << "Error!!! File not open" << endl;
	}
	   

	//Converting string into char array
		
 
	        int n = c.length();
    		//declaring character array
    		char process [n + 1];
 
    		// copying the contents of the string to char array
    		strcpy(process, c.c_str());
 		
 		string Sarr[10];
 		
 		int c1=0;
 		int w=0;
 		
 		
 		
 		
    		for (int i = 0; i < n; i++)
        	{
        		if(process[i] == 'p' || process[i] == 'P')
        		{
        			while(process[i] != ' ')
        				{
        					Sarr[c1]=Sarr[c1] + process[i];
        					i++;	
        				}
        				c1++;
        		}
        		
        	}
	
		
		string temp[10];
		int c2=0;
		for (int j = 0; j < n; j++)
        	{
        		if(process[j] == ' ' )
        		{
        			j++;
        			while(process[j] != 'p' && j < n)
        			{
        				temp[c2] = temp[c2]+ process[j];
        				j++;
        			}
        			c2++;
        		}
        		
        	}
		
		
		int arrival[10];
		for(int i =0; i<c2; i++)
		{
			arrival[i] = stoi(temp[i]);
		}
		int burstTime[10];
		
		/////////////////////////////////////////////////////////////////////////// CALCULATING BURST TIME
		string random;
		fstream bt;
		int pro0=0;
		
		
		bt.open("process0.txt",ios::in); //open a file to perform read operation using file object
   		if (bt.is_open()) 
   		{   
      		
      			while(getline(bt, random))
      			{ //read data from file object and put it into string.
      				pro0++;
      				
      			}
      		        bt.close(); //close the file object.
       	}
		else
		{
			cout << "Error!!! File not open" << endl;
		}
		
		burstTime[0]=pro0;
		pro0=0;
		
		string inst0[20];
		int counter0 =0;
		
		bt.open("process0.txt");
		while(!bt.eof())
  		{
   			 getline(bt,inst0[counter0],'\n');
   			 counter0++;
   		}	 
   		bt.close();
   		
		
		
		
		////
		bt.open("process1.txt",ios::in); //open a file to perform read operation using file object
   		if (bt.is_open()) 
   		{   
      		
      			while(getline(bt, random))
      			{ //read data from file object and put it into string.
      				pro0++;
      				
      			}
      		        bt.close(); //close the file object.
       	}
		else
		{
			cout << "Error!!! File not open" << endl;
		}
		
		burstTime[1]=pro0;
		pro0=0;
		string inst1[20];
		int counter1=0;
		
		
		bt.open("process1.txt");
		while(!bt.eof())
  		{
   			 getline(bt,inst1[counter1],'\n');
   			 counter1++;
   		}	 
   		bt.close();
   		
		
		bt.open("process2.txt",ios::in); //open a file to perform read operation using file object
   		if (bt.is_open()) 
   		{   
      		
      			while(getline(bt, random))
      			{ //read data from file object and put it into string.
      				pro0++;
      				
      			}
      		        bt.close(); //close the file object.
       	}
		else
		{
			cout << "Error!!! File not open" << endl;
		}
		
		burstTime[2]=pro0;
		pro0=0;
		
		string inst2[20];
		int counter2=0;
		
		bt.open("process2.txt");
		while(!bt.eof())
  		{
   			 getline(bt,inst2[counter2],'\n');
   			 counter2++;
   		}	 
   		bt.close();
   		
   		////////////////////////////////////////////    Doubly LInkedLIst main
		node n1;
		DoublyLinkedList a;
	
	
	
		for(int i=0; i< c1; i++)
		{
		
			node *newNode= new node;
			a.insertNode(newNode,arrival[i],Sarr[i],burstTime[i]);
			  
		}
		a.display();
		
		/////////////////////////////////////////////// FCFS QUEUE 1
		QNode f1;
		Queue1 q1;
		
		for(int i=0; i< c1; i++)
		{
			q1.enQueue(burstTime[i]);
		}
		q1.fcfs();
		q1.sort();
		q1.display();
		for(int i=0; i< c1; i++)
		{
			burstTime[i]=burstTime[i]-3;
		}
		
		
		/////////////////////////////////////////////// FCFS QUEUE 2
		QNode f2;
		Queue2 q11;
		
		for(int i=0; i< c1; i++)
		{
			q11.enQueue(burstTime[i]);
		}
		q11.fcfs();
		q11.sort();
		q11.display();
		for(int i=0; i< c1; i++)
		{
			burstTime[i]-6;
		}
		/////////////////////////////////////////////// SJF QUEUE
		QNode f3;
		Queue3 q111;
		
		for(int i=0; i< c1; i++)
		{
			q111.enQueue(burstTime[i]);
		}
		q111.sdf();
		q111.sort();
		q111.display();
		
		
		/////////////////////////////////////////////////
		
		string instructions;
		for(int i=0; i < counter0; i++)
		{
			instructions= instructions + inst0[i];
		}
		for(int i=0; i < counter1; i++)
		{
			instructions= instructions + inst1[i];
		}
		for(int i=0; i < counter2; i++)
		{
			instructions= instructions + inst2[i];
		}
		
		int N = instructions.length();
		char find[N + 1];
		strcpy(find, instructions.c_str());
		
 		char har[10]="DISK";
 		char net[10]="NETWORK";
 		char scr[10]="SCREEN";
		
		ofstream wr("Queue.txt", ios::app);
    		if (!wr)
		{
    			cout << "There was an error opening file for output" << endl;	
    		}
    		
		//For Hardisk Waiting Queueu
		for(int i=0;i < N-2; i++)
		{
			if(find[i]== 'D' && find[i+1]== 'I' && find[i+2]== 'S' && find[i+3]== 'K')
			{
				wr<<"Hard Disk Queue" << endl;
				wr << "Process 1" << endl;
				
			}
			if(find[i]== 'N' && find[i+1]== 'E' && find[i+2]== 'T' && find[i+3]== 'W' && find[i+4] == 'O' && find[i+5] == 'R' && find[i+6] == 'K')
			{
				wr<<"Network Queue" << endl;
				wr << "Process 1" << endl;
			}
			
			if(find[i]== 'S' && find[i+1]== 'C' && find[i+2]== 'R' && find[i+3]== 'E'&& find[i+4] == 'E' && find[i+5]== 'N')
			{
				if(i < 35)
				{
					wr<<"Device Queue" << endl;
					wr << "Process 0" << endl;
				}
				else
				{
					wr<<"Device Queue" << endl;
					wr << "Process 1" << endl;
				}
			}
			
		}
		
		
		
		
		wr.close();
		
	
	
	return 0; 
}
