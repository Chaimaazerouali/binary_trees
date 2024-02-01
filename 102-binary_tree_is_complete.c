#include "binary_trees.h"

/**
* QueueNode - Struct for a queue node.
* @node: A pointer to a binary tree node.
* @next: A pointer to the next node in the queue.
*/	
typedef struct QueueNode {
binary_tree_t *node;
struct QueueNode *next;
} QueueNode;

/**
* Queue - Struct for a queue.
* @front: A pointer to the front of the queue.
* @rear: A pointer to the rear of the queue.
*/
typedef struct Queue {
QueueNode *front;
QueueNode *rear;
} Queue;

/**
* init_queue - Initializes a new queue.
*
* Return: A pointer to the new queue.
*/
Queue *init_queue(void)
{
Queue *queue = malloc(sizeof(Queue));
if (queue == NULL)
exit(EXIT_FAILURE);

queue->front = queue->rear = NULL;
return queue;
}

/**
* enqueue - Adds a binary tree node to the rear of the queue.
* @queue: A pointer to the queue.
* @node: A pointer to the binary tree node.
*/
void enqueue(Queue *queue, binary_tree_t *node)
{
QueueNode *new_node = malloc(sizeof(QueueNode));
if (new_node == NULL)
exit(EXIT_FAILURE);

new_node->node = node;
new_node->next = NULL;

if (queue->rear == NULL) {
queue->front = queue->rear = new_node;
} else {
queue->rear->next = new_node;
queue->rear = new_node;
}
}

/**
* dequeue - Removes the front node from the queue.
* @queue: A pointer to the queue.
*/
void dequeue(Queue *queue)
{
if (queue->front == NULL)
return;

QueueNode *temp = queue->front;
queue->front = temp->next;

if (queue->front == NULL)
queue->rear = NULL;

free(temp);
}

/**
* binary_tree_is_complete - Checks if a binary tree is complete.
* @tree: A pointer to the root node of the tree to check.
*
* Return: 0 if tree is NULL, 1 if the tree is complete.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
return 0;

Queue *queue = init_queue();
int null_seen = 0;

enqueue(queue, (binary_tree_t *)tree);

while (queue->front != NULL) {
binary_tree_t *current = queue->front->node;
dequeue(queue);

if (current->left != NULL) {
if (null_seen)
return 0;
enqueue(queue, current->left);
} else {
null_seen = 1;
}

if (current->right != NULL) {
if (null_seen)
return 0;
enqueue(queue, current->right);
} else {
null_seen = 1;
}
}

return 1;
}

