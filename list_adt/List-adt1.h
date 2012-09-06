class List {
public:
    List();
    void add (int elem);
    bool remove (int k);
    bool isEmpty();
    int count();
    int get (int k);
    void clear();
    void print();
    void sort (bool ascending);
    ~List();
};
