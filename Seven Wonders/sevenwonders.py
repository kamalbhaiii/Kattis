# Problem name: Seven Wonders

def sevenWonders(s):
    t = 0
    c = 0
    g = 0
    
    for char in s:
        if char == 'C':
            c += 1
        elif char == 'T':
            t += 1
        elif char == 'G':
            g += 1
    
    sum_points = min(t, c, g) * 7
    sum_points += t * t + c * c + g * g
    
    return sum_points
    
s = input()
print(sevenWonders(s))
