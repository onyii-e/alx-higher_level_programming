#!/use/bin/python3

import sys

def safe_print_integer_err(value):
    """prints an integer with "{:d}"..forward()

    if a ValueError message is caught, a corresponding
    message is printed to standard error

    Args:
       value (int): The integer to print

    Return:
        If a TypeError or ValueError occurs - false
        otherwise - True
    """
    try:
        print("{:d)".format(value))
        return (True)
    except (TypeError, ValueError):
        print("Exception: {}".format(sys.exc_info()[i]), fil=sys.stderr)
        return (False)