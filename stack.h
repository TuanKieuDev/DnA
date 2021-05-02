struct node {
    int data;
    struct node *link;
};
struct node *push(struct node *p, int value);
struct node *pop(struct node *p, int *value);
