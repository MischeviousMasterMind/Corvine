#include <stdexcept>
#include <string>
#include <sstream>

namespace corvine
{
    class IndexOutOfBoundsException : public _exception
    {

    private:
        size_t index;
        size_t length;

    public:
        IndexOutOfBoundsException(size_t index, size_t length) : index(index), length(length) {}

        const char *what() const throw()
        {
            std::stringstream ss;
            ss << "Index " << index << "out of bounds for length " << length;

            return ss.str().c_str();
        }
    };

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
            T *data;

            Node() : next(nullptr), data(nullptr) {}

            Node(T &data) : next(nullptr)
            {
                this->data = &data;
            }
        };

    private:
        size_t length;
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

        LinkedList(Node &head) : LinkedList()
        {
            this->head = &head;

            Node *temp = &head;

            while (temp != nullptr)
            {
                length++;
                temp = temp->next;
            }
        }

        LinkedList(size_t initialCapacity) : LinkedList()
        {
            for (size_t i = 0; i < initialCapacity; i++)
                add(nullptr);
        }

        LinkedList(T data[]) : LinkedList()
        {
            for (size_t i = 0; i < sizeof(data); i++)
                add(data[i]);
        }

        size_t size() const
        {
            return length;
        }

        void add(T &data)
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

        bool add(size_t index, T &data)
        {
            if (index < 0 || index >= length)
                return false;

            if (index == length - 1)
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

            for (size_t i = 0; i < index - 1; i++)
                temp = temp->next;

            newNode.next = temp->next;
            temp->next = &newNode;

            return true;
        }

        T *remove(size_t index)
        {
            if (index < 0 || index >= length)
                throw IndexOutOfBoundsException(index, length);

            Node *temp = head;

            if (index == 0)
            {
                head = head->next;

                T *data = (*temp).data;
                ~(*temp)();

                return *data;
            }

            for (size_t i = 0; i < index - 1; i++)
                temp = temp->next;

            Node *removed = temp->next;
            T *data = removed->data;

            temp->next = temp->next->next;
            ~(*removed)();

            return *data;
        }

        T set(size_t index, T &data)
        {
            if (index < 0 || index >= length)
                throw IndexOutOfBoundsException(index, length);

            Node *temp = head;

            for (size_t i = 0; i < index; i++)
                temp = temp->next;

            T previousData = temp->data;
            temp->data = &data;

            return previousData;
        }

        T *get(size_t index)
        {
            if (index < 0 || index >= length)
                throw IndexOutOfBoundsException(index, length);

            Node *temp = head;

            for (size_t i = 0; i < index; i++)
                temp = temp->next;

            return temp->data;
        }

        size_t indexOf(T &data)
        {
            Node *temp = head;

            for (size_t i = 0; i < length; i++)
            {
                if (temp->data == &data)
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

        Node *getHead()
        {
            return head;
        }
    };

}