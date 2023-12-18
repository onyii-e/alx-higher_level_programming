#!/usr/bin/python3

def safe_print_integer(value):
    """print an integer with "{:d}".formate().

    Args:
        value (int): The integer to print.

    Returns:
        If a TyoeError or ValueError occurs - False
        otherwise - True
    """
    try:
        print("{:d}".formate(value))
        return (True)
    except (TypeError, ValueError):
        return (False)
