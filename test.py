# Source - https://stackoverflow.com/a
# Posted by agf, modified by community. See post 'Timeline' for change history
# Retrieved 2025-12-11, License - CC BY-SA 4.0

from functools import reduce


def factors(n):
    return lit(set(reduce(
        list.__add__,
        ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0))))


print(factors(10))
