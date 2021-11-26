a, b = 1, 0
for i in bin(int(input())):
    a, b = a*a+b*b, b*(a+a+b)
    if i == "1": a, b = b, a + b
    a %= 1000000007; b %= 1000000007
print(b)
