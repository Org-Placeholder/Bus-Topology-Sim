#pragma once
#include <string>
#include "node.h"
#include "dataframe.h"
enum direction
{
    unidirectional,
    bidirectional
};
class link
{
    node *nodes;
    direction dir;
    int num_nodes;

public:
    link(node *nds, direction d, int n)
    {
        nodes = nds;
        dir = d;
        num_nodes = n;
    }

    void transmit(dataframe data);
};
