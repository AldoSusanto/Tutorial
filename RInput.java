/*
 * Created By : Aldo Aldo
 * UIN :624000908
 * Project 1 Dr. Ronald Ward
 * This program receives data of the NFL teams from Stats.txt then calculate data with it
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;
import java.util.regex.Pattern;

import org.apache.commons.math3.stat.descriptive.SummaryStatistics;
import org.apache.commons.math3.stat.inference.*;

public class RInput {
	private static Scanner file;	// scanner file for reading files
	public static Team temp;	
	public static Vector<Team> Vdata = new Vector<Team>(); // A vector of Team class objects
	public static double[] ASMList,PSMList; //array of ASM and PSM list of the teams
	static double  t_statistic;

	public static void main ( String args[]) throws FileNotFoundException{
		
		TTest ttest = new TTest();
		
		
		file = new Scanner(new File("Stats.txt"));
		Pattern pattern = Pattern.compile("(49)?[A-Za-z]*(.)?"); // if the regex identifies it, it means its a string
		String s = ""; 
		double n0,n1,n2,n3,n4,n5,n6,n7,n8;
		while (file.hasNextLine()){
			Scanner team = new Scanner(file.nextLine());
			while(team.hasNext(pattern)){ // if the word is a string
				s += team.next() + " "; // add it to name
			}
			n0 = team.nextDouble(); //ASM
			n1 = team.nextDouble(); //PYA
			n2 = team.nextDouble(); //DPYA
			n3 = team.nextDouble(); //RYA
			n4 = team.nextDouble(); //DRYA
			n5 = team.nextDouble(); //TO
			n6 = team.nextDouble(); //DTO
			n7 = team.nextDouble(); //PENDIF
			n8 = team.nextDouble(); //RETTD
			temp = new Team(s,n0,n1,n2,n3,n4,n5,n6,n7,n8); // Create the object
			s = ""; // reset the name for next line
			Vdata.add(temp);
		
		}//while
		
		// creat the list of ASM and PSM of the teams
		ASMList = new double[Vdata.size()];
		PSMList = new double[Vdata.size()];
		
		//figuring out the T-test
		//******************************************
		for(int i = 0; i < Vdata.size();i++){
			ASMList[i] = Vdata.get(i).getasm();
			PSMList[i] = Vdata.get(i).getpsm();
		}
		t_statistic = ttest.t(ASMList, PSMList);
		System.out.println("The T-test : "+ Double.toString( t_statistic) );
		//******************************************
		
		// using the summarystatistics class
		SummaryStatistics ASM = new SummaryStatistics();
		for(double i : ASMList){ // copying the values of array to summarystatistics object
			ASM.addValue(i);
		}
		SummaryStatistics PSM = new SummaryStatistics();
		for(double i : PSMList){
			PSM.addValue(i);
		}
		
		// print out the results
		System.out.println("The ASM Mean :" + ASM.getMean() + "\t The PSM Mean : " + PSM.getMean());
		System.out.println("The ASM SD : " + ASM.getStandardDeviation() + "\t\t The PSM Standard Deviation : " + PSM.getStandardDeviation());
		System.out.println("The ASM Max Val : " + ASM.getMax() + "\t\t\t The PSM Max Val : " + PSM.getMax());
		System.out.println("The ASM Min Val : " + ASM.getMin() + "\t\t The PSM Min Val : " + PSM.getMin());
		
		//Prints all the NFL teams
		//..........................................
		System.out.println( "Name\t\t\tASM\tPY/A\t\tDPY/A\t\tRY/A\tDRY/A\tTO\tDTO\tPENDIF\tRETTD\tPSM");
		for(int i = 0; i < Vdata.size();i++){
			Vdata.get(i).toString();
		}
		//..........................................
		

		
	}//main
	

}//RInput Class
	

