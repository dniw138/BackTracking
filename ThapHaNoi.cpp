#include<iostream>
using namespace std;

int step = 1;

void SSThapHN(int n,int col1,int col2,int col3)
{
    if(n==1)
    {
        cout<<"Buoc "<<step<<": chuyen 1 dia tu cot "<<col1<<" sang cot "<<col3<<endl;
        step++;
        return;
    }
    else
    {
        SSThapHN(n-1,col1,col3,col2);
        SSThapHN(1,col1,col2,col3);
        SSThapHN(n-1,col2,col1,col3);
    }
}

int main()
{
    SSThapHN(4,1,2,3);
    return 0;
}