#!/usr/bin/python3

if __name__ == "__main__":
    from calculate_1 import add, sub, mul, div

    a = 10
    b = 5

    operations = [
            (add, "+"),
            (sub, "-"),
            (mul, "*"),
            (div, "/")
        ]

    for operation, symbol in operations:
        result = operation(a, b)
        print("{} {} {} = {}".format(a, symbol, b, result))
