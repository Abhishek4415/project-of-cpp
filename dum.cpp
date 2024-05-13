#include<iostream>
#include<vector>
using namespace std;

class user{
    private:
    string username;
    string password;
    public:
    user(){};
    user( string _username, string _password){
        username=_username;
        password=_password;


    }
    string getusername(){
        return username;
    };
    string getpassword(){
        return password;
    }

};

//route class------------------------------------

class Route{
    private:
    string name;
    string source;
    string destination;

    int distance;
    public:
    Route(){};
    Route(  string _name,
    string _source,
    string _destination,

    int _distance){
        name=_name;
        source=_source;
        destination=_destination;
        distance=_distance;


    };

    string getName(){
        return name;
    };

    string getSource(){
        return source;
    };
    string getDestination(){
        return destination;
    };
    int getDistance(){
        return distance;
    };


};

class Bus{
    private:
    string busnumber;
    string routename;
    string desparture;
    string arrival;
    int totalseat;
    public:
    Bus(){};
    Bus(string _routename,string _busnumber,string _arrival,
    string _desparture,
    int _totalseat){
        routename=_routename;
        busnumber=_busnumber;
        totalseat=_totalseat;
        desparture=_desparture;
        arrival=_arrival;
        totalseat=_totalseat;
    };

        string getArrival(){
        return arrival;
    };
    string getDeparture(){
        return desparture;
    };

    string getroute(){
        return routename;
    }
    

    string getbusnumber(){
        return busnumber;
    };

    int gettotalseat(){
        return totalseat;
    };


};

class ticket{
    private:
    int seatnumber;
    string routename;
    string busnumber;
    string passenger;
    public:
    ticket (){};

    ticket(    int _seatnumber,
    string _routename,
    string _busnumber,
    string _passenger)
    {
        seatnumber=_seatnumber;
        routename=_routename;
        busnumber=_busnumber;
        passenger=_passenger;

    }
    string getpassengername(){
        return passenger;
    };

    int getseatnumber(){
        return seatnumber;
    };

    string getbusnumber(){
        return busnumber;
    };

    string getroutename(){
        return routename;
    };

    




    
    
};

class busreservation{
    private:
    static const int MAX=100;
    user users[MAX];
    Route routes[MAX];
    Bus buses[MAX];
    ticket tickets[MAX];
    int buscount;
    int routecount;
    int itemcount;
    int ticketcount;
    public:
    // busreservation(){};
    busreservation(){
        itemcount=0;
        routecount=0;
        buscount=0;
        ticketcount=0;
    };

    void adduser(user u){
        if(itemcount<MAX){
          users[itemcount++]=u;
        };
       
    };

    void addroute(Route r){
        if(routecount<MAX){
            routes[routecount++]=r;
        };
 
    };

    void addBus(Bus b){
        if(buscount<MAX){
            buses[buscount++]=b;
        }
    };

    void addticketdetail(ticket t){
    if(ticketcount<MAX){
        tickets[ticketcount++]=t;
    };

}



bool value;

int count=0;
char v[15]="avail..";
void displayavailablebus(string r){
            for(int j=0;j<buscount;j++){
                if(buses[j].getroute()==r){
            cout<<"Available Bus for Route "<<r<<endl;
                    int availableseat=buses[j].gettotalseat();
                    if(availableseat>0){
                        cout<<"\n\n";
                        cout<<"Bus Number:"<<buses[j].getbusnumber()<<"\tDestinaiton:"<<routes[j].getDestination()<<"\nArrival:"<<buses[j].getArrival()
                        <<"\tDeparture:"<<buses[j].getDeparture()<<"\nTotal seat:"<<buses[j].gettotalseat()<<"\nAvailable seat:"<<availableseat<<endl;
                        cout<<"\n\n----------::Available seats::---------\n";
                        for(int seat=1;seat<=buses[j].gettotalseat();seat++){
                            //checked seat is booked or not

                            if(seat%2==0){
                                cout<<"\t"<<seat;
                            }else{
                                cout<<seat<<"/n";
                            }

                            


                            value=true;
                        }
                    }
                }else{count++; }
                
            }
        
    
    if(count == buscount){
       value=false;
       cout<<"NO bus is available:-";
    }
        

};


    


    

    

    void login(string username,string password){
        for(int i=0;i<itemcount;i++){
            if(users[i].getusername() == username  && users[i].getpassword()==password ){
                cout<<"---login successfully---\n";
            
                int choice2;
                do{
                    cout<<"\n\n-----------------|| WELCOME TO MENU BY ABHISHEK ||--------------------\n";
                    cout<<"1.Display Routes\n";
                    cout<<"2.Display Buses\n";
                    cout<<"3.Book ticket\n";
                    cout<<"4.Cancel ticket\n";
                    cout<<"5.Booking \n";
                    cout<<"6.Logout\n";
                    cout<<"Enter your choice:-";
                    cin>>choice2;

                    switch (choice2)
                    {
                    case 1:{
                        cout<<"\n\n";
                        cout<<"-----------------------------||ROUTE INFORAMTION||------------------------------\n";
                        for(int i=0;i<routecount;i++){
                        cout<<"Route Name:"<<routes[i].getName()<<" "<<"("<<routes[i].getDestination()<<")"<<"\n"<<"Distance:"
                        <<routes[i].getDistance()<<"km"<<"\n\n";
                        };
                        break;
                    }
                    case 2:{string routeName;
                    cout<<"Enter the route name:";
                    cin>>routeName;
                    displayavailablebus(routeName);
                        break;
                    }
                    case 3:{
                        cout<<"\n\n";
                        cout<<"-----------------------------||ROUTE INFORAMTION||------------------------------\n";
                        for(int i=0;i<routecount;i++){
                        cout<<"Route Name:"<<routes[i].getName()<<" Destination "<<"("<<routes[i].getDestination()<<")"<<"\n"<<"Distance:"
                        <<routes[i].getDistance()<<"km"<<"\n\n";
                        };

                        string route;
                        cout<<"Select Route Name:";
                        cin>>route;

                        displayavailablebus(route);
                        string number,username;int seatn;
                        if (value){

                        cout<<"\nSelect bus number:";
                        cin>>number;
                        cout<<"\n\n Enter the seat number you want to book:";
                        cin>>seatn;
                        cout<<"Enter your username:";
                        cin>>username;
                        ticket t(seatn,route,number,username);    
                        addticketdetail(t);

                        for(int i=0;i<ticketcount;i++){
                            cout<<"your ticket is book:\n";
                            cout<<tickets[i].getpassengername()<<"\t"<<tickets[i].getbusnumber()<<"\n"<<tickets[i].getroutename()<<"\t"
                            <<tickets[i].getseatnumber();
                            
                    
                        }

                        }else{
                            break;
                        }

                        
                        break;


                        //ticket

                    }
                    case 4:{ int n;
                        for(int i=0;i<ticketcount;i++){
                            cout<<tickets[i].getpassengername()<<"\t"<<tickets[i].getbusnumber()<<"\n"<<tickets[i].getroutename()<<"\t"
                            <<tickets[i].getseatnumber();
                        }
                        cout<<"Enter your Ticket number:-";
                        cin>>n;


                    }

                    case 5:{
                            for(int i=0;i<ticketcount;i++){
                            cout<<"your ticket is book:\n";
                            cout<<tickets[i].getpassengername()<<"\t"<<tickets[i].getbusnumber()<<"\n"<<tickets[i].getroutename()<<"\t"
                            <<tickets[i].getseatnumber();
                        }
                        
                    }

                       
                        
                        


                           
                    
                    
                    default:{
                        break;
                    }
                   
                }

                }while(choice2 !=6);
                
            break;
            }else{
                cout<<"invalid login data..\n";
            };
        }
    }  
        
};
    









int main(){
    busreservation b;
    Route newroute("R005","B","SOHNA to GURGOAN",50);
    Route newroute1("R002","A","BETTIAH TO MOTIHARI",80);
    Route newroute2("R003","A","GURGAON TO SOHNA",50);
    b.addroute(newroute);
    b.addroute(newroute1);
    b.addroute(newroute2);

    //add bus data;
    Bus newb("R005","B003","10:30","11:00",20);
    b.addBus(newb);
    Bus newb1("R002","B004","10:30","11:00",25);
    b.addBus(newb1);
    

    
    
    
    int choice;
    do{
        cout<<"----------------------------------------\n";
        cout<<"1.REGISTER\n";
        cout<<"2.LOGIN\n";
        cout<<"0.Exit\n\n";
        cout<<"Enter your choice:-";
        cin>>choice;

        switch(choice){
            case 1:{
                string username,password;
                cout<<"Enter your username:";
                cin>>username;
                cout<<"Enter your password:";
                cin>>password;
                user newuser(username,password);
                b.adduser(newuser);
                break;
            }
            case 2:{
                string username,password;
                cout<<"Enter your username:";
                cin>>username;
                cout<<"Enter your password:";
                cin>>password;
                b.login(username,password);
                break;

            }
            default:{
                cout<<"Invalid choice:---TRY AGAIN\n";break;
            }
                


        }

    }while(choice !=0);

    return 0;


}
