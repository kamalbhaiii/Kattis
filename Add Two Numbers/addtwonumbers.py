inp = input()
inp = inp.split(" ")
sum = 0

for i in range (0, len(inp)):
    sum += int(inp[i])

print(sum)