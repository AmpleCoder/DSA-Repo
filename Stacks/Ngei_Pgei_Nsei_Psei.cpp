vector<int> ngei(vector<int> &a)
{
    int size=a.size(),i;
    vector<int> ans(size);
    stack<int> s;
    ans[size-1]=size;
    s.push(size-1);
    
    for(i=size-2;i>=0;i--)
    {
        while(s.size()>0 && a[i]>=a[s.top()])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            ans[i]=size;
        }
        
        else
        {
            ans[i]=s.top();
        }
        
        s.push(i);
    }
    
    return ans;
}
    
vector<int> pgei(vector<int> &a)
{
    int size=a.size(),i;
    stack<int> s;
    vector<int> ans(size);
    ans[0]=-1;
    s.push(0);
    
    for(i=1;i<size;i++)
    {
        while(s.size() > 0 && a[i] >= a[s.top()])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            ans[i]=-1;
        }
        
        else
        {
            ans[i]=s.top();
        }
        
        s.push(i);
    }
    
    return ans;
}

/*
nsei and psei are similar 
*/