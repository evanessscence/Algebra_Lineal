/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.uam.bscc;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.Desktop;
import java.io.File;
/**
 *
 * @author a n n a
 */
public class Archivos {
    
    public static void guardarArchivo(String textoAGuardar, String nombreArchivo) {

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nombreArchivo))) {
            writer.write(textoAGuardar);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void ejecutarArchivo(String rutaDelArchivo) {
        try {
            File archivo = new File(rutaDelArchivo);

            if (archivo.exists()) {
                Desktop.getDesktop().open(archivo);
            } else {
                System.err.println("El archivo no existe: " + rutaDelArchivo);
            }
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Error al abrir el archivo: " + rutaDelArchivo);
        }
    } 
}
