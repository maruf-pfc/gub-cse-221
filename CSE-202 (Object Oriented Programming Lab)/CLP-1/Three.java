// Create a class named &#39;Programming&#39;. While creating an object of the class, if nothing is
// passed to it, then the message &quot;I love programming languages&quot; should be printed. If
// some String is passed to it, then in place of &quot;programming languages&quot; the name of that
// String variable should be printed. For example, while creating an object if we pass
// &quot;Java&quot;, then &quot;I love Java&quot; should be printed.

import java.util.*;

class Programming{
    Programming(){
        System.out.println("I love programming languages");
    }
    Programming(String str){
        System.out.println("Programming Languages");
    }
}

public class Three {
    public static void main(String[] args) {
        Programming m1 = new Programming();
        Programming m2 = new Programming("Java");
    }
}