# USAGE
The `nums` variable in the `t_dice` struct should be an array of less than
`MAX_NUMS` numbers of type `int`. It is allocated in the `init_dice` function
to size `how_many`, so you just have to fill it. The function will return (0)
if you give it a value for `how_many` that is larger than `MAX_NUMS`.

When grabbing a number from `nums`, you must index it with the `nums_counter`
variable. It should NOT be indexed if `nums_counter >= how_many`! Remember to
incrememt `nums_counter` each time you take a number from `nums`, to keep track
of how many numbers have been taken. Note: this all is implemented in the
`roll` function, which returns the result of the index.

The `diceroll` function does all of this for you! Simply provide it with the
amount of dice to roll, how many sides they have, and a function to get random
numbers (more on that later)! It starts up a dice struct, fills up it's random
numbers with the extra function, rolls all the numbers, and deletes the struct.

Here are rules for the random number function:
The `(*nums_source)` function pointer must be a pointer to an int function,
that takes an already allocated `t_dice` pointer and fills up it's nums
pointer. It should only fill up to the `how_many` variable in the `t_dice`
pointer. It should return -1 on failure (it doesn't matter what it returns if
it succeeds, but conventional wisdom says return (0)). Place prototypes for
these functions in the `"random_sources.h"` header file.
