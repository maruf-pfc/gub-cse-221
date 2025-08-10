/*
Garbage collection is a mechanism in Java that automatically manages the memory allocation and deallocation of objects. It frees up memory occupied by objects that are no longer referenced by any part of the program. This makes Java programs more efficient and eliminates the need for manual memory management.

The garbage collection process involves the following steps:

- Marking: The garbage collector traverses the object graph and marks all the objects that are still being referenced by the program.

- Sweep: The garbage collector then sweeps through the heap and frees up memory occupied by objects that are not marked.

- Compact: The garbage collector may also compact the memory by moving the surviving objects closer together, reducing fragmentation and improving memory locality.
*/
public class GarbageCollectionExample {
    public static void main(String[] args) {
      String s1 = new String("Hello");
      String s2 = new String("World");
      s1 = null; // s1 is no longer referenced
      System.gc(); // request garbage collection
      System.out.println(s2); // s2 is still referenced
    }
}
/*
In this example, two String objects s1 and s2 are created using the new keyword. s1 is assigned the value "Hello" and s2 is assigned the value "World". After that, s1 is set to null, which means that it no longer references the object "Hello". Finally, the System.gc() method is called to request garbage collection.

At this point, the garbage collector will mark the "World" object as still being referenced by the program and sweep the "Hello" object, freeing up its memory. The println statement will then print "World" to the console, confirming that the "World" object is still referenced and has not been garbage collected.
*/