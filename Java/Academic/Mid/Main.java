//Genertate 7 numbers that are divisible by both 2 and 3. And sum of the nummbers are as minimum as possible.

public class Main{
  public static void main(String[] args){
  int count = 0;
  int num = 1;
  for(int i=0;count<7;i++){
    if(num%2 == 0 && num%3 == 0){
      count++;
      System.out.print(" " + num);
    }
    num++;
  }
  
  }

}