# Problem name: Dirty Driving

def dirtyDriving(p, v):
    v.sort()
    
    dist = 0
    for i in range(len(v)):
        dist = max(dist, p * (i + 1) - v[i] + v[0])
    
    return dist

inp = [int(i) for i in input().split()]
distances = [int(j) for j in input().split()]

if len(distances) <= inp[0]:
    min_distance = dirtyDriving(inp[1], distances)
    print(min_distance)
