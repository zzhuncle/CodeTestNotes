//数字阶梯求和 https://www.nowcoder.com/practice/c66df29f6c1c4dbba0bd51619210e082
import java.math.BigInteger;
import java.util.Scanner;
public class Main
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int a = in.nextInt();
            int n = in.nextInt();
            BigInteger sum = BigInteger.valueOf(0);
            BigInteger A = BigInteger.valueOf(a);
            BigInteger tmp = BigInteger.valueOf(a);
            BigInteger radix = BigInteger.valueOf(10);
            for (int i = 0;i < n;i++) {
                sum = sum.add(tmp);
                tmp = tmp.multiply(radix);
                tmp = tmp.add(A);
            }
            System.out.println(sum);
        }
    }
}