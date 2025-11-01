import java.util.Scanner;

public class Number{
    public int a,b;
    
    public void input(){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter two integers: ");
        a=sc.nextInt();
        b=sc.nextInt();
    }

    public int divide(){
        return a/b;
    }
}
