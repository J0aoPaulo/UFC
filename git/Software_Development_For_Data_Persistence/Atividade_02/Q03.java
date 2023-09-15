import java.io.*;
import java.nio.charset.StandardCharsets;

public class Q03 {
    public static void main(String[] args) {
        String arqOrigem = args[0];
        String arqiso = args[1];
        String encode01 = args[2];
        String arqUtf = args[3];
        String encode02 = args[4];

        encodeConvert(encode01, arqOrigem, arqiso);
        encodeConvert(encode02, arqiso, arqUtf);
        System.out.println("Arquivos convetidos com sucesso!");
    }

    public static void encodeConvert(String encode, String arqOrigem, String arqDestino) {
        try {
            if ("ISO".equals(encode) || "iso".equals(encode)) {
                FileInputStream fis = new FileInputStream(arqOrigem);
                InputStreamReader isr = new InputStreamReader(fis, StandardCharsets.UTF_8);

                FileOutputStream fos = new FileOutputStream(arqDestino);
                OutputStreamWriter osr = new OutputStreamWriter(fos, StandardCharsets.ISO_8859_1);

                int c;
                while ((c = isr.read()) != -1) {
                    osr.write(c);
                }
                isr.close();
                osr.close();
            } else if ("UTF".equals(encode) || "utf".equals(encode)) {
                FileInputStream fis = new FileInputStream(arqOrigem);
                InputStreamReader isr = new InputStreamReader(fis, StandardCharsets.ISO_8859_1);

                FileOutputStream fos = new FileOutputStream(arqDestino);
                OutputStreamWriter osr = new OutputStreamWriter(fos, StandardCharsets.UTF_8);

                int c;
                while ((c = isr.read()) != -1) {
                    osr.write(c);
                }
                isr.close();
                osr.close();
            } else {
                System.err.println("Digite o encode correto e tente novamente.");
            }
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }
    }
}