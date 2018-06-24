//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_SEQUENCE_H
#define BEHAVIOURTREE_SEQUENCE_H

#include "Composite.h"

namespace BehaviourTree {

    /**
     * Sequence nodes are used to find and execute the first child
     * that has not yet succeeded. A sequence node will return
     * immediately with a status code of failure or running when
     * one of its children returns failure or running.
     */
    class Sequence : public Composite {
    public:
        using Ptr = std::shared_ptr<Sequence>;
        virtual Status tick() override;
        virtual ~Sequence() = default;

        static Ptr create();
    protected:
    };

}


#endif //BEHAVIOURTREE_SEQUENCE_H
