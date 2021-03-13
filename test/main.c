//
// ==================================
// libeom
//
// an open source c library.
// ==================================
//
// main.c
//
// Eric Meehan
// 2/18/21
//
//

#include "../libeom.h"

#include "../Networking/Nodes/PeerToPeer.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>



void * server_function(void *arg)
{
    printf("Server running.\n");
    struct PeerToPeer *p2p = (struct PeerToPeer *)arg;
    struct sockaddr *address = (struct sockaddr *)&p2p->server.address;
    socklen_t address_length = (socklen_t)sizeof(p2p->server.address);
    while (1)
    {
        int client = accept(p2p->server.socket, address, &address_length);
        char request[255];
        memset(request, 0, 255);
        read(client, request, 255);
        char *client_address = inet_ntoa(p2p->server.address.sin_addr);
        printf("\t\t\t%s says: %s\n", client_address, request);
        close(client);
        short found = 0;
        for (int i = 0; i < p2p->known_hosts.length && !found; i++)
        {
            if (strcmp(client_address, p2p->known_hosts.retrieve(&p2p->known_hosts, i)) == 0)
            {
                found = 1;
            }
        }
        if (!found)
        {
            p2p->known_hosts.insert(&p2p->known_hosts, p2p->known_hosts.length, client_address, sizeof(client_address));
        }
    }
    return NULL;
}

void * client_function(void *arg)
{
    struct PeerToPeer *p2p = arg;
    while (1)
    {
        struct Client client = client_constructor(p2p->domain, p2p->service, p2p->protocol, p2p->port, p2p->interface);
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        for (int i = 0; i < p2p->known_hosts.length; i++)
        {
            client.request(&client, p2p->known_hosts.retrieve(&p2p->known_hosts, i), request);
        }
    }
}

int main()
{
    struct PeerToPeer p2p = peer_to_peer_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY, server_function, client_function);
    p2p.user_portal(&p2p);
}
