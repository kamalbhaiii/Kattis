inp = input()

inp = inp.split(' ')

num = int(inp[0]) + int(inp[1])

if(num == int(inp[2])):
    print('correct!')
else:
    print('wrong!')