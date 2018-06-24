//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_FUNCTIONNODE_H
#define BEHAVIOURTREE_FUNCTIONNODE_H

#include "Node.h"

namespace BehaviourTree {

    class FunctionNode : public Node {
    public:
        using Function = Status (*)();
        virtual Status tick() override;
        virtual ~FunctionNode() = default;
        FunctionNode(Function function);

        static Node::Ptr create(Function function);
    protected:
        Function function = nullptr;
    };

}


#endif //BEHAVIOURTREE_FUNCTIONNODE_H
