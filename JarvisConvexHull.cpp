#include <bits/stdc++.h>
#include <iostream>
using namespace std;
  
struct Points
{
    float x;
    float y;
    int vis;
};

int main() 
{
    
    int n; // number points in data;
    cin>>n;
     
   struct Points p[n];
   float first;
   float second;
    int mini = 0;
    int maxi  = 0;
   for(int i=0;i<n;i++)       // takes input.
   {
       cin>>first>>second;
       
       p[i].x = first;
       p[i].y = second;
       if(p[mini].y > p[i].y)
       {
           mini= i;
       }
       else if(p[mini].y == p[i].y)
       {
           if(p[mini].x > p[i].x)
                  mini = i;
       }
       if(p[maxi].x < p[i].x)
       {
           maxi= i;
       }
       else if(p[maxi].x == p[i].x)
       {
           if(p[maxi].y < p[i].y)
                  maxi = i;
       }
       p[i].vis = 0;
   }
   
   p[mini].vis = 1;
 stack<int> st;
 st.push(mini);
 
 int count1 =1;
   
   float slope = INT_MAX;
   float tempslope;
int q;
int flag = 0;
while(count1 != 0)
   {

       count1 = 0;
       slope = INT_MAX;
       int r = st.top();
       int index;
       for(int i=0;i<n;i++)
       {
           if( i !=  r && i != q && (p[i].vis == 0 || i == mini) )
           {
               
               if(flag == 0)
               {
                   tempslope = (atan2(p[r].y - p[i].y, p[r].x - p[i].x)*180) / 3.14;
                   tempslope *= -1;
                      tempslope = 180 - tempslope;
                    if(tempslope >= 359.99)
                       tempslope =0;
               }
               else
               {
                   tempslope = (atan2(p[r].y - p[i].y, p[r].x - p[i].x)*180) / 3.14;
                   tempslope *= -1;
                   tempslope = 180-tempslope;
                   if(tempslope < 180)
                     tempslope = 360-tempslope;
                      
               }

             if(tempslope<slope)
             {
                  slope = tempslope;
                 index = i;
                 count1++;
             }
             else if(slope == tempslope)
             {
                  if(p[index].y > p[i].y)
                     {
                         index = i;
                         count1++;
                     }
             }
           }

       }
           if(count1 > 0)
           {
                if(index == mini)
                    break;
                 q = r;
               st.push(index);
               p[index].vis = 1;
               if(r == maxi)
                  flag = 1;
           }


   }     
   
  /* if(n <= 3)
   {
       for(int i=0;i<n;i++)
       {
           cout<<p[i].x<<" "<<p[i].y<<endl;
       }
       return 0;
   } */

/* int r = mini;

 for(int i=0;i<n;i++)
  {
      float slope = (atan2(p[r].y - p[i].y, p[r].x - p[i].x)*180) / 3.14;
      slope *= -1;
           slope = 180 - slope;
      cout<<slope<<" "<<p[i].x<<" "<<p[i].y;
      cout<<endl;
  }
 */
  /* slope = (atan2( -1,-1)*180) / 3.14;
      slope = -1*slope;
           slope = 180 - slope;
        cout<<"slope "<<slope<<endl;*/
    
    cout<<"ConvexHull contains "<<st.size()<<" number of edges"<<endl;
    
    cout<<p[mini].x<<" "<<p[mini].y<<endl;
    
 while(!st.empty())
 {
     cout<<p[st.top()].x<<" "<<p[st.top()].y<<endl;
     st.pop();
 }



	return 0;
}


//Second method to find ConvexHull and watch computational Geometry lectures.
