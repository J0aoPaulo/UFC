import java.io.*;
import java.util.Objects;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

/*1. Crie uma aplicação em Java que recebe via linha de comando
 * o nome de um arquivo compactado a ser criado e uma pasta. Compactar
 * todos os arquivos e subpastas em um arquivo compactado com extensão zip.*/
public class Q01 {
    public static void main(String[] args) {
        String camArquivo = args[0];
        String nomeZip = args[1];

        ziparPasta(camArquivo, nomeZip);
    }
    public static void ziparPasta(String caminho, String nomeDoZip) {
        try {
            FileOutputStream fos = new FileOutputStream(nomeDoZip);
            ZipOutputStream zos = new ZipOutputStream(fos);
            zipSubDirect(caminho, caminho, zos);

            zos.closeEntry();
            zos.finish();
            fos.close();
            zos.close();
        } catch (IOException e) {
            System.err.println("Erro: " + e);
        }
    }
    public static void zipSubDirect(String camOrigem, String camAtual, ZipOutputStream zos) {
        try {
            File pasta = new File(camAtual);
            for (File arq : Objects.requireNonNull(pasta.listFiles())) {
                if (arq.isDirectory()) {
                    zipSubDirect(camOrigem, arq.getPath(), zos);
                } else {
                    byte[] buffer = new byte[1024];
                    FileInputStream fis = new FileInputStream(arq);
                    String arqOriginal = arq.getPath().substring(camOrigem.length() + 1);
                    ZipEntry ze = new ZipEntry(arqOriginal);
                    zos.putNextEntry(ze);
                    int leitura;
                    while ((leitura = fis.read(buffer)) > 0) {
                        zos.write(buffer, 0, leitura);
                    }
                    fis.close();
                }
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
