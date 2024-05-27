# Problem name: Chewbacca

def main():
    n, k, q = map(int, input().split())

    for _ in range(q):
        a, b = map(int, input().split())

        moves = 0
        a -= 1
        b -= 1
        while a != b:
            moves += 1
            if b > a:
                a, b = b, a
            
            a = (a - 1) // k

        print(moves)

if __name__ == "__main__":
    main()
