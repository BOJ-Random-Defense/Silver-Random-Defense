// BOJ 17129
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
int adj[3030][3030];
bool visited[3030][3030];
int dist[3030][3030];
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    int x, y;
    // 문자열로 받아서 숫자로 바꿔서 집어넣자
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<M;j++){
            if(str[j] == '2'){
                x = i;
                y = j;
            }
            adj[i][j] = str[j]-'0';
        }
    }
    // 1 : 장애물 2 : 출발점 3~5 음식
    visited[x][y] = true;
    q.push({x, y});
    // bfs 시작~
    while(!q.empty()){
        // current 설정
        auto [cx, cy] = q.front();
        q.pop();
        // current가 3, 4, 5인 경우에 반복을 끊고 바로 출력
        if(adj[cx][cy] == 3 || adj[cx][cy] == 4 || adj[cx][cy] == 5){
            cout << "TAK" << "\n" << dist[cx][cy];
            return 0;
        }
        // 탐색 돌리기
        for(int dir=0;dir<4;dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(!visited[nx][ny] && isInIndex(nx, ny, N, M) && 
            (adj[nx][ny] == 0 || adj[nx][ny] == 3 || adj[nx][ny] == 4 ||adj[nx][ny] == 5)){
                visited[nx][ny] = true;
                // 한 depth 더 들어갔기 때문에 거리에 +1 해준다
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    // BFS 다 돌렸는데 안되면
    cout << "NIE";
    return 0;
}
