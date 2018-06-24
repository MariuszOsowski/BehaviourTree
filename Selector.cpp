//
// Created by Mariusz Osowski on 18.06.2018.
//

#include "Selector.h"

namespace BehaviourTree {

    Node::Status Selector::tick() {
        for(auto& child : children) {
            if(isRunning() && !child->isRunning()) continue;

            status = child->tick();

            switch (status) {
                case Status::RUNNING:
                    return Status::RUNNING;

                case Status::SUCCESS:
                    return Status::SUCCESS;

                default:
                    break;
            }
        }

        return Status::FAILURE;
    }

    Selector::Ptr Selector::create() {
        return std::make_shared<Selector>();
    }
}