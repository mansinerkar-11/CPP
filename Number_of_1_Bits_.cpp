//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int cnt=0;
        while(N){
            if(N&1)
                cnt++;
            N>>=1;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {{
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends