def abc (inp, string):
    inp = inp.split(' ') 
    inp = list(map(int, inp))
    a = min(inp)
    inp.remove(a)
    c = max(inp)
    inp.remove(c)
    b = inp[0]
    vocab = {'A':a, 'B':b, 'C':c}
    sol = ''
    for i in range(len(string)):
        if(i == 0):
            sol = str(vocab[string[i]])
        else:
            sol = sol + ' ' + str(vocab[string[i]])
        
    return sol
    
inp = input()
string = input()
answer = abc(inp, string)
print(answer)