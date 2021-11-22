memo = [0]*100
def fib(n):
   if memo[n] > 0:
       return memo[n]
   if n <= 2:
       memo[n] = 1
       return memo[n]
   memo[n] = fib(n-1) + fib(n-2)
   return memo[n]
for i in range(1, 61):
   print(fib(i))
