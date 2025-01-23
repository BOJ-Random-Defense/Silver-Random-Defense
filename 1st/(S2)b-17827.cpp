#include <iostream>
using namespace std;
int N, M, V;
int arr[202020];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    cin >> N >> M >> V;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    while(M--){
        int find; 
        cin >> find;
        if(find < (V-1)){
            cout << arr[find] << "\n";
        }
        else{
            int index = (find-(V-1))%(N-V+1);
            cout << arr[V-1+index] << "\n";
        }
    }
    return 0;
}