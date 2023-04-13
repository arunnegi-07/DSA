 #include<iostream>
 using namespace std;

 struct Node {
      int val;
      Node *next;
      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
      Node(int x, Node *next) : val(x), next(next) {}
  };
 typedef struct Node Node;
 
void print(Node *head){
    Node *ptr = head;
    while(ptr){
        cout << ptr -> val << " ";
        ptr = ptr -> next;
    }
}

void addNode(int val,Node* &tail){
     tail -> next = new Node(val);
     tail = tail -> next;
}

// TC : O(N)  SC : O(1)
void removeLoop(Node* &head)
{    
    // This Part will detect if cycle is present as well as sets the slow and fast pointer to desired positions.
    // detect the cycle using Floyd's cycle-finding algorithm
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    
    if(slow != fast) return; // means cycle not present

    // This part will remove the cycle
        // bring slow pointer to start while fast pointer will remain as it is 
        slow = head;
        
        // this check is needed when slow and fast both meet at the head of the LL
        // This if is to handle the case 2 mentioned in Intuition of this problem
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        // This else will handle all other cases
        else{
            while (slow -> next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            } 
        }
        // removing cycle
        fast->next = NULL;
}

int main(){
      // creating a List containing cycle
      Node *head = NULL, *tail = NULL;
      head = new Node(1);
      tail = head;
      addNode(2,tail);
      addNode(3,tail);
      addNode(4,tail);
      addNode(5,tail);
      addNode(6,tail);
      addNode(7,tail);
      addNode(8,tail);
      addNode(9,tail);
      tail -> next = head -> next -> next -> next -> next -> next;

      removeLoop(head);
      
      // print the linked list
      print(head);

      return 0;      
  }