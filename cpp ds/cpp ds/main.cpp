#include "QueueUsingLinkedList.h"
int main()
{

	int choice,size;
	bool exit = false;
	string input;

	do
	{
		cout << "Enter Size of the queue:";
		cin >> size;
		
	} while (size <= 0);

	QueueUsingLinkedList queue(size);

	while (!exit)
	{
		cout << "------------------------------"<<endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Print" << endl;
		cout << "4. Get Front element" << endl;
		cout << "5. Get Rear element" << endl;
		cout << "6. Queue is full?" << endl;
		cout << "7. Queue is empty?" << endl;
		cout << "8. Exit" << endl;
		cout << "------------------------------"<<endl;
		cout << "Enter Choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout <<"Enter String to insert"<<endl;
			cin >>input;
			queue.push(input);
			break;
		case 2:
			queue.pop();
			break;
		case 3:
			cout << "Elements in the queue" << endl;
			queue.print();
			break;
		case 4:
			cout << "Element at front is:" << queue.frontElementOfQueue()<<endl;
			break;
		case 5:
			cout<<"Element at rear is:"<< queue.rearElementOfQueue()<<endl;
			break;
		case 6:
			if (queue.isFull())
				cout << "Queue is full" << endl;
			else
				cout << "Queue is not full" << endl;
			break;
		case 7:
			if (queue.isEmpty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is not Empty" << endl;
			break;
		case 8:
			exit = true;
			break;
		default:
			cout << "Enter Valid choice!!"<<endl;
			break;
		}

	}









	/*QueueUsingLinkedList queue(3);
	queue.push("deepika");
	queue.push("deep");
	queue.push("sumeet");
	queue.push("sanket");

	queue.print();
	queue.pop();
	queue.print();
	cout << "Front:" << queue.frontElementOfQueue() << endl;
	cout << "Rear:" << queue.rearElementOfQueue() << endl;*/





	return 0;
}