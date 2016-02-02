/*
Created by : Aldo Aldo
UIN : 624000908
CSCE 315 Project 1 
This program Read Inputs of the NFL team from stats.txt file
and do some calculations with it
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
#include "Team.h" //includes a team class object

using namespace std;

int main(){
	ifstream file;
	string line;
	string name = "";
	bool oneline = false;		// bool to notify if a line has been read
	vector<Team> Vdata;			// The vector of objects
	vector<double> VASM,VPSM;	// Vector of ASM and PSM values for the stats calculations
	double n0,n1,n2,n3,n4,n5,n6,n7,n8 = 0;

	file.open("Stats.txt");
	int i= 0;
	while(file.good()){ 
		file >> line;
		regex e("(49)?([A-Za-z]+)(\\.)?"); // use regex to distinguish between string and double
		bool match = regex_match(line,e);
		if (match){ // if the input match the regex, means it is the name of the team
			name += line + " ";
 		}else{		// if it is a number
			switch(i) // use a counter "i" to determine what type of number it is
			{
				case 0 :
					n0 = stod(line);
					i++;
					break;
				case 1 :
					n1 = stod(line);
					i++;
					break;
				case 2 :
					n2 = stod(line);
					i++;
					break;
				case 3 :
					n3 = stod(line);
					i++;
					break;
				case 4 :
					n4 =stod(line);
					i++;
					break;
				case 5 :
					n5 = stod(line);
					i++;
					break;
				case 6 :
					n6 = stod(line);
					i++;
					break;
				case 7 :
					n7 = stod(line);
					i++;
					break;
				case 8 :
					n8 =stod(line);// if it is the last num of the line, we should reset the counter
					i=0;
					oneline=true;	// one line has been read
					break;
				default:
					cout << "something is wrong !" << endl;
			}//switch	
		}//else
		if (oneline){ 	// make an object after each line is read
			Team temp = Team(name,n0,n1,n2,n3,n4,n5,n6,n7,n8);
			Vdata.push_back(temp);
			oneline = false;
			name =" "; // reset the name
		} 
		
	}//while
	
	// This section is the printing sections of the data.
	//.................................................
	cout << "Name \t\t\t ASM \t\t PYA \t\t DPYA \t\t RYA \t DRYA \t TO \t DTO \t PENDIF  RETTD \t PSM\n " ;
	for(int i = 0; i <= Vdata.size()-1;i++){
		Vdata.at(i).to_string();
	}
	// ................................................
	
	//fill the ASM and PSM vectors
	for (int i = 0; i <= Vdata.size()-1;i++){
		VASM.push_back( Vdata.at(i).get_asm());
		VPSM.push_back( Vdata.at(i).get_psm());
	}
	
	//set the variables
	double TotASM , TotPSM, meanA, meanP, size, SDA,SDP,tempA,tempP, maxA,maxP = 0;
	size = Vdata.size();	
	//assigning the total of ASM and PSM and dtermining the max numbers
	for (int i = 0 ;i <= VASM.size()-1 ; i++){
		TotASM += VASM.at(i);
		TotPSM += VPSM.at(i);
		if (VASM.at(i) > maxA){
			maxA = VASM.at(i);
		}
		if (VPSM.at(i) > maxP){
			maxP = VPSM.at(i);
		}
	}
	
	// calculate the means for the ASM and PSM
	meanA = TotASM / size;
	meanP = TotPSM / size;
	
	// Standard deviation calculation
	// .............................................
	for(int i = 0 ; i <= size-1; i++){
		tempA += (VASM.at(i)-meanA)*(VASM.at(i)-meanA);
		tempP += (VPSM.at(i)-meanP)*(VPSM.at(i)-meanP);		
	}
	cout << tempP << endl;
	SDA = sqrt(tempA/(size-1));
	SDP = sqrt(tempP/(size-1));
	//...............................................
	
	//Calculate The R-value
	//................................................
	double Rval;
	for (int i = 0; i < size-1 ; i++){
		Rval += ((VASM.at(i) - meanA)/SDA)*((VPSM.at(i) - meanP/SDP));
	}
	Rval = Rval / (size -1) ;
	//................................................
	
	
	// print the stats
	cout << "\n\n\nNumber of teams : " <<size << endl;
	cout << "Mean of ASM : " << meanA << endl;
	cout << "Mean of PSM : " << meanP << endl;
	cout << "Standard Deviation ASM : " << SDA << endl;
	cout << "Standard Deviation PSM : " << SDP << endl;	
	cout << "Max ASM : " << maxA << endl;
	cout << "Max PSM : " << maxP << endl;
	cout << "The R value : " << Rval << endl;
	
	file.close();
}