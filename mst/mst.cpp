#include <bits/stdc++.h>

using namespace std;

#define SQ(x) ((x)*(x))

#define N 18

struct Point {
  int x, y;
};

struct Trio {
  long double d; int a, b;
  bool operator < (const Trio& t) const {
    return d > t.d;
  }
};

long double dist(Point a, Point b) {
  return sqrt(SQ(a.x - b.x) + SQ(a.y - b.y));
}

Point p[N];
string s[N];

int fr[N], h[N];

// find() and join() of Union-Find Algorithm

int find(int x) {
  if (fr[x] == x) return x;
  return fr[x] = find(fr[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  
  if (x == y) return;
  
  if (h[x] > h[y]) swap(x, y);
  
  fr[x] = y;
  
  if (h[x] == h[y]) h[y]++;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); //input and output optimization
  
  //using files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  //-----input reading-----
  
  int n; cin >> n >> ws;
  
  for (int i = 0; i < n; i++) {
    getline(cin, s[i]);
    
    cin >> p[i].x >> p[i].y >> ws;
  }
  
  //-----Kruskal Algorithm-----
  
  priority_queue<Trio> pq;
  
  // generating complete graph
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      pq.push({dist(p[i], p[j]), i, j});
  
  // starting union-find
  for (int i = 0; i < n; i++) 
    fr[i] = i, h[i] = 0;
  
  int cnt = 0; //number of vertices added in the MST
  long double w = 0.; //total weight of the mst
  vector<pair<int, int>> edges; //edge added in MST
  
  while (!pq.empty()) {
    Trio x = pq.top(); pq.pop();
    
    if (find(x.a) != find(x.b)) {
      join(x.a, x.b);
      
      cnt++;
      w += x.d;
      
      edges.push_back({x.a, x.b});
      
      if (cnt == n) break;
    }
  }
  
  w *= 2.65; // pixel to km conversion
  
  //-----printing output-----
  
  cout << "Distancia MST: " << w << "Km" << '\n';
  cout << "Arestas:" << '\n';
  
  for (auto x : edges)
    cout << "(" << s[x.first] << ", " << s[x.second] << ")\n";
}
