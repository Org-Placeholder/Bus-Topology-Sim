#pragma once
#include "link.cpp"
#include "node.cpp"

#include <vector>
#include <string>
using namespace std;
class bus_topology
{
    vector<node> node_list;
    vector<link> link_list;

public:
    bus_topology()
    {
    }
    void insert_node(int d_id, string msg);

    void insert_link(int *l, direction d, int size);

    void transmit(int src_ind, string msg, int seq_num, string dest_mac);

    void insert_link_to_node(int node_ind, int link_ind);
};
