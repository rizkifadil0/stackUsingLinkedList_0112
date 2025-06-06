#include <iostream>
using namespace std;

//node class representing a single node in the linked list
class Node
{
    public:
        int data;
        Node *next;

        Node()
        {
            next = NULL;
        }
};

//stack class
class Stack
{
    private:
        Node *top; //pointer to the top node of the stack

    public:
        Stack()
        {
            top = NULL; //intialize the stack with a null top pointer
        }

    //Push operation: insert an element onto the top of the stack
    int push(int value)
        {
        Node *newNode = new Node(); //1. Allocate memory for the new Node
        newNode->data = value;      //2. assign value
        newNode->next = top;        //3. Set the next pointer of the new node to the current
        top = newNode;              //4. Update the top pointer to the new node
        cout << "Push Value: " << value << endl;
        return value;
        }
    //lsEmpty operation: Check if the stack is empty
    bool isEmpty()
    {
        return top == NULL; //Return true if the top pointer is null, indicating an empty stack
    }

    //pop operation: Remove the topmost element from the stack
    void pop()

    {
        Node *temp = top;//create a temporary pointer to the current to node
        if (isEmpty())
        {
            cout << "Stack id Empty." << endl;
            return;//if the stack is empty, print a messegfe and return
        }
        cout << "Popped Value: " << top->data << endl;
        top = temp->next; // Update the top pointer to the next node
        temp = nullptr; //free the memory of the popped node
    }

    //peek/top operation: retrive the value of the topmost element without removing it
    void peek()
    {
        if (isEmpty())
        {
            cout << "List is empty." << endl;
            return; // if the stack is empty, print a messege and return
        }
        else
        {
            Node *current = top;
            while (current != NULL)
            {
                cout << current->data << " " << endl;
                current =current->next;
            }
            cout << endl;
        }//return the value of the top node
    }
};

int main()
{
    Stack stack;

    int choice = 0;
    int value;

    while (choice != 4)
    {
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.peek\n";
        cout << "4.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    

        switch (choice)
        {
            case 1:
                cout << "Enter Value to push: ";
                cin >> value;
                stack.push(value);//push the entered value onto the stack
            
            case 2:
                stack.pop(); //pop the topmost element from stack
                break;
            case 3:
                stack.peek();
                break;
                
            case 4:
                cout << "Exiting program." <<endl;
                break;
            default:
                cout << "Invaliid choice. try again." << endl;
                break;
        }
    }
}

