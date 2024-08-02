//Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<conio.h>
using namespace std;
class removeDuplicates{
    public:
  string s;
  vector<string> ans;
  void input(){
      cout<<"enter the string"<<endl;
      getline(cin,s);
  }
  void duplicates(){
      string output="";
      for(int i=0;i<s.length();i++){
          if(s[i]==' '){
              if(find(ans.begin(),ans.end(),output) != ans.end()){
                  output="";
              }
              else{
              ans.push_back(output);
              output="";
          }
          }
          else{
              output +=s[i];
          }
      }
         cout<<"\nNew string is : \n";
      for(int i=0;i<ans.size();i++){
          cout<<ans[i]<<" ";
      }

  }
  void reverse(){
         cout<<"\nReversed string is : \n";
      stack<char> st;
      for(int i=0;i<s.length();i++){
          if(s[i]!=' '){
              st.push(s[i]);
          }
          else{
              while(st.empty()==false){
                  cout<<st.top();
                  st.pop();
              }
              cout<<" ";
          }
      }
       while(st.empty()==false){
                  cout<<st.top();
                  st.pop();
              }

  }

};
int main() {
    // Write C++ code here
    removeDuplicates abc;
    abc.input();
    abc.duplicates();
    abc.reverse();
    getch();
    return 0;
}

