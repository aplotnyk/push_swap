# Push_swap - Efficient Sorting Algorithm

> A stack-based sorting algorithm implementation that sorts numbers using a limited set of operations with optimal move count.

## 📋 Project Overview

This project is a **sorting algorithm challenge** where you must sort a stack of random integers using only two stacks and a restricted set of operations. The goal is to sort the numbers in ascending order with the **minimum number of moves possible**.

**Key Achievement:** Implemented an efficient sorting algorithm that handles 500 numbers in under 5,500 operations, demonstrating algorithmic optimization and problem-solving skills.

---

## 🎮 How It Works

### The Rules

You have **two stacks** to work with:
- **Stack A**: Contains the random numbers to sort
- **Stack B**: Empty helper stack

### Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push first element from B to A |
| `pb` | Push first element from A to B |
| `ra` | Rotate stack A up (first becomes last) |
| `rb` | Rotate stack B up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate A (last becomes first) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` at the same time |

### The Challenge

Sort stack A in ascending order using the **fewest operations possible**.

---

## 🚀 Usage

### Compilation

```bash
# Clone the repository
git clone https://github.com/aplotnyk/push_swap.git
cd push_swap

# Compile
make

# This creates the push_swap executable
```

### Running the Program

```bash
# Sort a list of numbers
./push_swap 4 67 3 87 23

# Output: series of operations (sa, pb, ra, etc.)
# Each operation is printed on a new line
```

### Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

### Visualizer (Included)

The project includes a visualizer to see the sorting in action:

```bash
cd push_swap_visualizer
# Follow the visualizer's instructions to see your algorithm work
```

---

## 🎯 Algorithm Strategy

The sorting approach uses a **hybrid algorithm** optimized for different input sizes:

### Small Stacks (2-5 numbers)
- **Hardcoded solutions** for maximum efficiency
- Uses pattern recognition to minimize moves

### Medium Stacks (6-100 numbers)
- **Simple sorting strategy**
- Push elements to stack B strategically
- Rotate to optimal positions

### Large Stacks (100-500+ numbers)
- **Chunk-based algorithm**
- Divides numbers into sorted chunks
- Optimizes rotation costs (ra vs rra)
- Minimizes total operations

---

## 📊 Performance Benchmarks

| Stack Size | Max Operations | Achieved |
|------------|----------------|----------|
| 3 numbers  | 3 moves | ✅ 2-3 moves |
| 5 numbers  | 12 moves | ✅ 8-12 moves |
| 100 numbers | 700 moves | ✅ ~550 moves |
| 500 numbers | 5500 moves | ✅ ~4500 moves |

---

## 🎓 Key Learning Outcomes

This project demonstrates:

1. **Algorithm Design** - Creating efficient sorting strategies under constraints
2. **Complexity Analysis** - Understanding and minimizing operation counts (O(n²) to O(n log n))
3. **Data Structures** - Stack operations and manipulation
4. **Optimization** - Balancing different approaches for different input sizes
5. **Edge Case Handling** - Duplicates, already sorted, reverse sorted, etc.

---

## 🛠️ Technical Implementation

### Project Structure

```
push_swap/
├── srcs/               # Source files
│   ├── push_swap.c     # Main program
│   ├── operations/     # Stack operations (push, swap, rotate)
│   ├── algorithm/      # Sorting logic
│   └── utils/          # Helper functions
├── push_swap_visualizer/  # Visual debugging tool
├── Makefile            # Build configuration
└── README.md
```

### Error Handling

The program handles:
- ✅ Non-numeric arguments
- ✅ Duplicates (exits with error)
- ✅ Integer overflow
- ✅ Empty input
- ✅ Invalid formatting

```bash
$ ./push_swap 1 2 2 3
Error  # Duplicate detected

$ ./push_swap "not a number"
Error  # Invalid input
```

---

## 🔧 Makefile Commands

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

---

## 🧪 Testing

```bash
# Test with random numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l

# Verify it sorts correctly
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker_Mac $ARG
# Should output: OK
```

---

## 📝 Technical Details

- **Language:** C
- **Compilation Flags:** `-Wall -Wextra -Werror`
- **Memory Management:** No leaks, proper malloc/free
- **Coding Standard:** 42 Norm compliant

---

## 🏆 Algorithm Highlights

**Optimization Techniques Used:**
- **Cost calculation** - Calculates rotation costs for both stacks
- **Greedy approach** - Always chooses the cheapest move
- **Chunk division** - Splits large inputs into manageable segments
- **Pre-sorted detection** - Exits immediately if already sorted

---

## ✅ Project Status

**Completed** - Passes all 42 School test cases with optimal performance.

---

## 📖 About This Project

Part of the **42 School curriculum**, push_swap teaches:
- Algorithm optimization
- Constraint-based problem solving
- Efficient data structure manipulation
- Performance benchmarking
