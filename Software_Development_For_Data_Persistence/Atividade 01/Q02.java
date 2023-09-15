package Q01;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Q02 {

    public static void main(String[] args) {
        String caminhoArq = args[0];
        String palavraChave = args[1];
        try {
            InputStream is = new FileInputStream(caminhoArq);
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader bf = new BufferedReader(isr);

            String linha;
            while ((linha = bf.readLine()) != null) {
                if(linha.contains(palavraChave)) {
                    System.out.println(linha);
                }
            }
            bf.close();
        } catch (Exception e) {
            System.out.println("Arquivo nao encontrado: " + e.getMessage());
        }
    }
}