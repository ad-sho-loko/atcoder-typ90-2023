#include <iostream>
using namespace std;

long long N, L, K;
long long A[1 << 18];

bool isCuttable(int x)
{
  int length = 0;
  int num = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] - length >= x)
    {
      length = A[i];
      num++;
    }
  }

  if (L - length >= x)
    num++;

  return num >= K + 1;
}

int main()
{
  cin >> N >> L >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int left = -1, right = L + 1;
  while (right - left > 1)
  {
    int mid = (right + left) / 2;
    if (isCuttable(mid))
    {
      left = mid;
    }
    else
    {
      right = mid;
    }
  }

  cout << left << endl;
  return 0;
}