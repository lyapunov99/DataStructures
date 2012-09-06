#define DEFAULT_CAPACITY 1000

class List {
public:
    List();
    List(int maxCapacity);
    void add (int elem);
    bool remove (int index);
    bool isEmpty();
    int count();
    int get (int index);
    void clear();
    void print();
    void sort (bool ascending);
    ~List();
private:
    int capacity;
    int currSize;
    int *list;
};
