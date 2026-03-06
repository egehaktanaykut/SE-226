'''while True:
    num = int(input("Please enter a positive integer greater than 9: "))
    if num > 9:
        break
    print("Number must be greater than 9!")

steps = 0
current = num
print(f"{current}", end="")

while current > 9:
    total = 0
    temp = current
    while temp > 0:
        total += temp % 10
        temp //= 10
    print(f" → {total}", end="")
    current = total
    steps += 1

print(f"\nFinal value: {current}")
print(f"Total steps: {steps}")


 while True:
    try:
        num = int(input("Please enter a number between 10 and 100: "))
        if 10 <= num <= 100:
            break
        else:
            print("Please enter a number between 10 and 100!")
    except ValueError:
        print("Invalid input. Please enter a valid number.")

fizz_count = 0
buzz_count = 0
fizzbuzz_count = 0

for i in range(1, num+1):
    if i % 7 == 0:
        continue
    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
        fizzbuzz_count += 1
    elif i % 3 == 0:
        print("Fizz")
        fizz_count += 1
    elif i % 5 == 0:
        print("Buzz")
        buzz_count += 1
    else:
        print(i)

print("Fizz:", fizz_count)
print("Buzz:", buzz_count)
print("FizzBuzz:", fizzbuzz_count)



 while True:
    try:
        n = int(input("Please enter a number between 3 and 9: "))
        if 3 <= n <= 9:
            break
        else:
            print("Invalid input! Number must be between 3 and 9.")
    except ValueError:
        print("Invalid input! Please enter an integer.")

for i in range(1, 2*n):
    k = n - abs(n - i)
    for j in range(1, k+1):
        print(j, end="")
    print() '''



