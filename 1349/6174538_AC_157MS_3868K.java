import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		BigInteger x[] = new BigInteger[55];
		x[0] = BigInteger.valueOf(1);
		for(int i = 1; i < 55; i++)
			x[i] = x[i-1].multiply(BigInteger.valueOf(i));

		String ori;
		byte pp[] = new byte[1000];
		int arr[] = new int[55];
		int cnt;
		cnt = 0;
		while(cin.hasNext())
		{
			ori = cin.next();
			pp = ori.getBytes();
			for(int i = 0; i < ori.length(); i++)
				if((pp[i] < '0' || pp[i] > '9') && pp[i] != '-')
					pp[i] = ' ';
			ori = new String(pp);
			Scanner nn = new Scanner(ori);
			int t;
			t = nn.nextInt();
			if(t == -1) {
				System.out.println("");
				return ;
			}
			BigInteger res;
			res = BigInteger.valueOf(1);
			for(int i = 0; i < t; i++) {
				arr[i] = nn.nextInt();
//				System.out.println(arr[i]);
			}
			for(int i = 0; i < t; i++) {
				for(int j = i+1; j < t; j++)
					if(arr[i] > arr[j]) {
						res = res.add(x[t-i-1]);
						//System.out.println(res.toString());
				}
			}
			if(cnt++ > 0)
				System.out.print(',');
			System.out.print(res.toString());

		}
	}
}
