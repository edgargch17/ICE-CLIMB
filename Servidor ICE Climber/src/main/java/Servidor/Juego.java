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
public class Juego {
    
    //Matriz del tablero
    int tablero [][];
    int nFilas = 8;
    int nColumnas = 32;
    
    //lista de los Jugadores
    Jugador listaJugadores[];
    
    public Juego(){ };
    
    public void crearTablero (){
        tablero = new int[nFilas][nColumnas];
        for (int i=0;i<nFilas;i++){
            for (int j=0;j<nColumnas;j++){
                tablero[i][j] = 1;
            }
        }
        
        listaJugadores = new Jugador[4];
        for (int i=0;i<4;i++){
            if (listaJugadores[i]==null){
                listaJugadores[i] = new Jugador();
            }
        }
    }
    
    public void agregarJugador (String nomJugador){
        for (int i=0;i<4;i++){
            if (listaJugadores[i].getNombre().equals("")){
                listaJugadores[i].setNombre(nomJugador);
                i=5;
            }
        }
    }
    
    public String agregarPuntos (String jugador, int puntos){
        for (int i=0;i<4;i++){
            if (listaJugadores[i].getNombre().equals(jugador)){
                i=5;
                listaJugadores[i].setPuntos(listaJugadores[i].getPuntos()+puntos);
                return String.valueOf(listaJugadores[i].getPuntos());
            }
        }
        return "No existe ese jugador";
    }
    
    public String restarVidas (String jugador){
        for (int i=0;i<4;i++){
            if (listaJugadores[i].getNombre().equals(jugador)){
                listaJugadores[i].setVidas(listaJugadores[i].getVidas()-1);
                System.out.println(listaJugadores[i].getVidas());
                return String.valueOf(listaJugadores[i].getVidas());
            }
        }
        return "No existe ese jugador";
    }
    
    public String eliminarBloque (String jugador, String bloque){
        // Tablero[x][y]=0 , ya que se elimina el bloque
        tablero[nFilas-Integer.parseInt(bloque.substring(0,1))][Integer.parseInt(bloque.substring(2,4))]=0;
        imprimirTablero();
        return "Bloque eliminado";
    }
    
    public String enemigoEliminado (String jugador, String enemigo){
        if (enemigo.equals("yeti")){return "enemigo eliminado";}
        else if (enemigo.equals("ave")){return "enemigo eliminado";}
        else {return "enemigo no encontrado";}
    }
    
    public String frutaRecolectada (String jugador, String fruta){ //(naranjas 100, bananos 200, Berenjenas 300, Lechugas 400)
        for (int i=0;i<4;i++){
            
            if (listaJugadores[i].getNombre().equals(jugador)){
                if (fruta.equals("naranja")){
                    listaJugadores[i].setPuntos(listaJugadores[i].getPuntos()+100);
                    return String.valueOf(listaJugadores[i].getPuntos());
                }
                else if (fruta.equals("banano")){
                    listaJugadores[i].setPuntos(listaJugadores[i].getPuntos()+200);
                    return String.valueOf(listaJugadores[i].getPuntos());
                }
                else if (fruta.equals("berenjena")){
                    listaJugadores[i].setPuntos(listaJugadores[i].getPuntos()+300);
                    return String.valueOf(listaJugadores[i].getPuntos());
                }
                else if (fruta.equals("lechuga")){
                    listaJugadores[i].setPuntos(listaJugadores[i].getPuntos()+400);
                    return String.valueOf(listaJugadores[i].getPuntos());
                }
                else {return "No existe esa fruta";}
            }
        }
        return "No existe ese jugador";
    }
    
    public String hielo (String piso){
        tablero[nFilas-Integer.parseInt(piso.substring(0,1))][Integer.parseInt(piso.substring(2,4))]=2;
        imprimirTablero();
        System.out.println("\n \n");
        tablero[nFilas-Integer.parseInt(piso.substring(0,1))][Integer.parseInt(piso.substring(2,4))]=1;
        imprimirTablero();
        return "Hielo agregado";
    }
    
    public void imprimirTablero (){
        for (int x=0; x < nFilas; x++) {
            System.out.print("|");
            for (int y=0; y < nColumnas; y++) {
              System.out.print (" "+tablero[x][y]);
            }
            System.out.println(" |");
            System.out.println("\n");            
        }
    }
    
}
