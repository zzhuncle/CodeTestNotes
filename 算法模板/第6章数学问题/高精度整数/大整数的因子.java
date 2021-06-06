//大整数的因子 https://www.nowcoder.com/practice/3d6cee12fbf54ea99bb165cbaba5823d
import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            BigInteger c = in.nextBigInteger();
            boolean flag = true;
            for (int i = 2;i <= 9;i++) {
                BigInteger t = BigInteger.valueOf(i);
                if (c.remainder(t).equals(BigInteger.ZERO)) {
                    flag = false;
                    System.out.print(i + " ");
                }
            }
            if (flag)
                System.out.println("none");
            else
                System.out.println();
        }
    }
}