/* Write a Java program that:
a) Accepts an integer n from the user.
b) Uses a for loop to print all odd numbers from 1 to n.
c) If the number is divisible by 7, skip it using continue.
d) If the number exceeds 50, stop the loop using break. */

import java.util.Scanner;

public class MultiTask {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0; i<n; i++){
            if(i>=50){
                break;
            }
            if(i%2==0){
                continue;
            }
            if(i%7==0){
                continue;
            }
            System.out.println(i);
        }
    }
    
}
