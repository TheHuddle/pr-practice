#BogoWorld

This program demonstrates a function, BogoPrint, which operates in a similar fashion to BogoSort.
It prints a string by generating a random character, printing it, then checking if it was the
correct character to print. If an incorrect character was printed, the program emits a backspace
character to erase it. This repeats until the program reaches the end of the string.

## Testing

Run `main.py` with a python3 interpreter.
Optional arguments are:

* msg - The string to print. (default = "Hello, world!")
* delay - The average time between successfully printed characters, in seconds. (default = 0.2 seconds)
