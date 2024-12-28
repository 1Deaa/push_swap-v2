# PUSH_SWAP

Given a set of integers, sort it using a predefined set of instructions using two stacks.

What does it do?
Push_swap creates for you a list of instructions that sorts integers using 2 stacks A & B
## Intruction Set

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm
Partition stack A into 4 parts and push the first part to B then
partition the remaining elements in A into 4 parts and push to B repeat till
there's nothing in A then return the largest value to A until B is empty

Stack A unsorted
<div>
<img src="https://github.com/user-attachments/assets/be2b524e-1ea1-4887-830e-afa3cba871ce" width="450" height="400">
</div>

Stack B partitioned
<div>
<img src="https://github.com/user-attachments/assets/cb00cc35-85f5-41c0-962f-d58edda55dbf" width="450" height="400">
</div>

Stack A sorted
<div>
<img src="https://github.com/user-attachments/assets/55b8ecbd-76f4-462d-a3c8-24aa3b1c2ac9" width="450" height="400">
</div>

##### Visualizer Source:
##### [Visualizer](https://github.com/o-reo/push_swap_visualizer) - Made by o-reo
