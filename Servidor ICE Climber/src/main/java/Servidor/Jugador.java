/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Servidor;

/**
 *
 * @author PC34
 */
public class Jugador {
    
    int puntos=0;
    String nombre="";
    int vidas=3;
    
    public Jugador(){ };
    
    //Funciones para obtener y modificar los puntos
    public int getPuntos(){return puntos;};
    public void setPuntos(int p){puntos=p;}
    
    //Funciones para obtener y modificar el nombre
    public String getNombre(){return nombre;};
    public void setNombre(String n){ nombre=n;};
    
    //Funciones para obtener y modificar las vidas
    public int getVidas(){return vidas;};    
    public void setVidas(int v){vidas=v;};
    
}
