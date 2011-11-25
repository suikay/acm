import java.math.*;
import java.util.*;
import java.io.*;
class main
{
	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		String a,b;
		a = cin.next();
		b = cin.next();
		BigInteger aa = new BigInteger(a);
		BigInteger bb = new BigInteger(b);
		System.out.println(aa.multiply(bb).toString());		
	
	}
}
