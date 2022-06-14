# AtCoder コードテストでの実行結果
# Python 3.8.2:  実行時間: 5707 ms, メモリ: 42260 KB
# PyPy3 7.3.0:   実行時間: 1080 ms, メモリ: 62980 KB
# ほぼ同じ動作をするc++コードだと
# C++ gcc 9.2.1: 実行時間:   40 ms, メモリ:  4408 KB

import queue

H = 1000
W = 1000
length = [ [-1] * (H + 1) for i in range(W + 1) ]

dp = [ [1, 0], [0, 1], [-1, 0], [0, -1] ]

q = queue.Queue()
p = [ 1, 1 ]
q.put( p )
length[ 1 ][ 1 ] = 0

while not q.empty():
  p = q.get()
  if p[0] == H and p[1] == W:
    break
  for k in range( 4 ):
    r = [p[0] + dp[k][0], p[1] + dp[k][1] ]
    if 1<= r[0] and r[0] <= H and 1 <= r[1] and r[1] <= W:
      if length[ r[0] ][ r[1] ] == -1:
        q.put( r )
        length[ r[0] ][ r[1] ] = length[ p[0] ] [ p[1] ] + 1
print( length[ H ][ W ] )
