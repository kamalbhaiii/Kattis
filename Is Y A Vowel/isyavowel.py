# Problem name: Is Y a Vowel?

def isYAVowel (inp):
    vowels=0
    y=0
    for i in inp:
        if(i=='a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'):
            vowels += 1
        elif (i == 'y'):
            y += 1
            
    return [vowels, vowels + y]
    
inp = input().lower()
solution = isYAVowel(inp)
print(solution[0], solution[1])