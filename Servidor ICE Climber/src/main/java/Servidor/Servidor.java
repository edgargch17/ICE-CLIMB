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
    
    Juego juego = new Juego();
    
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
           
            String mensaje="";
            String mensajeComparacion = "cerrar Server";
            
            while(mensaje.compareTo(mensajeComparacion)!=1){
                
                ///////////// Acepta la conexion de un cliente ////////////////
                socket = new Socket();
                socket = server.accept();
                entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                mensaje = entrada.readLine();
                System.out.println("Palabra cliente: "+mensaje);
                
                
                int m=0;
                String clave="";
                String codigo1="";
                String codigo2="";
                //Clave..
                boolean estado1=false;
                //Codigo1: Jugador,boolean
                boolean estado2=false;
                //Codigo2: elimnar bloque (x,y), +puntos.
                boolean estado3=false;
                
                for(int i=0;i<mensaje.length();i++){
                    
                    /////////// Comparaciones para sacar palabras clave ///////////
                    if (mensaje.substring(m,i+1).equals("{")){estado1=true;}
                    else if (mensaje.substring(m,i+1).equals(",")){estado2=true;}
                    else if (mensaje.substring(m,i+1).equals("}")){estado1=false;estado2=false;}
                    else if (mensaje.substring(m,i+1).equals("/")){estado3=true;}
                    else if (mensaje.substring(m,i+1).equals(";")){estado3=false;}
                    else{
                        if(estado1==true & estado2==false){clave+=mensaje.substring(m,i+1);}
                        if(estado1==true & estado2==true){codigo1+=mensaje.substring(m,i+1);}
                        if(estado3==true){codigo2+=mensaje.substring(m,i+1);}
                    }
                    m++;
                }
                
                System.out.println("La clave es: "+clave);
                System.out.println("El codigo 1 es: "+codigo1);
                System.out.println("El codigo 2 es: "+codigo2);
                
                /////////////// Mensaje que le envia al cliente ////////////////////////////
                salida = new DataOutputStream(socket.getOutputStream());
                
                /////////////// Hace verificaciones para poder realizar una tarea ///////////////
                if (clave.equals("Crear juego")){
                    juego.crearTablero();
                    salida.writeUTF("//////////////////////Juego Creado");
                }
                else if (clave.equals("Agregar jugador")){
                    juego.agregarJugador(codigo1);
                    salida.writeUTF("//////////////////////Jugador agregado");
                }
                else if (clave.equals("Eliminar bloque")){
                    //juego.eliminarBloque(codigo1, codigo2);
                    salida.writeUTF("//////////////////////"+juego.eliminarBloque(codigo1, codigo2));
                }
                else if (clave.equals("Hielo")){
                    //juego.hielo(codigo2);
                    salida.writeUTF("//////////////////////"+juego.hielo(codigo2));
                }
                else if (clave.equals("Restar vida")){ // (Yetis, Aves)
                    //juego.restarVidas(codigo1);
                    salida.writeUTF("//////////////////////Vida restada de "+
                            codigo1+": "+juego.restarVidas(codigo1));
                    //salida.writeUTF("//////////////////////Vida restada");
                }
                else if (clave.equals("Enemigo eliminado")){ // (Yetis, Aves)
                    //juego.enemigoEliminado(codigo1,codigo2);
                    salida.writeUTF("//////////////////////"+juego.enemigoEliminado(codigo1,codigo2));
                }
                else if (clave.equals("Fruta recolectada")){ //(naranjas 100, bananos 200, Berenjenas 300, Lechugas 400)
                    //juego.frutaRecolectada(codigo1,codigo2);
                    salida.writeUTF("//////////////////////Puntos Totales de "+
                            codigo1+": "+juego.frutaRecolectada(codigo1,codigo2));
                }
                
                ////////////// Si no encuentra ninguna clave ///////////////
                else{salida.writeUTF("//////////////////////Error");};
                
                salida.flush();
                salida.close();
                
                ///////////// Cierra comunicacion con el cliente ////////////////////////
                socket.close();
                
            }
            
        }catch(Exception e){};
        }
        
    
    }    
    
}
