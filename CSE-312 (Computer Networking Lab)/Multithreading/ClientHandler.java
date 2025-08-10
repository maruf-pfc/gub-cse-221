import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class ClientHandler extends Thread {
    DateFormat forDate = new SimpleDateFormat("yyyy/MM/dd");
    DateFormat forTime = new SimpleDateFormat("hh:mm:ss");

    final Socket con_tunnel;
    final DataInputStream dis_tunnel;
    final DataOutputStream dos_tunnel;
    String received = "";
    String toreturn = "";

    public ClientHandler(Socket s, DataInputStream dis, DataOutputStream dos){
        this.con_tunnel = s;
        this.dis_tunnel = dis;
        this.dos_tunnel = dos;
    }

    public void run(){
        while(true){
            try{
                dos_tunnel.writeUTF("Do you want to exit? yes/no");
                received = dis_tunnel.readUTF();

                if(received.equals("yes")){
                    System.out.println("Client " + this.con_tunnel + " sends exit.");
                    System.out.println("Closing the connection");
                    this.con_tunnel.close();
                    break;
                }else{
                    // server to client
                    dos_tunnel.writeUTF("What do you want (Date/Time)");
                    // client to server
                    received = dis_tunnel.readUTF();

                    Date date = new Date();
                    switch (received) {
                        case "Date":
                            toreturn = forDate.format(date);
                            dos_tunnel.writeUTF(toreturn);
                            break;

                        case "Time":
                            toreturn = forTime.format(date);
                            dos_tunnel.writeUTF(toreturn);
                            break;
                    
                        default:
                            dos_tunnel.writeUTF("Invalid Input");
                            break;
                    }
                }
            }catch(IOException err){
                Logger.getLogger(ClientHandler.class.getName()).log(Level.SEVERE, null, err);
            }
        }
        try{
            this.dos_tunnel.close();
            this.dis_tunnel.close();
        }catch(IOException err){
            Logger.getLogger(ClientHandler.class.getName()).log(Level.SEVERE, null, err);
        }
    }
}
