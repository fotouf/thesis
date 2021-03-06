#include <algorithm>
#include <cstring>
#include "Rapid_Parsing_functions.hpp"

using namespace rapidxml;
using namespace std;






void rxml_read(Sked *sked, std::istream & myfile)
{

/*Ts*/
   std::stringstream ssTs;
   std::string sTs;
   std::stringstream ssId;
   std::string sId;
/*Mode*/
   std::stringstream ssMode;
/*Time*/
   std::stringstream ssTime;
/*frame*/
   std::stringstream ssX;std::stringstream ssY;std::stringstream ssZ;std::stringstream ssRz;std::stringstream ssRx;std::stringstream ssRy;
   std::string sX;
   std::string sY;
   std::string sZ;
   std::string sRx;
   std::string sRy;
   std::string sRz;
/*Joints*/
   std::stringstream ssJ1;std::stringstream ssJ2;std::stringstream ssJ3;std::stringstream ssJ4;std::stringstream ssJ5;std::stringstream ssJ6;
   std::string sJ1;
   std::string sJ2;
   std::string sJ3;
   std::string sJ4;
   std::string sJ5;
   std::string sJ6;
/*FTime*/
   std::stringstream ssFTime;
/*fframe*/
   std::stringstream ssfX;std::stringstream ssfY;std::stringstream ssfZ;std::stringstream ssfRz;std::stringstream ssfRx;std::stringstream ssfRy;
   std::string sfX;
   std::string sfY;
   std::string sfZ;
   std::string sfRx;
   std::string sfRy;
   std::string sfRz;
/*fjoints*/
   std::stringstream ssfJ1;std::stringstream ssfJ2;std::stringstream ssfJ3;std::stringstream ssfJ4;std::stringstream ssfJ5;std::stringstream ssfJ6;
   std::string sfJ1;
   std::string sfJ2;
   std::string sfJ3;
   std::string sfJ4;
   std::string sfJ5;
   std::string sfJ6;

   std::stringstream ssName;
   std::string sName;


	RobotMessage f;

	rapidxml::xml_document<> doc;

   	/* "Read file into vector<char>"  See linked thread above*/
	vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
   	buffer.push_back('\0');
	//cout<<&buffer[0]<<endl; /*test the buffer */
   	doc.parse<0>(&buffer[0]); 
	xml_node<> *root_node = doc.first_node("RobotMessage");

	
	ssId << root_node->first_attribute("Id")->value();
	f.Id = ssId.str();
	//cout<<f.Id<<"\n";
	ssTs << root_node->first_attribute("Ts")->value();
	f.Ts = ssTs.str();
	int i=0;
	for (xml_node<> *data_node = root_node->first_node("Type"); data_node; data_node =data_node->next_sibling())
	{	
		i=++i;
		
		switch (i){
		case 1:							//Type
				f.Type = *(data_node->value());
				//cout<<"Type\n";
				//cout<<i;
				break;
		case 2:							//Status
				f.Status = *(data_node->value());
				//cout<<"status\n";
				//cout<<i;
				break;
		case 3:							//Mode
				ssMode << data_node->value();				
				ssMode >> f.Mode;
				//cout<<"mode\n";
				//cout<<i;
				break;
		case 4:					//Time
				ssTime << data_node->value();
				ssTime >> f.Time;
				//cout<<"time\n";
				//cout<<i;
				break;
		case 5:					//Frame
				ssX <<  data_node->first_attribute("X")->value();
    				ssX>>sX;
				ssY <<  data_node->first_attribute("Y")->value();
    				ssY>>sY;
				ssZ <<  data_node->first_attribute("Z")->value();
			    	ssZ>>sZ;
				ssRx <<  data_node->first_attribute("Rx")->value();
  			  	ssRx>>sRx;
				ssRy <<  data_node->first_attribute("Ry")->value();
			    	ssRy>>sRy;
				ssRz <<  data_node->first_attribute("Rz")->value();
			    	ssRz>>sRz;
				break;
		case 6:					//Joints
				ssJ1 <<  data_node->first_attribute("J1")->value();
    				ssJ1>>sJ1;
				ssJ2 <<  data_node->first_attribute("J2")->value();
    				ssJ2>>sJ2;
				ssJ3 <<  data_node->first_attribute("J3")->value();
			    	ssJ3>>sJ3;
				ssJ4 <<  data_node->first_attribute("J4")->value();
  			  	ssJ4>>sJ4;
				ssJ5 <<  data_node->first_attribute("J5")->value();
			    	ssJ5>>sJ5;
				ssJ6 <<  data_node->first_attribute("J6")->value();
			    	ssJ6>>sJ6;
				break;
		case 7:					//FTime
				ssFTime << data_node->value();
				ssFTime >> f.FTime;
				break;
		case 8:					//FFrame
				ssfX <<  data_node->first_attribute("X")->value();
    				ssfX>>sfX;
				ssfY <<  data_node->first_attribute("Y")->value();
    				ssfY>>sfY;
				ssfZ <<  data_node->first_attribute("Z")->value();
			    	ssfZ>>sfZ;
				ssfRx <<  data_node->first_attribute("Rx")->value();
  			  	ssfRx>>sfRx;
				ssRy <<  data_node->first_attribute("Ry")->value();
			    	ssfRy>>sfRy;
				ssfRz <<  data_node->first_attribute("Rz")->value();
			    	ssfRz>>sfRz;
				
				break;
		case 9:					//FJoints
				ssfJ1 <<  data_node->first_attribute("J1")->value();
    				ssfJ1>>sfJ1;
				ssfJ2 <<  data_node->first_attribute("J2")->value();
    				ssfJ2>>sfJ2;
				ssfJ3 <<  data_node->first_attribute("J3")->value();
			    	ssfJ3>>sfJ3;
				ssfJ4 <<  data_node->first_attribute("J4")->value();
  			  	ssfJ4>>sfJ4;
				ssfJ5 <<  data_node->first_attribute("J5")->value();
			    	ssfJ5>>sfJ5;
				ssfJ6 <<  data_node->first_attribute("J6")->value();
			    	ssfJ6>>sfJ6;
				break;
		default:
				break;
		}
	}	


f.Frame.push_back(sX);
f.Frame.push_back(sY);
f.Frame.push_back(sZ);
f.Frame.push_back(sRx);
f.Frame.push_back(sRy);
f.Frame.push_back(sRz);

f.Joints.push_back(sJ1);
f.Joints.push_back(sJ2);
f.Joints.push_back(sJ3);
f.Joints.push_back(sJ4);
f.Joints.push_back(sJ5);
f.Joints.push_back(sJ6);

f.FFrame.push_back(sfX);
f.FFrame.push_back(sfY);
f.FFrame.push_back(sfZ);
f.FFrame.push_back(sfRx);
f.FFrame.push_back(sfRy);
f.FFrame.push_back(sfRz);

f.FJoints.push_back(sfJ1);
f.FJoints.push_back(sfJ2);
f.FJoints.push_back(sfJ3);
f.FJoints.push_back(sfJ4);
f.FJoints.push_back(sfJ5);
f.FJoints.push_back(sfJ6);


(*sked).push_back(f);

}









/*
void rxml_read(Sked *sked, std::istream & myfile)
{

   RobotMessage f;

   rapidxml::xml_document<> doc;

   /* "Read file into vector<char>"  See linked thread above
   vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));
   
   buffer.push_back('\0');

   //cout<<&buffer[0]<<endl; /*test the buffer 

   doc.parse<0>(&buffer[0]); 

/*Ts
   std::stringstream ssTs;
   std::string sTs;
   std::stringstream ssId;
   std::string sId;
/*Mode
   std::stringstream ssMode;
/*Time
   std::stringstream ssTime;
/*frame
   std::stringstream ssX;std::stringstream ssY;std::stringstream ssZ;std::stringstream ssRz;std::stringstream ssRx;std::stringstream ssRy;
   std::string sX;
   std::string sY;
   std::string sZ;
   std::string sRx;
   std::string sRy;
   std::string sRz;
/*Joints
   std::stringstream ssJ1;std::stringstream ssJ2;std::stringstream ssJ3;std::stringstream ssJ4;std::stringstream ssJ5;std::stringstream ssJ6;
   std::string sJ1;
   std::string sJ2;
   std::string sJ3;
   std::string sJ4;
   std::string sJ5;
   std::string sJ6;
/*FTime
   std::stringstream ssFTime;
/*fframe
   std::stringstream ssfX;std::stringstream ssfY;std::stringstream ssfZ;std::stringstream ssfRz;std::stringstream ssfRx;std::stringstream ssfRy;
   std::string sfX;
   std::string sfY;
   std::string sfZ;
   std::string sfRx;
   std::string sfRy;
   std::string sfRz;
/*fjoints
   std::stringstream ssfJ1;std::stringstream ssfJ2;std::stringstream ssfJ3;std::stringstream ssfJ4;std::stringstream ssfJ5;std::stringstream ssfJ6;
   std::string sfJ1;
   std::string sfJ2;
   std::string sfJ3;
   std::string sfJ4;
   std::string sfJ5;
   std::string sfJ6;




   rapidxml::xml_node<> *RobotMessage = doc.first_node();
	ssId << (*RobotMessage).first_attribute()->value();
	//ssId>>sId;

	(*RobotMessage).remove_first_attribute();
	ssTs << (*RobotMessage).first_attribute()->value();
	//ssTs>>sTs;

   rapidxml::xml_node<> *Type = (*RobotMessage).first_node();
   rapidxml::xml_node<> *Status = (*Type).next_sibling();
   rapidxml::xml_node<> *Mode = (*Status).next_sibling();
	ssMode<< Mode->value();

   rapidxml::xml_node<> *Time = (*Mode).next_sibling();
	ssTime << Time->value();

   rapidxml::xml_node<> *Frame = (*Time).next_sibling();
	ssX <<  (*Frame).first_attribute()->value();
    	ssX>>sX;

	(*Frame).remove_first_attribute();
	ssY <<  (*Frame).first_attribute()->value();
    	ssY>>sY;

	(*Frame).remove_first_attribute();
	ssZ <<  (*Frame).first_attribute()->value();
    	ssZ>>sZ;

	(*Frame).remove_first_attribute();
	ssRx <<  (*Frame).first_attribute()->value();
    	ssRx>>sRx;

	(*Frame).remove_first_attribute();
	ssRy <<  (*Frame).first_attribute()->value();
    	ssRy>>sRy;

	(*Frame).remove_first_attribute();
	ssRz <<  (*Frame).first_attribute()->value();
    	ssRz>>sRz;

    rapidxml::xml_node<> *Joints = (*Frame).next_sibling();
	ssJ1 << (*Joints).first_attribute()->value();
	ssJ1>>sJ1;

	(*Joints).remove_first_attribute();
	ssJ2 << (*Joints).first_attribute()->value();
	ssJ2>>sJ2;

	(*Joints).remove_first_attribute();
	ssJ3 << (*Joints).first_attribute()->value();
	ssJ3>>sJ3;

	(*Joints).remove_first_attribute();
	ssJ4 << (*Joints).first_attribute()->value();
	ssJ4>>sJ4;

	(*Joints).remove_first_attribute();
	ssJ5 << (*Joints).first_attribute()->value();
	ssJ5>>sJ5;

	(*Joints).remove_first_attribute();
	ssJ6 << (*Joints).first_attribute()->value();
	ssJ6>>sJ6;

   rapidxml::xml_node<> *FTime = (*Joints).next_sibling();
	ssFTime << FTime->value();

   rapidxml::xml_node<> *FFrame = (*FTime).next_sibling();
	ssfX <<  (*FFrame).first_attribute()->value();
	ssfX>>sfX;

	(*FFrame).remove_first_attribute();
	ssfY <<  (*FFrame).first_attribute()->value();
	ssfY>>sfY;

	(*FFrame).remove_first_attribute();
	ssfZ <<  (*FFrame).first_attribute()->value();
	ssfZ>>sfZ;

	(*FFrame).remove_first_attribute();
	ssfRx <<  (*FFrame).first_attribute()->value();
	ssfRx>>sfRx;

	(*FFrame).remove_first_attribute();
	ssfRy <<  (*FFrame).first_attribute()->value();
	ssfRy>>sfRy;

	(*FFrame).remove_first_attribute();
	ssfRz <<  (*FFrame).first_attribute()->value();
	ssfRz >> sfRz;

   rapidxml::xml_node<> *FJoints = (*FFrame).next_sibling();
	ssfJ1 << (*FJoints).first_attribute()->value();
	ssfJ1>>sfJ1;

	(*FJoints).remove_first_attribute();
	ssfJ2 << (*FJoints).first_attribute()->value();
	ssfJ2>>sfJ2;

	(*FJoints).remove_first_attribute();
	ssfJ3 << (*FJoints).first_attribute()->value();
	ssfJ3>>sfJ3;

	(*FJoints).remove_first_attribute();
	ssfJ4 << (*FJoints).first_attribute()->value();
	ssfJ4>>sfJ4;

	(*FJoints).remove_first_attribute();
	ssfJ5 << (*FJoints).first_attribute()->value();
	ssfJ5>>sfJ5;

	(*FJoints).remove_first_attribute();
	ssfJ6 << (*FJoints).first_attribute()->value();
	ssfJ6>>sfJ6;


ssId>>f.Id;
ssTs>>f.Ts;
f.Type = (*(Type->value()));
f.Status = (*(Status->value()));
ssMode>>f.Mode;
ssTime>>f.Time;


f.Frame.push_back(sX);
f.Frame.push_back(sY);
f.Frame.push_back(sZ);
f.Frame.push_back(sRx);
f.Frame.push_back(sRy);
f.Frame.push_back(sRz);

f.Joints.push_back(sJ1);
f.Joints.push_back(sJ2);
f.Joints.push_back(sJ3);
f.Joints.push_back(sJ4);
f.Joints.push_back(sJ5);
f.Joints.push_back(sJ6);

f.FFrame.push_back(sfX);
f.FFrame.push_back(sfY);
f.FFrame.push_back(sfZ);
f.FFrame.push_back(sfRx);
f.FFrame.push_back(sfRy);
f.FFrame.push_back(sfRz);

f.FJoints.push_back(sfJ1);
f.FJoints.push_back(sfJ2);
f.FJoints.push_back(sfJ3);
f.FJoints.push_back(sfJ4);
f.FJoints.push_back(sfJ5);
f.FJoints.push_back(sfJ6);

ssFTime>>f.FTime;


(*sked).push_back(f);

}
*/

void rxml_write(Sked *sked, std::stringstream & os )
{
	ofstream buffer("Buffer.xml");
	std::string str;	
	RobotMessage *f;
	f = (*sked).data();

	const char ccType = (char)(*f).Type;		//conversion from unsinged int to char
	const char *pccType = &ccType;

	const char *pccId = ((*f).Id).c_str();		//convertion from string to const char*
	const char *pccTs = ((*f).Ts).c_str();		//convertion from string to const char*

	xml_document<> doc;
	xml_node<> *RMsg = doc.allocate_node(node_element, "ReplyMessage");
	doc.append_node(RMsg);
	xml_attribute<> *Id = doc.allocate_attribute("Id",pccId);
	(*RMsg).append_attribute(Id);
	xml_attribute<> *Ts = doc.allocate_attribute("Ts",pccTs);
	(*RMsg).append_attribute(Ts);
	xml_node<> *Type = doc.allocate_node(node_element,"Type","12");
	(*RMsg).append_node(Type);
	xml_node<> *Status = doc.allocate_node(node_element,"Status");
	(*RMsg).append_node(Status);
	xml_node<> *Time = doc.allocate_node(node_element,"Time","12");
	(*RMsg).append_node(Time);

	/*xml_node<> *Time 
	xml_node<> *Frame
	xml_node<> *Joints
	xml_node<> *FTime
	xml_node<> *FFrame
	xml_node<> *FJoints*/

	
	os<< doc;
	os<<"\0";
	str = os.str();	
	
	str.erase (remove(str.begin(), str.end(), '\n'),str.end());
	size_t pos=str.find(">");
	std::string sSecondPartofRM = str.substr(pos);	
	sSecondPartofRM.erase(remove_if(sSecondPartofRM.begin(), sSecondPartofRM.end(), ::isspace), sSecondPartofRM.end());
	sSecondPartofRM=sSecondPartofRM+"\0";
	std::string modifiedStr = str.substr(0,pos) + sSecondPartofRM;
	os.str("");
	os<<modifiedStr;
 
//	rapidxml::print(os, doc, parse_no_string_terminators); 
	//rapidxml::print(cout, doc, 0);
}

















