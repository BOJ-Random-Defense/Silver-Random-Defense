// BOJ 23352
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<map>
#include<set>
using namespace std;
bool isInIndex(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
int adj[55][55];
bool visited[55][55];
int dist[55][55];
queue<pair<int, int>> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> adj[i][j];
        }
    }
    // 거리도 알아야 하고 거리의 양끝값의 합도 알아야 하기 때문에
    // 2개를 설정하고, 데이터 크기가 작기 때문에 브루트 포스로 하고
    // 0인 경우는 벽이니깐 그냥 continue 처리 하면 되겠다 했어요
    int bestDistance = -1;
    int bestSum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(adj[i][j] == 0){
                continue;
            }
            // 매번 세팅해줘야 하기 때문에 
            // 반복 주기 될때마다 초기화 하기.
            // 처음에 이거 안해서 답 안나와서 한참 생각함
            for(int a=0;a<N;a++){
                for(int b=0;b<M;b++){
                    visited[a][b] = false;
                    dist[a][b] = -1;
                }
            }
            // bfs 시작~
            visited[i][j] = true;
            dist[i][j] = 0;
            q.push({i, j});

            while(!q.empty()){
                auto current = q.front();
                q.pop();
                int cx = current.first;
                int cy = current.second;
                for(int dir=0;dir<4;dir++){
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if(!visited[nx][ny] && isInIndex(nx, ny, N, M) && adj[nx][ny] != 0){
                        visited[nx][ny] = true;
                        dist[nx][ny] = dist[cx][cy] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            for(int a=0;a<N;a++){
                for(int b=0;b<M;b++){
                    //dist가 -1인 경우는 손 안댄거니깐 패스
                    if(dist[a][b] == -1){
                        continue;
                    }
                    // 지금 거리랑 지금 sum을 비교해서
                    // 둘 중 큰 놈을 저장하면 되겠다
                    // 같은 경우에는 sum이 큰 놈으로..
                    int curDist = dist[a][b];
                    int curSum = adj[i][j] + adj[a][b];
                    if(curDist > bestDistance){
                        bestDistance = curDist;
                        bestSum = curSum;
                    }
                    else if(curDist == bestDistance){
                        bestSum = max(bestSum, curSum);
                    }
                }
            }
        }
    }
    if(bestDistance < 0){
        cout << 0 << "\n";
    }
    else{
        cout << bestSum << "\n";
    } 
    return 0;
}