interface LibraryItem{
    public void checkout();
    public void returnItem();
    public boolean isAvailable();
}

class Book implements LibraryItem{
    int bookCount = 0;
    String author = "Maruf Sarker";
    
    Book(int booksCount){
        this.bookCount = booksCount;
    }

    public String getAuthor(){
        return author;
    }
    public void checkout(){
        bookCount--;
        System.out.println("Checkout Comepleted");
        System.out.println("Total Books Available = " + bookCount);
    }
    public void returnItem(){
        bookCount++;
        System.out.println("Thanks for returning your book");
        System.out.println("Total Books Available = " + bookCount);
    }
    public boolean isAvailable(){
        if(bookCount != 0) return true;
        else return false;
    }
}

class DVD implements LibraryItem{
    int dvdCount = 0;
    String director = "Maruf Sarker";

    DVD(int dvdCount){
        this.dvdCount = dvdCount;
    }

    public String getDirector(){
        return director;
    }
    public void checkout(){
        dvdCount--;
        System.out.println("Checkout Comepleted");
        System.out.println("Total DVD Available = " + dvdCount);
    }
    public void returnItem(){
        dvdCount++;
        System.out.println("Thanks for returning your DVD");
        System.out.println("Total DVD Available = " + dvdCount);
    }
    public boolean isAvailable(){
        if(dvdCount != 0) return true;
        else return false;
    }
}

public class Main {
    public static void main(String[] args) {
        Book book = new Book(3);
        DVD dvd = new DVD(3);

        System.out.println("Book Class");
        System.out.println("----------");
        book.checkout();
        System.out.println("Author Name = " + book.getAuthor());
        book.returnItem();
        book.checkout();
        System.out.println("Books available? = " + book.isAvailable());
        
        System.out.println();

        System.out.println("DVD Class");
        System.out.println("---------");
        dvd.checkout();
        System.out.println("Director Name = " + dvd.getDirector());
        dvd.returnItem();
        dvd.checkout();
        dvd.checkout();
        dvd.checkout();
        System.out.println("Dvd's available? = " + dvd.isAvailable());
    }
}