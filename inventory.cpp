#include<iostream>
using namespace std;
class item{
    public:
    string name;
    int id;
    int quantity;
    double price;
    public:
    item():id(0),name(""),quantity(0),price(0.0){};
    item(int _id,string _name,int _quantity,double _price){
        id=_id;
        name=_name;
        quantity=_quantity;
        price=_price;

    };
    int getid(){
        return id;
    };

    string getname(){
        return name;
    };
    int getquantity(){
        return quantity;
    };
    int getprice(){
        return price;
    }
    int gettotal(){
        return price*quantity;
    }


};

class inventory{
    static const int MAX_ITEMS =100;
    item items[MAX_ITEMS];
    int itemcount;
    public:
    inventory(){
        itemcount=0;
    };

    //add items
    void additem(item newitem){
        if(itemcount < MAX_ITEMS){
            items[itemcount++]=newitem;
        }else{
            cout<<"inventory is full";
        }

    };

    //remove item
    void removeitem(int id){
        for(int i=0;i<itemcount;++i){
            if(items[i].getid() == id){
                for(int j=i;j<itemcount-1;j++){
                    items[j]=items[j+1];
                }
                itemcount--; //decrement of itemcount after remove one item
                break;
            }

        }
    };

    //update item
    void updateitem(int id, int quantity){
         for(int i=0;i<itemcount;++i){
            if(items[i].getid() == id){
                items[i]= item(items[i].getid(),items[i].getname(),quantity,items[i].getprice());
                break;
            };

         }
        
    };

    //display items
    void displayitem(){
         cout << "Inventory:\n";
        cout << "ID\tName\t\tQuantity\tPrice\tTotalprice\n";
        for(int i=0;i<itemcount;i++){
            cout<<items[i].getid()<<"\t"<<items[i].getname()<<"\t\t"<<items[i].getquantity()<<"\t"<<items[i].getprice()<<"\t"<<items[i].gettotal();
            cout<<"\n--------------------------------------------------------------------------\n";
            
        }
    }
    

};

int main(){
    inventory i;

    int choice;
    

    //create menu driven system
    do{
        //define 
        cout<<"\n------------------------------------------\n";
        cout<<"        INVENTORY MANAGEMENT SYSTEM       \n";
        cout<<"------------------------------------------\n";
        cout<<"1.Add items\n";
        cout<<"2.Remove items\n";
        cout<<"3.Update items\n";
        cout<<"4.Display items\n";
        cout<<"5.Exit\n";
        cout<<"********************************************\n";

        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice) {
             case 1:{ int id,quantity;
                double price;

                string name;
                cout<<"Enter item id : \n";
                cin>>id;
                cout<<"Enter item name : \n";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter quantity : \n";
                cin>>quantity;
                cout<<"Enter price of per item : \n";
                cin>>price;
                item newitem(id,name,quantity,price);
                i.additem(newitem);
                break;
                }
            case 2:{
                   int id;
                   cout<<"Enter id of item to remove :";
                   cin>>id;
                   i.removeitem(id);
                   break;
            }
            case 3:{
                   int id,quantity;
                   cout<<"Enter id of item to update : ";
                   cin>>id;
                   cout<<"\nEnter updated no. of quantity : ";
                   cin>>quantity;
                   i.updateitem(id,quantity);
                   break;

            }
            case 4:{
                i.displayitem();break;
            }
            case 5:cout<<"Exiting..../n";break;

            default:cout<<"invalid choice! Try again";
                 break;




        
        }


    }while(choice != 5);

    return 0;
}
