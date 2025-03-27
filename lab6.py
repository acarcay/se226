import math

def factorial(x):
    if x == 0 or x == 1:
        return 1
    else:
        return x * factorial(x - 1)
#örnek
x = int(input("Enter a number: "))
print(factorial(x))



def sine_x(x, n):
    x_rad = math.radians(x)

    sine_sum = 0
    for i in range(n):
        term = lambda i: ((-1) ** i) * (x_rad ** (2 * i + 1)) / factorial(2 * i + 1)
        sine_sum += term(i)

    return sine_sum


# örnek
x = float(input("Enter angle in degrees: "))
n = int(input("Enter number of terms: "))
print("sine value:", sine_x(x, n))


total_sum = 0


def harmonic(n):
    """
    Recursively calculates the harmonic series sum and updates the global variable.
    The function does not return anything.

    Parameters:
    n (int): The number of terms in the harmonic series.
    """
    global harmonic_sum
    if n == 0:
        return
    harmonic(n - 1)
    harmonic_sum += 1 / n


# örnek
n = int(input("Enter n: "))
harmonic(n)
print("Harmonic sum:", harmonic_sum)

