#include <stdlib.h>
#include <stdio.h>

// create a linked list node structure named node (by convention)
typedef struct node
{
	// num is a int variable
	int num;
	// next is a pointer that holds a node value
	struct node *next;
}
// typedef <struct = node> <new name = node> => so don't have to call struct node each time
node;

int main(void){
	// create root pointer to type node
	node *list = NULL;
	
	// 1. add first node to list

	// allocate memory for a new node to address n
	node *n = malloc(sizeof(node));
	
	// error check that allocation was successfull
	if (n != NULL)
	{
		// dereference n to equal value 1
		// ( below is prettier equivalent of (*n).num = 1 )
		n->num = 2;
	
		// n is last in list now, so n.next == NULL
		n->next = NULL;
	
		// list points to address n, now
		list = n;
	}
	
	// 2. add a new node to end of list

	// allocate new memory to address n
	n = malloc(sizeof(node));

	// error check memory allocation
	if (n != NULL)
	{
		// add values to the new node
		n->num = 4;
		n->next = NULL; // do I need to do this?

		// create temporary pointer to address of root node, which is list
		node *tmp = list;

		// iterate over nodes in list
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		
		// once we reach the last node, ie: where tmp->next == NULL
		// give it the address of the new n node
		tmp->next = n;
	}

  // print list
  for (node *tmp = list; tmp != NULL; tmp = tmp->next)
  {
    printf("%i\n", tmp->num);
  }

	// Free list
	while (list != NULL)
	{
		// tmp points to address of next node in list - tmp ptr initalized on each step
		node *tmp = list->next;

		// free the the node list points to
		free(list);

		// point list to the node tmp points to -
		// list ptr exists outside this loop, remembers where it's pointing
		list = tmp;
	}

	// end of program
	printf("end of program\n");
	return 0;
}