/* . Largest of Three Numbers Using Nested. Write a Java program that takes three integer inputs and determines which one is the largest using nested if statements.
 */

import java.util.Scanner;

public class LargestNumber {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.println("Enter 3 numbers");
        int a=in.nextInt();
        int b=in.nextInt();
        int c=in.nextInt();

        if(a>=b){
            if(a>=c){
                System.out.println("A is the Largest number");
            }
        }
        else if(b>=a){
            if(b>=c){
                System.out.println("B is the Largest number");
            }
        }
        else{
                System.out.println("C is the Largest number");
            }
    }
}
