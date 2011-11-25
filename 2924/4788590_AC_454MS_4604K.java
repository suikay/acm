import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);
	int n= scanner.nextInt();
	String a,b;
	BigInteger x,y,one = new BigInteger("1"),xx,yy; 
	for(int i = 1; i <= n; i++)
	{
		a = scanner.next();
		b = scanner.next();
		x = new BigInteger(a);
		y = new BigInteger(b);
		xx = x.add(y);
		//System.out.println(xx);
		yy = y.add(x.add(BigInteger.valueOf(-1)).multiply(BigInteger.valueOf(-1)));
		//System.out.println(yy);
		//x = x.add(y).divide(BigInteger.valueOf(2)).multiply(y.add(x.add(BigInteger.valueOf(1)).multiply(BigInteger.valueOf(-1))));
		System.out.println("Scenario #"+i+":");
		System.out.println(xx.multiply(yy).divide(BigInteger.valueOf(2)));
		System.out.println("");
	}
	}
}
