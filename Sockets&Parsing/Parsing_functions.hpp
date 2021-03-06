#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <sstream>
#include <list>
//#include <iostream>
//#include <sstream>
#include <cstring>      // Needed for memset

//#include <boost/date_time/gregorian/gregorian.hpp>

//typedef boost::gregorian::date Date;

/*typedef struct sFrame
{
  	std::string X;
	std::string Y;
	std::string Z;
	std::string Rx;
	std::string Ry;
	std::string Rz;
} Frame, FFrame;	

typedef struct sJoints
{
 	std::string J1;	
	std::string J2;
	std::string J3;
	std::string J4;
	std::string J5;
	std::string J6;
} Joints, FJoints;
 
typedef std::vector<sFrame> SkedFrame;
typedef std::vector<sJoints> SkedJoints;*/

struct RobotMessage
{
  unsigned int Type;
  std::string Status;
  std::string Mode;
  float Time;
  std::list<std::string> Frame;
  /*
  	std::string X;
	std::string Y;
	std::string Z;
	std::string Rx;
	std::string Ry;	
	std::string Rz;
  */
  std::list<std::string> Joints;
  /*
 	std::string J1;
	std::string J2;
	std::string J3;
	std::string J4;
	std::string J5;
	std::string J6;
   */			

  float FTime;
  std::list<std::string> FFrame;
  std::list	<std::string> FJoints;
  
  std::string Id;
  std::string Ts;
};
 
typedef std::vector<RobotMessage> Sked;


void read(Sked *sked, std::istream & is );
void write( Sked *sked, std::ostream & os );
