#include <bits/stdc++.h>

using namespace std;

struct Points
{
   float x;
   float y;
   int val;
};
map<pair<float,float>,float> mpd;

map<pair<float,float>,float> mpa;

double findAngle(float x1,float y1,float x2,float y2,float x3,float y3)
{
      double tempslope1 = (atan2(y1 - y2,y1 - y2)*180) / 3.14;
       if(tempslope1 < 0)
            tempslope1 = 360+tempslope1;
        
       double  tempslope2 = (atan2(y1 - y2,y1 - y2)*180) / 3.14;
       if(tempslope2 < 0)
            tempslope2 = 360+tempslope2;
            
        cout<<tempslope2-tempslope1<<endl;
        
     return tempslope2-tempslope1;

}

bool call(struct Points p1, struct Points p2)
{
    //cout<<"atleast i am called"<<endl;
    
    //if(mpa[{p1.x,p1.y}] > mpa[{p1.x,p1.y}])
      if (mpa[{p1.x,p1.y}] < mpa[{p2.x,p2.y}])
              return true;
      else if(mpa[{p1.x,p1.y}] == mpa[{p2.x,p2.y}])
         return (mpd[{p1.x,p1.y}] > mpd[{p2.x,p2.y}]);
      else
         return false;
    
}

int main()
{
    int n;
    cin>>n;
    
    vector<struct Points>  p(n);
    float xv,yv;
    float centerx =0,centery=0;
    for(int i=0;i<n;i++)
    {
         cin>>xv>>yv;
         centerx  = centerx+xv;
         centery  = centery+yv;
         p[i].x = xv;
         p[i].y = yv;
    }
    
    centerx = centerx/n;
    centery = centery/n;
    
    vector<float> dist(n,0);
    
    
    
    for(int i=0;i<n;i++)
     {
         dist[i] = (p[i].x - centerx)*(p[i].x - centerx) + (p[i].y - centery)*(p[i].y - centery);
         
         mpd[{p[i].x,p[i].y}]  = dist[i];
     }
     
     
    vector<float> ang(n,0);
     
     float tempslope;
    for(int i=0;i<n;i++)
    {
        tempslope = (atan2(p[i].y - centery,p[i].x - centerx )*180) / 3.14;
        //tempslope *= -1;
        
        // cout<<p[i].x<<" "<<p[i].y<<" "<<"angle is"<<ang[i]<<endl;
        
        //tempslope = 180 - tempslope;
        
        if(tempslope < 0)
            tempslope = 360+tempslope;
        ang[i] = tempslope;
        
       // cout<<p[i].x<<" "<<p[i].y<<" "<<"angle is"<<ang[i]<<endl;
        
        mpa[{p[i].x,p[i].y}]  = ang[i];
        
    }
    

   sort(p.begin(),p.end(),call);
   
    for(int i=1;i<p.size();i++)
     {
         if(mpa[{p[i].x,p[i].y}] == mpa[{p[i-1].x,p[i-1].y}])
            p.erase(p.begin()+i);
     }
     
     n = p.size();
   for(int i=0;i<=n;i++)
    {
        cout<<p[i].x<<" "<<p[i].y<<endl;
    } 
    cout<<"--------------------------------"<<endl; 
    stack<int> st;
    st.push(0);
    st.push(1);
    int q = 0;
    int r,s;
    for(int i=2;i<n;i++)
    {
        r = st.top();
        s = i;
        double val = findAngle(p[q].x,p[q].y,p[r].x,p[r].y,p[s].x,p[s].y);
        //double val = findAngle(1,0,1,1,0,1);
        if(val<180)
        {
            st.pop();
            st.push(i);
        }
        else
        {
            q = st.top();
            st.push(i);
        }
    }
    
    
   /*// cout<<q<<endl;
    cout<<p[q].x<<" "<<p[q].y<<endl;
   // cout<<s<<endl;
    cout<<p[s].x<<" "<<p[s].y<<endl;
   // cout<<r<<endl;
    cout<<p[r].x<<" "<<p[r].y<<endl;
    while(!st.empty())
    {
        cout<<p[st.top()].x<<" "<<p[st.top()].y<<endl;
        
        st.pop();
    } */
    
    
}
