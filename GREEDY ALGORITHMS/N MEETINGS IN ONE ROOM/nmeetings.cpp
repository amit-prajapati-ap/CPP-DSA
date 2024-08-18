#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pair pair<int,int>
static bool cmp(pair a,pair b) {
    return a.second < b.second;
}
int maxMeetings(int n,vector<int> &start,vector<int> &end) {
    vector<pair> v;
    for(int i = 0 ; i < n ; i++) {
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),cmp);
    int count = 1;
    int ansend = v[0].second;
    for(int i = 1 ; i < n ; i++) {
        if(v[i].first > ansend) {
            count++;
            ansend = v[i].second;
        }
    }
    return count;
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
int main()
{
    int n;
    vector<int> start,end;
    input(n,start,end);
    output(n,start,end);
    cout<<"Maximum Number Of Meeting In One Room : "<<maxMeetings(n,start,end)<<endl;
}