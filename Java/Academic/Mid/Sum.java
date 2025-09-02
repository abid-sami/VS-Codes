/* Accept a number n and use a for loop to calculate the sum of the first n natural numbers. */

import java.util.Scanner;
public class Sum {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n;
        int c=0;
        n=s.nextInt();
        for(int i=0; i<=n; i++){
            c+=i;
        }
        System.out.println("Answer: "+c);
    }
}
