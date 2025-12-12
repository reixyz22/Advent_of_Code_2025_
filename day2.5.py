from functools import reduce

file = "./inputs/day2.txt"


# returns two lists, with both lists combined containing all factors of a number
def factor(n: int):
    factors = reduce(
        list.__add__,
        ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0))
    factors_small = []  # small factors
    factors_large = []  # larger factors
    for i, item in enumerate(factors):
        if i % 2 == 0:
            factors_small.append(item)
        else:
            factors_large.append(item)
    return factors_small, factors_large


def repeat_checker(s: str, factors_small: list, factors_large: list) -> bool:
    for i, v in enumerate(factors_small):
        if i == 0:
            if s == s[0] * len(s):  # all the same
                return True
        else:
            if s == s[0:v] * factors_large[i]:
                return True
            if s == s[0:factors_large[i]] * v:
                return True
    return False


# debugging function
# def spot_checker(num):
#     factors_small, factors_large = factor(len(num))
#     return repeat_checker(str(num), factors_small, factors_large)
#
#
# print(spot_checker("111885111885"))
# print(spot_checker("446446"))
# print(spot_checker("38593859"))
# quit()

with open(file, "r", encoding="utf-8") as f:  # reading the input
    id_ranges = f.read().strip().split(",")

    total = 0  # set counter variable for this file run

    # read the file
    for id_range in id_ranges:
        start, end = id_range.split("-")
        start = int(start)
        end = int(end)
        # print(start, end) debug

        for num in range(start, end + 1):
            if num > 10:
                factors_small, factors_large = factor(len(str(num)))
                total += num if repeat_checker(str(num), factors_small, factors_large) else 0  # print(f"Not: {num}")
    print(total)

test_output = []
with open("./inputs/day2testAnswers.txt", "r", encoding="utf-8") as f:  # reading the input
    for line in f:
        test_output.append(int(line.strip()))

test_check = []
with open("./inputs/day2test.txt", "r", encoding="utf-8") as f:  # reading the input
    id_ranges = f.read().strip().split(",")

    # read the file
    for id_range in id_ranges:
        start, end = id_range.split("-")
        start = int(start)
        end = int(end)
        # print(start, end) debug

        for num in range(start, end + 1):
            factors_small, factors_large = factor(len(str(num)))
            test_check.append(num) if repeat_checker(str(num), factors_small, factors_large) else 0
    print("test passed") if test_output == test_check else print("test failed")
    for case in test_output:
        if case not in test_check:
            print(case)
