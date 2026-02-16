# Algorithm & Data Structure Solutions Advent of Code 2025

Solutions to [Advent of Code](https://adventofcode.com/) challenges demonstrating problem-solving approach, code quality,
and optimization techniques. This year contains 12 questions, with 2 parts each.
- **Days 1-3 are done in both C++, Python. Days 4-12 (WIP) are in C++.**
## Challenge Solutions

### Day 1: Spinning Dial State Machine
Simulates a circular dial system with wraparound logic and state tracking.

- **Part 1** (`Python/Day_1.py, Cpp/Day_1.cpp`): Tracks zero-crossings with basic wraparound
- **Part 2** (`Python/Day_1.5.py, Cpp/Day_1.5.cpp`): Enhanced click-counting with refined boundary handling

**Key challenge**: Proper handling of edge cases when dial is at position 0

---

### Day 2: Repeating Pattern Recognition
Identifies repeating digit patterns within number ranges.

- **Part 1** (`Python/Day_2.py, Cpp/Day_2.cpp`): Simple symmetry detection (first half = second half)
- **Part 2** (`Python/Day_2.5.py, Cpp/Day_2.5.cpp`): Complete pattern detection using factor analysis

**Optimization**:
```python
# Pre-compute factor table to avoid redundant calculations
for i in range(1, biggest_length + 1):
    factored[i] = factor(i)
```
Reduces time complexity from O(n√m) to O(n) by caching factor calculations.

---

### Day 3: Greedy String Algorithms
Extracts maximum value substrings if you can only keep k digits.

**Greedy monotonic stack algorithm**

- **Part 1** (`Python/Day_3.py, Cpp/Day_3.cpp`): Finds two largest digits in O(n) time
- **Part 2** (`Python/Day_3.5.py, Cpp/Day_3.5.cpp`): Finds K (12 for advent of code) digits in O(n) time

**Algorithm**: O(n) time complexity, O(1) space relative to input size
- Decided to use deque for learning purposes but also could've used a string.
---

### Day 4: Simple grid traversal and neighbors monitoring.
- **Part 1** (`Cpp/Day_4.cpp`): Traverses a 2d array, taking note of how populated neighboring cells are and totaling those with only 3 or fewer. 
- **Test** (`Cpp/Day_4_test.cpp`): Displays the grid, replacing @ symbols with the raw number of neighbors.
- **Part 2** (`Cpp/Day_4.5.cpp`): Maybe the easiest part 2, that I've seen. Simply loops part 1, updating the grid with each pass until not further progress can be made


### Day 5: Counting numbers in ranges.
- **Part 1** (`Cpp/Day_5.cpp`): We learned to store entire ranges and use dual comparisons 
```c++
if (std::stoll(line) >= start && std::stoll(line) <= end) {
```
rather than the naive version of looping through
- **Test** (`Cpp/Day_5_test.cpp`): This is a naive approach that I first tried and lagged out my PC. 
- **Part 2** (`Cpp/Day_5.5.cpp`): This deals with only ranges, which seems easier until we consider duplicates, we solve this by merging the intersecting ranges together thus solving the duplicate edge case.

### Day 6: Reading a strange input
- **Part 1** (`Cpp/Day_6.cpp`): This question seems easy.. until we see how weird the input is. After figuring out that notepad was wrapping the lines, of which there are only four.
It became a mater of building matrix while reading input and then transposing and finally doing math on that matrix. 


**Requirements**: Python 3.x, C++ v17 (no external dependencies)

## Testing

Some solutions include built in validation through:
- Automated test cases (`tests/` directory)
- Edge case monitoring

Example from `day2.5.py`:
```python
main("./inputs/day_2.txt", "Full")      # Run on full input
main("./tests/day_2_test.txt", "Test1")  # Validate against expected
```
Most tests now live in dedicated files:
- As, I progressed I found that this approach was cleaner and had fewer tradeoffs to this use case.

Test case's expected solutions are typically found on https://adventofcode.com/2025/.


**Note**: Input files are not included in the repository per `.gitignore` and Advent Of Code's Policy. 

To get your own full inputs visit [Advent Of Code](https://adventofcode.com/2025/).
