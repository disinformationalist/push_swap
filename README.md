<h1 align="left">Push Swap : A Frankenstein's Monster of ideas to sort the stack in short order</h1>

This sorter uses a custom algorithm to sort the stack, An overview of how it works will be given in the Algorithm section below. [#Algorithm](#algorithm)  
But first, let's look at the stats.

## Much Fast, Such Speed
For full credit, sort 5  integers in 12 moves or less, 100 in under 700, and 500 in under 5500.
Here are the approximate speeds for my solution, from testing with 5000 random sets.


| Integers to sort | Average moves required | Lowest moves required | Highest moves required |
|------------------|------------------------|-----------------------| -----------------------|
| 3                | 1.3                    | 1                     | 2                      |
| 4                | 3.3                    | 1                     | 6                      |
| 5                | 6                      | 1                     | 8                      |
| 50               | 218                    | 158                   | 262                    |
| 100              | **520** 🏁🏁🏁         | **428**               | **605**                |
| 250              | 1652                   | 1452                  | 1872                   |
| 500              | **3763** 🏁🏁🏁        | **3389**              | **4085**               |

## The Problem, The Goal, and The Rules

- ### In push swap, we have two stacks A and B.  
- ### We start with all of the values to be sorted in stack A, unsorted. Stack B is empty
- ### We must end with all the values in A once more, sorted, with the lowest value on top. Stack B must be empty again.
- ### We have limited operations we can use to manipulate the stacks.


## The Operations

| Symbol |          Name         |                                     Action                                     |
|------- |-----------------------|--------------------------------------------------------------------------------|
| `sa`   |         Swap A        |Swap the first 2 elements at the top of stack A.                                |
| `sb`   |         Swap B        |Swap the first 2 elements at the top of stack B.                                |
| `ss`   |       Double Swap     | `sa` and `sb` at the same time.                                                |
| `pa`   |         Push A        |Take the first element at the top of b and put it at the top of a.              |
| `pb`   |         Push B        |Take the first element at the top of a and put it at the top of b.              |
| `ra`   |        Rotate A       |Shift up all elements of stack A by 1. The first element becomes the last one.  |
| `rb`   |        Rotate B       |Shift up all elements of stack B by 1. The first element becomes the last one.  |
| `rr`   |     Double Rotate     |`ra` and `rb` at the same time.                                                 |
| `rra`  |   Reverse Rotate A    |Shift down all elements of stack A by 1. The last element becomes the first one.|
| `rrb`  |   Reverse Rotate B    |Shift down all elements of stack B by 1. The last element becomes the first one.|
| `rrr`  | Double Reverse Rotate |`rra` and `rrb` at the same time.                                               |


## Usage

### Steps to run:

1. **Clone the repository**:
```bash
git clone https://github.com/disinformationalist/push_swap.git push_swap
```

2. **Change to the project directory**:
```bash
cd push_swap
```
3. **Build the executable**:
```bash
make
```
4. **Run with any list of integer values within [INT_MIN, INT_MAX], and no repeated values, quotation marks around values is optional**. 
**The list of moves will print and the total number of moves will show at the end.**   
**example with 6 integers:**

```bash
./push_swap 7 1 -3 9 23 -123

```
## output:
```bash
pb
pb
ra
pa
ra
pa
ra
ra
ra

Moves: 9
```

# Algorithm

Push swap is different from most sorting problems due to its restricted operations. Instead of a data problem, it makes more sense as a physical one.
Imagine a factory with two conveyor belts with boxes with some parameter, say, weight rounded to the nearest whole number, and the weights can be any integer, 
and we need to find a way to sort them by the chosen parameter in the fewest moves. Thus minimizing energy costs, wear on the machines, etc. How we come up with the
list of moves, and how long it takes doesn't matter. Ok so it isn't a perfect analogy, but it gives the right frame of mind. **Now let's crack the problem.** 

**NOTE** : Each stack is set up as a doubly linked list in this implementation.

And now for the 11 secret herbs and spices....

## Logic outline

It isn't feasable to sort stack A in place in reasonable moves given the restrictions, except for 
very small stacks, so we know we will need to move some to stack B and back. So what are our options?

### Option 1.
We could move all but the last few over, sort those easily in A, then return the others
from B back into A in their correct places.

### Option 2. 
We could figure out how to get out of the way of what is already sorted in A, 
by finding the longest cyclic sorted sequence in A and remove the elements in between those to B.
then put the ones from B back to A in their proper place. Cyclic sorted means we only need to rotate 
the stack(or sequence) until the smallest value is at the top for it to be sorted. 

Lastly (for both options) we apply conditions to be considered when moving a node either way. This way the algo
can make smarter choices.

So which one will we use.... the answer is both. The version of 1 was the fastest for stacks over 210 or so,
and the 2nd was faster for the smaller stacks of less than approximately 210.

Let's look at 1 first.

## Option 1 (210 or more)

So now the problem has become how to move the values from A to B with the maximum amount of presorting
at the lowest possible move expense, and then move them back to the right place in A with the fewest moves possible. 

**Step 1. Get final positions**

We figure out where the values are supposed to go by sorting the data directly with quicksort,
and then we place the final position for a value with its node. For example:

Note that final position is the final position of the values in Unsorted,
and matches their position in the Sorted list.

| Unsorted | Sorted |  Final Position (goes with values in the unsorted list)|
|----------|--------|--------------------------------------------------------|
|	5      |   2    |  3                                                     |
|	6      |   3    |  4                                                     |
|	3      |   5    |  2                                                     |
|	2      |   6    |  1                                                     |
|	7      |   7    |  5                                                     |

We now know that 3 ends in the second postion, 6 in the 4th, etc.
This information will be very valuable for the rest of the algorithm.

**Step 2. Move to stack B**

I will be using 500 as an example stack size in the explanation from here on.

Now we use the information from step 1 to break up stack a into blocks and move it into B.
We do this recursively by taking the values that end in the top half(the 250 smallest values, 
with final positions 0 - 249) of the stack and moving them to B, each time finding the value 
that requires the least number of moves(rotations or reverse rotations) to bring to the top of 
stack A and push it to B. That is the one that we send next. But wait.. if we always take the cheapest
to send, we will sometimes reverse rotate to get the cheapest to the top, and this part of the algo builds
upward rotating momentum, largely due to the rotation(or double) after moving to B(see the paragraph after next).
So we should only do so when the node we want is on the very bottom(experimentation shows we shouldn't go farther)
otherwise the algorithm is fighting itself. 

Then we do it for the next third of the original value, 500 / 3 = 166, so the next 166 go(final 
positions 250 - 415).

This is where the recursion comes in and we use same process with the remaining values in A.
So after the first 416(250 + 166) values are gone to B, we are left with 84 values, so then we send
the next 42 because 84 / 2 = 42 and then the next 24 because 84 / 3 = 24. We repeat this recursion 
until less than 10 remain in stack A. Why break it up like this? Numerous schemes were tried for this 
recursion and this provided the best result on average.

It is important to note that when we send one over to B, we check if it is in the top or bottom half of its block,
for example if we are currently moving over a block of 24, is it in the smaller 12, or the larger? If in the smaller
We rotate B so it goes to the bottom, thus splitting the block into high and low halves. When we are going to
rotate here, we also check if the next value coming from A is going to be rotated up(is in the top half)
and is also not already in top position(we don't want to rotate it away), and if these conditions are met we save a move by 
using the double rotation. If neither of these occur, we check if a double swap is beneficial

Next we sort those 9 still in A, ending up with them in A using an optimized method for sorting 9
without disturbing stack B. We also can perform checks for cylic sorted, and typically use this with 
small stacks to sort them quickly if we are in luck and only need to rotate.

Now we have moved things to B, and minimized moves used while acheiving the maximum presorting. Time to 
bring it back.

**Step.3 moving back to A**

In order to move back into A we will use a greedy algorithm.

For each of the values in B(nodes of our list), we:

1. Find their 'target node' in A. The target node should be the node in stack A which is closest in 
final positon to the sending node while being larger than it. for example:

|Stack A | Stack B |  Current Target for the stack B value |
|--------|---------|---------------------------------------|
|	3    |   6     |  9                                    |
|	27   |   1     |  0                                    |
|	0    |   2     |  3                                    |
|	9    |   5     |  9                                    |

2. Look at all possible routes to bring node in B to be on top of its target
in A and set the cheapest(fewest moves) route as its return cost.

When looking for the cheapest route we must examine 6 different ways to possibly bring the nodes together.
To bring them together we need the sending node and the target node to come to the top of their respective
stacks. So why 6 routes? lets look at two example stacks again.

|Stack A | Stack B |  Current Target for the stack B value |
|--------|---------|---------------------------------------|
|	3    |   6     |  9                                    |
|	27   |   1     |  0                                    |
|	0    |   2     |  3                                    |
|	9    |   5     |  9                                    |

Let's say we are sending '1' from stack B, its target is 0.
The possible routes can be broken down into **Both move up**, **Both move down**,
**They move in opposite directions**.

Let's look at all six routes for bringing them both to the top. Since the double rotations count
as only 1 move, we must maximize our use of them.

-------------------------------------Both move upward routes-------------------------------------

Route 1: Use double rotation `rr` until the B node is at the top, then `ra` until the A node is also at top  
Route 2: Use double rotation `rr` until the B node is at the top, then `rb` until the A node is also at top  

-------------------------------------Both move downward routes---------------------------------  

Route 3: Use double rotation `rr` until the B node is at the top, then `rb` until the A node is also at top  
Route 4: Use double rotation `rr` until the B node is at the top, then `ra` until the A node is also at top  

-------------------------------------Moving opposite directions routes----------------------------------  

Route 5: Use double rotation `ra` until the B node is at the top, then `rrb` until the A node is also at top  
Route 6: Use double rotation `rra` until the B node is at the top, then `rb` until the A node is also at top  

Next We Work out which of these routes will require the fewest moves.

In our example with 0 and 1:

moving both to the top going upward will cost 2 moves, `rr` `ra`.  
moving both to the top going downward will cost 3 moves, `rrr` `rrr` `rra`.  
moving both to the top in opposite directions will cost 3 moves, `rra` `rra` `rb`.

Tie breaks must go to the node with the larger final position value. 

Once we have the minimum return cost for each node in B we compare them and find the cheapest one,
This is the one we will return using its fastest route. Thereby making the greediest choice each time.
When B is empty, the stack in back in A, cyclic sorted, and will only need to be rotated until the
smallest value(having final position 1) is at the top.

When making the greediest choice each time we notice a certain amount of debt builds up, and the sends toward
the end take large numbers of moves. In the 500 sorter we reduce this by sending nodes back half blocks at a time,
in the same intervals which they were sent. Half blocks because we broke them up that way when moving them to B
(rotating if the last push was in the smaller half of final positions). This has been written for 500 numbers 
but not yet generalized for all. For 500 it saves about 100 moves off of the average. Placing the 
average moves required around 3900. On to option 2.

## Option 2 (Less than 210)

For this method, the key is to leave behind the largest cyclic sorted set in A, so we save the cost of moving
nodes to and back from B. When I first wrote this program I hadn't heard of this, but later I found out that this
is refferred to as **Longest Increasing Subsequence** or **L.I.S.** What does this look like? Here we see the largest
sequence marked in bold.

| Unsorted | Leave  |  Stack A post removal|  Stack B post removal|
|----------|--------|----------------------|----------------------|
|	7      |   0    |                      |                      |
|	**17** |   1    |                      |                      |
|	1      |   0    |                      |                      |
|	**28** |   1    |  0                   |                      |
|	6      |   0    |  5                   |                      |
|	**0**  |   1    |  9                   | 6                    |
|	**5**  |   1    |  17                  | 7                    |
|	**9**  |   1    |  28                  | 1                    |

Notice that to get the longest possible, we must search in a loop that connects to the bottom of the stack.
We mark those in the subsequence with a leave flag, so when we move over the rest we dont include them
in searches for cheapest nodes. 


**NOTE:** For this method to be more effective than my other one, we need to leave at least
14 percent of the stack behind. For 100 numbers we typically get 19 - 20. But as we increase in stack size
the relative chaoticness of the stack increases and the L.I.S. decreases non linearly, which is why we
should only use it up to a certain stack size before it becomes counter productive to do so. The expected max value 
for L.I.S. is given by:

				subsequence length = 2 * √total length

so for 100, we have 2 * sqrt(100) = 20. With 100 thats 20%, So the method works pretty good. But for 500,
we have 2 * sqrt(500) = 45, so even the expected best case is only 9 percent of out stack.

But how can we find the largest one quickly? To check every possible way is too
computationally intensive with larger sets, While good algos for L.I.S. exist,
I didn't know this yet, So we use a bit of a (very effective) hack for the method.

We start at the smallest value to give our selves the most room to increase, although is is possible that the actual
longest will not start with the smallest, its a good bet.





