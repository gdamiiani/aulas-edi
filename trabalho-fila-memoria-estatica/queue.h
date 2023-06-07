#define SIZE 25000

typedef struct {
  int numbers[SIZE];
  int position;
  int size;
} Queue;

void initialize(Queue *queue, int size);

void enqueue(Queue *queue, int number);

int dequeue(Queue *queue);

int peek(Queue queue);

void print_queue(Queue queue);

Queue create_and_fill_queue(int size);

void free_queue(Queue *queue);

double stress_test_insert(int size);

double stress_test_delete(int size);

double stress_test_print(int size);
