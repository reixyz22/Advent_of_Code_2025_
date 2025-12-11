x = "./inputs/day1.txt"

dial: int = 50  # dial starts at 50
clicks: int = 0  # question 2
print("")
with open(x, "r", encoding="utf-8") as f:  # reading the input
    for line in f:
        line = line.strip()
        direction = line[0]  # 'L' / 'R'
        value = int(line[1:])  # number part
        # print(direction, value) # debug

        if direction == "R":
            dial += value
            while dial > 99:
                dial -= 100
                clicks += 1
        else:
            if dial == 0:
                clicks -= 1
            dial -= value
            while dial < 0:
                dial += 100
                clicks += 1
            if dial == 0:
                clicks += 1

        # print(line, "Clicks:", clicks, "Dial:", dial)
    print(clicks)
