// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if (!head) return NULL;
        if (m == n) return head;
        
        Node *prev_start = head, *start = head, *end = head;
        
        int start_point = m;
        
        if (m != 1)
            start = start->next;
        m -= 1;
        
        while(m > 1)
        {
            start = start->next;
            prev_start = prev_start->next;
            m--;
        }

        while(--n) end = end->next;
        
        Node *prev = start, *curr = start, *st_next;
        
        curr = curr->next;
        
        prev->next = end->next;
        
        while(curr != end)
        {
            st_next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = st_next;
        }
        
        curr->next = prev;
        
        if (start_point == 1)
            head = curr;
        else
            prev_start->next = curr;
            
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends