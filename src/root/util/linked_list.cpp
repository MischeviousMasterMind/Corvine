namespace corvine
{
    /** \class
     * @brief Linked list data type defined and used by Corvine.
     * @tparam T Generic class type
     * @author MindFlares
     */
    template <class T>
    struct LinkedList
    {
        /** \struct
         * @brief Node data type used for Corvine's linked list.
         *
         * Attributes include \c next (the pointer to the next node) and \c data (the data the Node stores)
         */
        struct Node
        {
            Node *next;
            T data;

            Node(T data) : data(data) {}
        };

    private:
        int length;
        Node *head;

    public:
        /**
         * @brief Constructs a LinkedList object with the \c head node initialized 
         * with \c nullptr and \c length intialized as \c 0
         */
        LinkedList()
        {
            head = nullptr;
            length = 0;
        }

        LinkedList(int initialCapacity) : LinkedList()
        {
            for (int i = 0; i < initialCapacity; i++)
                add(nullptr);
        }

        LinkedList(T data[]) : LinkedList()
        {
            for (int i = 0; i < sizeof(data); i++)
                add(data[i]);
        }

        int size()
        {
            return length;
        }

        void add(T data)
        {
            length++;
            Node newNode = Node(data);

            if (head == nullptr)
            {
                head = &newNode;
                return;
            }

            Node *temp = head;

            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = &newNode;
        }

        bool add(int index, T data)
        {
            if(index < 0 || index >= length)
                return false;

            if(index == length - 1)
            {
                add(data);
                return true;
            }

            length++;
            Node newNode = Node(data);

            if (index == 0)
            {
                newNode.next = head;
                head = &newNode;
                return true;
            }

            Node *temp = head;

            for(int i; i < index - 1; i++)
                temp = temp->next;

            newNode.next = temp->next;
            temp->next = &newNode;

            return true;
        }

        T remove(int index)
        {
            if(index < 0 || index >= length)
                return nullptr;
            
            Node *temp = head;

            if(index == 0)
            {
                head = head->next;

                T data = (*temp).data;
                ~(*temp)();

                return data;
            }

            for(int i = 0; i < index - 1; i++)
                temp = temp->next;
            
            Node *removed = temp->next;
            T data = removed->data;

            temp->next = temp->next->next;
            ~(*removed)();

            return data;
        }

        T set(int index, T data) {
            if(index < 0 || index >= length)
                return nullptr;
            
            Node *temp = head;

            for(int i = 0; i < index; i ++)
                temp = temp->next;
            
            T previousData = temp->data;
            temp->data = data;

            return previousData;
        }

        T get(int index)
        {
            if(index < 0 || index >= length)
                return nullptr;
            
            Node *temp = head;

            for(int i = 0; i < index; i ++)
                temp = temp->next;
            
            return temp->data;
        }

        int indexOf(T data) {
            Node *temp = head;

            for(int i = 0; i < length; i++)
            {
                if(temp->data == data)
                    return i;
            
                temp = temp->next;
            }
            
            return -1;
        }

        void clear()
        {
            if (head == nullptr)
                return;

            length = 0;
            Node *next = head->next;

            ~(*head)();
            head = nullptr;

            while (next != nullptr)
            {
                Node *temp = next;
                next = next->next;

                ~(*temp)();
            }
        }

        T operator=(const T data[])
        {
            clear();

            for (int i = 0; i < sizeof(data); i++)
                add(data[i]);

            return *this;
        }
    };

}