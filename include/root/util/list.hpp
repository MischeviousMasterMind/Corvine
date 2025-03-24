#include <vector>

namespace corvine {
    template<typename T>
    class List
    {
        std::vector<T> list = {};
        size_t length = 0;

    public:
        List() {}

        void push(T element)
        {
            list.push_back(element);
            length++;
        }

        T pop()
        {
            T element = list.at(list.size - 1);
            list.pop_back();
            length--;
            return element;
        }

        T get(int i)
        {
            return list[i];
        }

        size_t size()
        {
            return length;
        }

        bool contains(T element)
        {
            for(T e : list)
            {
                if(e == element) return true;
            }

            return false;
        }

        size_t indexOf(T element)
        {
            for(size_t i = 0; i < length; i++)
            {
                if(list[i] == element)
                {
                    return i;
                }
            }

            return -1;
        }

        T *toArray()
        {
            T array[] = new T[list.size];

            for(int i = 0; i < list.size; i++)
            {
                array[i] = list[i];
            }

            return array;
        }
    };
}