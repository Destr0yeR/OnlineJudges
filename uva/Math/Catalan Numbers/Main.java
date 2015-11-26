
import java.io.*;
import java.util.*;
import java.math.*;

class Main{
		
	public static void main(String args[]){
		Main myWork = new Main();
        myWork.Begin();
	}
	
	BigInteger Ca[] = new BigInteger[1001];
	
	BigInteger catalan(int n){
		if(Ca[n].compareTo(BigInteger.valueOf(-1)) != 0)return Ca[n];
		
		return Ca[n] = catalan(n-1).multiply(BigInteger.valueOf(4*n-2)).divide(BigInteger.valueOf(n+1));
	}
	
	static String ReadLn (int maxLg)
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }
	
	void Begin(){
		String input;
        StringTokenizer idata;
        int a, b, min, max, num, n, cycle, cyclemax, T;
        
        for(int i = 0 ; i < 1001 ; ++i){
			Ca[i] = new BigInteger("-1");
		}
		Ca[0] = new BigInteger("1");
		
		input = Main.ReadLn (255);
		idata = new StringTokenizer (input);
		
		T = Integer.parseInt (idata.nextToken());
		
		for(int tc = 1 ; tc <= T ; ++tc)
        {
			input = Main.ReadLn (255);
			idata = new StringTokenizer (input);
			n = Integer.parseInt (idata.nextToken());
			System.out.println("Case "+tc+": "+catalan(n/2-1).multiply(BigInteger.valueOf(n-1)));
        }
	}
}

