import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	BigInteger[] Ca = new BigInteger[301];
	
	BigInteger catalan(int n){
		if(Ca[n].compareTo(BigInteger.valueOf(-1)) != 0)return Ca[n];
		
		return Ca[n] = catalan(n-1).multiply(BigInteger.valueOf(4*n-2)).divide(BigInteger.valueOf(n+1));
	}
	
	static String ReadLn(int maxLg){
		byte lin[] = new byte [maxLg];
		int lg = 0, car = -1;
		String line = "";
		
		try{
			while(lg < maxLg){
				car = System.in.read();
				if((car < 0) || (car == '\n'))break;
				lin[lg++] += car;
			}
		}
		catch(IOException e){
			return (null);
		}
		
		if((car < 0) && (lg == 0)) return (null);
		
		return (new String (lin, 0, lg));
	}
	
	public static void main(String args[]){
		Main mywork = new Main();
		mywork.Begin();
	}
	
	void Begin(){
		String input;
		StringTokenizer idata;
		int n;
		
		for(int i = 0 ; i < 301 ; ++i){
			Ca[i] = new BigInteger("-1");
		}
		Ca[0] = new BigInteger("1");
		
		while((input = Main.ReadLn(255)) != null){
			idata = new StringTokenizer(input);
			n = Integer.parseInt(idata.nextToken());
			if(n == 0)break;
			System.out.println(catalan(n).multiply(BigInteger.valueOf(2)));
		}
	}
}
