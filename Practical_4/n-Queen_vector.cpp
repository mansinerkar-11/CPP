#include <iostream>
#include <vector>
using namespace std;

class Solution{
    vector<int> temp;
    vector<vector<int> > ans; 

    bool safe(int col,int row){
        if(col==1) return true;
        for(int i=0;i<temp.size();i++) {
            int c = i+1,r = temp[i];
            if((r == row) || ((row - r) == (col-c)) || ((col-c == (r-row)))) return false;
        }
        return true;
    }
    void fun(int n,int ctr=1){
        if(ctr>n) ans.push_back(temp);
        for(int i=1;(ctr<=n) &&  i<=n;i++) {
            if(safe(ctr,i))
            {
                temp.push_back(i);
                fun(n,ctr+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int> > nQueen(int n) {
        fun(n);
        return ans;
    }
};
int main(){
        int n;
        cin>>n;
        Solution ob;
        vector<vector<int>  > ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
    return 0;
}
