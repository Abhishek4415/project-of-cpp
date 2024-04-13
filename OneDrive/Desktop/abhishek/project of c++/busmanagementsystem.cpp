#include <iostream>
#include<string>
using namespace std;
class Reservation{

    private:
    
    int busNumber;
    string passengerName;
    int seatNumber;
    public:
    Reservation(){};
    Reservation(int b,int s,string p)
    {
        busNumber=b;
        seatNumber=s;
        passengerName=p;
    };

    int getbusnumber(){
        return busNumber;
    };
    int getseatnumber(){
        return seatNumber;
    };
    string passengername(){
        return passengerName;
    }

    

};

class bus{
    static const int MAX_ITEMS =100;
    Reservation p[MAX_ITEMS];
    int itemcount;
    public:
    bus(){
        itemcount=0;
    }

    void addpassenger(Reservation newp){
        if(itemcount<MAX_ITEMS){
            p[itemcount++]=newp;
        }
    };
    void show(){
        cout<<"Bus number\tseat number\tpassenger name\n";
        for(int i=0;i<itemcount;i++){
            cout<<p[i].getbusnumber()<<"\t\t"<<p[i].getseatnumber()<<"\t\t"<<p[i].passengername()<<endl;
            cout<<"------------------------------------------------------------------------------------\n";
        };
    }
};

int main(){
    bus p;
    int choice;
    int arr[5]={101,102,103,104,105};

    do{
        cout<<"----------------------------------------\n";
        cout<<"    BUS MANAGEMENT SYSTEM                \n";
        cout<<"-------------------------------------------\n";
        cout<<"     1.Book bus                           \n";
        cout<<"     2.check bus information              \n";
        cout<<"     3.Show                                \n";
        cout<<"     4.Bus available                        \n";
        cout<<"     5.exit                                  \n";
        cout<<"     6.Enter bus information                 \n";
        cout<<"Enter your choice :-";
        cin>>choice;
        switch (choice)
        {
        case 1:{int bn,sn;
                string name;
                cout<<"\nEnter your name:-";
                cin>>name;
                cout<<"\nEnter bus number:-";
                cin>>bn;
                cout<<"\nEnter seat number:-";
                cin>>sn;
                int c=0;
                for(int i=0;i<5;i++){
                    if(bn==arr[i]){
                        Reservation newp(bn,sn,name);
                        p.addpassenger(newp);
                        break;
                    }else{
                        c++;

                    }
                    
                };
                if(c==5){
                    cout<<"invalid bus number\n";
                }
                

                    
                break;}
        case 2:{
            break;
        }
        case 3:p.show();break;
        
        case 4:{
            break;

        }
        case 5:{
            break;
            cout<<"Exiting...\n";
        }
        case 6:{
            int bn;
        }
        
                

    }
    }while(choice !=5);


    return 0;

}

