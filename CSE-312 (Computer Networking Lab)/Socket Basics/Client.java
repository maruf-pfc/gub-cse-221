import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException{
        int port = 5000;
        Socket sc = new Socket("localhost", port);
        System.out.println("Client connected at server Handsaking port " + sc.getPort());

        System.out.println("Client's communication port " + sc.getPort());
        System.out.println("Client is connected");
        System.out.println("Enter the messages that you want to send and send to close");

        DataOutputStream output = new DataOutputStream(sc.getOutputStream());
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String str = "";
        while(!str.equals("stop")){
            str = read.readLine();
            output.writeUTF(str);
        }

        output.close();
        read.close();
        sc.close();
    }
}
