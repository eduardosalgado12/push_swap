*This project has been created as part of the 42 curriculum by edsalgad and khooftma.*

---

## Description

**Push_swap** is an algorithmic performance project within the 42 curriculum. The core objective is to sort a chaotic stack of integers in ascending order using two stacks (`A` and `B`) and a strictly constrained set of stack manipulation operations (swaps, pushes, and rotations). 

The ultimate goal is to achieve a perfect sort using the absolute lowest number of instructions possible. This implementation achieves that through an **Adaptive Sorting Engine** that automatically evaluates data topology and inversion density to dynamically provision the most efficient algorithmic strategy.

---

## Instructions

### Compilation
The project includes a strict, Norminette-compliant `Makefile` to handle compilation. It is designed to compile cleanly without relinking and splits shared source assets beautifully to cleanly isolate the mandatory binary from the bonus binary.

```bash
# Compile the main push_swap executable
make

# Compile the bonus checker executable
make bonus

# Remove all binary object files (.o) from both targets
make clean

# Remove all object files as well as both compiled binaries
make fclean

# Recompile the entire project (including the bonus) from scratch
make re
```

### Execution & Usage
Run the binary executable by passing a shuffled sequence of integers as arguments. The program seamlessly supports both independent arguments and single-quoted string literals split by spaces.

```bash
# Standard execution with loose arguments
./push_swap 2 1 3 0

# Standard execution with a quoted string literal
./push_swap "2 1 3 0"
```

*Note: If no parameters are specified, the program will display nothing and return the terminal prompt.*

### Error Handling
In case of invalid inputs, the program securely routes a clean `"Error\n"` message to the **standard error (stderr)** stream. Valid errors caught include:
* Non-integer inputs (alphabetic characters or formatting errors).
* Numeric values outside the limits of a 32-bit signed integer (`INT_MAX` or `INT_MIN`).
* Duplicate numbers within the input sequence.

---

## Algorithmic Structure

The adaptive sorting engine chooses the best strategy based on the quantity of the numbers provided:

### Small Sets (2 to 5 elements)
* **2 elements:** Executes a simple swap (`sa` ) if the elements are out of order.
* **3 elements:** Analyzes the three values to apply an exact combination of a maximum of 2 instructions (uses a hardcoded case-mapping sort).
* **4 to 5 elements:** Pushes the smallest values temporarily to Stack `B`, sorts the remaining values in Stack `A`, and pushes them back into their correct positions.

### Large Sets (More than 5 elements)
## Selected Algorithms: Detailed Explanation & Justification

To fulfill the strict project criteria, our binary embeds all four required strategies (simple / medium / complex / adaptive). Strategy selection is fully robust and works seamlessly across all valid inputs, regardless of input size or disorder matrix.

### 1. Selection Sort with Chunks (`STRAT_SIMPLE` / O(n²))
* **Explanation:** Triggered via the `--simple` flag. It groups numbers into 5 fixed blocks (if total size bigger than 25), pushes them to stack `B` based on proximity, and then pulls them back while isolating maximum values.
* **Justification:** While theoretically an O(n²) algorithm due to its nested lookup scanning loops, the 5-chunk partition serves as a constant factor inhibitor that significantly dampens rotation costs for smaller input sequences.

### 2. Chunk Sort (`STRAT_MEDIUM` / O(n√n))
* **Explanation:** Triggered via the `--medium` flag, this is our core strategy for handling large datasets. It computes a dynamic chunk size based on the square root of the stack size (√n) combined with an empirical scaler.
* **Justification:** Scaling the number of chunks with √n prevents the internal chunk search areas from expanding linearly as the input grows. This guarantees that a valid number always remains near the top of stack `A`, minimizing the total cost of operations (`ra`/`rra`) drastically and safely validating its O(n√n) classification.

### 3. Recursive Quicksort (`STRAT_COMPLEX` / O(n log n))
* **Explanation:** Triggered via the `--complex` flag. A sophisticated, highly optimized "Divide and Conquer" implementation split into `complex.c` and `complex_utils.c` to fully satisfy the 42 Norm (holding functions strictly under 25 lines). It samples the exact median of a sub-stack via a temporary stack allocation array, pushes bounded elements to `B`, and handles the remaining larger elements in `A` via deep dual-recursions (`quick_sort_a` / `quick_sort_b`). 
* **Justification:** By calculating the exact mathematical median for every split, the recursive call tree depth is strictly held at a logarithmically bounded O(log n) scale. Optimization mechanisms, such as rounding targets up via a `(size + 1) / 2` threshold in Stack B, stop partition sweeps early to drastically cut unneeded `rb`/`rrb` cycles. Additionally, subsets of size ≤ 3 are passed to a chirurgic `sort_small_a` shield function that manipulates the top entries using localized rollbacks (`ra` → `sa` → `rra`), dynamically protecting pre-sorted historical elements stacked underneath.

### 4. Adaptive Strategy (`STRAT_ADAPTIVE`)
* **Explanation:** This is the default behavior if no selector flag is specified. It runs a pre-sort inversion count formula (`disorder_metric`) to gauge the precise mathematical chaos of the stack, auto-selecting the most optimal strategy from the pipeline.

---

## Instruction Set

The program outputs a list of the following allowed instructions to manipulate both stacks:

| Command | Human Operation | Detailed Description |
| :--- | :--- | :--- |
| **`sa`** / **`sb`** | Swap A / Swap B | Swaps the first 2 elements at the top of the selected stack. |
| **`ss`** | Swap Both | Executes `sa` and `sb` at the same time. |
| **`pa`** / **`pb`** | Push A / Push B | Takes the top element from one stack and puts it on top of the other. |
| **`ra`** / **`rb`** | Rotate A / Rotate B | Shifts all elements of the stack up by 1 position. The top element becomes the bottom one. |
| **`rr`** | Rotate Both | Executes `ra` and `rb` at the same time. |
| **`rra`** / **`rrb`** | Reverse Rotate A/B | Shifts all elements of the stack down by 1 position. The bottom element becomes the top one. |
| **`rrr`** | Rev Rotate Both | Executes `rra` and `rrb` at the same time. |


---

## Advanced Benchmarking Mode

Our project includes an advanced benchmarking feature activated exclusively by the `--bench` flag. To comply with the strict project parameters, all benchmark data is output exclusively to `stderr` so it does not interfere with standard automated evaluation checkers or Unix pipes.

```bash
# Run the adaptive engine with the benchmark monitor
./push_swap --bench 5 1 4 2 3
```

The benchmark monitor tracks and prints:
* **The computed disorder** expressed as a percentage with exactly two decimals.
* **The strategy name** used alongside its valid theoretical complexity class.
* **The total number of operations** executed.
* **An itemized operation breakdown** (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

---

## Bonus Part: The `checker` Program

We have engineered a fully independent, robust structural verification program called `checker`. It takes the initial integer stack format as an argument, reads stack manipulation instructions sequentially from standard input (`stdin`) via an optimized `get_next_line` engine, and executes them live on a simulated stack environment.

### Architectural Silence Design
To safeguard evaluation integrity and strictly adhere to the 42 subject rules, the execution operations share a smart filter design using an `is_checker` boolean flag located inside the `t_bench` structure:
```c
if (!bench->is_checker)
    write(1, "pa\n", 3);
```
When running the bonus `checker`, a tracking `dummy_bench` overrides operations to run them completely muted. This ensures that the checker *never* echoes operations back to standard output, yielding a completely silent operational evaluation pipeline.

### Verification Usage
To test whether the instructions output by `push_swap` correctly and cleanly sort the data topology, bridge the programs using a standard Unix Pipe (`|`):

```bash
# Pipeline check (The official evaluation method)
ARG="4 67 3 87 23"; ./push_swap ARG | ./checker ARG

# Expected output on perfect sort:
OK
```

### Interactive Manual Testing
You can also seed a stack state into the checker and manually input operations row by row to step-debug your stack logic. Press `Ctrl + D` when done to pass the End-Of-File (`EOF`) token to GNL:

```bash
./checker 3 2 1 0
sa
pb
ra
[Ctrl + D]
KO
```

### Checker Error Controls
The `checker` matches the error handling parameters of the core project. It catches and securely routes `"Error\n"` to `stderr` under the following conditions:
* Invalid arguments passed during stack initialization (duplicates, non-ints, overflows).
* Receiving an unknown or poorly formatted operation sequence via standard input (e.g., `abc\n` or an empty instruction).
* *Note: Completely empty inputs (pressing Enter instantly or supplying an empty pipe) are safely parsed as valid EOF indicators, resulting in a normal stack evaluation (`OK` or `KO`) rather than an error crash.*

---

## Contributors

This project was co-developed as a collaborative effort within the 42 School network. Both learners contributed equally to core milestones while dividing specific technical responsibilities:


* **khooftma**  
  * **Core Setup & Instructions**: Initialized the foundational workspace infrastructure and programmed the base set of operation instructions (`sa`, `pb`, `ra`, etc.).
  * **Algorithmic Pipeline**: Authored the implementation for both the **Simple Algorithm** (Selection Sort with Chunks) and the **Medium Algorithm** (Dynamic Chunk Sort).
  * **Validation & Documentation**: Wrote the structural **README.md** manual and engineered the complete **Checker binary framework** to satisfy the 42 project bonus rules.

* **edsalgad**  
  * **Advanced Sorting Architecture**: Designed and engineered the highly complex **Recursive Quicksort** logic alongside its multi-file implementation structures.
  * **Input Engineering & Safety**: Programmed the strict argument **parsing layer** and standard error verification matrix.
  * **Optimization & Verification**: Led systemic **debugging loops**, built the project **benchmarking module** (`t_bench`), and executed **all deep end-to-end stress tests** to minimize operation costs.

---

## Resources & AI Use Description

### References & Documentation
* **42 Push_swap Subject Documentation**: System limitations, instruction constraints, and boundary validation rules.
* **Divide and Conquer Paradigms**: Structural design guidelines for median-driven quicksort implementations.
* **Asymptotic Notation & Time Complexity Studies**: Theoretical foundations explaining the behavior of O(n²), O(n√n), and O(n log n) tracking curves.

### Description of AI Assistance
Artificial Intelligence was actively leveraged as a collaborative peer during the code validation, architectural audit, norminette compliance, and documentation engineering phases of this project.

* **Code Verification & Architecture Auditing:** AI was used to trace complex nested memory conditions within the recursive loops to confirm that rollback structures (`rrb`/`rra`) safely protected lower pre-sorted blocks from structural corruption.
* **Norminette Engineering:** AI assisted in refactoring the 6-function layout of the complex algorithm, safely extracting utility loops into an autonomous `complex_utils.c` layout while using comma-operator grouping tricks (`return (f(), (void)0)`) to cleanly compress void function parameters under the tight 25-line structural ceiling.
* **Defense Preparation & Explanations:** AI was utilized to analyze the streaming pipelines of Unix standard outputs (`stdout` vs `stderr`), verifying how to build a `--bench` toggle structure that guarantees perfect transparency during manual execution while remaining hidden away from automated evaluation parsers.