//分解质因数
void divide(int x) {
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      int s = 0;
      while (x % i == 0) x /= i, s ++ ;
      cout << i << ' ' << s << endl;
    }
  }
  if (x > 1) cout << x << ' ' << 1 << endl;
  cout << endl;
}

//埃式筛
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
  for (int i = 2; i <= n; i ++ ) {
    if (st[i]) continue;
    primes[cnt ++ ] = i;
    for (int j = i + i; j <= n; j += i)
        st[j] = true;
  }
}

//线性筛
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) primes[cnt ++ ] = i;
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
