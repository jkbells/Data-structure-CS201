
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

// #defing int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

priority_queue<int,vi, greater<int> > pqmin;
priority_queue<int,vi> pqmax;

void insert(int x)
{
    if(pqmin.size() == pqmax.size())
    {
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        if(x < pqmax.top()){
            pqmax.push(x);
        }else{
            pqmin.push(x);
        }
    }
    else{
        {
            // two cases possible
            // case 1: size of maxheap > size of minheap
            // case 2: size of minheap > size of maxheap

            if(pqmax.size() > pqmin.size()){
                if(x >= pqmax.top()){
                    pqmin.push(x);
                }else{
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            }
            else{
                if(x<= pqmin.top()){
                    pqmax.push(x);
                }else{
                    int temp = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }
}

double findmedian()
{
    if(pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top())/2.0
    }
    else if(pqmax.size()>pqmin.size())
    {
    return pqmax.top();
    }
    else 
    {
        return pqmin.top();
    }
}


signed main()
{
    insert(10);
    cout << findmedian() << endl;
    return 0;
}