import java.io.*;
import java.security.*;

/*Crie uma aplica��o em java que recebe via linha de comando o nome de um arquivo
* para gera��o/armazenamento dos hashes md5, shal e sha256 do arquico especificado
* A aplica��o deve mostrar o tempo de execu��o de cada uma dessas opera��es.*/
public class Q04 {

    public static void main(String[] args) {
        String nomeArq = args[0];
        try {
            File file = new File(nomeArq);
            String[] algoritmos = {"MD5", "SHA-1", "SHA-256"};

            for (String algoritmo : algoritmos) {
                long ini = System.currentTimeMillis();
                String hash = generateHash(file, algoritmo);
                long fim = System.currentTimeMillis();

                System.out.println(algoritmo + " Hash: " + hash);
                System.out.println("Tempo de execu��o (" + algoritmo + "): " + (fim - ini) + " ms\n");
            }

        } catch (IOException | NoSuchAlgorithmException e) {
            System.err.println("Erro: " + e);
        }
    }
    private static String generateHash(File file, String algorithm)
            throws IOException, NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance(algorithm);
        try (FileInputStream fis = new FileInputStream(file)) {
            byte[] arrayBytes = new byte[1024];

            int leitorByte;
            while ((leitorByte = fis.read(arrayBytes)) != -1) {
                md.update(arrayBytes, 0, leitorByte);
            }
            byte[] hashBytes = md.digest();
            StringBuilder hexHash = new StringBuilder();

            for (byte hashByte : hashBytes) {
                hexHash.append(String.format("%02x", hashByte));
            }
            return hexHash.toString();
        }
    }
}