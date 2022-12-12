#include<iostream>
using namespace std;

class diagonal{
    private:
    int n;
    int *a;
public:
diagonal(int n){
    this->n=n;
    a=new int [n];
}
void set(int ,int,int );
int get(int, int);
void display();
};
void diagonal::set(int i,int j,int x){
    if (i==j){
        a[i-1]=x;
    }
}

int diagonal::get(int i,int j){
    if(i==j)
    return this->a[i-1];
}
void diagonal::display(){
    
    for(int i=0;i<n;i++){
        
            for(int j=0;j<n;j++){
            if( i==j){
                cout<<a[i-1]<<"\t";
            }
            else{
                cout<<"0";
            }
            }
            cout<<endl;
    }
}
int main()
{

    int d;
cout<<"Enter Dimensions";
cin>>d;
diagonal dm(d);
int x;
cout<<"Enter All Elements";
for(int i=1;i<=d;i++)
{
for(int j=1;j<=d;j++)
{
cin>>x;
dm.set(i,j,x);
}
}
dm.display();
    return 0;
}