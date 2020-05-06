#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#include <stdio.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
		int n;
		struct binary_tree_s *parent;
		struct binary_tree_s *left;
		struct binary_tree_s *right;
} binary_tree_t;

typedef struct Queue
{
		struct binary_tree_s *node;
		struct Queue *next;
} que;

typedef struct binary_tree_s heap_t;


void free_que(que **h_queue);
heap_t *add_node_to_tree(heap_t **root, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const heap_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif