import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {
	public static void main(String []args)
	{
		int n;
		boolean left;
		BigInteger one = new BigInteger("1");
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext())
		{
			n = scanner.nextInt();
			BigInteger tmp = new BigInteger("0");
			BigInteger onep = new BigInteger("0");
			BigInteger zerop = new BigInteger("0");
			left = false;
			for(int i = 0; i < n; i++){
				//System.out.println(one);
				if(left){
					tmp = onep.add(one);
					tmp = tmp.add(zerop);
					//System.out.println(tmp);
				}
				else
					tmp = onep.add(zerop);
				//System.out.println(tmp);
				onep = zerop.add(onep);
				zerop = tmp;
				left = !left;
			}
			System.out.println(zerop);
		}
	}
}
