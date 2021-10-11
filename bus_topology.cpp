#include "bus_topology.h"
void bus_topology::insert_node(int d_id, string msg)
{
    node nd(d_id, msg);
    node_list.push_back(nd);
}

void bus_topology::insert_link(int *l, direction d, int size)
{
    node *nd = new node[size];
    for (int i = 0; i < size; i++)
    {
        nd[i] = node_list[l[i]];
    }

    link lnk(nd, d, size);

    link_list.push_back(lnk);
}

void bus_topology::transmit(int src_ind, string msg, int seq_num, string dest_mac)
{
    node_list[src_ind].transmit(msg, seq_num, dest_mac);
}

void bus_topology::insert_link_to_node(int node_ind, int link_ind)
{
    node_list[node_ind].set_links(&link_list[link_ind], 1);
}