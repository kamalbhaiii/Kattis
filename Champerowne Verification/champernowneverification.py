# Problem name: Champernowe Verification
# Solved by: Kamal

r = '12345678910111213141516171819202122'
s = input()

if s in r and r.find(s) == 0:
    print(r.find(s)+len(s))
else:
    print(-1)
