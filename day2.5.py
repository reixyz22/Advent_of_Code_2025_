# returns two lists, with both lists combined containing all factors of a number
def factor(n: int):
    factors_small = []
    factors_large = []

    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            factors_small.append(i)
            factors_large.append(n // i)

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
def spot_checker(num):
    factors_small, factors_large = factor(len(num))
    print(repeat_checker(str(num), factors_small, factors_large))


def main(file: str, option: str):
    if option == "Test1":
        test_check = []
    with open(file, "r", encoding="utf-8") as f:  # reading the input
        id_ranges = f.read().strip().split(",")

        total = 0  # set counter variable for this file run

        # make factor table up to the largest_digit length, j , of test cases
        biggest_length = 0
        factored = {}
        for id_range in id_ranges:
            start, end = id_range.split("-")
            end = end
            if len(end) > biggest_length:
                biggest_length = len(end)
        for i in range(1, biggest_length + 1):
            factored[i] = factor(i)
        count = 0
        for id_range in id_ranges:
            # parse the ranges from the file
            start, end = id_range.split("-")
            start = int(start)
            end = int(end)
            # print(start, end) debug

            for num in range(start, end + 1):
                if num > 10:
                    factors_small, factors_large = factored[len(str(num))]
                    if option == "Full":
                        total += num if repeat_checker(str(num), factors_small, factors_large) else 0
                    if option == "Test1":
                        test_check.append(num) if repeat_checker(str(num), factors_small, factors_large) else 0
                    if option == "Test2":
                        print(num) if repeat_checker(str(num), factors_small, factors_large) else None

        if option == "Full":
            print(total)

        if option == "Test1":
            test_output = []
            with open("tests/day2_test_answers.txt", "r", encoding="utf-8") as f:  # reading the test answers
                for line in f:
                    test_output.append(int(line.strip()))
            print("test passed") if test_output == test_check else print("test failed")  # comparing expected results
            for case in test_output:
                if case not in test_check:
                    print(case)


if __name__ == "__main__":
    main("./inputs/day2.txt", "Full")
    main("./tests/day2_test.txt", "Test1")
    # main("./tests/day2_test_1_to_9999999.txt", "Test2")
    # spot_checker("111835111835")
