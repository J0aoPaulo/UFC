import java.io.*;
import java.util.Arrays;

public class Q01 {
    public static void main(String[] args) {
        String arqCsv = args[0];
        String delimitador = args[1];
        String[] colunasEscolhidas = Arrays.copyOfRange(args, 2, args.length);

        try (BufferedReader br = new BufferedReader(new FileReader(arqCsv))){
            String[] headers = br.readLine().split(delimitador);
            int[] indColunas = new int[colunasEscolhidas.length];
            for (int i = 0; i < indColunas.length; i++) {
                indColunas[i] = -1;
            }

            for (int i = 0; i < colunasEscolhidas.length; i++) {
                for (int j = 0; j < headers.length; j++) {
                    if(colunasEscolhidas[i].equals(headers[j])) {
                        indColunas[i] = j;
                        break;
                    }
                }
            }
            String linha;
            double[] sumCol = new double[colunasEscolhidas.length];
            int[] contCol = new int[colunasEscolhidas.length];

            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(delimitador);
                for (int i = 0; i < colunasEscolhidas.length; i++) {
                    int ind = indColunas[i];

                    if (ind != -1) {
                        try {
                            double valor = Double.parseDouble(dados[ind]);
                            sumCol[i] += valor;
                            contCol[i]++;
                        } catch (NumberFormatException e) {
                            System.err.println("Erro: " + e);
                        }
                    }
                }
            }
            for (int i = 0; i < colunasEscolhidas.length; i++) {
                if(indColunas[i] != -1) {
                    double sum = sumCol[i];
                    int cont = contCol[i];
                    if(cont > 0) {
                        double media = sum / cont;
                        System.out.println("Coluna: " + colunasEscolhidas[i]);
                        System.out.println("Soma: " + sum);
                        System.out.println("Media: " + media);
                    } else {
                        System.out.println("Coluna: " + colunasEscolhidas[i]);
                        System.out.println("Coluna nao numerica");
                    }
                    System.out.println();
                } else {
                    System.out.println("Coluna: " + colunasEscolhidas[i]);
                    System.out.println("Nao encontrada no arquivo.");
                    System.out.println();
                }
            }
        } catch (IOException e) {
            System.err.println("Erro: " + e);
        }
    }
}