/*
    최단거리 알고리즘 구현이 아무것도 생각나지 않는데
    깊이가 그렇게 깊지 않아서 단순히 거리배열로 해서
    6보다 거리가 커지는 경우 탈출조건 걸고,
    만약에 방문 못하는 경우가 생길 수 있으니 이때도
    탈출조건 걸어주고 전부 다 통과하는 경우에는 small world
    
    풀이가 너무 naive 해서 데이터가 커지면 터질 가능성 높음!
    다익스트라나 플로이드 워셜 짜면 되겠는데 아무래도 
    플로이드 워셜 쪽이 시간복잡도에서 이득을 많이 보니깐
    이부분으로 업솔빙 해보면 될듯
*/
#include<iostream>
#include<queue>
using namespace std;
bool visited[105]; // 방문 체크 배열
int arr[105][105]; // 인접행렬로 해도 메모리 및 시간 문제 안생길 것 같았음
int dist[105]; // 거리 저장할 녀석
queue<int> q;
int main(){
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    // 인접행렬 처리
    for(int i=0;i<K;i++){
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;
        arr[end][start] = 1;
    }
    // BFS
    for(int i=1;i<=N;i++){
        // 배열 초기화
        fill(visited, visited + 105 , false);
        fill(dist, dist + 105 , -1);
        q.push(i);
        visited[i] = true;
        dist[i] = 0;
        int cnt = 0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            for(int j=1;j<=N;j++){
                if(arr[current][j] == 1 && !visited[j]){
                    visited[j] = true;
                    dist[j] = dist[current] + 1;
                    // 이렇게 보니 cnt 보다는 depth같은게 좀 맞았을지도
                    cnt = max(cnt, dist[j]);
                    q.push(j);
                    if(cnt > 6){
                        cout << "Big World!";
                        return 0;
                    }
                }
            }
        }
        for(int j=1;j<=N;j++) {
            if(dist[j] == -1) {
                cout << "Big World!";
                return 0;
            }
        }
    }
    cout << "Small World!";
    return 0;
}