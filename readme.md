# Algorithm & Data Structure Solutions Advent of Code 2025

Solutions to [Advent of Code](https://adventofcode.com/) challenges demonstrating problem-solving approach, code quality, and optimization techniques.
## Challenge Solutions

### Day 1: Dial State Machine
Simulates a circular dial system with wraparound logic and state tracking.

- **Part 1** (`Python/Day_1.py, Cpp/Day_1.cpp`): Tracks zero-crossings with basic wraparound
- **Part 2** (`Python/Day_1.5.py, Cpp/Day_1.5.cpp`): Enhanced click-counting with refined boundary handling

**Key challenge**: Proper handling of edge cases when dial is at position 0

---

### Day 2: Pattern Recognition
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

---


**Requirements**: Python 3.x, C++ v17 (no external dependencies)

## Testing

Some solutions include built in validation through:
- Automated test cases (`tests/` directory)
- Expected output comparison
- Edge case monitoring

Example from `day2.5.py`:
```python
main("./inputs/day_2.txt", "Full")      # Run on full input
main("./tests/day_2_test.txt", "Test1")  # Validate against expected
```



**Note**: Input files are not included in the repository per `.gitignore`