#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fin(10,(vector<int>(10,0)));
vector<vector<int>> sudo(10,(vector<int>(10,0)));
int temp = 0;
int check()
{
     for(int i=1;i<=9;i++)
     {
         for(int j=1;j<=9;j++)
         {
              if(sudo[i][j] == 0)
               return 0;
         }
     }
   return 1; 
}
vector<int> isvalid(int r, int c)
{
     vector<int> vec(10,0);
    for(int i=1;i<=9;i++)
        vec[sudo[r][i]]++;
    for(int i=1;i<=9;i++)
         vec[sudo[i][c]]++;
    
    int start,end;
    if( r<= 3)
      start = 1;
    else if(r<=6)
       start = 4;
    else
      start = 7;
    if( c<= 3)
      end = 1;
    else if(c<=6)
       end = 4;
    else
      end = 7;
    
    for(int i=start;i<=start+2;i++)
    {
        for(int j=end;j<=end+2;j++)
        {
             vec[sudo[i][j]]++;
        }
    }
 vector<int> ans;
  for(int i=1;i<=9;i++)
     if(vec[i] == 0)
        ans.push_back(i);
 return ans;
}

void solve()
{
    int p = 1;
    if(temp == 1)
       return  ;
    if(check())
      {
          for(int i=1;i<=9;i++)
          {
              for(int j=1;j<=9;j++)
              {
                 cout<<sudo[i][j]<<" ";
              }
              cout<<endl;
          }
          temp = 1;
          return ;
      }
    int j,k;
        for( j=1;j<=9;j++)
        {
            p = 1;
            for( k=1;k<=9;k++)
            {
                p =1;
                if(sudo[j][k] == 0)
                { 
                    p = 0;
                     break;
                }
            }
            if(p == 0)
             break;
        }
  if(p == 0)
  {
      vector<int> valids = isvalid(j,k);
         if(valids.size() == 0)
             return ;
        for(auto x: valids)
            {
                sudo[j][k] = x;
                 solve();
             if(temp == 0)
                sudo[j][k] = 0;
            }                         
  }

 return ;
}

int main()
{
      
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
         {
             cin>>sudo[i+1][j+1];
             fin[i+1][j+1] = sudo[i+1][j+1];
         }
     }
       solve();
     
    /*for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
          cout<<sudo[i][j]<<" ";
       cout<<endl;
    }*/
    
    //cout<<temp<<endl;
     
}
