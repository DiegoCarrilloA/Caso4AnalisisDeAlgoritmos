/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clase1poo2021;
import java.awt.*;
import javax.swing.*;

class MyCanvas extends JComponent { 
       
    
    @Override
    public void paint(Graphics g) 
    { 
        
        
        
        // Pegar la salida del programa en C++
        //Here
        

   
    } 
} 
  
public class GFG1 { 
    public static void main(String[] a) 
    { 
   
        JFrame window = new JFrame(); 
        window.setBackground(Color.white);
        // setting closing operation 
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
  
        // Cambiar las dimensiones que requieran
        window.setSize(1920, 1080);
  
        // setting canvas for draw 
        window.getContentPane().add(new MyCanvas()); 
        window.setLocationRelativeTo(null);
        // set visibility 
        window.setVisible(true);
        
    } 
} 
