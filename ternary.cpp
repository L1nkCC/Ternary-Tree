//-----------------------------------------------------------------------------------
//ternary.cpp
//Author: Connor Leslie
//Date: 3/4/21
//Class: CS315
//Description: commplete a design for a ternary tree with the greater on the right
//-----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;


//This variable will define the size of the data in the tree. ex: 2 makes a ternary Tree; 3 makes a quad
#define ARY 2



//int Node struct
//holds both int to compare to and pointers to it's left, middle and right children
struct tnode{
	//array for each direction for children
	tnode* children[ARY+1];

	//partial array for each data entry
	int data[ARY];
	int dataLen;
};



//isNull()
//returns true if node is pointing to nothing
bool isNull(tnode* node){
	if(node == NULL)
		return true;
	return false;
}


//createNode
//both of the following create a node with the data given
tnode* createNode(){
	tnode* node = (tnode*)malloc(sizeof(tnode));  //allocate memory
	node-> dataLen = 0;
	for(int i = 0; i < ARY+1; i++){
		node->children[i] = NULL;	//set all children to NULL
	}
	return node;
}
		
tnode* createNode(int data1){//accepts the first data entry
	tnode* node = createNode();
	node->data[0] = data1;
	node->dataLen = 1;
	return node;
}


/*
strToPrint()
creates a string that prints out the tree steming from a passed node
recursive
Had issues with the spaces so each space is commented with a "Code" which corresponds to it's spot in the example
Example:
	((0=(2)+2)-2=4)-4=(5=5)+6#((7)-8=((9=12)-14=(15)+15#(17))+18#(19=19))
*/
string strToPrint(tnode* node){
	if(isNull(node)) //Safety not end case
		return "Error: accessing NULL node in strToPrint()\n";
	string returnStr = "";//initialize returnStr

	//if the first child is not null
	if(node->children[0] != NULL){
		//
		returnStr = returnStr + "(" + strToPrint(node->children[0])+ ") "; // adds space after the first child  Code: '-'
	}
	for(int i = 0; i < node->dataLen; i++){
		returnStr = returnStr + to_string(node->data[i]);
		if(i != node->dataLen-1)
			returnStr = returnStr + " ";//add space after everydata except the last one  code: '='
		if(node->children[i+1] != NULL){
			if(i+1 == node->dataLen)
				returnStr = returnStr +" "; //add a space before  Code: '#'
			returnStr = returnStr + "(" + strToPrint(node->children[i+1])+")";
			if(i+1 != node->dataLen)
				returnStr = returnStr +" ";  // add a space after every child except the last Code: '+'
		}
	} 
	
	return returnStr; //return string
}

//insert
//add "insertVal" to the tree from the node given
//recursive
//returns true if node is not null and the process is completed
bool insert(tnode* node, int insertVal){
	if(isNull(node))
		return false;
	//small is used to find the hole between data points. ex:  _ d1 _ d2 _     (d2 & d1 represent the values in data)
	int small = -1;                                      //   -1    0    1
	for(int i = 0; i < node->dataLen; i++){
		if (node->data[i] < insertVal)
			small = i;
	}
	small++;//shift the holes of small into arry indexes   ex: _ d1 _ d2 _
							//         0    1    2 
	if(node->dataLen >= ARY){ //if node is filled
		if(isNull(node->children[small])){			//if the child insert val doesn't exist
		       node->children[small] = createNode(insertVal);	//create a new node that has only insertVal
		}else{							//else
	 		insert(node->children[small], insertVal);	//call insert on the correct child with insertVall  --Recursive
		}		
	}else{//if node is not filled

		for(int j = node->dataLen; j > small; j--){ //shift the values in node->data over to make room for insertVal
			node->data[j] = node->data[j-1];
		}
		node->data[small] = insertVal;          	//add insertVal to the right location
		node->dataLen = node->dataLen + 1;		//increase the length to correspond correctly to data's length
	}
	return true;

}


//main()
//passed number of ints to be put into a tree,
//takes those ints from standard in and creates and prints the corresponding tree
int main(int argc, char* argv[]){
	int numOfInputs = stoi(argv[1]);
	//input the first Value
	int inputVal;
	cin >> inputVal;
	tnode* headNode = createNode(inputVal); // create the head node with the first input

	//accept all but the first ints from standard input until numOfInputs is hit.
	for(int i = 0; i <numOfInputs - 1; i++)
	{
		cin >> inputVal;
		insert(headNode, inputVal);//add inputVal to tree
	}
	string printThis = strToPrint(headNode); //get the string that represents the tree
	cout << printThis << endl;		 //print the string that represents the tree
	return 0;
}

























