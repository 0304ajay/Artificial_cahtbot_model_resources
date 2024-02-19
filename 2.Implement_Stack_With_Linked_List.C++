//link -https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack{
    Node *head=NULL;
public:
    int count=0;
    Stack()
    {
        //Write your code here
    }
    int getSize()
    {
        return count;
    }
    
    bool isEmpty()
    {
    if(head==NULL)
        {
            return 1;
        }
        return 0;
    }

    void push(int data)
    {
            Node *temp=new Node;
            temp->data=data;
            temp->next=head;
            head=temp;
            count++;
    }

    void pop()
    {
        if(head!=NULL)
        {
        Node *temp=head;
        head=head->next;
        count--;
        delete temp;
        }
    }

    int getTop()
    {
        if(head!=NULL)
        {
            return head->data;
        }
        else{
            return -1;
        }
    }
};

