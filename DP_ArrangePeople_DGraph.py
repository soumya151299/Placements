n = 3
m = 2
k  = 4
dp = [[[0 for _ in range(n)] for _ in range(2)] for _ in range(k)]
#0 to n-1 people at k positions
dp[0][0][1] = 1
dp[0][1][1] = 1
for i in range(1,k):
  for num in [0,1]:
    other = num^1
    if num == 0:
      end = n
    else:
      end = m
    dp[i][num][1] += sum(dp[i-1][other])
    for new_count in range(1,end):
      #dp[i][num][1] += dp[i-1][other][new_count]
      if new_count > 1:
        dp[i][num][new_count] += dp[i-1][num][new_count - 1]
ans = 0;
for num in [0,1]:
  for new_count in range(1,max(n,m)):
    ans += dp[-1][num][new_count];
print(ans)
