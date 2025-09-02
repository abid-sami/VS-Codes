/* Simulate a login system where the user has 5 attempts to enter the correct password. Use break to exit early if the password is correct. */

import java.util.Scanner;

public class LoginAttempts {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int i;
        String p="pass";
        for(i=0; i<5; i++){
            String n=s.nextLine();
            if(p.equals(n)){
                System.out.println("Login Successful");
                break;
            }
            else{
                System.out.println("Login failed");
            }      
        }
        
    }
    
}
