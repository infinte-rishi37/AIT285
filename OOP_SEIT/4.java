package Shape;

import java.util.* ;

abstract class shape
{
	Scanner sc=new Scanner(System.in);
	double a,b;
	abstract void input();
    abstract public void printArea() ;
}

class triangle extends shape
{
	
	void input() {
		do{
			System.out.print("Height of the Triangle: ") ;
            this.a = sc.nextInt() ;
            System.out.print("Base of the Triangle: ");
            this.b = sc.nextInt() ;
		}while(a<=0 || b<=0);
	}
    public void setBase(int base)
    {
        this.a = base ;
    }
    public void setHeight(int height)
    {
        this.b = height ;
    }
    public void printArea()
    {
        double area = (a*b)/2 ;
        System.out.println("Area of the Triangle is : " + area) ;
    }
}

class rectangle extends shape
{
	void input() {
		do{
			System.out.print("Length of the Rectangle: ");
            this.a = sc.nextInt() ;
            System.out.print("Breadth of the Rectangle: ") ;
            this.b = sc.nextInt() ;
		}while(a<=0 || b<=0);
	}
    public void printArea()
    {
        double area = a*b ;
        System.out.println("Area of the Rectangle is : " + area) ;
    }
}

public class Main
{
    static Scanner sc = new Scanner(System.in) ;
    public static void main(String[] args)
    {
    	int choice = 1;
        do
        {
            System.out.println();
            System.out.println("Choose Your Shape") ;
            System.out.println("1.Triangle") ;
            System.out.println("2.Rectangle");
            System.out.println("3.Exit") ;
            System.out.print("Enter you choice: ");
            
            choice = sc.nextInt();
            
            if(choice == 1)
            {
                triangle obj = new triangle() ;
                
                obj.input();
     
                obj.printArea() ;
            }
            else if(choice == 2)
            {
                rectangle obj = new rectangle() ;
                
                obj.input();
                
                obj.printArea() ;
            }
            else if(choice == 3)
            {
                System.out.println("Thank you!") ;
                System.exit(0);
                
                break ;
            }
            else
            {
                System.out.println("Invalid choice!") ;
            }
        }while(choice!=3);
    }
}