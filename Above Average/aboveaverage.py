noOfTestCases = int(input())

for i in range (0,noOfTestCases):
    record = input()
    record = record.split(' ')
    sum = 0
    for j in range (1, len(record)):
        sum += int(record[j])
    avg = sum / int(record[0])
    
    pointer = 0
    for k in range (1, len(record)):
        if (int(record[k]) > avg):
            pointer += 1 
        else:
            continue
    
    sol = (pointer / int(record[0])) * 100
    print(f'{sol:.3f}%')    