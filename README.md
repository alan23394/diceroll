# USAGE
The nums variable should be an array of less than `MAX\_NUMS`
numbers of type int. It is allocated in the init\_dice function to
size how\_many, so you just have to fill it.
The init function will return (0) if you give it a value for
how\_many that is larger than MAX\_NUMS.

When grabbing a number from nums, you must index it with the
nums\_counter variable.
It should NOT be indexed if nums\_counter is >= how\_many!
Remember to incrememt nums\_counter each time you take a number
from nums, to keep track of how many numbers have been taken.
Note: this all is implemented in the roll function, which
returns the result of the index.

The diceroll function does all of this for you! Simply provide
it with the amount of dice to roll, how many sides they have,
and a function to get random numbers (more on that later)! It
starts up a dice struct, fills up it's random numbers with the
extra function, rolls all the numbers, and deletes the struct.

Here are rules for the random number function:
The (*nums\_source) function pointer must be a pointer to an int
function, that takes an already allocated t\_dice pointer and
fills up it's nums pointer. It should only fill up to the
how\_many variable in the t\_dice pointer. It should return -1 on
failure (it doesn't matter what it returns if it succeeds, but
conventional wisdom says return (0)).
Place prototypes for these functions in the "random\_sources.h"
header file.
