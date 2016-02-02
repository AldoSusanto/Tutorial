
public class Team {

	String name;
	double asm,pya,dpy,rya,drya,to,dto,pendif,rettd,psm;

	
	public Team(String n, double A, double P,double D, double R, double DR, double T, double DT, double PE, double RE){
		name = n;
		asm = A;
		pya = P;
		dpy = D;
		rya = R;
		drya = DR;
		to = T;
		dto = DT;
		pendif = PE;
		rettd = RE;
		psm = (3.17*rettd) - (0.06*pendif) + (61.67*pya) +(26.44*rya) - (2.77*to) - (67.5*drya) - (22.79*drya) + (3.49*dto);
	}
	
	public String getname(){
		return name;
	}
	
	public double getasm(){
		return asm;
	}
	
	public double getpya(){
		return pya;
	}
	
	public double getdpy(){
		return dpy;
	}
	
	public double getrya(){
		return rya;
	}
	
	public double getdrya(){
		return drya;
	}
	
	public double getto(){
		return to;
	}
	
	public double getdto(){
		return dto;
	}
	
	public double getpendif(){
		return pendif;
	}
	
	public double getrettd(){
		return rettd;
	}
	
	public double getpsm(){
		return psm;
	}
	
	public String toString(){
		System.out.println( name + "\t" + asm + "\t" + pya + "\t" + dpy + "\t" + rya + "\t" + drya + "\t" + to + "\t" + dto + "\t" + pendif + "\t" + rettd + "\t" + psm);
		return "asd";
		
	}
}
