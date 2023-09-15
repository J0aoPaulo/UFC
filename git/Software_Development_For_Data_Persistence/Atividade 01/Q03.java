package Q01;

import java.io.*;
import java.util.*;

public class Q03 {

    public static void main(String[] args) throws IOException {
        String caminhoArq01 = args[0];
        String caminhoArq02 = args[1];

        readArq(caminhoArq01);
        readArq(caminhoArq02);
    }
    public static void readArq(String arquivo) throws IOException {
        InputStream is = new FileInputStream(arquivo);
        InputStreamReader isr = new InputStreamReader(is);
        BufferedReader bf = new BufferedReader(isr);
        String linha;
        while ((linha = bf.readLine()) != null) {
            System.out.println(linha);
        }
        bf.close();
    }
}