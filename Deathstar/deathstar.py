# Problem name: Deathstar

def main():
    size = int(input())
    
    plans = [0] * size

    for i in range(size):
        row = list(map(int, input().split()))
        for num in row:
            plans[i] |= num

    for plan in plans:
        print(plan, end=" ")
    print()

if __name__ == "__main__":
    main()
