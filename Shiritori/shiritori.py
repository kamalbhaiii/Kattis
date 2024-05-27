def shiritori():
    arr = set()  # Using a set for O(1) lookup time
    tries = int(input())
    
    for i in range(tries):
        inp = input()
        player = 1 if i % 2 == 0 else 2
        
        if i > 0 and inp[0] != last_word[-1]:
            print(f'Player {player} lost')
            return
        
        if inp in arr:
            print(f'Player {player} lost')
            return

        arr.add(inp)
        last_word = inp
        
    print('Fair game')

shiritori()
