/*
sockets, TCP/IP.
*/

#include <chrono>
#include <ctime>


#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include "Rapid_Parsing_functions.hpp"


/*void myReplace(std::string& str,  std::string oldStr, std::string newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}*/

int main()
{
    int status;
    struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
    struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.
    host_info_list = &host_info;       //  <-----											check
    std::stringstream DataBuffer;   // stream for received data, used for converting data buffer(vector) in a stream which is used by read_xml() 
    std::stringstream OutputBuffer;
    Sked sked1;
    Sked *psked ;
    psked = &sked1;
    //std::ofstream odata_buffer("data_buffer.xml");
    std::fstream  data_buffer;
    std::string mynewstring;
    int length;
    ssize_t bytes_recieved;
    char incomming_data_buffer[1000];
    RobotMessage *p;
// allocate memory:
    char * buffer = new char [150];
    size_t pos;
    size_t ppos;
//allocate memory 
std::string mynewnewstring;
char *cstr = new char[150]; 
char *msg = new char[100];;
int len;
ssize_t bytes_sent;
std::stringbuf *backup;
std::stringstream test;



    memset(&host_info, 0, sizeof host_info);

    std::cout << "Setting up the structs..."  << std::endl;

    host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.		//AF_INET or PF_INET			check
    host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.						check
    //host_info.ai_protocol = IPPROTO_TCP; //The Transmission Control Protocol (TCP) (possibly redundant setting)				check
    host_info.ai_flags = AI_PASSIVE;     // IP Wildcard	(The socket address will be used in a call to the bind function.)										


    // FILL IN PORT NUMBER HERE!!!!!!
    status = getaddrinfo(NULL, "5151", &host_info, &host_info_list);					//5151 supports TCP - 5555 supports udp
    // getaddrinfo returns 0 on succes, or some other value when an error occured.			//both produce the same communication error though
    // (translated into human readable text by the gai_gai_strerror function).
    if (status != 0)  std::cout << "getaddrinfo error" << gai_strerror(status) ;


    std::cout << "Creating a socket..."  << std::endl;

    int socketfd ; // The socket descripter
    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
                      host_info_list->ai_protocol);

    if (socketfd == -1)  std::cout << "socket error " ;

    std::cout << "Binding socket..."  << std::endl;
    // we use to make the setsockopt() function to make sure the port is not in use
    // by a previous execution of our code. (see man page for more information)
    int yes = 1;
    status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1)  std::cout << "bind error" << std::endl ;

    std::cout << "Listen()ing for connections..."  << std::endl;
    status =  listen(socketfd, 5);
    if (status == -1)  std::cout << "listen error" << std::endl ;


    int new_sd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size = sizeof(their_addr);
    new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);
    if (new_sd == -1)
    {
        std::cout << "listen error" << std::endl ;
    }
    else
    {
        std::cout << "Connection accepted. Using new socketfd : "  <<  new_sd << std::endl;
    }

// RECEIVING............
//......................


    for(int k=1;k<500;k++) 
    {

    //std::cout << "Waiting to recieve data..."  << std::endl;

std::chrono::time_point<std::chrono::system_clock> start, end;
start = std::chrono::system_clock::now();
 
   bytes_recieved = recv(new_sd, incomming_data_buffer,1000, 0);

    // If no data arrives, the program will just wait here until some data arrives.
    if (bytes_recieved == 0) std::cout << "host shut down." << std::endl ;
    if (bytes_recieved == -1)std::cout << "recieve error!" << std::endl ;
    //std::cout << bytes_recieved << " bytes recieved :" << std::endl ;
    incomming_data_buffer[bytes_recieved] = '\0';
    

std::chrono::time_point<std::chrono::system_clock> start1= std::chrono::system_clock::now();
   
    
    DataBuffer<<incomming_data_buffer;
   
    //---take sstream for the read() function (puts data in a struct)
    if ((bytes_recieved != 0)&(bytes_recieved != -1))
    {
	sked1.clear();
	rxml_read(psked,DataBuffer);
    }
 

    
/*------------- Create the ReplyMessage -----------------*/

// --------------------------------------------------------------------------------- USE A STRINGSTREAM ---//
OutputBuffer.str("");

    p = (*psked).data();			//RobotMessage *
    (*p).Type = k+10;
    rxml_write(psked,OutputBuffer);
mynewstring = OutputBuffer.str();

OutputBuffer.flush();
//buffer has a line with the xml version

//-----------------------------------------------------------------------------------------------------------//

//mynewnewstring = mynewstring.substr(39);		//38 characters is the first line about the xml version always! UNcomment if boost library is used! 
mynewnewstring = mynewnewstring;// +'\0';

strcpy(msg, mynewstring.c_str());
//msg[mynewnewstring.length()]='\0';
//mynewnewstring = mynewnewstring +'\0';
//std::cout<<"\nReply message = "<< mynewnewstring;
//-----------------------------------------------------------------------------------------------------------------------------

/*Test Stuff*/
//std::cout << "\nsend()ing back a message..."  << std::endl;
//test.str("");
//test<<(k-1);
//std::string la = test.str();
// mynewnewstring = "<ReplyMessage Id=\""+ (la) +"\" Ts=\""+ (la) + "\"><Type>"+(la)+"</Type><Status/><Mode>2</Mode></ReplyMessage>";
/*end of test stuff*/

    len = strlen(msg);
    bytes_sent = send(new_sd, msg, len, 0);
   
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds4 = end-start;
 
std::cout << "whole duration: " << elapsed_seconds4.count() << "s\n";
     
std::chrono::duration<double> elapsed_seconds1 = end-start1; 
std::cout << "process data and send them duration: " << elapsed_seconds1.count() << "s\n";
   }

//END OF LOOP ---------------------------
    RobotMessage *f =(*psked).data();
    std::cout <<"\nLast Message Id = "<< (*f).Id<<"\n";
    std::cout << "Stopping server..." << std::endl;
    freeaddrinfo(host_info_list);
    close(new_sd);
    close(socketfd);


return 0 ;


}


