# Problem name: A Different List Game
# Solved by: Kamal

x = int(input())
p, ans = 2, 0

def count(rem, to_use, hs):
    i = 1
    while i <= len(to_use) and to_use[-i] == len(rem) - 1:
        i += 1
    if i == len(to_use) + 1:
        to_use = [0] * i
    else:
        to_use[-i] += 1
        for j in range(-1, -i-1, -1):
            to_use[j] = to_use[-i]
        
    if hs >= sum(rem) // len(to_use):
        return hs
    
    nxt = rem.copy()
    for idx in to_use:
        if nxt[idx] == 0:
            nxt = []
            break
        nxt[idx] -= 1
    if nxt:
        hs = 1 + count(nxt.copy(), to_use.copy(), max(hs - 1, 0))
    
    return count(rem, to_use.copy(), hs)

check = []
while p * p <= x:
    k = 0
    while x % p == 0:
        x //= p
        k += 1
    if k:
        ans += 1
    if k > 1:
        check.append(k - 1)
    p += 1

if x != 1: # x is prime, extra y
    ans += 1

if check:
    ans += count(check, [len(check) - 1], 0)
print(ans)