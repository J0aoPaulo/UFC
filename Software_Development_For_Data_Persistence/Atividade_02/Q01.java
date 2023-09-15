import java.io.*;

public class Q01 {
    public static void main(String[] args) {
        String arqOrigem = args[0];
        String arqDestino = args[1];

        try (FileInputStream inOrigem = new FileInputStream(arqOrigem);
        FileOutputStream outDestino = new FileOutputStream(arqDestino)) {
            int byteLido;
            long inicio = System.currentTimeMillis();
            while ((byteLido = inOrigem.read()) != -1) {
                outDestino.write(byteLido);
            }
            long fim = System.currentTimeMillis();
            long tempMili = fim - inicio;
            double tempSegundos = (double) tempMili / 1000.0;

            System.out.println("Tempo decorrido em milisegundos: " + tempMili + "ms");
            System.out.println("Tempo decorrido em segundos: " + tempSegundos + "s");
            System.out.println("Arquivo lido e transferido com sucesso!");
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }
    }
}