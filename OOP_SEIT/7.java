package assignment7;

import java.util.*;

class Collection<T> {
	
	static <T> boolean isPalindrome(T s){
		String t = (String)s;
		char[] arr = t.toCharArray();
		int n = t.length();
		boolean flag = true;
		for(int i=0 ; i<n/2 ; i++) {
			if(arr[i] != arr[n-i-1]) {
				flag = false;
			}
		}
		return flag;
	}
	
	static <T> boolean isPrime(T s){
		boolean flag = true;
		try{
			int tmp = Integer.parseInt((String)s);
			for(int i=2; i*i<=tmp ;i++) {
				if(tmp%i==0) {
					flag = false;
				}
			}
		}catch(NumberFormatException e) {
			flag = false;
		}
		return flag; 
	}
	
	static <T> boolean isOdd(T s) {
		boolean flag = true;
		try{
			int tmp = Integer.parseInt((String)s);
			if(tmp%2==0) flag = false;
		}catch(NumberFormatException e) {
			flag = false;
		}
		return flag;
	}
	
	static<T> boolean isEven(T s) {
		boolean flag = true;
		try{
			int tmp = Integer.parseInt((String)s);
			if(tmp%2==1) flag = false;
		}catch(NumberFormatException e) {
			flag = false;
		}
		return flag;
	}
	
	static<T> boolean isInteger(T s) {
		boolean flag = true;
		try{
			int tmp = Integer.parseInt((String)s);
		}catch(NumberFormatException e) {
			flag = false;
		}
		return flag;
	}
}


public class New {
	static Scanner sc = new Scanner(System.in);
	
	static void menu() {
		System.out.println("========================MENU======================");
		System.out.println("\t1.Add Element to the Collection");
		System.out.println("\t2.Show Integer Collection");
		System.out.println("\t3.Show String Collection");
		System.out.println("\t4.Show Odd Collection");
		System.out.println("\t5.Show Even Collection");
		System.out.println("\t6.Show Prime Collection");
		System.out.println("\t7.Show Palindrome Collection");
		System.out.println("\t8.Display Collection");
		System.out.println("\t0.Exit");
		System.out.println("==================================================");
		System.out.print("\t  Enter Your Choice              : ");
	}
	
	public static void main(String[] args) {
		int choice = 1, count, c1, c2;
		ArrayList<String> collection = new ArrayList<>();
		do {
			menu();
			choice = sc.nextInt();
			switch(choice) {
			case 1:
				System.out.print("How Many Elements you want to add ? : ");
				int n = sc.nextInt(); 
				while(n>0) {
					System.out.print("Enter the new value : ");
					String input = sc.next();
					collection.add(input);
					n--;
				}
				break;
			case 2:
				count = 0;
				for(String i: collection) {
					if(Collection.isInteger(i)) {
						count++;
						System.out.println("\t" + count + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Integers in the Collection is : "+ count);
				break;
			case 3:
				count = 0;
				for(String i: collection) {
					if(Collection.isInteger(i) == false) {
						count++;
						System.out.println("\t" + count + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Strings in the Collection is : "+ count);
				break;
			case 4:
				count = 0;
				for(String i: collection) {
					if(Collection.isOdd(i)) {
						count++;
						System.out.println("\t" + count + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Odds in the Collection is : "+ count);
				break;
			case 5:
				count = 0;
				for(String i: collection) {
					if(Collection.isEven(i)) {
						count++;
						System.out.println("\t" + count + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Evens in the Collection is : "+ count);
				break;
			case 6:
				count = 0;
				for(String i: collection) {
					if(Collection.isPrime(i)) {
						count++;
						System.out.println("\t" + count + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Primes in the Collection is : "+ count);
				break;
			case 7:
				c1 = c2 = 0;
				for(String i: collection) {
					if(Collection.isPalindrome(i) && Collection.isInteger(i)) {
						c1++;
						System.out.println("\t" + c1 + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of Integer Palindromes : "+ c1 );
				for(String i: collection) {
					if(Collection.isPalindrome(i) && Collection.isInteger(i)==false ) {
						c2++;
						System.out.println("\t" + c2 + ".\t" + i);
					}
				}
				System.out.println("Total Numbers of String Palindromes : "+ c2 );
				count = c1+c2;
				System.out.println("Total Numbers of Palindromes in Collection : "+ (count) );
				break;
			case 8:
				count = 0;
				for(String i: collection) {
					count++;
					System.out.println("\t" + count + ".\t" + i);
				}
				System.out.println("Total Numbers of Elements in the Collection is : "+ count);
				break;
			default:
				choice = 0;
			}
		}while(choice!=0);
	}

}