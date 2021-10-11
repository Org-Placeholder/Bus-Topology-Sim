#include "link.cpp"
#include "node.cpp"
#include "bus_topology.h"

int main()
{
    
   bus_topology b_topo;
    b_topo.insert_node(1,"Ramesh");
    b_topo.insert_node(2,"Siresh");
    b_topo.insert_node(3,"Rame");
    b_topo.insert_node(4,"Ramesh");
    
    int l[]={0,1,2,3};

    b_topo.insert_link(l,unidirectional,4);
    b_topo.insert_link_to_node(0,0);
    b_topo.insert_link_to_node(1,0);
    b_topo.insert_link_to_node(2,0);
    b_topo.insert_link_to_node(3,0);

    b_topo.transmit(0,"hello",1,"K");
    b_topo.transmit(1,"bye", 2, "FF:FF:FF:FF:FF:FF");
}

/*
bus_topology b_topo;
    b_topo.insert_node(1,"Ramesh");
    b_topo.insert_node(2,"Siresh");
    b_topo.insert_node(3,"Rame");
    b_topo.insert_node(4,"Ramesh");
    
    int l[]={0,1,2,3};

    b_topo.insert_link(l,unidirectional,4);
    b_topo.insert_link_to_node(0,0);
    b_topo.insert_link_to_node(1,0);
    b_topo.insert_link_to_node(2,0);
    b_topo.insert_link_to_node(3,0);

    b_topo.transmit(0,"hello",1,"K");
    b_topo.transmit(1,"bye", 2, "FF:FF:FF:FF:FF:FF");
*/