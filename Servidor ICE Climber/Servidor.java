/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Servidor;
import java.net.*;
import java.io.*;

/**
 *
 * @author PC34
 */
public class Servidor {
    
    public Servidor(){ }
    
    public void server(){
    
        ServerSocket server;
        Socket socket;
        int puerto = 8080;
        DataOutputStream salida;
        BufferedReader entrada;
        {
            try{
            server = new ServerSocket(puerto);
            socket = new Socket();
           
            String mensaje="";
            String mensajeComparacion = "cerrar Server";
            
            while(mensaje.compareTo(mensajeComparacion)!=1){
                socket = server.accept();
                entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                mensaje = entrada.readLine();
                
                if (mensaje.compareTo(mensajeComparacion)==1){
                    System.out.println("Palabra encontrada: "+mensaje);
                }
                System.out.println("Palabra cliente: "+mensaje);
                /*Mensaje que le envia al cliente*/
                salida = new DataOutputStream(socket.getOutputStream());
                salida.writeUTF("//////////////////////Hola soy el Servidor de Java");
                salida.flush();
                salida.close();
                
            }
            socket.close();
        }catch(Exception e){};
        }
        
    
    }    
    
}
