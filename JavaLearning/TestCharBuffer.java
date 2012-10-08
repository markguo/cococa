import java.nio.CharBuffer;
import java.nio.ByteBuffer;

    public class TestCharBuffer{
    public static void main(String[] args)
    {
        System.out.println(ByteBuffer.wrap("hello").asCharBuffer().toString());
    }
}
