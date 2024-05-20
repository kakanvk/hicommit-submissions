#include <bits/stdc++.h>

using namespace std;

//0 1 1 2 3 5 8 13 21 34 55 89 144 233
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

long long multi (long long a, long long b, long long m) {
	if (b==0) return 0;
	long long t = multi (a, b/2, m) % m;
	if (b % 2 == 1) {
		return ((t+t)%m+a%m)%m;
	}
	else {
		return (t+t)%m;
	}
}

void matrix_multiplication(long long A[2][2], long long B[2][2], long long M) {
  long long C[2][2];
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      C[i][j] = 0;
      for (long long k = 0; k < 2; k++) {
        C[i][j] += multi (A[i][k], B[k][j], M);
        C[i][j]%=M;
      }
    }
  }
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      A[i][j] = C[i][j];
    }
  }
}

long long fib(long long n, long long m) {
  if (n <= 1) {
    return n;
  }
  long long F[2][2] = {{1, 1}, {1, 0}};
  long long result[2][2] = {{1, 0}, {0, 1}};
  while (n > 0) {
    if (n % 2 == 1) {
      matrix_multiplication(result, F, m);
    }
    matrix_multiplication(F, F, m);
    n /= 2;
  }
  return result[0][1];
}

void solve () {
	long long a, b, m, k;
	cin >> a >> b >> m;
	k = __gcd(a, b);
	cout << fib(k, m) << endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	solve();
	return 0;
	// test
}