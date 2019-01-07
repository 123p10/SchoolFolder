Using the program:
Run main.bat it will compile and run the program,
gcc required

Explanation of Decoder
The program takes in a dictionary of codes in the format:

Letter Binary Code
Ex.
A 01
B 100
C 0001

After the codes are entered a binary tree is created with the binary codes
as an address to the node values as a letter, all other nodes of the tree are given
the character code '\0' the null escape character as a placeholder

example tree using inputs above(left is 0)(right is 1)

              Root
           /        \

        /  \       /
            A
      /          /
                B
       \
        C

Decoding the string:
The algorithm works by going character by character in the coded string
and it traverses the tree until it reaches a node with a value the algorithm
then prints that character and goes to the top of the tree again

Example the decoded string 01
would traverse through the trees as such
'0'
            / \
               A
          /

           \
            C
'1'
A
