file = "../inputs/day_2.txt"


def symmetry_checker(s: str) -> bool:
    if len(s) // 2 and s[0:len(s) // 2] == s[len(s) // 2:]:
        return True
    return False


with open(file, "r", encoding="utf-8") as f:  # reading the input
    id_ranges = f.read().split(",")  # this is one line, seperated by commas

    total = 0  # set counter variable for this file run

    # read the file
    for id_range in id_ranges:
        start, end = id_range.split("-")
        start = int(start)
        end = int(end)
        # print(start, end) debug

        for num in range(start, end + 1):
            total += num if symmetry_checker(str(num)) else 0
    print(total)
