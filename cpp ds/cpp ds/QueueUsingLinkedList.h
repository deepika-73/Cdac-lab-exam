#pragma once
#include<iostream>
#include<string>

using namespace std;
class Node
{
private:
	string data;
	Node* next; //pointer to next node
	

public:
	Node();
	~Node();
	//friend class,so that it can access private and protected members of Node class
	friend class QueueUsingLinkedList; 
};


class QueueUsingLinkedList
{
private:
	int size;
	//removal of existing element from front
	Node* front;
	//element is inserted from rear
	Node* rear;
public:
	QueueUsingLinkedList();
	QueueUsingLinkedList(int); //parameterised constrctor to initilize the size of linked list
	~QueueUsingLinkedList();
	bool isEmpty(); //to check if the queue is empty
	bool isFull(); // to check if queue is full
	void push(string e); //to insert the element in queue
	void pop(); //to pop the element from the queue
	void print(); //to print the list
	string frontElementOfQueue(); // get the element at front
	string rearElementOfQueue();	//get the element at rear

};

