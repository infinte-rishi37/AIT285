package Complex;

import java.util.*;

public class Complex {
	int real;
	int img;
	
	void setValue(Scanner SC)
	{
		System.out.print("Enter Real Part      : ");
		real = SC.nextInt();
		System.out.print("Enter Imaginary Part : ");
		img = SC.nextInt();
	}
	static Complex addCom(Complex c1, Complex c2)
	{
		Complex c3 = new Complex();
		c3.real = (c1.real+c2.real);
		c3.img = (c1.img+c2.img);
		return c3;
	}
	static void subCom(Complex c1, Complex c2)
	{
		System.out.println("Substraction is ("+(c1.real-c2.real)+")+("+(c1.img-c2.img)+")i ");
	}
	void mulCom(Complex c2)
	{
		int r = (this.real*c2.real - this.img*c2.img);
		int i = (this.real*c2.img + this.img*c2.real);
		System.out.println("Multiplication is ("+(r)+")+("+(i)+")i ");
	}
	void divCom(Complex c1, Complex c2)
	{
		int r = (c1.real*c2.real + c1.img*c1.img);
		int i = (c1.real*c2.img - c1.img*c2.real);
		int d = (c1.real*c1.real + c2.img*c2.img);
		this.real = r/d;
		this.img = i/d;
	}
	public static void main(String[] args) 
	{
		Complex c1 = new Complex();
		Complex c2 = new Complex();
		Complex c3 = new Complex();
		
		Scanner sc = new Scanner(System.in);
		
		int choice  = 1;
		do
		{
			System.out.println("\nWe will Perform Mahtematical operations on Complex Numbers.\n"+
					"Enter Your Choice:-\n1. Update/Enter Values of two Complex numbers.\t"+
					"2. Addition \n3. Substraction \t4. Multiply \t5. Divide \t0. Terminate");
			choice = sc.nextInt();
			switch(choice)
			{
				case 0:
					break;
				case 1:
					c1.setValue(sc);
					c2.setValue(sc);
					break;
				case 2:
					c3 = addCom(c1, c2);
					System.out.println("Addition is ("+(c3.real)+")+("+(c3.img)+")i ");
					break;
				case 3:
					subCom(c1, c2);
					break;
				case 4:
					c1.mulCom(c2);
					break;
				case 5:
					if((c1.real*c1.real + c2.img*c2.img)==0)
					{
						System.out.println("The Division is not possible for this case.\n");
					}
					else
					{
						c3.divCom(c1, c2);
						System.out.println("Division is ("+(c3.real)+")+("+(c3.img)+")i ");
					}
					break;
				default:
					System.out.println("Invalid Value, Enter your choice again :");
			}
		}
		while(choice != 0);
		sc.close();
	}
}
