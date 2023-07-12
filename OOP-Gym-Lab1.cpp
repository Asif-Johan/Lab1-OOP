//program to get a gym membership system
//Where is the EGG??
//Header files
#include <iostream>
#include <vector> //to create a vector of objects made with class
#include <conio.h> //to use the _getch() function to hold screen
using namespace std;


//Creating member class
class Member {

//adding private elements(datatypes)
private: 
int memberID;
double height,weight;
string memberName;

//adding public elements (methods,constructor and function)
public:

//Constructor
Member (int memID,string memName, double memHeight,double memWeight ){
    memberID= memID;
    height = memHeight;
    weight= memWeight;
    memberName=memName;
}


//Setter methods

void setID(int memID){
    memberID=memID;
}
void setHeight(double memHeight){
    height=memHeight;
}
void setweight(double memWeight){
    weight=memWeight;
}
void setname(string memName){
    memberName=memName;
}


//getter methods
int getID(){
    return memberID;
}
double getHeight(){
    return height;
}
double getWeight(){
    return weight;
}
string getName(){
    return memberName;
}

};


///////////////////////////////////
//1. Function to Add new members//
/////////////////////////////////

void addNewMember(vector<Member>&members){
    //clear system
    system("cls");
    //Add Info datatypes
    int ID;
    double height, weight;
    string name;

//adding interface
    cout <<".....Welcome New Member....."<<endl;
    cout <<"New Member Id:";
    cin>>ID;

for(int i=0;i<members.size();i++){
    if (members[i].getID() == ID )
    {
        cout<<"Member With This Id Already Exists"<<endl;
        _getch();
        return;
    }
    
}
cout <<"New Member Name:";
    cin.ignore();//to ignore the buffer 
    getline(cin,name); 

    cout <<"New Member Height in meters (m):";
    cin>>height;
    cout <<"New Member Weight in Kg:";
    cin>>weight;
    

    Member newMember(ID, name, height, weight);
    members.push_back((newMember));

    cout<<"Member Successfully Added"<<endl;
    _getch();


}



///////////////////////////////////
//2. Function to Update member  //
/////////////////////////////////

void UpdateMember(vector<Member>&members){
//changing through Id
int UpdateID, choice;
string name;
cout<<"Enter Id of Member"<<endl;
cin>>UpdateID;
system("cls");
for(int i=0; i<members.size();i++){

if(members[i].getID() == UpdateID){
cout<<"Update Menu of ID: "<<UpdateID<<endl;
cout<<"1. Update ID"<<endl;
cout<<"2. Update Name"<<endl;
cout<<"3. Update Height"<<endl;
cout<<"4. Update Weight"<<endl;
cin>>choice;

switch (choice)
{
case 1:
    int NewID;
    cout<<"Enter New ID :";
    cin>>NewID;
    members[i].setID(NewID);
    break;
case 2:
    cout<<"Enter New Name :";
    cin.ignore();
    getline(cin,name);
    members[i].setname(name);
    
    break;
case 3:
int NewHeight;
    cout<<"Enter New Height (m) :";
    cin>>NewHeight;
    members[i].setHeight(NewHeight);


    break;
case 4:
   int NewWeight;
    cout<<"Enter New Weight (Kg):";
    cin>>NewWeight;
    members[i].setweight(NewWeight);
    break;

default:cout<<"Enter valid Number"<<endl;
_getch();
    break;
}
cout<<"Member Updated Successfully"<<endl;
_getch();
}

}

}

///////////////////////////////////
//3. Function to Remove member  //
/////////////////////////////////

 void RemoveMember(vector<Member>&members){
system("cls");
int delID;
cout<<"Enter ID to delete record: ";
cin>>delID;

for(int i=0; i<members.size();i++){
if(members[i].getID() == delID){
    members.erase((members.begin()+i));
}


}

cout<<"Member Removed Successfully"<<endl;
_getch();


 }

////////////////////////////////////////////////
//4. Function to Check Max Hight and width   //
//////////////////////////////////////////////

 void checkMax(vector<Member>&members){

    double maxH=0, maxW=0;

    for(int i=0;i<members.size();i++){// goes through the loop and swaps max at every next max
        if(members[i].getHeight()>=maxH){maxH=members[i].getHeight();};
        if(members[i].getWeight()>=maxW){maxW=members[i].getWeight();};
    }
cout<<endl<<"Max Height: "<< maxH;
cout<<endl<<"Max Weight: "<< maxW;

_getch();

 }


////////////////////////////////////////////////
//5. Function to Check Min Hight and width   //
//////////////////////////////////////////////

 void checkMin(vector<Member>&members){

    double minH=1000, minW=10000;

    for(int i=0;i<members.size();i++){// goes through the loop and swaps at every next min
        if(members[i].getHeight()<=minH){minH=members[i].getHeight();};
        if(members[i].getWeight()<=minW){minW=members[i].getWeight();};
    }
cout<<endl<<"Min Height: "<< minH;
cout<<endl<<"Min Weight: "<< minW;
_getch();


 }


///////////////////////////////////////////////////
//6. Function to Check Average Hight and width  //
/////////////////////////////////////////////////

 void checkAvg(vector<Member>&members){

    double sumH=0, sumW=0;

    for(int i=0;i<members.size();i++){
        sumH+=members[i].getHeight();
        sumW+=members[i].getWeight();
    }
cout<<endl<<"Average Height: "<< (sumH/members.size());
cout<<endl<<"Average Weight: "<< (sumW/members.size());

_getch();

 }

  /////////////////////////////////////////////////
 // 7. Function to Check The BMI Classification //
/////////////////////////////////////////////////

 void BMIClassification(vector<Member>&members){
    double BMI, height, weight;
    int Id,i ;

cout << "Enter Id...";
cin>> Id;

for (i=0; i< members.size();i++){
    if(members[i].getID() == Id){ 
        height= members[i].getHeight(); //Gets height of member with given ID
        weight = members[i].getWeight(); // Gets Weigth of member with given ID
BMI= (weight/ (height*height));
    }
}
cout<<"BMI is: "<<BMI; //Prints BMI
cout<<endl;

// Classification of BMI
if (BMI<16){
    cout<<"Severe Thinness"<<endl;
}

else if (BMI<17)
{
    cout<<"Moderate Thinness"<<endl;
}
else if (BMI<18.5)
{
    cout<<"Mild Thinness"<<endl;
}
else if (BMI<25)
{
    cout<<"Normal"<<endl;
}
else if (BMI<30)
{
    cout<<"Overweight"<<endl;
}
else if (BMI<35)
{
    cout<<"Obesity level I"<<endl;
}
else if (BMI<40)
{
    cout<<"Obesity Level II"<<endl;
}else{
        cout<<"Obesity Level III"<<endl;

}


_getch();

 }

/////////////////////////////////////////////////////////////////////////
 // check all members////////// EGG///////////////// Click 0 on menu ////
 ////////////////////////////////////////////////////////////////////////
 void CheckAllMembers(vector<Member>members){

for(int i=0; i<members.size();i++){
cout<<endl;
cout<<"Sl: "<<i <<endl;
cout<<"ID: "<<members[i].getID() <<endl;
cout<<"Name: "<<members[i].getName() <<endl;

cout<<"Height: "<<members[i].getHeight() <<endl;
cout<<"Weight: "<<members[i].getWeight() <<endl;
cout<<"BMI: "<<((members[i].getWeight())/((members[i].getHeight())*(members[i].getHeight()))) <<endl;

}

_getch();

 }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main (){

vector<Member>members;
members.push_back(Member(16, "Johan", 1.7, 73 ));

int choice;

do
{
    //the display menu
    system("cls");
    cout<<"*****Main Menu*******"<<endl;
    // cout<<"0. View All Members"<<endl;
    cout<<"1. Add Member"<<endl;
    cout<<"2. Update Member"<<endl;
    cout<<"3. Remove Member"<<endl;
    cout<<"4. Max height and Width"<<endl;
    cout<<"5. Min Height And Widht"<<endl;
    cout<<"6. Average Height and Width"<<endl;
    cout<<"7. BMI Classification"<<endl;
    cout<<"8. Exit "<<endl;
    cout<<".........Enter Choice (1-8)............"<<endl;
cin>>choice;

switch (choice)
{
case 1:
    addNewMember(members);
    break;
case 2:
    UpdateMember(members);
    break;
case 3:
    RemoveMember(members);
    break;
case 4:
    checkMax(members);
    break;
case 5:
    checkMin(members);
    break;
case 6:
    checkAvg(members);
    break;
case 7:
    BMIClassification(members);
    break;

case 8:
exit(1);//exits
break;

case 0:
CheckAllMembers(members);
break;

default:
cout<<"Please select Valid Option";
    break;
}


} while (1);


    return 0;
}