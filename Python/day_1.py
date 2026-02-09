x = "../inputs/day_1.txt"

dial: int = 50  # dial starts at 50
zeros: int = 0  # counting the number of times the dial returns to 0

with open(x, "r", encoding="utf-8") as f:  # reading the input
    for line in f:
        line = line.strip()
        direction = line[0]  # 'L' / 'R'
        value = int(line[1:])  # number part
        # print(direction, value) # debug

        if direction == "R":
            dial += value
        else:
            dial -= value

        # tuning for under / over values
        while dial > 99:
            dial -= 100

        while dial < 0:
            dial += 100

        # final check
        if dial == 0:
            zeros += 1
print(zeros)
