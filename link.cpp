#include "link.h"
#pragma once

void link::transmit(dataframe data)
{

    int i = 0;
    if (dir == unidirectional)
    {
        //if the link is unidirectional, only nodes that are defined after the source nodes will get the message.
        //ie - direction of transmission is in increasing order of node list index.
        while (nodes[i].get_mac_address() != data.get_src_mac_address() && i < num_nodes)
        {
            i++;
        }
        i++;
    }

    for (; i < num_nodes; i++)
    {
        if (data.get_src_mac_address() != nodes[i].get_mac_address())
        {
            nodes[i].recieve(data); 
        }
    }
}