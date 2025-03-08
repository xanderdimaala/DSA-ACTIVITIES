#include <iostream>

using namespace std;


typedef struct Node{
    string songName;
    Node *link;
}Node;


Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

Node *insertAtEnd(string data, Node*head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode; 
        cout << " A new node been inserted at the end\n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while( temp->link !=NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end\n" <<endl;
    
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << " A new node has been inserted at the beginning\n" <<endl;
    
    return head;
}

string insertAfter( string after, string data, Node*head){
    Node *temp = new Node;
    temp = head;
    
    while (temp->songName.compare(after)!=0){
        if ( temp== NULL){
              return " No such song exist, please try again later.";
    }
    temp = temp->link;
    
}
    Node *newNode = createNode(data);
    newNode->link = newNode;
    temp->link = newNode;
    
    return "An new node has been added after " + after + "\n";
    
}


void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while (temp !=NULL){
        cout << temp->songName<< "->" <<endl;
        if (temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

string insertAfter(string after, string data, string *head){
    Node *temp  = new Node;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been added after" + after + "\n";
}
string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return "A node has been deleted at the end \n";
}
Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" <<endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    
    cout <<"A node has been delete from the beginning \n" <<endl;
    
    return head;
}
Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" <<endl;
        return NULL;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout <<"The Node" + givenNode + "has been deleted. \n" <<endl;
        return head;
    }
    
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;
    
    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" <<endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    
    temp->link = next->link;
    cout << "The Node" + givenNode + "has been deleted. \n" <<endl;
    return head;
}


int main(){
    Node *head = createNode("Sanctuary by Joji");
    
    head = insertAtEnd(" Sunday Morning by Maroon 5", head);
    head = insertAtEnd("Hanggang Kailan by Orange and Lemon", head);
    head = insertAtEnd("One hit Combo by Parokya ni Edgar", head);
    
    head = insertAtBeginning("Pure Imagination by by John Borleo", head);
    head = insertAtBeginning("Sinta by Rob Daniel", head);
    head = insertAtBeginning("orange soda by koteon", head);
    
    cout << insertAfter<<("Walang kapalit by Arthur Miguel", head);
    cout << insertAfter<<("Dalangin by Earl Justin", head);
    cout << insertAfter<<("Miss You by Juan Carlos", head);
    traverse(head);

    cout << deleteAtEnd(head);
    head = deleteFromBeginning(head;)
    head = deleteFromGivenNode("Hanggang Kailan by Orange and Lemon", head);
    traverse (head);

    return 0;
}