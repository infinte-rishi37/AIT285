package ExceptionHandling;

import java.util.*;

class Exception{
	int a;
	Scanner sc = new Scanner(System.in);
	public int takeInput() {
		while(true) {
			try {
				a = Integer.parseInt(sc.next());
				break;
			}
			catch(NumberFormatException e) {
				System.out.println(e);
				System.out.println("Numer Format Error\n");
			}
		}
		return a;
	}
	
}

public class Main {
	static Scanner sc = new Scanner(System.in);
	static void menu() {
		System.out.println("\n\nChoose the desired option : ");
		System.out.println("1. Create an Array");
		System.out.println("2. Input Array element"); // For number format exception
		System.out.println("3. Access Array element"); // For array index out of bound exception
		System.out.println("4. Perform Division"); // For arithmetic exception
		System.out.println("*. Press any other numeric key to exit");
	}
	public static void main(String[] args) {
		int n = 0, choice = 1;
		int[] ar = new int[0];
		Exception inp = new Exception();
		do{
			menu();
			choice = inp.takeInput();
			switch(choice) {
			case 1:{
				System.out.println("Enter the size of array.");
				n = inp.takeInput();
				ar = new int[n];
				break;
			}
			case 2:{
				if(n==0) {
					System.out.println("Create an array first.");
				}
				else {
					int ind, val;
					System.out.println("Enter the index for which you would like to enter data.");
					ind = inp.takeInput();
					System.out.println("Enter the value at the index" + ind);
					val = inp.takeInput();
					try {
						ar[ind] = val;
					}
					catch(ArrayIndexOutOfBoundsException e){
						System.out.println(e);
					}
				}
				break;
			}
			case 3:{
				if(n==0) {
					System.out.println("Create an array first.");
				}
				else {
					int ind, val;
					System.out.println("Enter the index for which you would like to access data.");
					ind = inp.takeInput();
					try {
						System.out.println("Value at " + ind + " is " + ar[ind]);
					}
					catch(ArrayIndexOutOfBoundsException e){
						System.out.println(e);
					}
				}
				break;
			}
			case 4:{
				int n1, n2, c;
				while(true) {
					
					n1 = inp.takeInput();
					n2 = inp.takeInput();
					try {
						c = ar[n1]/ar[n2];
						break;
					}
					catch(ArithmeticException e) {
						System.out.println(e);
					}
					catch(ArrayIndexOutOfBoundsException e) {
						System.out.println(e);
					}
				}
				System.out.println("Division of value at given index is " + c +" .");
			}
			case 0:{
				break;
			}
			default:{
				System.out.println("Invalid Choice.");
			}
			}
		}while(choice!=0);
	}

}
