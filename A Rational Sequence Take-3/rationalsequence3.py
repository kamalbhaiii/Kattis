class Fraction:
    def __init__(self, n, d):
        self.n = n
        self.d = d

def find_fraction(node, frac):
    bin = 0
    start = 0
    while node != 1:
        if node & 1:
            bin |= (1 << start)
        start += 1
        node >>= 1
    for i in range(start - 1, -1, -1):
        if bin & (1 << i):
            frac.n = frac.n + frac.d
        else:
            frac.d = frac.n + frac.d

def main():
    n = int(input())
    for _ in range(n):
        c, node = map(int, input().split())
        frac = Fraction(1, 1)
        find_fraction(node, frac)
        print(f"{c} {frac.n}/{frac.d}")

if __name__ == "__main__":
    main()
