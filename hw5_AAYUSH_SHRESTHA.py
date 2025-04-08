# Aayush Shrestha
# Dr. Lynda Danielson
# Programming Languages
# Apr 15, 2025
# This program solves a quadratic equation of the form ax^2 + bx + c = 0.
# It handles real and complex roots, and also checks the roots by substituting them back into the equation.

import math
import cmath

def get_coefficients():
    # Prompt user for input and convert to float
    return [float(x) for x in input("Please enter a, b, and c separated by commas: ").split(",")]

def solve_equation(a, b, c):
    try:
        # Try solving as a quadratic with real roots
        d = math.sqrt(b**2 - 4*a*c)
        return [(-b + d) / (2*a), (-b - d) / (2*a)]
    except ValueError:
        # If discriminant is negative, use complex square root
        d = cmath.sqrt(b**2 - 4*a*c)
        return [(-b + d) / (2*a), (-b - d) / (2*a)]
    except ZeroDivisionError:
        # If a = 0, try solving as linear equation: bx + c = 0
        try:
            return [-c / b]
        except ZeroDivisionError:
            # If b = 0 too, no solution exists
            return []

def check_roots(a, b, c, roots):
    print("\nChecking the roots:")
    for r in roots:
        val = a * r**2 + b * r + c
        # Print real part only if result is complex
        print(val.real if isinstance(val, complex) else val)

def main():
    a, b, c = get_coefficients()
    roots = solve_equation(a, b, c)
    print("roots:", roots)
    check_roots(a, b, c, roots)

main()
