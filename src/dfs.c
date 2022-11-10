/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"
#include <assert.h>
#include <stddef.h>

void DFT(Bnode *root)
{
  // Implement DFS
  // Hint: You can use print_node, print_tree and/or print_stack.

  // Creating a stack for storing the values of the tree searched
  stack *post_search = (struct stack *)malloc(sizeof(stack));

  push(post_search, root);

  while (!isEmpty(post_search))
  {
    Bnode *head = pop(post_search);

    assert(head != NULL);

    printf("node: %2d\n", head->num);

    if (head->rchild != NULL)
    {
      push(post_search, head->rchild);
    }

    if (head->lchild != NULL)
    {
      push(post_search, head->lchild);
    }
  }
}

Bnode *make_node(int num, Bnode *left, Bnode *right)
{
  // Creates an element which holds elements of same type branching left and right, alongside an integer and a boolean value.
  Bnode *element = (struct Bnode *)malloc(sizeof(Bnode));
  element->num = num;
  element->lchild = left;
  element->rchild = right;
  element->visited = false;

  return element;
}
/*
void print_node(Bnode *p)
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(Bnode *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}
*/

void push(stack *topp, Bnode *n)
{
  struct node *card = (struct node *)malloc(sizeof(struct node));
  card->data = n;
  card->next = topp->top;
  topp->top = card;
}

bool isEmpty(stack *topp)
// Checks if the stacks is empty
{
  if (topp->top == NULL)
  {
    printf("\n the stack is empty!\n");
    return true;
  }
  else
  {
    printf("\n the stack is not empty!\n");
    return false;
  }
}

// Utility function to pop topp
// element from the stack

Bnode *pop(stack *topp)
{
  // Check is stack is empty
  if (topp->top == NULL)
  {
    printf(" the stack is empty!!");
    return NULL;
  }
  // the place-holder is assigned the value of the data top of the stack
  // the top of the stack is assigned the value of its own next, which is index of the previous card-element.
  Bnode* top_data = topp->top->data;
  node *freeer = topp->top; /* Node for freeing the top element */
  topp->top = topp->top->next;

  free(freeer);
  return top_data;
}
/*
void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
} */