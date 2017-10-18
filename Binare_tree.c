
#include<stdio.h>
#include<stdlib.h>
typedef struct BIN_TREE{
int value;
struct BIN_TREE *right;
struct BIN_TREE  *left;
}bin_tree;

typedef struct QUEUE{
	struct QUEUE *next;
	int value;
}Queue;

bin_tree *initree(int val);
void printleft_infix(bin_tree *tree);
void add_left(int val,bin_tree *tree);
void add_right(int val,bin_tree *tree);
void set_value(int val,bin_tree *tree);


//queue
Queue *init_queue();
int is_empty(Queue *queue);
void enqueue(Queue *queue,int val);
int dequeue(Queue *queue);
int len_queue(Queue *queue);

int main(int argc, char *argv[])
{	
	bin_tree *tree=initree(1);
	add_left(2,tree);
	add_left(3,tree->left);
	add_right(4,tree->left);
	add_right(5,tree);
	printleft_infix(tree);
	set_value(15,tree);
	printleft_infix(tree);
	
	Queue *queue=init_queue();
	enqueue(queue,10);
	enqueue(queue,12);
	enqueue(queue,14);
	int a=len_queue(queue);
	dequeue(queue);
	int b=len_queue(queue);
	return 0;
}



//initialisation racine
bin_tree *initree(int val)
{
  bin_tree *tree = malloc(sizeof(bin_tree));
  tree->left = NULL;
  tree->right= NULL;
  tree->value =val;
  return tree;
}

//ajout fils gauche
void add_left(int val,bin_tree *tree)
{
	if(tree->left!=NULL)
		return;
	tree->left=initree(val);
}
//ajout fils droit
void add_right(int val,bin_tree *tree)
{
	if(tree->right!=NULL)
		return;
	tree->right=initree(val);
}
//change la valeur du noeud
void set_value(int val,bin_tree *tree)
{
	tree->value=val;
}

//parcours pofondeur main gauche en infix
void printleft_infix(bin_tree *tree)
{
	if (tree==NULL)
	{	
		printf("\n");
		return ;
	}
	printleft_infix(tree->left);
	printf("- %d",tree->value);
	printleft_infix(tree->right);
}


//file
Queue *init_queue()
{
	Queue *queue = malloc(sizeof(Queue));
	queue->next=NULL;
	return queue;
}

void enqueue(Queue *queue,int val)
{
		
			Queue *temp=init_queue();
			temp->value=val;
			if(!is_empty(queue))
			{
			temp->next=queue->next;
			}
			queue->next=temp;
}

int dequeue(Queue *queue)
{
		Queue *temp=queue;
		while(temp->next->next!=NULL)
			temp=temp->next;
			
		free(temp->next);
		temp->next=NULL;
		return temp->value;
		
}

int len_queue(Queue *queue)
{
	Queue *temp =queue;
	int i=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d \n",temp->value);
		i+=1;
		
	}
	return i;
}
int is_empty(Queue *queue)
{
	return queue->next==NULL;
}



