#include "root/graph/elements/element.hpp"
#include "root/util/linked_list.hpp"

namespace corvine {

    struct Graph {

        LinkedList<Element> elements;

        Graph()
        {
            elements = LinkedList<Element>();
        }

    };

}