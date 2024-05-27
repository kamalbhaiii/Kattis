# Problem name: Distributing Poffins
# Solved by: Kamal

def min_poffin_diff(n, m):
    base_poffins = m // n
    extra_poffins_count = m % n

    if extra_poffins_count == 0:
        return 0
    else:
        return 1

# Read input
inp = [int(i) for i in input().split()]
min_diff = min_poffin_diff(inp[0], inp[1])
print(min_diff)
