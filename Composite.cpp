//
// Created by Mariusz Osowski on 18.06.2018.
//

#include "Composite.h"

namespace BehaviourTree {
    void Composite::addChild(Node::Ptr child) {
        children.push_back(child);
    }
}