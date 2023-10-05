package Inheritance;

import java.util.*;

class Employee
{
	Scanner sc = new Scanner(System.in) ;
	String emp_name ;
	String address ;
	String mail_id ;
	String mobile  ;
	int emp_id ;
	
	public void getData() {
		System.out.println("Enter the Employee Name : ");
		this.emp_name = sc.next();
		System.out.println("Enter address of Employee : ");
		this.address = sc.next();
		System.out.println("Enter mail address             : ");
		this.mail_id = sc.next();
		System.out.println("Enter mobile number         : ");
		this.mobile = sc.next();
		System.out.println("Enter Employee ID             : ");
		this.emp_id = sc.nextInt();
	}
	
	public void Display() {
		System.out.println("Employee ID     : "+emp_id);
		System.out.println("Employee Name: "+emp_name);
		System.out.println("Address             : "+address);
		System.out.println("Mobile Number : "+mobile);
		System.out.println("Mail address     : "+mail_id);
	}
	
	double basic , da , hra , pf , club , gross , net ;
	
	public void GetSalary() {
		System.out.println("Enter the this.basic Salary of the Employee: ");
		this.basic = sc.nextDouble();
	}
	
	public void DisplaySalary() {
		System.out.println("this.basic Salary of the Employee                : " + this.basic);
		System.out.println("Dearness Allowance of the Employee    : " + this.da );
		System.out.println("House Rent Allowance of the Employee: " + this.hra);
		System.out.println("Provident Fund of the Employee            : " + this.pf);
		System.out.println("Staff this.club Fund of the Employee           : " + this.club);
		System.out.println("this.gross Salary of the Employee                : " + this.gross);
		System.out.println("this.net Salary Fund of the Employee           : " + this.net);
	}
}

class Programmer extends Employee
{
	public void calculateSal()
    {
        this.da = this.basic*0.97 ;
        this.hra = this.basic*0.1 ;
        this.pf = this.basic*0.12 ;
        this.club = this.basic*0.001 ;
        this.gross = this.basic - this.pf ;
        this.net = this.gross - this.hra - this.club ;
    }
}

class teamLead extends Employee
{
	public void calculateSal()
    {
        this.da = this.basic*0.97 ;
        this.hra = this.basic*0.1 ;
        this.pf = this.basic*0.12 ;
        this.club = this.basic*0.001 ;
        this.gross = this.basic - this.pf ;
        this.net = this.gross - this.hra - this.club ;
    }
}

class projectManager extends Employee
{
	public void calculateSal()
    {
        this.da = this.basic*0.97 ;
        this.hra = this.basic*0.1 ;
        this.pf = this.basic*0.12 ;
        this.club = this.basic*0.001 ;
        this.gross = this.basic - this.pf ;
        this.net = this.gross - this.hra - this.club ;
    }
}

class assistantprojectManager extends Employee
{
	public void calculateSal()
    {
        this.da = this.basic*0.97 ;
        this.hra = this.basic*0.1 ;
        this.pf = this.basic*0.12 ;
        this.club = this.basic*0.001 ;
        this.gross = this.basic - this.pf ;
        this.net = this.gross - this.hra - this.club ;
    }
}

public class inheritance {
	  public static void menu(){
	      System.out.println("\n---------------------------------------") ;
	      System.out.println("1.Programmer") ;
	      System.out.println("2.Team Leader") ;
	      System.out.println("3.Project Manager") ;
	      System.out.println("4.Assistant Project Manager") ;
	      System.out.println("0.Exit") ;
	      System.out.println("---------------------------------------") ;
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
				obj.calculateSal();
				obj.Display();
				obj.DisplaySalary();
				break;
			case 2:
				teamLead obj1 = new teamLead();
				obj1.getData();
				obj1.GetSalary();
				obj1.calculateSal();
				obj1.Display();
				obj1.DisplaySalary();
				break;
			case 3:
				projectManager obj2 = new projectManager();
				obj2.getData();
				obj2.GetSalary();
				obj2.calculateSal();
				obj2.Display();
				obj2.DisplaySalary();
				break;
			case 4:
				assistantprojectManager obj3 = new assistantprojectManager();
				obj3.getData();
				obj3.GetSalary();
				obj3.calculateSal();
				obj3.Display();
				obj3.DisplaySalary();
				break;
			default:
				System.out.println("Invalid Choice Enter again : ");
			}
		}
		while(choice != 0);
	}
}
