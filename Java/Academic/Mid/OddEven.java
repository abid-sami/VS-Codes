/*Write a Java program that takes an integer input from the user and checks whether the number is even or odd using an if-else statement.*/


import java.util.Scanner;

public class OddEven {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        System.out.println("Enter Number: ");
        int a=in.nextInt();
        if(a%2==0){
            System.out.println("Even Number");
        }
        else{
            System.out.println("Odd Number");

        }

    }
    
}
