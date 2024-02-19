
//link -https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209
class Node
{
    public:
    int data;
    Node *next;
};
class Stack {
    Node *head=NULL;
    int count=0;
    int capacity=0;
public:
    
    Stack(int capacity) {
        this->capacity=capacity;
    }

    void push(int num) {
        if(count<capacity)
        {
            Node *temp=new Node;
            temp->data=num;
            temp->next=head;
            head=temp;
            count++;
        }        
    }

    int pop() {
        if(head!=NULL)
        {
            Node *temp=head;
            head=head->next;
            int x=temp->data;
            count--;
            delete temp;
            return x;
        }
        else
        {
            return  -1;
        }
    }
    
    int top() {
        if(head!=NULL)
        {
            return head->data;
        }
        else{
            return -1;
        }
    }
    
    int isEmpty() {
        if(head==NULL)
        {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(count==capacity)
        {
            return 1;
        }
            return 0;
    }
    
};
