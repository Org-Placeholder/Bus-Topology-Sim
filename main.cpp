#include "link.cpp"
#include "node.cpp"
#include "bus_topology.cpp"
#include <iostream>
int main()
{

    bus_topology b_topo;
    b_topo.insert_node(1, "DA:63:E9:11:8F:36");
    b_topo.insert_node(2, "06:C4:31:1E:B3:52");
    b_topo.insert_node(3, "D4:F2:39:8B:AD:FF");
    b_topo.insert_node(4, "26:24:3C:C7:F0:E8");

    int l[] = {0, 1, 2, 3};

    b_topo.insert_link(l, bidirectional, 4);
    b_topo.insert_link_to_node(0, 0);
    b_topo.insert_link_to_node(1, 0);
    b_topo.insert_link_to_node(2, 0);
    b_topo.insert_link_to_node(3, 0);

    cout << "[TEST CASE 1] : Unicast 'hello' from Device 1 to Device 3 on a bidirectional link" << endl;
    b_topo.transmit(0, "hello", 1, "D4:F2:39:8B:AD:FF");
    cout << "[TEST CASE 2] : Broadcast 'world' from Device 2 on a bidirectional link" << endl;
    b_topo.transmit(1, "world", 2, "FF:FF:FF:FF:FF:FF");

    bus_topology b_topo2;
    b_topo2.insert_node(1, "DA:63:E9:11:8F:36");
    b_topo2.insert_node(2, "06:C4:31:1E:B3:52");
    b_topo2.insert_node(3, "D4:F2:39:8B:AD:FF");
    b_topo2.insert_node(4, "26:24:3C:C7:F0:E8");

    b_topo2.insert_link(l, unidirectional, 4);
    b_topo2.insert_link_to_node(0, 0);
    b_topo2.insert_link_to_node(1, 0);
    b_topo2.insert_link_to_node(2, 0);
    b_topo2.insert_link_to_node(3, 0);

    cout << "[TEST CASE 3] : Unicast 'hello' from Device 3 to Device 1 on a unidirectional link." << endl;
    cout << "(The message should not reach since unidrectional link is assumed to send data in increasing index order only)" << endl;
    b_topo2.transmit(2, "hello", 1, "DA:63:E9:11:8F:36");
    cout << "[TEST CASE 4] : Broadcast 'world' from Device 2 on a unidirectional link" << endl;
    cout << "(The message will reach all devices except device 1 since unidrectional link is assumed to send data in increasing index order only)" << endl;
    b_topo2.transmit(1, "world", 2, "FF:FF:FF:FF:FF:FF");
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