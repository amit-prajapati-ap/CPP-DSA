#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> maxMeetings(int N,vector<int> S,vector<int> F) {
        vector<int> ans;
        vector<pair<pair<int,int>,int > > v;
        for(int i = 0 ; i < N ; i++) {
            v.push_back({{F[i],S[i]},i+1});
        }
        sort(v.begin(),v.end());
        ans.push_back(v[0].second);
        int ansEnd = v[0].first.first;
        for(int i = 1 ; i < N ; i++) {
            if(v[i].first.second > ansEnd) {
                ans.push_back(v[i].second);
                ansEnd = v[i].first.first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
}
void input(int &n,vector<int> &start,vector<int> &end) {
    cout<<"Enter The Number Of Meetings in Room : ";
    cin>>n;
    cout<<"Enter The Start Time Of Each Meeting : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        int data;
        cin>>data;
        start.push_back(data);
    }
    cout<<"Enter The End Time Of Each Meeting : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        int data;
        cin>>data;
        end.push_back(data);
    }
}
void output(int &n,vector<int> &start,vector<int> &end) {
    cout<<"Printing The Start Time Of Each Meeting : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        cout<<start[i] << ' ';
    }
    cout<<endl;
    cout<<"Printing The End Time Of Each Meeting : "<<endl;
    for(int i = 0 ; i < n ; i++) {
        cout<<end[i] << ' ';
    }
    cout<<endl;
}
void print(vector<int> ans) {
    cout<<"Printing The Positions : "<<endl;
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i] <<' ';
    }
    cout<<endl;
}
int main()
{
    int n;
    vector<int> start,end;
    input(n,start,end);
    output(n,start,end);
    vector<int> ans = maxMeetings(n,start,end);
    print(ans);
}