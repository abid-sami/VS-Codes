// Print numbers from 1 to 50, but skip numbers divisible by 3 using continue.
public class Print50 {
    public static void main(String[] args) {
        for(int i=0; i<=50; i++){
            if(i%3==0){
                continue;
            }
            System.out.println(i);
        }
    }
    
}
