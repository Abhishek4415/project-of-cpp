#include<iostream>
#include<stdlib.h>
using namespace std;
void calculatecgpa();
void calculategpa();

int main(){
    system("cls");
     sub:

     int input;
     cout<<"------------------------------------------------------"<<endl;
     cout<<"        CGPA CALULATOR (DEVELOP BY ABHISHEK)          "<<endl;
     cout<<"-----------------------------------------------------"<<endl;

     cout<<"MENU:"<<endl;
     cout<<"                   1.calculate gpa"<<endl;
     cout<<"                   2.calculate cgpa"<<endl;
     cout<<"                   3.exit"<<endl;
     cout<<"choose an option:";
     cin>>input;
     switch(input){
        case 1:calculategpa();break;
        case 2:calculatecgpa();break;
        case 3:exit(EXIT_SUCCESS);break;
        default:cout<<"you have enter wronog input.try again";
            goto sub;break;

     };

    goto sub;
    

}

 void calculategpa(){
    int q;
    cout<<"how many subject point do you want to calculate:";
    cin>>q;

    float point[q];
    float credit[q];

    cout<<endl;
    for(int i=0;i<q;i++){
        cout<<"Enter the credit for the subject "<<i+1<<":"<<endl;
        cin>>credit[i];
        cout<<"Enter the point for the subject "<<i+1<<":"<<endl;

        cin>>point[i];
        cout<<"----------------------------------------------"<<endl;

    };
    float mul;
    float tpoint=0;
    for(int i=0;i<q;i++){
        mul=point[i]*credit[i];
        tpoint=tpoint+mul;

    }
    // cout<<tpoint;
    float tcredit=0;
    for(int i=0;i<q;i++){
        tcredit=tcredit+credit[i];
    };
    cout<<tcredit;

    cout<<"\n\n Total Point:"<<tpoint<<".Total credit:"<<tcredit<<".Total GPA :"<<tpoint/tcredit<<" ."<<endl;



};

void calculatecgpa(){
    system("cls");
    int s;
    cout<<"------------calulate CGPA-----------"<<endl;
    cout<<"HOW many semester result do you want input? : ";
    cin>>s;

    float sem[s];
    for(int i=0;i<s;i++){
        cout<<"Enter semester "<<i+1<<"result(GPA):";
        cin>>sem[i];
        cout<<endl;
    }
    float semtot=0;
    for(int i=0;i<=s;i++){
        semtot=semtot+sem[i];
    };

    cout<<"***********your CGPA IS :"<<semtot/s<<"**********"<<endl;


}