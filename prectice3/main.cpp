#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,Q;
    while (cin>>n>>Q){
        priority_queue<int> item;
        for(int i=0;i<n;i++){
            int input;
            cin>>input;
            item.push(input);
        }
        vector<int>box;
        box.push_back(Q);
        while(!item.empty()){
            sort(box.begin(),box.end());
            bool have=0;
            for(auto i=box.begin();i!=box.end();i++){
                if(*i>=item.top()){
                    *i-=item.top();
                    item.pop();
                    have=1;
                    break;
                }
            }
            if(!have){
                box.push_back(Q-item.top());
                item.pop();
            }
        }
        cout<<box.size()<<endl;
    }
    
    return 0;
}