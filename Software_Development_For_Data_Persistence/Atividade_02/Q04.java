import java.io.*;

public class Q04 {
    public static void main(String[] args) {
        BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder texto = new StringBuilder();

        try {
            String linha;

            while (true) {
                linha = teclado.readLine();
                if (linha.equalsIgnoreCase("FIM")) {
                    break;
                }
                texto.append(linha).append("\n");
            }
            System.out.print("Digite o nome do arquivo para salvar o texto: ");
            String arquivoDestino = teclado.readLine();

            FileOutputStream fos = new FileOutputStream(arquivoDestino);
            OutputStreamWriter osw = new OutputStreamWriter(fos);

            osw.write(texto.toString());
            osw.close();
            System.out.println("Texto salvo no arquivo: " + arquivoDestino);
        } catch (IOException e) {
            System.err.println("Erro ao ler ou gravar o arquivo: " + e.getMessage());
        }
    }
}