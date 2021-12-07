from random import randint
import sys, time

#prints a string by:
# printing a random character
# checking against the current desired character
# backspacing if the result was incorrect
#
#Arguments:
# s - the string to be printed (ASCII-only)
# d - the average delay between correctly printed characters (in seconds)
def bogoprint(s, delay=0.2):

 #generator comprehension that returns the numeric value of every character in a string, one at a time
 g = (ord(char) for char in s)

 try:
  #pre-generate the first character
  i = next(g)
  while 1:

   #randomly generate and print a valid ASCII character
   c = randint(32,126)
   sys.stdout.write(chr(c))
   sys.stdout.flush()

   if i == c:
    #if the printed character was correct, generate the next character in the sequence.
    i = next(g)

   else:
    #print a backspace to remove the incorrect generated character
    sys.stdout.write('\b')
    sys.stdout.flush()

   #add a delay between every step that corresponds to an average of one successful character every 'delay' seconds
   time.sleep(delay / (126-32 + 1))

 #when the generator runs out, a 'StopIteration' exception is generated. We use that to terminate the function.
 except StopIteration:
  sys.stdout.write('\n')
  sys.stdout.flush()

#function demo for direct execution.
if __name__ == "__main__":

 #pre-define arguments
 s = "Hello, world!"
 delay = 0.2

 #unpack provided arguments if they exist
 if len(sys.argv) > 1:
  s = sys.argv[1]
 if len(sys.argv) > 2:
  delay = float(sys.argv[2])

 #invoke the function
 bogoprint(s, delay)
