import sys

input = sys.stdin.readline
 
class student:
    def __init__(self, name, grade, age, score):
        self.name = name
        self.grade = grade
        self.age = age
        self.score = score
 
    def pr(self):
        print('name: ' + self.name + ' grade: ' + str(self.grade) + ' age: ' + str(self.age))

def cmp(x):
    return (x.age, x.grade) # primary key = age, secondary key = grade
 
lst = []
n = int(input())
for i in range(n):
    s = input().split()
    lst.append(student(s[0], int(s[1]), int(s[2]), float(s[3])))
lst.sort(key=cmp)
for x in lst:
    x.pr()
