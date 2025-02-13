/*
    DP를 쓸 수 없는 이유
    고정된 칸을 이동하는 것이 아니기 때문에
    전 단계에서 몇번을 통해서 왔더라도 다음에 어디로 갈 지
    확실하지 않은 상황이기 때문에 불가함 
    ^ 이거 때문에 1시간 고민했네요..
*/
#include<iostream>
#include<queue>
using namespace std;
int arr[101010];
bool visited[101010];
bool isInIndex(int i, int N){
    return i > 0 && i <= N;
}
queue<pair<int,int>> q;
int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    int start, end;
    cin >> start >> end;
    q.push({start, 0}); // 시작점과 이동횟수를 queue에 저장
    visited[start] = true;
    int ans = -1;
    while(!q.empty()){
        int current = q.front().first;
        int time = q.front().second;
        int dist = arr[current];
        q.pop();
        if(current == end){
            ans = time;
            break;
        }
        // 문제를 잘 읽어보면 양쪽으로 다 이동할 수 있음을 알 수 있다.
        // 그렇기 때문에 증가하는 방향 뿐만 아니라
        // 감소하는 방향도 고려해야 한다.
        for(int i=1;isInIndex(current + dist * i, N);i++){
            int next = current+dist*i;
            if(!visited[next]){
                visited[next] = true;
                q.push({next, time + 1});
            }
        }
        for(int i=1;isInIndex(current - dist * i, N);i++){
            int next = current-dist*i;
            if(!visited[next]){
                visited[next] = true;
                q.push({next, time + 1});
            }
        }
    }
    cout << ans;
    return 0;
}