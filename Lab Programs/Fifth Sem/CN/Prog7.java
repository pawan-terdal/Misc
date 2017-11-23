import java.util.*;

public class Prog7 {
  static String AppendZeros(String myString, int length) {
    for(int i = 0; i < length; i++)
      myString += '0';
    return myString;
  }
  static String GetRemainder(String a, String b) {
    String remainder = "";
    for(int i = 0; i < a.length(); i++)
      remainder += a.charAt(i) == b.charAt(i) ? '0': '1';
    return remainder;
  }
  static String CRC(String dividend, String divisor, boolean isGenerator) {
    if(isGenerator == true)
      dividend = AppendZeros(dividend, divisor.length() - 1);
    String remainder = dividend.substring(0, divisor.length());
    int i = divisor.length();
    while(true)
    {
      if(remainder.charAt(0) == '1')
        remainder = GetRemainder(remainder, divisor);
      else
        break;
      while(remainder.charAt(0) != '1' && i != dividend.length()) 
      {
        remainder = remainder.substring(1);
        remainder += dividend.charAt(i);
        i++;
      } 
    }
    return remainder;
  }
  public static void main(String[] args) {
    String dividend , divisor, remainder;
    Scanner in = new Scanner(System.in);
    System.out.print("Enter dividend : \t");
    dividend = in.nextLine();
    System.out.print("Enter divisor : \t");
    divisor = in.nextLine();
    remainder= CRC(dividend, divisor, true);
    dividend += remainder.substring(1);
    System.out.println("Final Data Sent: \t" + dividend);
    System.out.print("Modify data(0 or 1)? : \t");
    if(in.nextLine().equals("1"))
    {
      System.out.print("Overwrite Final Data: \t");
      dividend = in.nextLine();
    }
    remainder = CRC(dividend, divisor, false);
    for(int i = 0; i < remainder.length(); i++)
    {
      if(remainder.charAt(i) == '1')
      {
        System.out.println("[ERROR] Data corrupted");
        System.exit(0);
      }
    }
    System.out.println("[SUCCESS] Data not corrupted");
  }  
}