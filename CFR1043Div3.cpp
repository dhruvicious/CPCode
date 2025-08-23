#include <iostream>
#include <string>
using namespace std;

void sim(string& a, string& b, string& c, int m, string& result){
    for(int i =0;i<m;i++){
        if(c[i]=='V'){
            result=b[i]+result;
        }else{
            result=result+b[i];
        }
    }
}


int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n ,m;
        string a, b, c;
        cin>>n;
        cin>>a;
        cin>>m;
        cin>>b>>c;
        string result=a;
        sim(a,b,c,m,result);
        cout<<result<<'\n';
    }
    return 0;
}