namespace corvine
{

    template <class T>
    struct LinkedList
    {

    struct Node
    {
        Node *next;
        T data;

        Node(T data) : data(data) {}
    };

    private:
        int size;

    public:
        Node *head;

        LinkedList() {
            head = nullptr;
            size = 0;
        }

        LinkedList(T data[]) : LinkedList()
        {
            for(int i = 0; i < sizeof(data); i++)
                add(data[i]);
        }

        int size() {
            return size;
        }

        void add(T data) {
            size++;

            Node newNode = Node(data);

            if(head == nullptr)
            {
                head = &newNode;
                return;
            }

            Node *temp = head;

            while(temp.next != nullptr)
                temp = temp.next;
            
            temp.next = &newNode;
        }

        void add(int i, T data)
        {

        }

        T remove(int i)
        {

        }

        void clear()
        {
            if(head == nullptr)
                return;

            size = 0;
            Node *next = head.next;
            
            ~(*head)();
            head = nullptr;

            while(next != nullptr)
            {
                Node *temp = next;
                next = next.next;

                ~(*temp)();
            }
        }

        T operator=(const T data[])
        {
            clear();

            for(int i = 0; i < sizeof(data); i++)
                add(data[i]);
            
            return *this;
        }
    };

}