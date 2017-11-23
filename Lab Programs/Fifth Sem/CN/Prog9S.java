import java.io.*;
import java.net.*;
import java.nio.file.*;

class Prog9S
{
	public static void main(String args[]) throws Exception
	{
    while(true)
		{
      ServerSocket welcomeSocket = new ServerSocket(6789);
      Socket connectionSocket = welcomeSocket.accept();
      BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
      DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
      
      String fileName = inFromClient.readLine();
      System.out.println("Query: " + fileName);
      
      try
      {
        String content = getContent(fileName);
        outToClient.writeBytes(content);
      }
      catch(Exception e)
      {
        outToClient.writeBytes("File not found" + "\n");
      }
      connectionSocket.close();
      welcomeSocket.close();
    }
 	}

	public static String getContent(String fileName) throws Exception
	{
		return new String(Files.readAllBytes(Paths.get(fileName)));
	}
}
