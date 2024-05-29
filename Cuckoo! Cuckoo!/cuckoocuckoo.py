# Problem name: Cuckoo! Cuckoo!
# Solved by: Kamal

def cuckoo(current_time, target_count):
    current_hour = current_time[0]
    current_minute = current_time[1]
    cuckoo_count = 0
    
    while cuckoo_count < target_count:
        if current_minute == 0:
            cuckoo_count += current_hour
        elif current_minute == 15 or current_minute == 30 or current_minute == 45:
            cuckoo_count += 1

        if cuckoo_count >= target_count:
            hour_str = f"{current_hour:02}"
            minute_str = f"{current_minute:02}"
            return f'{hour_str}:{minute_str}'

        current_minute += 1
        if current_minute == 60:
            current_minute = 0
            current_hour += 1
            if current_hour == 13:
                current_hour = 1

time = [int(i) for i in input().split(':')]
count = int(input())
result_time = cuckoo(time, count)
print(result_time)
