package Inheritance;

import java.util.*;

class Employee
{
	// Declared Scanner
	Scanner sc = new Scanner(System.in) ;
	
	//Employee Data Variables
	String emp_name ;
	String address ;
	String mail_id ;
	String mobile  ;
	int emp_id ;
	
	//To Get Employee Data
	public void getData() {
		System.out.println("Enter the Employee Name : ");
		this.emp_name = sc.next();
		System.out.println("Enter address of Employee : ");
		this.address = sc.next();
		//To Check and Enter Email ID Until it's Incorrect
		boolean mailcheck=false;
		while(mailcheck==false)
		{
			System.out.println("Enter mail address             : ");
			this.mail_id = sc.next();
			mailcheck = true;
			boolean attherate = false, dot = false;
			char ch[]= this.mail_id.toCharArray();
			for(int i=0; i<this.mail_id.length();i++)
			{
				if(ch[i]=='@')
				{
					attherate = true;
				}
				else if(ch[i]=='.')
				{
					dot = true;
				}
			}
			if(!dot | !attherate)
			{
				System.out.println("Invalid Mail ID!, Enter again");
				mailcheck=false;
			}
		}
		//To Check and Enter Mobile Number Until it's Incorrect
		boolean mobilecheck=false;
		while(mobilecheck==false)
		{
			System.out.println("Enter mobile number         : ");
			this.mobile = sc.next();
			mobilecheck=true;
			char ch[]= this.mobile.toCharArray();
			if(ch[0]=='0' & ch.length!=10)
			{
				System.out.println("Invalid Mobile Number!, Enter again");
				mobilecheck=false;
			}
		}
		System.out.println("Enter Employee ID             : ");
		this.emp_id = sc.nextInt();
	}
	
	//To Display Employee Data
	public void Display() {
		System.out.println("Employee ID     : "+emp_id);
		System.out.println("Employee Name: "+emp_name);
		System.out.println("Address             : "+address);
		System.out.println("Mobile Number : "+mobile);
		System.out.println("Mail address     : "+mail_id);
	}
	
	//Allowances of the Employee
	double da , hra , pf , club , gross , net ;
	
	//To Calculate Salary
	public void calculateSal(double basic)
    {
        this.da = basic*0.97 ;
        this.hra = basic*0.1 ;
        this.pf = basic*0.12 ;
        this.club = basic*0.001 ;
        this.gross = basic - this.pf ;
        this.net = this.gross - this.hra - this.club ;
    }
	
	//To Display Salary and allowances of Employee
	public void DisplaySalary(double basic) {
		System.out.println("Basic Salary                      : " + basic);
		System.out.println("Dearness Allowance          : " + this.da );
		System.out.println("House Rent Allowance      : " + this.hra);
		System.out.println("Provident Fund                  : " + this.pf);
		System.out.println("Staff Club Fund                 : " + this.club);
		System.out.println("Gross Salary                      : " + this.gross);
		System.out.println("Net Salary Fund                : " + this.net);
	}
}

class Programmer extends Employee
{
	double basic ;
	public void GetSalary() {
		System.out.println("Enter the Basic Salary of the Employee: ");
		this.basic = sc.nextDouble();
	}
}

class TeamLead extends Employee
{
	double basic ;
	public void GetSalary() {
		System.out.println("Enter the Basic Salary of the Employee: ");
		this.basic = sc.nextDouble();
	}
}

class ProjectManager extends Employee
{
	double basic ;
	public void GetSalary() {
		System.out.println("Enter the Basic Salary of the Employee: ");
		this.basic = sc.nextDouble();
	}
}

class AssistantprojectManager extends Employee
{
	double basic ;
	public void GetSalary() {
		System.out.println("Enter the Basic Salary of the Employee: ");
		this.basic = sc.nextDouble();
	}
}

public class inheritance {
	  public static void menu() {
	      System.out.println("\n---------------------------------------") ;
	      System.out.println("1.Programmer------------------------") ;
	      System.out.println("2.Team Leader-----------------------") ;
	      System.out.println("3.Project Manager-------------------") ;
	      System.out.println("4.Assistant Project Manager------") ;
	      System.out.println("0.Exit-----------------------------------") ;
	      System.out.println("-------------------------------------------") ;
	}
	 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice = 1;
		do
		{
			menu();
			System.out.println("Enter Your Choice : ");
			choice = sc.nextInt();
			switch(choice)
			{
			case 0:
				break;
			case 1:
				Programmer obj = new Programmer();
				obj.getData();
				obj.GetSalary();
				obj.calculateSal(obj.basic);
				obj.Display();
				obj.DisplaySalary(obj.basic);
				break;
			case 2:
				TeamLead obj1 = new TeamLead();
				obj1.getData();
				obj1.GetSalary();
				obj1.calculateSal(obj1.basic);
				obj1.Display();
				obj1.DisplaySalary(obj1.basic);
				break;
			case 3:
				ProjectManager obj2 = new ProjectManager();
				obj2.getData();
				obj2.GetSalary();
				obj2.calculateSal(obj2.basic);
				obj2.Display();
				obj2.DisplaySalary(obj2.basic);
				break;
			case 4:
				AssistantprojectManager obj3 = new AssistantprojectManager();
				obj3.getData();
				obj3.GetSalary();
				obj3.calculateSal(obj3.basic);
				obj3.Display();
				obj3.DisplaySalary(obj3.basic);
				break;
			default:
				System.out.println("Invalid Choice Enter again : ");
			}
		}
		while(choice != 0);
	}
}
