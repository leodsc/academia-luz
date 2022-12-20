class Node {
  private:
    int *value;
  public:
    Node *next;
    Node(int value);
    ~Node();
    int* getValue();
    void setNext(Node *next);
};
