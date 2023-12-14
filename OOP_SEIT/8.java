package fileHandling;
import java.util.*;
import java.io.*;

public class File2 {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		 int choice;
	        do {
	            System.out.println("1. Create Database");
	            System.out.println("2. Display Database");
	            System.out.println("3. Delete Records");
	            System.out.println("4. Update Record");
	            System.out.println("5. Search Record");
	            System.out.println("6. Exit");
	            System.out.print("Enter your choice: ");
	            choice = sc.nextInt();
	            switch (choice) {
	                case 1:
	                    CreateDB();
	                    break;
	                case 2:
	                    displayDB();
	                    break;
	                case 3:
	                    DeleteDB();
	                    break;
	                case 4:
	                    updateDB();
	                    break;
	                case 5:
	                    SearchDB();
	                    break;
	                case 6:
	                    System.out.println("Exiting the program. Goodbye!");
	                    break;
	                default:
	                    System.out.println("Invalid choice. Please enter a valid option.");
	            }
	        } while (choice != 6);
	}
	
	static void CreateDB() {
		try(FileWriter writer = new FileWriter("new.txt", true)){
			System.out.print("Enter Student ID : ");
			String studID = sc.next();
			System.out.print("Enter Name : ");
			String name = sc.next();
			System.out.print("Enter Semester : ");
			String Semester = sc.next();
			System.out.print("Enter Marks : ");
			double  marks= sc.nextDouble();
			System.out.print("Enter Address: ");
            String address = sc.next();
			writer.write(studID+','+name+','+Semester+','+marks+','+address+",\n");
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
	
	static void displayDB() {
		try(BufferedReader reader = new BufferedReader(new FileReader("new.txt"))){
			String line;
			System.out.println("-------------------------------------------------------- ");
			System.out.println("                     STUDENT DATABASE                    ");
			System.out.println("-------------------------------------------------------- ");
			System.out.println("\tID\tName\tSem\tMarks\tAddress\n");
			while( (line = reader.readLine() ) != null) {
				String[] data = line.split(",");
				for(String s: data) {
					System.out.print("\t"+s);
				}
				System.out.println();
			}
			System.out.println("-------------------------------------------------------- ");
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
	
	static void DeleteDB() {
		try(BufferedReader reader = new BufferedReader(new FileReader("new.txt"))){
			ArrayList<String> newDB = new ArrayList<>();
			String line;
			boolean flag = false;
			System.out.println("Enter the Student ID to remove : ");
			int reqIND = sc.nextInt();
			while((line = reader.readLine()) != null) {
				String[] data = line.split(",");
				if(Integer.parseInt(data[0]) != reqIND && flag==false) {
					newDB.add(line + "\n");
				}
				else {
					flag = true;
				}
			}
			if(flag) {
				//writer
				FileWriter writer = new FileWriter("new.txt");
				for(String s: newDB) {
					writer.write(s);
				}
				writer.close();
			}
			else {
				System.out.println("Invalid Index");
			}
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
	
	static void SearchDB() {
		try(BufferedReader reader = new BufferedReader(new FileReader("new.txt"))){
			String line;
			boolean flag = false;
			System.out.println("Enter the Student ID to search : ");
			int reqIND = sc.nextInt();
			while((line = reader.readLine()) != null) {
				String[] data = line.split(",");
				if(Integer.parseInt(data[0]) == reqIND){
					flag = true;
					System.out.println("Student data found");
				}
			}
			if(flag == false) {
				System.out.println("Student data does not exists.");
			}
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
	
	static void updateDB() {
		try(BufferedReader reader = new BufferedReader(new FileReader("new.txt"))){
			ArrayList<String> newDB = new ArrayList<>();
			String line;
			boolean flag = false;
			int reqIND;
			System.out.print("Enter the Student ID you want to update : ");
			reqIND = sc.nextInt();
			while( (line = reader.readLine()) != null) {
				String[] data = line.split(",");
				if(Integer.parseInt(data[0]) == reqIND) {
					flag = true;
					System.out.print("Enter the new Marks : ");
					data[3] = sc.next();
				}
				for(int i = 0; i<data.length; i++) {
					newDB.add(data[i]+',');
				}
				newDB.add("\n");
			}
			if(flag == false) {
				System.out.println("No Such student in the DataBase :");
			}
			//writer
			FileWriter writer = new FileWriter("new.txt");
			for(String i: newDB) {
				writer.write(i);
			}
			writer.close();
		}catch(IOException e) {
			System.out.println(e.getMessage());
		}
	}
}
