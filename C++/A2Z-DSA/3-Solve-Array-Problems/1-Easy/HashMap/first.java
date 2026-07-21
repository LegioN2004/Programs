package HashMap;

import java.util.HashMap;

public class first {
    public static void main(String[] args) {
        HashMap<String, Integer> empid = new HashMap<>();

        /*
         * before java 7 you had to redefine this generic type again at the right side
         * of the = that you initially declared in the left side, i.e new
         * HashMap<String, Integer> . After java 7 it has been removed where we only
         * need the diamond operator <> only.
         *
         * But why not Map. Bcz Map is an interface that java implements and it
         * specifies what kind of methods the real map implementation have to support.
         * There are different types of implementations of that map interface and the
         * HashMap is just one of those implementations, the common one. It just how it
         * works underneath that's a little different.
         */

        empid.put("john", 123451);
        empid.put("john2", 123452);
        empid.put("john3", 123453);

        System.out.println(empid); // it doesn't guarantee an order of storing.

        System.out.println(empid.get("john"));

        System.out.println(empid.containsKey("john2"));

        System.out.println(empid.containsKey("hello"));

        System.out.println(empid.containsValue("123451"));

        empid.put("john5", 123); // this replaces the value of john but if it doesn't exist it'll create a new
                                 // one
        System.out.println(empid);

        empid.replace("john", 123); // this replaces the value of john
        System.out.println(empid);

        empid.replace("hello", 123); // this replaces the value of john, if it doesn't exist then it'll do nothing
        System.out.println(empid);

        empid.putIfAbsent("john", 123); // this puts the value only if it doesn't exist.
        System.out.println(empid);

        empid.remove("john", 123); // this puts the value only if it doesn't exist.
        System.out.println(empid);
    }
}
