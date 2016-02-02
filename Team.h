#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
class Team{
public:
	string name;
	double Asm,pya,dpya,rya,drya,to,dto,pendif,rettd,psm = 0;


	Team(){};
	Team(string n, double a, double py, double dp, double ry, double dr,double to, double dt, double pnd ,double re); 
	
	string get_name();
	double get_asm();
	double get_pya();
	double get_dpy();
	double get_rya();
	double get_drya();
	double get_to();
	double get_dto();
	double get_pendif();
	double get_rettd();
	double get_psm();
	void to_string();
};