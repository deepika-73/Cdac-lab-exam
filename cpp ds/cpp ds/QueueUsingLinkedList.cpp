#include "QueueUsingLinkedList.h"

Node::Node():data(""),next(NULL) {
}
Node::~Node()
{}

QueueUsingLinkedList::QueueUsingLinkedList(): size(0),front(NULL),rear(NULL)
{
}

QueueUsingLinkedList::QueueUsingLinkedList(int s) 
{
    rear = NULL;
    front = NULL;
    size = s;
}

QueueUsingLinkedList::~QueueUsingLinkedList()
{
	delete(front);
	delete(rear);
}

//function to checck if queue is empty
bool  QueueUsingLinkedList::isEmpty()
{
    
    if (front == NULL)
        return true;
    
    else
        return false;

}


//function to checck if queue is full
bool QueueUsingLinkedList::isFull() 
{
    int count = 0;
    Node* temp = front;
    while (temp != NULL)
    {
        count++;                //to get the count of inserted nodes
        temp = temp->next;
    }

    if (count == size)          //if equal then queue is full
    {
        return true;
    }
    else
        return false;

}

//function of insert data in the queue
void  QueueUsingLinkedList::push(string e) 
{
    //checking if queue is full or not,if full return otherwise push
    if (isFull())
    {
        cout << "Queue already is Full !!" << endl;
        return;
    }

    //creating new node
    Node* newnode = new Node;
    newnode->data = e;
    newnode->next = NULL;

    //adding the first element in queue
    if (rear == NULL)
    {
        rear = newnode;
        front = newnode;  
    }
    else
    {
        //incrementing rear pointer then adding new node
        rear->next = newnode;
        rear = newnode;
        
    }
    cout << "Element added in the queue" << endl;

}

//function to delete the element from queue
void  QueueUsingLinkedList::pop()
{
    //if empty nothing to print
    if (isEmpty())
    {
        cout << "Queue is empty !!" << endl;
        return;
    }
    
 
    else
    {
        Node* temp = front;
        if (front == rear)    //if only one node is present assign front and rear to NULL
        {
            rear = NULL;
            front = NULL;
        }
        else
            front = front->next;
           
        cout << temp->data << " deleted from queue." << endl;
        delete (temp);
    }


}

//function get the element present at front 
string  QueueUsingLinkedList::frontElementOfQueue() 
{  
    if (isEmpty())
        return "Queue is empty";
    else
        return front->data;
        
}

//function get the element present at rear 
string  QueueUsingLinkedList::rearElementOfQueue()
{
    if (isEmpty())
        return "Queue is empty";
    else
        return rear->data;

}

//to print is list
void QueueUsingLinkedList::print()
{

    Node* temp = front;

    if (isEmpty())
    {
        cout << " Queue is empty !!" << endl;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

}

