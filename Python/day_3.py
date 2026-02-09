file = "../inputs/day_3.txt"

with open(file, "r", encoding="utf-8") as f:  # reading the input
    total = 0

    for line in f:
        line = line.strip()

        if len(line) == 2 or len(line) == 1:
            total += int(line)
            continue

        first_digit = int(line[0])
        second_digit = 0

        for _ in line[1:len(line)-1]:
            digit = int(_)
            if digit > first_digit:
                first_digit = digit
                second_digit = 0
            elif digit > second_digit:
                second_digit = digit

        if int(line[len(line)-1]) > second_digit:
            second_digit = int(line[len(line)-1])

        total += int(str(first_digit)+str(second_digit))
        print(str(first_digit)+str(second_digit))
    print(total)
