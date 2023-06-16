struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *tail;
  struct Node *head;
};

void initialize(struct Queue *queue);

void enqueue(struct Queue *queue, int data);

int dequeue(struct Queue *queue);

int peek(struct Queue queue);

void print_queue(struct Queue queue);

struct Queue create_and_fill_queue(int size);

void free_queue(struct Queue *queue);

double stress_test_insert(int size);

double stress_test_delete(int size);

double stress_test_print(int size);
