#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

// int main(int argc, char *argv[]) {
//     int sock = socket(AF_INET, SOCK_STREAM, 0);

//     struct sockaddr_in server_address;
//     server_address.sin_family = AF_INET;
//     server_address.sin_port = htons(8080);
//     inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

//     connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));

//     string search_query;
//     cout << "Enter your search query: ";
//     getline(cin, search_query);

//     send(sock, search_query.c_str(), search_query.length(), 0);

//     char buffer[1024];
//     int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
//     buffer[bytes_received] = '\0';

//     cout << "Search Results: \n" << buffer << endl;

//     close(sock);
//     return 0;
// }