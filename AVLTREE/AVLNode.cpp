//
// Created by amirziya on 12/11/25.
//

#include "AVLNode.h"

#include <iterator>
#include <bits/ranges_base.h>

AVLNode::AVLNode(const int ele) {
    left = right = nullptr;
    height = 1;
    value = ele;
}
