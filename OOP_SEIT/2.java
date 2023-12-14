package polymorphism;
import java.util.*;

class Publication {
    String title;
    double price;
    int copies;
    static double totalPrice;
    Scanner sc = new Scanner(System.in);

    void getData(){

        System.out.print("Enter Price : ");
        price = sc.nextDouble();
        System.out.print("Enter Number of Copies : ");
        copies = sc.nextInt();
    }
    void saleCopy(){
        System.out.println("\nTotal Sell by the publication house: " + (totalPrice));
    }
}
class Book extends Publication{
    String author;
    public int g =50;
    public double bookSell;
    public static double totalBookSell;
    public Scanner sc = new Scanner(System.in);

    void getAuthor(){
        System.out.print("Enter Author's Name : ");
        author = sc.nextLine();
        System.out.print("Enter Title : ");
        title = sc.nextLine();
    }
    void getBookData(){

        getAuthor();
        getData();
    }

    void restock(){
        if(this.copies>g){
            System.out.println("Restock the values of book to 100 and enter the values again");

            g=g+100;
            getBookData();
        }
        else {
            g=g-this.copies;
        }
    }
    //Override
    void saleCopy(){
        bookSell = (this.copies * this.price);
        Book.totalBookSell += bookSell;
        Publication.totalPrice += totalBookSell;
        System.out.print("\n");
        System.out.println("Ordered Book : " + this.author);
        System.out.println("Total Amount : " + bookSell);
        System.out.print("\n");
    }
    void totalBookSell(){
        System.out.println("Total Book Sell : " + totalBookSell);
    }
}
class Magazine extends Publication{
    String author;
    public int g=50;
    public double MagSell;
    public static double totalMagSell;
    Scanner sc = new Scanner(System.in);

    void getAuthor(){
        System.out.print("Enter Author's Name : ");
        author = sc.nextLine();
    }
    void getBookData(){
        getData();
        getAuthor();
    }
    void restock(){
        if(this.copies>g){
            System.out.println("Restock the values of magazine to 100 and enter the values again");

            g=g+100;
            getData();
            getAuthor();
        }
        else {
            g=g-this.copies;
        }
    }
    //Override
    void saleCopy(){
        MagSell = (this.copies * this.price);
        Magazine.totalMagSell += MagSell;
        Publication.totalPrice += totalMagSell;
        System.out.print("\n");
        System.out.println("Ordered Magazine :" + this.title);
        System.out.println("Total Amount : " + MagSell);
        System.out.print("\n");

    }
    void totalMagSell(){
        System.out.println("Total Magazine Sell : " + totalMagSell);
    }
}
 class Assignment2 {
	static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        Book b = new Book();
        Magazine m = new Magazine();
        Publication p = new Publication();
        while(true){
            System.out.println("Enter");
            System.out.println("1.Order Book");
            System.out.println("2.Order Magazine");
            System.out.println("3.Total Book Sell");
            System.out.println("4.Total Magazine Sell");
            System.out.println("5.Total Publication Sell");
            System.out.println("6.Exit\n");

            System.out.print("Enter Your Choice : ");
            int choice = sc.nextInt();
            System.out.print("\n");
            switch (choice){
                case 1:

                    b.getBookData();
                    b.restock();
                    b.saleCopy();
                    break;
                case 2:

                    m.getBookData();
                    m.restock();
                    m.saleCopy();
                    break;

                case 3:
                    b.totalBookSell();
                    break;

                case 4:
                    m.totalMagSell();
                    break;

                case 5:
                    m.totalMagSell();
                    b.totalBookSell();
                    p.saleCopy();

                    break;

                case 6:
                    System.out.println("Exiting The Program..");
                    System.exit(0);
                default:
                    System.out.println("Please Enter Valid Input..");

            }
        }
    }
 }