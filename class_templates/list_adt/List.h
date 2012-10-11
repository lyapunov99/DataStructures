// C++ templates: make abstract data types even more abstract
// The big idea: define behavior without knowing what data type will be handled

template <class T>
class List {
 public:
  List();
  void push (T data);
  T pop();
  T get (int index);
  void sort();
  bool contains(T data);
  bool isEmpty();
  ~List();
 private:
  T *head;
  int currentSize;
  int maxSize;
};

template <class T>
List<T>::List()
{
  maxSize = 1000;
  head = new T[maxSize];
  currentSize = 0;
}

template <class T>
void List<T>::push(T data)
{
  if (currentSize < maxSize) {
    head[currentSize] = data;
    currentSize++;
  }
  else {
    exit(0);
  }
}

template <class T>
T List<T>::get(int index)
{
  if (index >= 0 && index < currentSize) {
    return head[index];
  }
  else {
    exit(0);
  }
}

template <class T>
bool List<T>::isEmpty()
{
  return (currentSize == 0);
}

template <class T>
List<T>::~List()
{
  delete [] head;
}
