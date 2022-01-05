# Author: Little Mouse
import math
a, b, alpha = map(float, input().split())
sol1 = math.degrees(math.asin((math.sin(math.radians(alpha))/a)*b))
sol2 = 180 - sol1
if sol2+alpha<180:
    print("Two solutions are:", sol1, "and", sol2)
else:
    print("The solution is:", sol2)
