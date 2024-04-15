#include<iostream>
#include<string>
#include"gettime.h"
using namespace std;
class busdata{
    private:
    int busnumber;
    string ownername;
    string drivername;
    string from;
    string to;
    int Ahour,Amin;int Dhour;int Dmin;
    public:
    busdata(){};

    busdata( int _busnumber,
    string _ownername,
    string _drivername,
    string _from,
    string _to,
    int _Ahour,int _Amin,int _Dhour,int _Dmin)
    {
        busnumber=_busnumber;
        ownername=_ownername;
        drivername=_drivername;
        from=_from;
        to=_to;
        Ahour=_Ahour;
        Amin=_Amin;
        Dhour=_Dhour;
        Dmin=_Dmin;
    }

    int getbusnumber(){
        return busnumber;
    };

    string getownername(){
        return ownername;
    };
    string getdrivername(){
        return drivername;
    };
    string getfrom(){
        return from;
    };
    string getto(){
        return to;
    };
    string getarrival(){
        string arrival= to_string(Ahour)+":"+ to_string(Amin);
        return arrival;
    };

    string getdeparture(){
        string departure= to_string(Dhour) +":"+ to_string(Dmin)  ;
        return departure;
    };




};

class bus{
    private:
    static const int MAX=100;
    busdata p[MAX];
    int buscount;
    public:
    bus(){
        buscount=0;
    }

    //add bus data
    void addbusdetail(busdata newb){
        if(buscount<MAX){
            p[buscount++]=newb;
        }

    };

    //show detail
    void showdetail(){
        cout << "----------*----------*-----------*------*----------*-------------*-------\n";
        cout << "Bus number\tBus Owner\tBus driver\tFrom\tTo\tArrival\t\tDeparture\n";
        for(int i=0;i<buscount;i++){
            cout<<p[i].getbusnumber()<<"\t\t"<<p[i].getownername()<<"\t"<<p[i].getdrivername()
            << "\t" << p[i].getfrom() << "\t" << p[i].getto() << "\t" << p[i].getarrival()
            << "\t" << p[i].getdeparture() << endl;
        };
    }













};

int main(){

    bus data;

    int choice;
    do{
        cout<<"------------------------------------\n";
        cout<<"         BUS OWNER                  \n";
        cout<<"-------------------------------------\n";
        cout<<"1.Add bus detail             \n";
        cout<<"2.Show detail                \n";
        cout<<"3.Exit                       \n";
        cout<<"Enter your choice";
        cin>>choice;
        switch (choice)
        {
        case 1:{ int bn;string bo,bd;
                string from;string to;
                int Ahour,Amin;int Dhour;int Dmin;
                cout<<"\nEnter your bus number:";
                cin>>bn;
                cout<<"\nEnter bus owner name:";
                cin.ignore();
                getline(cin,bo);
                cout<<"\nEnter bus driver name:";
                cin>>bd;
                cout<<"\nEnter bus destination:---";
                cout<<"From:";
                cin>>from;
                cout<<"\tTo:";
                cin>>to;
                cout<<"\nEnter Arrival time:";
                getTimeFromUser(Ahour,Amin);
                cout<<"\nEnter Departure time:";
                getTimeFromUser(Dhour,Dmin);

                busdata newp(bn,bo,bd,from,to,Ahour,Amin,Dhour,Dmin);
                data.addbusdetail(newp);
                break;
        }
        case 2:{
            data.showdetail();break;
        }
        default:
            break;
        }









    }while(choice != 3);
    return 0;
}