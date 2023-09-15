import java.io.*;

public class Q02 {
    public static void main(String[] args) {
        String arqOrigem = args[0];
        String arqDestino = args[1];
        File arquivo = new File(arqOrigem);
        long tam = arquivo.length();
        System.out.println("O arquivo tem " + tam + "bytes!");

        try (FileInputStream fis = new FileInputStream(arqOrigem);
        FileOutputStream fos = new FileOutputStream(arqDestino)) {
            byte[] buffer = new byte[8192];
            int byteLido;
            long inicio = System.currentTimeMillis();

            while ((byteLido = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, byteLido);
            }
            long fim = System.currentTimeMillis();
            long tempMili = fim - inicio;
            double tempSegundos = (double) tempMili / 1000.0;

            System.out.println("Tempo em milisegundos: " + tempMili + "ms");
            System.out.println("Tempo em segundos: " + tempSegundos + "s");
            System.out.println("Dados escritos com sucesso!");
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }
    }
}