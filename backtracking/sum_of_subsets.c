#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*== Problem ==*/

//Implement the Backtracking algorithm for the Sum-of-Subsets problem
//find all combinations of the following numbers that sum to W = 52
//w1 = 2, w2 = 10, w3 = 13, w4 = 17, w5 = 22, w6 = 42


//I will use tree to solve this backtracking problem
//It is easy to implement with tree structure
//because state-space tree of this problem is a binary tree.
typedef bool* State;

//parent will be used when we have to free();
struct TreeNode {
	State include;
	struct TreeNode* parent
	struct TreeNode* left_child;
	struct TreeNode* right_child;
};

//I wii use Queue for create state space tree;
//This queue is only for state-space tree:)
//I implement queue with singly linked-list.
struct QueueNode{
	struct QueueNode* previous;
	struct QueueNode* next;
	struct TreeNode* data;
};

//find last node and add node
void enqueue(QueueNode* head_pointer, QueueNode* e, TreeNode* t){
	QueueNode* temp = head_pointer;
	
	//when queue is empty
	if(header_pointer == NULL){
		header_pointer = e;
		e->previous = NULL;
	}
	else{
		while(temp->link != NULL) temp = temp->link;
		temp->next = e;
		e->previous = temp;
	}


	e->next = NULL;
	e->data = t;
}

//move head pointer to next node and free(previous node)
void dequeue(QueueNode* head_pointer){
	head_pointer = head_pointer->next;
	
	free(head_pointer->previous);
	head_pointer->previous = NULL;
}


//return pointer of state-space-tree root
TreeNode* const createSpaceStateTree(int const depth){
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode)*1);
	QueueNode* header_pointer = NULL;
	
	//enqueue root
	QueueNode* e = (QueueNode*)malloc(sizeof(QueueNode)*1);
	enqueue(head_pointer, e, root);

	//we have to more nodes in state space tree 
	//depth of root is 0
	for(int i = 1; i <= depth; ++i){
		TreeNode* temp = header_pointer->data;
		temp -> left_child = (TreeNode*)malloc(sizeof(TreeNode));
		temp -> right_child = (TreeNode*)malloc(sizeof(TreeNode));
		
		QueueNode* e = (QueueNode*)malloc(sizeof(QueueNode)*1);
		enqueue(header_pointer, e, temp->left_child);
	      	enqueue(header_pointer, e, temp->right_child);

		dequeue(header_pointer);
	}
}

void sum_of_subsets_problem(TreeNode* state_space_tree, int total);
