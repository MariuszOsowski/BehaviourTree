//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_COMPOSITE_H
#define BEHAVIOURTREE_COMPOSITE_H

#include "Node.h"
#include <vector>

namespace BehaviourTree {
    class Composite : public Node {
    public:
        virtual void addChild(Node::Ptr child);
        virtual ~Composite() = default;
    protected:
        std::vector<Node::Ptr> children;
    };
}

#endif //BEHAVIOURTREE_COMPOSITE_H
