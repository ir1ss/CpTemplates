//头插法链表
int h[N], ne[N], e[N], w[N], idx;
void add(int a, int b, int c) {
  ne[idx] = h[a];
  e[idx] = b;
  w[idx] = c;
  h[a] = idx++;
}
memset(h, -1, sizeof(h));

// dijkstra
int dijkstra() {
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;
  for (int i = 0; i < n - 1; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
      if (!st[j] && (t == -1 || dist[j] < dist[t])) {
        t = j;
      }
    }
    st[t] = true;
    for (int j = 1; j <= n; j++) {
      dist[j] = min(dist[j], dist[t] + e[t][j]);
    }
  }
  return dist[n];
}

// dijkstra + heap
int dijkstra() {
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    auto t = pq.top(); pq.pop();
    int ver = t.second;
    int dis = t.first;
    if (st[ver]) continue;
    st[ver] = true;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dis + w[i]) {
        dist[j] = dis + w[i];
        pq.push({dist[j], j});
      }
    }
  }
  return dist[n];
}

//spfa
int spfa() {
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  st[1] = true;
  while (q.size()) {
    int t = q.front(); q.pop();
    st[t] = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        if (!st[j]) {
          q.push(j);
        }
      }
    }
  }
  return dist[n];
}

//spfa判负环
bool spfa() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
    st[i] = true;
  }
  while (q.size()) {
    auto t = q.front();
    q.pop();
    st[t] = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
          dist[j] = dist[t] + w[i];
          cnt[j] = cnt[t] + 1;
          if (cnt[j] >= n) return true;
          if (!st[j]) {
            q.push(j);
            st[j] = true;
          }
        }
    }
  }
  return false;
}
