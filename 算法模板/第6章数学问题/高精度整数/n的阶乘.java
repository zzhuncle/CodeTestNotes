//高精度整数
import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);//类似于cin
        while (in.hasNextInt()) {
            BigInteger t = new BigInteger("1");
            int n = in.nextInt();
            for (int i = 1;i <= n;i++) {
                BigInteger c = new BigInteger(String.valueOf(i));
                t = t.multiply(c);
            }
            System.out.println(t);          //类似于cout
        }
        in.close();
    }
}
