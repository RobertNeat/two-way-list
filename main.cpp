#include <iostream>
#include <cstdlib>//system("cls");
#include <time.h>
using namespace std;

struct element{
    int number;
    element* next;
    element* prev;
};

struct double_list{
    element* head;
    element* tail;
    int counter;
};
/////////////////Adding///////////////////////
void add_tail(double_list &l,int value){
    element* el=new element;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;
    if(l.tail!=nullptr){
        l.tail->next=el;
        el->prev=l.tail;
    }
    else{
        l.head=el;
    }
    l.tail=el;
    l.counter++;//counter increase
}

void add_head(double_list& l, int value){
    element* el= new element;
    el->number=value;
    el->next=nullptr;
    el->prev=nullptr;

    if(l.head!=nullptr){
        l.head->prev=el;
        el->next=l.head;
    }
    else{
        l.tail=el;
    }
    l.head=el;
    l.counter++;//counter increase
}

void add_position(double_list& l,int value, int position){
    element* temp=l.head;
    int i=1;
    while(i<position-1){
            temp=temp->next;
            i++;
    }
    element* el=new element;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    l.counter++;//counter increase
}
/////////////usuwanie///////////////
void delete_tail(double_list& l){
    element* temp=l.tail;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.tail=l.tail->prev;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;//counter decrease
}

void delete_head(double_list& l){
    element* temp=l.head;
    if(l.counter==1){
        l.tail=nullptr;
        l.head=nullptr;
    }
    else{
        l.head=l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;//counter decrease
}

void delete_position(double_list& l, int position){
    element* temp=l.head;
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i+=1;
    }
    element *tempUs=temp->next;
    temp->next=tempUs->next;
    temp->next->prev=temp;
    delete tempUs;
    l.counter--;//counter decrease
}
////////////displaying////////////////////
void show(double_list l, int mode){//1- from start, 2- from end
    int i=1;
    element* temp=l.head;
    if(mode==1){
        while(i<=l.counter){
            cout<<temp->number<<endl;
            temp=temp->next;
            i++;
        }
    }
    if(mode==2){
        i=l.counter;
        temp=l.tail;
        while(i>=1){
            cout<<temp->number<<endl;
            temp=temp->prev;
            i--;
        }
    }
}

void first(double_list l){
    cout<<l.head->number;
}

void last(double_list l){
    cout<<l.tail->number;
}
////////////is empty//////////////////
bool isEmpty(double_list l){
    if(l.head==nullptr){
        return true;
    }
    return false;
}
/////////////////////////////////////
void minDoubleList(double_list l){
    int minIndex=1;
    int i=1;
    element* temp=l.head;
    int min=temp->number;
    while(i<=l.counter){
        if(min<=l.counter){
            min=temp->number;
            minIndex=i;
        }
        temp=temp->next;
        i++;
    }
    cout<<"Minimal element:"<<min<<" on position:"<<minIndex<<endl;
}
////////////////Menu///////////////////////
void line(){
cout<<"--------------------------------------------------\n";
}

void menu(int& wybor){
line();
cout<<"Menu:"<<endl;
cout<<"1.check if list is empty\n";
cout<<"2.add element to the end of the list\n";
cout<<"3.add element on the start of the list\n";
cout<<"4.add element on the given position\n";
cout<<"5.delete element from the end of the list\n";
cout<<"6.delete element from the start of the list\n";
cout<<"7.delete element from the given position\n";
cout<<"8.display list elements from the start to the end\n";
cout<<"9.display list elements from the end to the start\n";
cout<<"10.search minimal element in the list\n";
cout<<"11.delete all list and release memory\n";
cout<<"12.exit program\n";
line();
cout<<"Choose:";
cin>>wybor;
system("cls");
}
//////////////////////MAIN//////////////////////////
int main()
{
    srand (time(NULL));//picking random values 1-50

    double_list l;
    l.head=nullptr;
    l.tail=nullptr;
    l.counter=0;
    //check special cases:
    //-position does not exist
    //-first position
    //-last position

    int index;//index used to input values

    int a;
    menu(a);
    while(a>0 && a<12){
        switch(a){
    case 1:
            cout<<"Is empty:"<<endl;
            if(isEmpty(l)){cout<<"Yes\n";}
            else{cout<<"No\n";}
        menu(a);
        break;
    case 2:
            add_tail(l,rand()%50+1);
        menu(a);
        break;
    case 3:
            add_head(l,rand()%50+1);
        menu(a);
        break;
    case 4:
            cout<<"Provide position to input value:";
            cin>>index;
            if(index<=1){
                cout<<"index too low - adding random value on the start"<<endl;
                add_head(l,rand()%50+1);
            }
            else if(index>1 && index<l.counter){
                add_position(l,rand()%50+1,index);
                cout<<"Added element on the position:"<<index<<endl;
            }
            else{
                cout<<"index too big - adding random value on the end"<<endl;
                add_tail(l,rand()%50+1);
            }
        menu(a);
        break;
    case 5:
            if(!isEmpty(l)){
                delete_tail(l);
            }
        menu(a);
        break;
    case 6:
            if(!isEmpty(l)){
                delete_head(l);
            }
        menu(a);
        break;
    case 7:
        if(!isEmpty(l)){
        cout<<"Provide position wchich whom delete element:";
        cin>>index;
        if(index<=1){
            cout<<"index too low - deleting value from the start"<<endl;
            delete_head(l);
        }
        else if(index>1 && index<l.counter){
            delete_position(l,index);
            cout<<"Deleted element from position:"<<index<<endl;
        }
        else{
            cout<<"index too big - deleting value from the end"<<endl;
            delete_tail(l);
        }}else{
        cout<<"Can't delete empty list"<<endl;
        }
        menu(a);
        break;
    case 8:
        show(l,1);
        menu(a);
        break;
    case 9:
        show(l,2);
        menu(a);
        break;
    case 10:
        minDoubleList(l);
        menu(a);
        break;
    case 11:
        while(!isEmpty(l)){
            delete_head(l);
        }
        menu(a);
        break;
        }
    }

    cout << "End of the program" << endl;
    return 0;
}
