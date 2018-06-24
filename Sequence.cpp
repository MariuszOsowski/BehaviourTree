//
// Created by Mariusz Osowski on 18.06.2018.
//

#include "Sequence.h"

namespace BehaviourTree {
    Node::Status Sequence::tick() {
        for(auto& child : children) {
            if(isRunning() && !child->isRunning()) continue;

            status = child->tick();

            switch (status) {
                case Status::RUNNING:
                    return Status::RUNNING;

                case Status::FAILURE:
                    return Status::FAILURE;

                default:
                    break;
            }
        }

        return Status::SUCCESS;
    }

    Sequence::Ptr Sequence::create() {
        return std::make_shared<Sequence>();
    }
}
