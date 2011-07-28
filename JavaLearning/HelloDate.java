import java.util.*;

/**
 * @brief A desc
 */
class A{
    public int a_int;
    public char a_char;
};

public class HelloDate{

    /**
     * Main method
     */
    public static void main(String[] args){
	System.out.println("Hello, it's: ");
	System.out.println(new Date());

	A a = new A();

	System.out.print("a.a_int == ");
	System.out.println(a.a_int);

	System.out.print("a.a_char == ");
	System.out.println(a.a_char);
    }
}
