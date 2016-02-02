#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Team.h"

using namespace std;
Team::Team(string n, double a, double py, double dp, double ry, double dr, double t, double dt, double pnd ,double re){
	name = n;
	Asm= a;
	pya = py;
	dpya = dp;
	rya = ry;
	drya = dr;
	to = t;
	dto = dt;
	pendif = pnd ;
	rettd = re ;
	psm = (3.17*rettd) - (0.06*pendif)+ (61.67*pya) + (26.44*rya) - (2.77*to) - (67.5*dpya) - (22.79*drya) + (3.49*dto);
}


double Team::get_asm(){return Asm;};
double Team::get_pya(){return pya;};
double Team::get_dpy(){return dpya;};
double Team::get_rya(){return rya;};
double Team::get_drya(){return drya;};
double Team::get_to(){return to;};
double Team::get_dto(){return dto;};
double Team::get_pendif(){return pendif;};
double Team::get_rettd(){return rettd;};
double Team::get_psm(){return psm;};
string Team::get_name(){return name;};
void Team::to_string(){
	cout << name << "\t " << Asm << "\t\t " << pya << "\t " << dpya << "\t " << rya << "\t " << drya << "\t " << to << "\t " << dto << "\t " << pendif << "\t " << rettd << "\t " << psm << endl;
}