# Enter your code here. Read input from STDIN. Print output to STDOUT
m = int(raw_input())
s1 = set(map(int,raw_input().split()))
n = int(raw_input())
s2 = set(map(int,raw_input().split()))
s3 = s1.difference(s2).union(s2.difference(s1))
s3 = list(s3)
s3.sort()
for i in s3 :
    print i
