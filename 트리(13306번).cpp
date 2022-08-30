#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, pair<int, int>> pi;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define X first
#define Y second
 
//------------------------------
 

// 문제풀이 링크 : https://cat-holic0713.tistory.com/2
 
vector<string> ans;
vector<pi> query;
int p[200100], v[200100];
 
int find(int a) {
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}
 
void merge (int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b) return;
 
    p[a] = b;
 
}
 
 
 
int main () {
    int n, m, q;
    cin >> n >> m;
    q = n+m;
    
    // i+1 번째 쿼리의 부모를 입력받음
    for (int i = 2; i <= n; i++) {
        cin >> v[i];
    }
    // 쿼리를 반대로 받기 위해 저장
    for (int i = 0; i < q; i++) {
        int x, a, b;
        cin >> x;
        if (x == 0) {
            cin >> a;
            query.push_back({x, {a, 0}});
 
        }
        else {
            cin >> a >> b;
            query.push_back({x, {a, b}});
            
            
        }
    }
    // 유파 초기화
    for (int i = 1; i <= n; i++) p[i] = i;
    // 쿼리 시작
    
    reverse(query.begin(), query.end());
 
    for (auto i : query) {
        
        if (i.X == 0) {
            merge(i.Y.X, v[i.Y.X]);
        }
        if (i.X == 1) {
            if(find(i.Y.X) == find(i.Y.Y)) ans.push_back("YES");
            else ans.push_back("NO");
        }
 
    }
    
    // 반대로 돌려줌
    reverse(ans.begin(), ans.end());
 
    for (auto i : ans) cout << i << endl;
    
 
 
    
    
 
 
}
