# Problem name: Double up

def double_up(numbers, itr):
  if (len(numbers) <= itr):
    while len(numbers) > 1:
      i = 0
      while i < len(numbers) - 1 and numbers[i] != numbers[i + 1]:
        i += 1

      if i == len(numbers) - 1:
        numbers.remove(min(numbers))

      else:
        numbers[i] *= 2
        del numbers[i + 1]

    return numbers[0]

itr = int(input())
numbers = input().split()
int_numbers = [int(i) for i in numbers]
double_up_res = double_up(int_numbers, itr)
print(double_up_res)
