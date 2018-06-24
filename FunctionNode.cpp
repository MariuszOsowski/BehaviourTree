//
// Created by Mariusz Osowski on 18.06.2018.
//

#include "FunctionNode.h"

namespace BehaviourTree {

    Node::Status FunctionNode::tick() {
        if(function != nullptr)
            return (*function)();

        return Status::FAILURE;
    }

    FunctionNode::FunctionNode(FunctionNode::Function function)
            :function(function){}

    Node::Ptr FunctionNode::create(Function function) {
        return std::make_shared<FunctionNode>(function);
    }
}