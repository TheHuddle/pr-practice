#!/usr/bin/env python3
#Written for python3.9

from random import randint
import sys, time

def backspace(count=1,out=sys.stdout):
    out.write('\b' * count)
    out.flush()

def bogoprint(msg, delay=0.2):
    '''Prints a string with a nice random effect:
    
    Arguments:
     msg - the string to be printed (ASCII-only)
     delay - the average delay between correctly printed characters (in seconds)
    '''

    g = (ord(char) for char in msg)

    #Calculate the delay per attempt that results in ~1 character per second
    delay_calc = delay / (126-32 + 1)

    try:
        i = next(g)
        while True:

            #randomly generate and print a valid ASCII character
            #(the range 32-126 are all single-width printables)
            c = randint(32,126)
            sys.stdout.write(chr(c))
            sys.stdout.flush()

            if i == c:
                i = next(g)

            else:
                backspace()

            time.sleep(delay_calc)

    except StopIteration:
        sys.stdout.write('\n')
        sys.stdout.flush()

#function demo for direct execution.
if __name__ == "__main__":
    
    msg = "Hello, world!"
    delay = 0.2
    
    #unpack provided arguments if they exist
    if len(sys.argv) > 1:
        msg = sys.argv[1]
    if len(sys.argv) > 2:
        delay = float(sys.argv[2])
    
    bogoprint(msg, delay)
