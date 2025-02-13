#include<iostream>
#include<queue>
using namespace std;
int arr[101010];
bool visited[101010];
bool isInIndex(int i, int N){
    return i > 0 && i <= N;
} // 범위 체크하는 함수
queue<int> q;
int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    } // 번호가 존재하기 때문에 1-BY INDEX로 
    int cnt = 0;
    int start;
    cin >> start; // 출발지점

    q.push(start);
    visited[start] = true;
    cnt++; // 출발지점은 무조건 방문하기 때문에 +1
    
    while(!q.empty()){ // BFS 진행
        int current = q.front();
        q.pop();
        /*
            앞으로 갈수도 있고 뒤로 갈수도 있기 때문에
            두가지 형태로 세팅하면 된다
            결국 돌다리에서 갈 수 있는 거리는 1 이상이기 때문에
            반드시 +1이나 -1 방향으로 이동 할 수 있다.

            DP를 사용할 필요가 없는 이유는 앞으로도 가고 뒤로도 가는 것도 있으며
            방문한 곳의 횟수이기 때문에 DP 문제가 아니다
        */
        int fwd = current + arr[current];
        int bck = current - arr[current];
        // 앞으로 가는 경우
        if(isInIndex(fwd, N) && !visited[fwd]) {
            visited[fwd] = true;
            q.push(fwd);
            cnt++;
        }
        // 뒤로 가는 경우
        if(isInIndex(bck, N) && !visited[bck]) {
            visited[bck] = true;
            q.push(bck);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}