//
// Created by Mariusz Osowski on 18.06.2018.
//

#ifndef BEHAVIOURTREE_DELEGATENODE_H
#define BEHAVIOURTREE_DELEGATENODE_H

#include "Node.h"

namespace BehaviourTree {

    template<class T>
    class DelegateNode : public Node {
    public:
        using Delegate = Status (T::*) ();
        using Ptr = std::shared_ptr<DelegateNode<T> >;

        Status tick() override {
            status = (object.*delegate)();
            return status;
        }

        DelegateNode(Delegate delegate, T& object) : delegate(delegate), object(object)
        {}

        static Ptr create(Delegate delegate, T& object) {
            return std::make_shared<DelegateNode<T> >(delegate, object);
        }

    protected:
        Delegate delegate;
        T& object;
    };
}

#endif //BEHAVIOURTREE_DELEGATENODE_H
