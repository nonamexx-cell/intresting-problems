#include <bits/stdc++.h>

using namespace std;
int falg = 0;
int isvalid(vector<vector<int>> &tic)
{
    if(tic[0][0] == tic[0][1] && tic[0][0] == tic[2][0] && tic[0][0] != 0)
    {
        return tic[0][0];
    }
    else if(tic[0][0] == tic[0][1] && tic[0][0] == tic[0][2] && tic[0][0] != 0)
    {
        return tic[0][0];
    }
   else if(tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2] && tic[0][0] != 0)
    {
        return tic[0][1];
    }
   else if(tic[0][1] == tic[1][1] && tic[1][1] == tic[2][0] && tic[2][0] != 0)
    {
        return tic[0][0];
    }
   else if(tic[0][2] == tic[1][2] && tic[2][2] == tic[1][2] && tic[2][2] != 0)
    {
        return tic[0][2];
    }
   else if(tic[0][2] == tic[1][1] && tic[1][1] == tic[2][0] && tic[2][0] != 0)
    {
        return tic[2][0];
    }
   else if(tic[1][0] == tic[1][1] && tic[1][1] == tic[1][2] && tic[1][0] != 0)
    {
        return tic[1][0];
    }
   else if(tic[2][0] == tic[2][1] && tic[2][1] == tic[2][2] && tic[2][2] != 0)
    {
        return tic[2][0];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tic[i][j] == 0)
            return 0;
        }
    }
    return 3;
}

int main()
{
	cout<<"Hello"<<endl;
    vector<vector<int>> tic(3,vector<int>(3,0));
    
    int r,c;
    
    for(int i=0 ; ;i++)
    {
         cin>>r>>c;
        if(i%2 == 0)
           {
			   while(r>2 || r<0 || c>2 || c<0 || tic[r][c] != 0 )
			   {
				   cout<<"NOt Valid :( please enter Valid indices"<<endl<<endl;
				   cin>>r>>c;
			   }
			      tic[r][c] = 1;
			 
		   }
        else
        {
			   while(r>2 || r<0 || c>2 || c<0 || tic[r][c] != 0 )
			   {
				   cout<<"NOt Valid :( please enter Valid indices"<<endl<<endl;
				   cin>>r>>c;
			   }
			      tic[r][c] = 2;
			 
		   }
          
          
        int k =isvalid(tic);
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<tic[i][j]<<" ";
            }
            cout<<endl;
        }
       cout<<endl;
        if(k != 0)
        {
            if(k == 1)
            {
                cout<<"The Winner is A"<<endl;
            }
            else if(k == 2) 
            {
                cout<<"The Winner is B"<<endl;
            }
            else
             {
                 cout<<"The Match is draw :)"<<endl;
             }
             break;
        }

        
    }
    
    
    return 0;
    
}
