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
  }s
}

//线性筛求欧拉函数
int n, primes[N], cnt;
int phi[N];
bool st[N];

void get_eulers() {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      phi[i] = i - 1;
      primes[cnt++] = i;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        phi[primes[j] * i] = phi[i] * primes[j];
        break;
      } else {
        phi[primes[j] * i] = phi[i] * (primes[j] - 1);
      }
    }
  }
}

// 高斯消元
// 返回0：有唯一解
// 返回1：有无穷解
// 返回2: 无解
int n;
double a[N][N];

int gauss() {
  int r, c;
  for (r = 0, c = 0; c < n; c++) {
    int t = r;
    for (int i = r + 1; i < n; i++) {
      if (fabs(a[i][c]) > fabs(a[t][c])) {
        t = i;
      }
    }
    if (fabs(a[t][c]) < eps) continue;
    for (int i = c; i <= n; i++) swap(a[r][i], a[t][i]);
    for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
    for (int i = r + 1; i < n; i++) {
      if (fabs(a[i][c]) > eps) {
        for (int j = n; j >= c; j--) {
          a[i][j] -= a[i][c] * a[r][j];
        }
      }
    }
    r++;
  }
  if (r < n) {
    for (int i = r; i < n; i++) {
      if (a[i][n] > eps) return 2;
    }
    return 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      a[i][n] -= a[i][j] * a[j][n];
    }
  }
  return 0;
}

// 快速幂
int qmi(int a, int b) {
  int ret = 1 % MOD;
  while (b) {
    if (b & 1) {
      ret = 1ll * ret * a % MOD;
    }
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

// 递推求组合数
int n;
int c[N][N];

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j) c[i][j] = 1;
      else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
}

// 逆元求组合数, c[a][b] = (1ll * fact[a] * infact[b] % MOD) * infact[a - b] % MOD;
int n;
int fact[N], infact[N];

void init() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    infact[i] = 1ll * qmi(i, MOD - 2) * infact[i - 1] % MOD;
  }
}
