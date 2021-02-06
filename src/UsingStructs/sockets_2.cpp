#include <iostream>
#include <memory>
#include <windows.h>
#include <winsock2.h>

#define DEFAULT_PORT "27015"

//g++ sockets_2.cpp -o sockets_2.exe -lws2_32

struct addrinfo {
  struct IPv4_sockaddr{
    uint16_t  sa_family;
    char    sa_data[14];
  };

  int ai_flags, ai_family, ai_socktype, ai_protocol;
  std::size_t ai_addrlen;
  IPv4_sockaddr* ai_addr;
  char*     ai_canonname;
  std::shared_ptr<addrinfo> ai_next;

  void TCP_Init(){
    ZeroMemory(this, sizeof(addrinfo));
    ai_family = AF_UNSPEC;
    ai_socktype = SOCK_STREAM;
    ai_protocol = IPPROTO_TCP;
  }
};

class WSA_Connector{
  WSADATA wsaData_;
  WORD wsa_word = MAKEWORD(2,2);
  addrinfo* result = nullptr;
  addrinfo*    ptr = nullptr;
  addrinfo  hints;

public:
  WSA_Connector(){
    if(WSAStartup(wsa_word, &wsaData_)){
      std::cerr << "[ERROR]: Startup failure." << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  ~WSA_Connector(){
    WSACleanup();
  }

  //FILE_STAT: Incomplete
};

int main() {
  WSA_Connector socket_dev;
  std::cout << "Success init." << std::endl;
  return EXIT_SUCCESS;
}