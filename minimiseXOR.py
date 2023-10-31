t = int(input())
for _ in range(t):
    a,b = list(map(int,input().split()))
    x = a ^ b
    c = bin(x)[2:]
    y = pow(2,len(c)-1)
    print(y^a)
    
        
