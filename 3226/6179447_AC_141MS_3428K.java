import java.io.*;
import java.*;
import java.util.*;
import java.math.*;
class Main 
{
	public static void main(String[] args) 
	{
		BigInteger x[] = new BigInteger[30];
		x[0] = BigInteger.valueOf(1);
		for(int i = 1; i <= 26; i++)
			x[i] = x[i-1].multiply(BigInteger.valueOf(i));
		String ori;
		int n;
		Scanner cin = new Scanner(System.in);
		Boolean	v[] = new Boolean[26];
		while(true)
		{
			for(int i = 0; i < 26; i++)
				v[i] = false;
			n = cin.nextInt();
			if(n == 0)
				return;
			ori = cin.next();
			int len = ori.length(),cnt;
			BigInteger res;
			res = BigInteger.valueOf(0);
			for(int i = 0; i < len; i++) {
				char ch = ori.charAt(i);
				cnt = 0;
				for(char j = 'A'; j < ch; j++)
					if(!v[j-'A'])
						cnt++;
				v[ch-'A'] = true;
				res = res.add(x[25-i].multiply(BigInteger.valueOf(cnt)));
			}
			System.out.println(res.divide(x[26-len]).toString());
		}
	}
}
