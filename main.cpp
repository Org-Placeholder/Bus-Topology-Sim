#include "link.cpp"
#include "node.cpp"

int main()
{
    node x(1, "Ramesh");
    node y(2, "Siresh");
    node z(3, "Ganpat");
    node w(4, "K");
    node nodes[4] = {x, y, z, w};
    link l(nodes, unidirectional, 4);
    link* links = &l;
    nodes[0].set_links(links, 1);
    nodes[1].set_links(links, 1);
    nodes[2].set_links(links, 1);
    nodes[3].set_links(links, 1);

    nodes[0].transmit("hello", 1, "K");
    nodes[1].transmit("bye", 2, "FF:FF:FF:FF:FF:FF");

    return 0;
}