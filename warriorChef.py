# cook your dish here

from math import floor

# function to check if current value of mid is a possible answer
def isPossible(mid,enemy_strength,strength):
    chef_strength = strength
    for enemy in enemy_strength:
        # if enemy's strength is lesser than chef resistance, skip
        if enemy <= mid:
            continue
        else:
            # chef's strength decreases by enemy strength
            chef_strength -= enemy
        if (chef_strength<=0):
            return False
    return True
    
            

# binary search
for _ in range(int(input())):
    x_min = 0
     
    n,strength = map(int,input().split())
    enemy_strength = list(map(int,input().split()))
    
    # resistance larger or equal to this means chef is always undefeatable
    x_max = max(enemy_strength)
    
    start = x_min
    end = x_max
    ans = 0
    while (start<=end):
      
        mid = floor(start + (end-start)/2)
        if (isPossible(mid,enemy_strength, strength) ):
            # then mid is a possible answer. Store this value and decrement end
            end = mid-1
            ans = mid
        else:
            # this means, for all values lesser than mid, chef looses, hence move search space to the right half
            start = mid + 1 
    # finally print answer stored
    print(ans)
            
