import java.math.*;
import java.util.*;

public class Prog11
{
  private BigInteger p;
  private BigInteger q;
  private BigInteger N;
  private BigInteger phi;
  private BigInteger e;
  private BigInteger d;
  private int bitlength = 20;
  private Random     r;

  public Prog11()
  {
    r = new Random();
    p = BigInteger.probablePrime(bitlength, r);
    q = BigInteger.probablePrime(bitlength, r);
    N = p.multiply(q);
    phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
    e = BigInteger.probablePrime(bitlength / 2, r);
    while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0)
    {
      e.add(BigInteger.ONE);
    }
    d = e.modInverse(phi);
  }

  public Prog11(BigInteger e, BigInteger d, BigInteger N)
  {
    this.e = e;
    this.d = d;
    this.N = N;
  }

  public static void main(String[] args)
  {
    Prog11 rsa = new Prog11();
    Scanner in = new Scanner(System.in);
    String teststring;
    System.out.println("Enter the plain text:");
    teststring = in.nextLine();
    System.out.println("p: " + rsa.p);
    System.out.println("q: " + rsa.q);
    System.out.println("n: " + rsa.N);
    System.out.println("phi: " + rsa.phi);
    System.out.println("d: " + rsa.d);
    System.out.println("e: " + rsa.e);
    System.out.println("Encrypting String: " + teststring);
    System.out.println("String in Bytes: " + bytesToString(teststring.getBytes()));

    // encrypt
    byte[] encrypted = rsa.encrypt(teststring.getBytes());

    // decrypt
    byte[] decrypted = rsa.decrypt(encrypted);

    System.out.println("Decrypting Bytes: " + bytesToString(decrypted));
    System.out.println("Decrypted String: " + new String(decrypted));
  }

  private static String bytesToString(byte[] encrypted)
  {
    String test = "";
    for (byte b : encrypted)
    {
      test += b;
    }
    return test;
  }

  // Encrypt message
  public byte[] encrypt(byte[] message)
  {
    return (new BigInteger(message)).modPow(e, N).toByteArray();
  }

  // Decrypt message
  public byte[] decrypt(byte[] message)
  {
    return (new BigInteger(message)).modPow(d, N).toByteArray();
  }
}