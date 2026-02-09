x = "../inputs/day_1.txt"

with open(x, "r", encoding="utf-8") as f:  # reading the input
    dial: int = 50  # dial starts at 50
    clicks: int = 0
    for line in f:
        line = line.strip()
        direction = line[0]  # 'L' / 'R'
        value = int(line[1:])  # number part
        # print(direction, value) # debug

        if direction == "R":
            dial += value
            clicks += dial // 100
            dial = dial % 100
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
