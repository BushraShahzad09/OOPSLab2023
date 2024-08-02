// matrix multiplication

#include <iostream>
using namespace std;
class matrix{
    public:
    int arr1[20][20];
    int arr2[20][20];
    int ans[20][20];
   
    int row1;
    int col1;
    int row2;
    int col2;
  //  vector<vector<int>>mat(row,vector<int>(col,0));
   
   void multiply()
   {
       for(int i=0;i<row1;i++)
       {
           for(int j=0;j<col2;j++)
           {
              
               for(int k=0;k<row2;k++)
               {
                  ans[i][j]+=arr1[i][k]*arr2[k][j];
               }
           }
       }
   }
   void print()
   {
       for(int i=0;i<row1;i++)
       {
           for(int j=0;j<col2;j++)
           {
              
               cout<<ans[i][j]<<" ";
           }
           cout<<"\n";
       }
       
   }
   void get1()
   {
       for(int i=0;i<row1;i++)
       {
           for(int j=0;j<col1;j++)
           {
              
               cin>>arr1[i][j];
           }
          
       }
       
   }
   void get2()
   {
       for(int i=0;i<row2;i++)
       {
           for(int j=0;j<col2;j++)
           {
              
               cin>>arr2[i][j];
           }
           
       }
       
   }
   
};
int main() {
   
    cout << "Hello world!";
    matrix* m=new matrix;
    cout<<"\nEnter row of matrix 1: ";
    cin>>m->row1;
     cout<<"\nEnter col of matrix 1: ";
    cin>>m->col1;
     cout<<"\nEnter row of matrix 2: ";
    cin>>m->row2;
     cout<<"\nEnter row of matrix 2: ";
    cin>>m->col2;
    
    if(m->col1!=m->row2)
        cout<<"Matrix multiplication not possible";
    m->get1();
    m->get2();
    m->multiply();
    m->print();
    

    return 0;
}