#include "root/graph/elements/element.hpp"
#include "root/util/linked_list.hpp"

namespace corvine {
    
    struct Folder : Element {

        bool isShown = true;
        bool isExpanded = true;
        LinkedList<Element> elements;

        Folder()
        {
            elements = LinkedList<Element>();
        }

        Folder(LinkedList<Element> elements)
        {
            this->elements = elements;
        }



    };

}