/*  Create a program that asks the user to enter a username and password. 
If both match predefined values, print "Login successful", otherwise print "Invalid credentials". */


import java.util.Scanner;

public class LoginSystem{
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String u,p;
        String user="Sami";
        String pass="pass";
        System.out.println("Enter Username: ");
        u=in.nextLine();
        System.out.println("Enter password: ");
        p=in.nextLine();

        if(u.equals(user) && p.equals(pass)){
            System.out.println("Login Successful");
        }
        else{
            System.out.println("Invalid info");
        }

    }
}