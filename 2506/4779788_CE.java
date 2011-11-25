import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class bi {
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		int x;
		BigInteger a,two = new BigInteger("2"),one = new BigInteger("1"),pone = new BigInteger("-1") ;
		boolean time = true;
		while(scanner.hasNext()){
			time = true;
			x = scanner.nextInt();
			a = new BigInteger("1");
			for(int i = 1; i < x; i++){
				a = a.multiply(two);
				if(time)
					a = a.add(one);
				else
					a = a.add(pone);
				time = !time;
			}
			System.out.println(a);
		}	
		
	}
}
