package Q01;
import java.io.*;
import java.util.Scanner;

public class Q01 {

    public static void main(String[] args) {
        String caminhoArq = args[0];
        try {
            InputStream is = new FileInputStream(caminhoArq);
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader bf = new BufferedReader(isr);

            String linha;
            int contLinha = 0, limiteLinha = 10;
            while(contLinha < limiteLinha) {
                linha = bf.readLine();
                System.out.println(linha);
                contLinha++;
            }
            bf.close();
        } catch (Exception e) {
            System.out.println("Arquivo não encontrado: " + e.getMessage());
        }
    }
}