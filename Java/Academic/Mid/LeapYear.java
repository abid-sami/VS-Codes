/* Write a program that checks whether a given year is a leap year. A year is a leap year if:
•	It is divisible by 4
•	But not divisible by 100
•	Unless it is also divisible by 400
 */

 import java.util.Scanner;

 public class LeapYear {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        if(a%4==0){
            System.out.println("Leap Year");
        }
        else if (a%400==0 && a%100!=0) {
            System.out.println("Leap Year");
        }
        else{
            System.out.println("Not Leap Year");
        }
    }
    
}
