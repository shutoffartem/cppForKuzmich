struct vector
{
    vector();

    vector(int _capacity);

    ~vector();

    int size;
    int capacity;
    int* data;

    void print();

    int get_size();

    int get_capacity();

    void resize();

    void push_back(int n);

    int& operator[](int n);
};

