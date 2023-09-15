import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;
import java.util.Scanner;

public class Q03 {
    public static void main(String[] args) {
        Properties propriedades = new Properties();

        try (FileReader fr =new FileReader("config.properties")) {
            propriedades.load(fr);

            String nameArchive = propriedades.getProperty("arquivo");
            int initialLine = Integer.parseInt(propriedades.getProperty("linha_inicial"));
            int finalLine = Integer.parseInt(propriedades.getProperty("linha_final"));

            try (Scanner arqScanner = new Scanner(new FileReader(nameArchive))) {
                int numLinha = 0;

                while (arqScanner.hasNextLine()) {
                    String linha = arqScanner.nextLine();
                    numLinha++;

                    if (numLinha >= initialLine && numLinha <= finalLine) {
                        System.out.println(linha);
                    }

                    if (numLinha > finalLine) {
                        break;
                    }
                }
            } catch (IOException e) {
                System.err.println("Erro: " + e.getMessage());
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}