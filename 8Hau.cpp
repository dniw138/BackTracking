#include<iostream>
using namespace std;
int sol = 1;

bool Check(int a[],int x,int y)
{
    for(int i=1;i < x;i++)
    {
        if(a[i] == y || i + a[i] == x + y || i - a[i] == x - y)
            return false;
    }
    return true;

void Xuat(int a[],int n){
    cout<<"Cach sap xep thu "<<sol<<" la:"<<endl;
    for(int i = 1;i <= n;i++)
    {
        cout<<i<<" "<<a[i]<<endl;
    }
    sol++;
}

void XepHau(int a[],int i,int n)
{
    for(int j=1;j<=n;j++)
    {
        if(Check(a,i,j))
        {
            a[i]=j;
            if(i==n)
            {
                Xuat(a,n);
            }
            else
            {
                XepHau(a,i+1,n);
            }
        }
    }
}

int main()
{
    int a[10];
    int n;
    XepHau(a,1,8);
    return 0;
}