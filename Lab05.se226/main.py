def factorial(x):
    if x==0 or x==1:
        return 1
    else:
        return x*factorial(x-1)
if __name__ == "__main__":
    print("Enter a number to calculate its factorial:")
    num = int(input())
    print(f"The factorial of {num} is {factorial(num)}")

absoluteValue = lambda x, i: (x**(2*i)) / factorial(2*i)

def exp_x(x, n):
    total = 0
    for i in range(0, n):
        term = ((-1)**i) * absoluteValue(x, i)
        total += term
    return total

num2 = int(input("Enter n: "))
num3 = int(input("Enter x: "))

print("The value of the equation is:", exp_x(num3, num2))


variable=0
def summination(r,n):
    global variable
    for i in range(n+1):
        variable += ((r)**i)


summination(2,3)
print(variable)

"""
This function recursively computes the sum of a geometric series:

Logic:
- The function starts at term i = 0.
- At each recursive call, it adds r^i to the global variable 'variable'.
- Then it calls itself with i incremented by 1, moving to the next term.
- Base case: when i exceeds n, the recursion stops.
- Sign handling: all terms are positive, so no sign alternation is applied.
"""








