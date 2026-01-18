# Algorithm & Data Structure Solutions Advent of Code 2025

Solutions to [Advent of Code](https://adventofcode.com/) challenges demonstrating problem-solving approach, code quality, and optimization techniques.
## Challenge Solutions

### Day 1: Dial State Machine
Simulates a circular dial system with wraparound logic and state tracking.

- **Part 1** (`Day1.py`): Tracks zero-crossings with basic wraparound
- **Part 2** (`Day1.5.py`): Enhanced click-counting with refined boundary handling

**Key challenge**: Proper handling of edge cases when dial is at position 0

---

### Day 2: Pattern Recognition
Identifies repeating digit patterns within number ranges.

- **Part 1** (`Day2.py`): Simple symmetry detection (first half = second half)
- **Part 2** (`day2.5.py`): Complete pattern detection using factor analysis

**Optimization**:
```python
# Pre-compute factor table to avoid redundant calculations
for i in range(1, biggest_length + 1):
    factored[i] = factor(i)
```
Reduces time complexity from O(n√m) to O(n) by caching factor calculations.

**Input format**: `100-999,1000-9999` (comma-separated ranges)

---

### Day 3: Greedy String Algorithms
Extracts maximum value substrings under deletion constraints.

- **Part 1** (`Day3.py`): Finds two largest digits in O(n) time
- **Part 2** WIP
**Algorithm**: O(n) time complexity, O(1) space relative to input size

---

## Project Structure
```
├── Day[X].py          # Part 1 solutions
├── Day[X].5.py        # Part 2 solutions (optimized/extended)
├── inputs/            # Input files (gitignored)
├── tests/             # Test cases and validation
└── .gitignore
```

## Running the Code
```bash
python Day1.py
python day2.5.py
python Day3.py
```

**Requirements**: Python 3.x (no external dependencies)

## Testing

Solutions include validation through:
- Automated test cases (`tests/` directory)
- Expected output comparison
- Edge case handling

Example from `day2.5.py`:
```python
main("./inputs/day2.txt", "Full")      # Run on full input
main("./tests/day2_test.txt", "Test1")  # Validate against expected
```

## Approach

Each solution demonstrates:
- Clear, readable code with descriptive naming
- Iterative improvement (basic → optimized versions)
- Consideration of time/space complexity trade-offs
- Proper edge case handling

---

**Note**: Input files are not included in the repository per `.gitignore`