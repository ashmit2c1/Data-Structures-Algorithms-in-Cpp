#include<bits/stdc++.h>
using namespace std;
// NODE CLASS FOR LINKED LIST
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// TRAVESING A LINKED LIST 
void traverse(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << "\n";
}
// INSERT AT HEAD 
void insertAtHead(Node*head,int val){
    if(head==nullptr){
        Node* newnode = new Node(val);
        head=newnode;
        return;
    }
    Node* newnode = new Node(val);
    newnode->next=head;
    head=newnode;
}
// INSERT AN ARRAY AT THE HEAD OF THE LINKED LIST 
void insertAtHead(Node*head,int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void insertArrayAtHead(Node* head,vector<int>arr){
    for(int i=0;i<arr.size();i++){
        int val=arr[i];
        insertAtHead(head,val);
    }
}
// INSERT NODE AT TAIL OF LINKED LIST 
void insertAtTail(Node*head,int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    Node*temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}
// INSERT ARRAY AT TAIL OF LINKED LIST ( approach 1 )
void insertAtTail(Node*head,int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertAtTail(Node*head,vector<int>arr){
    for(int i=0;i<arr.size();i++){
        int val = arr[i];
        insertAtTail(head,val);
    }
}
// INSERT ARRAY AT TAIL OF LINKED LIST ( approach 2 )
void insertAtTail(Node*head,vector<int>&arr){
    Node*tail=head;
    if(head==nullptr){
        head=new Node(arr[0]);
        tail=head;
    }
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    for(int i=1;i<arr.size();i++){
        Node* newnode = new Node(arr[i]);
        tail->next=newnode;
        tail=newnode;
    }
}
// INSERT AT THE KTH POSITION IN LINKED LIST 
void insertAtHead2(Node*&head,int val){
    Node* newnode= new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void insertAtK(Node* &head,int K,int val){
    int cp=0;
    if(K==0){
        insertAtHead2(head,val);
        return;
    }
    Node*temp=head;
    Node* newnode = new Node(val);
    while(cp!=K-1){
        temp=temp->next;
        cp++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
// UPDATING THE VALUE AT THE KTH POSITION IN LINKED LIST 
void updateAtK(Node *&head,int K,int val){
    int cp=0;
    Node*temp=head;
    while(cp!=K-1){
        temp=temp->next;
    }
    temp->data=val;
}
// DELETE A NODE AT THE HEAD OF LINKED LIST 
void deleteAtHead(Node*&head){
    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        delete(head);
        head=nullptr;
        return;
    }
    Node*temp=head;
    head=head->next;
    delete(temp);
}
// DELETE NODE AT TAIL OF LINKED LIST 
void deleteAtTail(Node* &head){
    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        delete(head);
        head=nullptr;
        return;
    }
    Node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node*del = temp->next;
    temp->next=nullptr;
    delete(del);
}
// DELETE THE KTH NODE IN LINKED LIST 
void deleteAtK(Node *&head,int K){
    if(K==0){
        deleteAtHead(head);
        return;
    }
    int cp=0;
    Node*temp=head;
    while(cp!=K-1){
        temp=temp->next;
        cp++;
    }
    Node* del = temp->next;
    temp->next=temp->next->next;
    delete(del);
}
//  FIND THE LENGTH OF THE LINKED LIST 
int findlen(Node*head){
    int cnt=0;
    Node*temp=head;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
// RETURN THE ITH NODE IN LINKED LIST 
int ithNode(Node*&head, int i){
    int cnt=0;
    Node*temp=head;
    while(cnt<i && temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    if(temp!=nullptr){
        return temp->data;
    }else{
        return -1;
    }
}
// UPDATE THE ITH NODE IN LINKED LIST
void updateIth(Node*&head,int i,int val){
    int cnt=0;
    Node*temp=head;
    while(cnt!=i && temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    if(temp!=nullptr){
        cout << "Invalid node" << "\n";
        return;
    }
    temp->data=val;
}
// REVERSE A GIVEN LINKED LIST 
void reverseList(Node*&head){
    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        return;
    }
    Node*prev=nullptr;
    Node*current=head;
    Node*next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
}
// FIND THE MIDDLE NODE OF A LINKED LIST 
int findmiddle(Node*&head){
    int cnt=0;
    Node*temp=head;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    cnt=cnt/2;
    temp=head;
    while(cnt--){
        temp=temp->next;
    }
    return temp->data;
}
// ROTATE A LINKED LIST BY K 
Node* rotate(Node*&head,int K){
    if(head==nullptr){
        return;
    }
    if(K==0){
        return;
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    K=cnt%K;
    Node*last=head;
    temp=head;
    while(last->next!=nullptr){
        last=last->next;
    }
    while(K--){
        head=head->next;
        temp->next=nullptr;
        last->next=temp;
        last=temp;
        temp=head;
    }
    return head;
}