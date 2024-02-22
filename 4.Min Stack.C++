//link -https://www.codingninjas.com/studio/problems/min-stack_3843991
#include <bits/stdc++.h> 
// Implement class for minStack.
class Node {
public:
    int data;
    Node* next;
};

class minStack
{
	int minimum = INT_MAX;
    Node* head = NULL;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
		Node* temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
        if (minimum > temp->data) {
            minimum = temp->data;
        }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
		int x;
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            x = temp->data;
            delete temp;
			    // updating the minimum value based on the deleted element
        	Node *temp1 = head;
        	if (x == minimum) {
            minimum = INT_MAX;
            while (temp1) {
                if (temp1->data < minimum) {
                    minimum = temp1->data;
                }
                temp1 = temp1->next;
            }
		}
		return x;
		} 
		else
		{
			minimum = INT_MAX;
			return -1;
		}

		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if (head != NULL) {
            return head->data;
            }
        return -1;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(head!=NULL)
			{
			return minimum;
			}
			else{
				return -1;
			}
		}
};
