#include<iostream>
using namespace std;

struct LLNode
{
	int data;
	LLNode *next;
    LLNode *child;
};
//this function will take head of level1 and will flatten the multilevel list
void flattenMultilevelLL(LLNode* head)
{
  LLNode* temp;
  if (head == NULL)
  {
    return;
  }

  LLNode* tail = head;
  //Finding the tail of the level1 list
  while(tail->next != NULL)
  {
      tail = tail->next;
  }
  LLNode* curr = head;
  //Traverse level1 list
  while(curr != NULL)
  {
      //If current node has child
      if (curr->child)
      {
        //Appending the child at the end of current list
        tail->next = curr->child;
        //Updating the tail to the new last node
        temp = curr->child;
        while(temp->next)
        {
          temp = temp->next;
        }
        tail = temp;
      }
   curr = curr->next;
  }
}

void insertAtBeginning(LLNode**head,int dataToBeInserted)
{
	LLNode*curr=new LLNode;
	//make a new node with this data and next pointing to NULL
	curr->data=dataToBeInserted;
	curr->next=NULL;

	if(*head==NULL) //if list is empty then set the current formed node as head of list
			*head=curr;

	else //make the next of the current node point to the present head and make the current node as the new head
		{
			curr->next=*head;
			*head=curr;
		}

		//O(1) constant time
}


void display(LLNode**head)
{
	LLNode*temp=*head;
	while(temp!=NULL) //till the list ends (NULL marks ending of list)
		{
			if(temp->next!=NULL)
			cout<<temp->data<<" ->";
			else
			cout<<temp->data;

			temp=temp->next; //move to next node
		}
		//O(number of nodes)
	cout<<endl;
}

int main()
{
	LLNode *result = NULL;
	LLNode *level1 = NULL; //initial list has no elements

	insertAtBeginning(&level1,5);
	insertAtBeginning(&level1,4);
  insertAtBeginning(&level1,8);
  insertAtBeginning(&level1,3);
  insertAtBeginning(&level1,1);
  insertAtBeginning(&level1,1);

  LLNode *level2 = NULL;
  insertAtBeginning(&level2,5);
  insertAtBeginning(&level2,2);
  insertAtBeginning(&level2,8);

  LLNode *level3 = NULL;
  insertAtBeginning(&level3,9);
  insertAtBeginning(&level3,7);
  insertAtBeginning(&level3,8);

  level1->child =level2;
  //cout<<level1->child->data;
  level2->next->child = level3;


	flattenMultilevelLL(level1);
	cout<<"Flattend List is"<<endl;
	display(&level1);
	return 0;
}
