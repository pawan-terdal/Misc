import java.io.*;
import java.net.*;

class Prog9C
{
	public static void main(String argv[]) throws Exception
	{
		String sentence;
		String modifiedSentence;
    // User
    BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
    sentence = inFromUser.readLine();

    // Connect to Server
		Socket clientSocket = new Socket("127.0.0.1", 6789);
		DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
		BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
		
    outToServer.writeBytes(sentence + '\n');
    
		modifiedSentence = inFromServer.readLine();
		System.out.println("FROM SERVER: " + modifiedSentence);
    
    clientSocket.close();
 	}
}

