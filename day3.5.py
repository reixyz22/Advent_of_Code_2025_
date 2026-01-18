file = "./tests/day_3test.txt"
#file = "./inputs/day3.txt"


# claude solved the sub problem here. Only issue is this implies we could maybe just run this on every string. Faster?
def largest_substring(s, k):
    """
    Find largest substring by removing k digits
    s: string of length 15
    k: number of digits to remove (default 3)
    """
    n = len(s)
    result_length = n - k  # 12 in your case
    stack = []

    for i, digit in enumerate(s):
        # While current digit is larger than stack top
        # AND we can still remove digits
        # AND we have enough remaining digits to fill result
        while (stack and
               stack[-1] < digit and
               k > 0 and
               len(stack) - 1 + (n - i) >= result_length):
            stack.pop()
            k -= 1

        stack.append(digit)

    # If we still have removals left, remove from end
    while k > 0:
        stack.pop()
        k -= 1

    return ''.join(stack)


# My code starts below
with open(file, "r", encoding="utf-8") as f:  # reading the input

    total = 0  # total of all results by each test case combined

    for line in f:  # O(1), since test cases don't count against our time complexity
        line = line.strip()

        largest_digit = int(max(line[0:len(line) - 12]))

        start_indices = []
        for i, _ in enumerate(line[0:len(line) - 12]):  # O(n)
            digit = int(_)
            if digit == largest_digit:
                # calculate strikes then save (valid starting indexes, strikes) as a 2 item list
                distance_to_edge = (len(line) - 1) - (i + 12)
                distance_to_edge = 0 if distance_to_edge > 3 else distance_to_edge
                strikes = 3 - distance_to_edge
                start_indices.append([i, strikes])

        known_digits = [largest_digit]

        while len(start_indices) > 1 and len(known_digits) < 13:  # O(1) as max length of known digits is 12
            next_digit = 0

            # greedy candidate cutting
            for i, (start, strikes) in enumerate(start_indices):  # O(n) again but not nested means O(n) + O(n) = O(n)
                # debug = line[start:start + 12 + strikes]
                cut = True
                search_space = len(known_digits) + strikes
                matches = 1
                for j in range(1, search_space):  # this loop is O(1) due to a max length of 15
                    n = int(line[start + j])
                    if matches < len(known_digits):
                        if n == known_digits[matches]:
                            matches += 1
                        else:
                            strikes -= 1
                    if strikes < 0:
                        break
                    if matches == len(known_digits):
                        cut = False
                        if n > next_digit:
                            next_digit = n
                if cut:
                    start_indices.pop(i)

            known_digits.append(next_digit)

        winner_index = start_indices[0][0]

        edge = (len(line) - 1) - (winner_index + 12)
        edge = 0 if edge > 3 else edge
        winner_strikes = 3

        winner = line[winner_index:winner_index + 12 + winner_strikes - edge]

        final = largest_substring(winner, winner_strikes)
        # print(final)
        total += int(final)
    print(total)
