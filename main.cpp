#include<iostream>
#include<winsock2.h>
using namespace std;

int main(){
WSADATA wsa;
SOCKET s,newsock;
string message;
const char* msg;
struct sockaddr_in server,client;
int c;
WSAStartup(MAKEWORD(2,2),&wsa);
s=socket(AF_INET,SOCK_STREAM,0);
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(8888);
bind(s,(sockaddr*)&server,sizeof(server));
puts("server started ,yay :)");
listen(s,3);
cout<<"waiting for connections"<<endl;
c= sizeof(struct sockaddr_in);
newsock=accept(s,(struct sockaddr*)&client,&c);
cout<<"COnnection accepted"<<endl;
while(true){
cin>>message;
msg=message.c_str();
send(newsock,msg,strlen(msg),0);
}

closesocket(s);
WSACleanup();
}
