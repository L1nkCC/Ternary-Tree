/--------------------------------------------------------\
		   Ternary Trees - README
		File: ternary.cpp
		Author: Connor Leslie
		Date: 3/5/21
		Description: takes a list of numbers 
			and creates a ternary tree.
\---------------------------------------------------------/
		    EXTRA CREDIT ATTEMPT
		The program has a #define ARY to 
		define the "-ary" of the tree. 
		Ei: 2 -ternary, 3- quadnary, ...
struct tnode
	holds an array of ints "data" that holds the values in the tree.
	holds a pointer of tnode in "children" of ARY+1. The appropriate number of holes in data 
func createNode
	Creates a Tnode* with either no given data and all children defined to be null, or creates a
	tnode* with a passed int val as the first in it's data.
func isNull
	passes true of the tnode* passed is Null
func insert
	adds a value to the node passed. 
	Three cases:
		if the node is already filled and the child where insertVal would go does not exist create a new node with insertVal
		if the node is already filled and the child where insertVal would go does exist recursively call insert with the child and insertVal
		if the node is not filled, add insert val to correct spot in data
func strToPrint
	return the string that represents the tree from the node passed
	does recursively call strToPrint()
func main
	takes a given number of inputs from stdin and creates a tree with those ints, and prints out the tree in
		(left most child) first data (next Child) second data (....

