//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_NODE_H
#define BEHAVIOURTREE_NODE_H

#include <memory>

namespace BehaviourTree {

    class Node {
    public:
        enum class Status { SUCCESS, FAILURE, RUNNING, INVALID };
        using Ptr = std::shared_ptr<Node>;

        virtual Status tick() = 0;
        virtual ~Node() = default;
        bool isRunning() {
            return status == Status::RUNNING;
        }

    protected:
        Status status = Status::INVALID;
    };
}

#endif //BEHAVIOURTREE_NODE_H
