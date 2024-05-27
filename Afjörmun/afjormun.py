num = int(input())

for i in range(num):
    string = input().lower()
    sol = string[0].upper() + string[1:]
    print(sol)