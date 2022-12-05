#include <iostream>
using namespace std;

int a[2][2],b[2][2],c[2][2],i,j;
void strassen(){
    int m1,m2,m3,m4,m5,m6,m7;

    m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
    m2= (a[1][0]+a[1][1])*b[0][0];
    m3= a[0][0]*(b[0][1]-b[1][1]);
    m4= a[1][1]*(b[1][0]-b[0][0]);
    m5= (a[0][0]+a[0][1])*b[1][1];
    m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

    c[0][0]=m1+m4-m5+m7;
    c[0][1]=m3+m5;
    c[1][0]=m2+m4;
    c[1][1]=m1-m2+m3+m6;
}

int main()
{
    cout<<"Enter the 4 elements of first matrix: "<<endl; 
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            cin>>a[i][j];}}

    cout<<"Enter the 4 elements of second matrix: "<<endl; 
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            cin>>b[i][j];}}

    strassen();
    cout<<"The final matrix is: ";
    for(i=0;i<2;i++)
    {
        cout<<endl;
        for(j=0;j<2;j++)
            cout<<c[i][j]<<" ";
    }

    return 0;
}
