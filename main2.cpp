#include <fstream>
#include <iostream>
#include <string>
using namespace std;



class Events
{ // declaration & definition
protected:
    string eventName, eventVenue, eventDate; // data members of Events
    int eventFee;

public:
    static int eventId;     // data
    static void Id(){eventId++;} // ref 16 line
    friend istream &operator>>(istream &in, Events &obj) // operator overloading to cin 
    {
        cout << "Kindly Enter your Event name : ";
        getline(cin, obj.eventName);
        cout << "What will be the Venue for " << obj.eventName << " ?" << endl;
        getline(cin, obj.eventVenue);
        cout<< "Enter date of the Event (DD/MM/YYYY): ";
        getline(cin,obj.eventDate);
        cout<<"Congratulations !!!"<<endl
        <<"Your event is added with eventId :"<<obj.eventId<<endl;
        return in;
    }; // declaration + definition
    

    void sendData(){ // file handling to write in file
        ofstream obj = ofstream("eventmanagement.txt", ios::app); // to append data in text file
        obj<<"Event no  :   "<<eventId<<endl;
        obj<<"Event Name :  "<<eventName<<endl;
        obj<<"Event Venue : "<<eventVenue<<endl;
        obj<<"Event Date : "<<eventDate<<endl<<endl;
        obj<<"=================================="<<endl<<endl;
    }

    Events(){Id();};
};

class Esports : public Events
{ // inheritance
protected:
    

public:

    friend istream &operator>>(istream &in, Esports &obj) // same as Events
    {
        cout << "Kindly Enter your Esports Event name : ";
        getline(cin, obj.eventName);
        cout << "What will be the Venue for " << obj.eventName << " ?" << endl;
        getline(cin, obj.eventVenue);
        cout<< "Enter date of the Event (DD/MM/YYYY): ";
        getline(cin,obj.eventDate);
        while(true){
        cout << "Enter Pass Fees :";
        cin >> obj.eventFee;
        if (cin.fail())
        {
            cin.clear(); // reset the stream
            cin.ignore(10000,'\n'); // ignore the invalid input
            cout << "Invalid input! Please enter a valid number." << endl;
            
        }
        else
        {
            break; // exit the loop if the input was valid
        }
        }
        cout<<endl<<"Congratulations !!!"<<endl
        <<"Your event is added with eventId :"<<obj.eventId<<endl;
        return in;
    }; // operator overload  

    void sendData(){
        ofstream obj = ofstream("eventmanagement.txt", ios::app); // to append data in text file
        obj<<"Event no :    "<<eventId<<endl;
        obj<<"Event Name :  "<<eventName<<endl;
        obj<<"Event Venue : "<<eventVenue<<endl;
        obj<<"Event Date : "<<eventDate<<endl;
        obj<<"Event Fee :   "<<eventFee<<endl<<endl;
        obj<<"=================================="<<endl<<endl;
    }

    Esports() {}
};

class Standup : protected Events
{ // inheritance
public:
    
    
    friend void buyTicket();                               // friend function
    friend istream &operator>>(istream &in, Standup &obj){
        

        cout << "Enter the name of your Standup special: ";
        getline(cin, obj.eventName);
        cout << "What will be the Venue for " << obj.eventName << " ?" << endl;
        getline(cin, obj.eventVenue);
        cout<< "Enter date of the Event (DD/MM/YYYY): ";
        getline(cin,obj.eventDate);
        while(true){
        cout << "Enter Pass Fees :";
        cin >> obj.eventFee;
        if (cin.fail())
        {
            cin.clear(); // reset the stream
            cin.ignore(10000,'\n'); // ignore the invalid input
            cout << "Invalid input! Please enter a valid number." << endl;
        }
        else
        {
            break; // exit the loop if the input was valid
        }
        }
        cout<<endl<<"Congratulations !!!"<<endl
        <<"Your event is added with eventId :"<<obj.eventId<<endl;
        return in;

    }; // operator overload

     void sendData(){
        ofstream obj = ofstream("eventmanagement.txt", ios::app); // to append data in text file
        obj<<"Event no :    "<<eventId<<endl;
        obj<<"Event Name :  "<<eventName<<endl;
        obj<<"Event Venue : "<<eventVenue<<endl;
        obj<<"Event Date : "<<eventDate<<endl;
        obj<<"Event Fee :   "<<eventFee<<endl<<endl;
        obj<<"=================================="<<endl<<endl;
    }
    Standup(){};
};

class Attendees 
{
    protected:
    static const int rows = 10;
    static const int columns = 10;
    string seats[rows][columns];
    
    public:
    void defaultSeats(){
        
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<columns; j++){
                seats[i][j] = " - ";
            }
        }
    }
    
    string printSeats(){
        cout << "      0  1  2  3  4  5  6  7  8  9" << endl;
        for (int i = 0; i < rows; i++) {
            cout << 0+i << " = " << (char)('A' + i);
            for (int j = 0; j < columns; j++) {
                cout << seats[i][j];
            }          
        cout << endl;
        }
    }

    bool bookSeat(int r, int c)
    {
        // Check if the seat is available
        if (seats[r][c] == " - ")
        {
            seats[r][c] = " X ";
            return true;
        }
        else
        {
            return false;
        }
    }

    
};


void getData(){
    char data[100];
    ifstream inFile;
    inFile.open("eventmanagement.txt");
    if (!inFile){cout<<"There are no upcoming events at the moment :("<<endl<<endl<<"Check again Later :D"<<endl<<endl;}
    else{
    while(!inFile.eof()){
        inFile.getline(data,100);
        cout<<data<<endl;
    }
    }
    inFile.close();
}

void addEvent(){
    Events newEvents;
    cin>>newEvents;
    newEvents.sendData();
}

void addEsports(){
    Esports newEsports;
    cin>>newEsports;
    newEsports.sendData();
}

void addStandUp(){
    Standup newStandup;
    cin>>newStandup;
    newStandup.sendData();
}


int Events::eventId = 0;
int main()
{   
    Attendees atnds;
    char ch = 'y';
    int opt;
    
    while(true){
        menu:
        cout<<endl<<"====== MENU ======"<<endl<<"1. Add Event"<<endl<<"2. Show Events"<<endl<<"3. Buy Tickets"<<endl<<"4. Exit"<<endl<<endl<<"Enter your choice : ";
        cin>>opt;
        cin.ignore();
        switch(opt){
            case 1:
            int opt2;
            l1: cout<<endl<<"====== ADD EVENTS ======"<<endl<<"1. Add Esports Event"<<endl<<"2. Add Standup Show"<<endl<<"3. Add anyother type of event."<<endl<<"4. Exit"<<endl<<endl<<"Enter your choice: ";
            cin>>opt2; 
            cin.ignore();
            if(opt2 == 1){
                addEsports();
            }
            else if(opt2 == 2){
                addStandUp();
            }
            else if(opt2 == 3){
                addEvent();
            }
            else if(opt2 == 4){
                goto menu;
            }
            else{
                cout<<"Enter valid choice please!"<<endl;
                goto l1;
            }
            break;

            case 2:
            cout<<"==== UPCOMING EVENTS ===="<<endl<<endl;
            getData();
            break;

            case 3:
            cout<<endl<<"=========== Book Tickets =========="<<endl<<endl;
            int seatsNum , seatX, seatY;
            int id;
            cout<<"Enter Event ID for the show you want to book: ";
            cin>>id;
            cout<<endl<<" =====Showing Available Seats for Event id: "<<id<<" ====="<<endl;
            atnds.defaultSeats();
            atnds.printSeats();
                cout<<"How many Tickets do you want to buy? : "; 
                cin>>seatsNum;
                for(int i = 0; i<seatsNum; i++){
                    cout<<"Enter seat coordinates for ticket no. "<<i+1<<": "<<endl;;
                    cout<<"X coordinates: "; cin>>seatX;
                    cout<<"Y coordinates: "; cin>>seatY;
                    atnds.bookSeat(seatX,seatY);    
                }
            cout<<endl;
            atnds.printSeats();
            if(seatsNum != 0){
                cout<<endl<<"Successfully booked seats"<<endl;
                cout<<"+ ---------receipt--------- +"<<endl;
                cout<<"   "<<"Show number:       "<<id<<endl;
                cout<<"   "<<"number of tickets: "<<seatsNum<<endl;
                cout<<"+ -------------------------- +"<<endl<<endl;

            }
            else{
                cout<<endl<<"No tickets were booked!"<<endl<<endl;
            }
            break;
                
            case 4:
            goto exit;
            break;

            default:
            cout<<"Enter valid choice please!"<<endl;
            break;

        }

        cout<<"Do you want to continue?(Y/N): ";
        cin>>ch;
        if(ch != 'y' && ch != 'Y'){
            goto exit;
        }
    }

    exit: return 0;
}