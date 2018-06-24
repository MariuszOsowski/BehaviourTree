//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_SELECTOR_H
#define BEHAVIOURTREE_SELECTOR_H

#include "Composite.h"

namespace BehaviourTree {

    /**
     * Selector nodes are used to find and execute the first child
     * that does not fail. A selector node will return immediately
     * with a status code of success or running when one of its
     * children returns success or running
     */
    class Selector : public Composite {
    public:
        using Ptr = std::shared_ptr<Selector>;
        virtual Status tick() override;
        virtual ~Selector() = default;

        static Ptr create();
    protected:
    };

}


#endif //BEHAVIOURTREE_SELECTOR_H
