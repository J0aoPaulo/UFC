import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
/*Crie uma aplicação em java que receba via linha de comando o nome de
* um arquivo a ser decriptado e o nome de um arquivo resultante da decriptação
* e a chave de decriptação.*/
public class Q03 {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, FileNotFoundException {
        String arqEncript = args[0];
        String nomeDecript = args[1];
        String keyDecript = args[2];

        decriptArq(arqEncript, nomeDecript, keyDecript);
        System.out.println("Arquivo decriptado com sucesso!");
    }
    public static void decriptArq(String arqEncript, String nomeDecript, String keyDecript) throws InvalidKeyException,
            NoSuchPaddingException, NoSuchAlgorithmException {
        SecretKeySpec sks = new SecretKeySpec(keyDecript.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, sks);

        try (InputStream is = new FileInputStream(arqEncript);
             CipherInputStream cis = new CipherInputStream(is, cipher);
             OutputStream outputStream = new FileOutputStream(nomeDecript)) {

            byte[] buffer = new byte[1024];
            int leitorByte;
            while ((leitorByte = cis.read(buffer)) != -1) {
                outputStream.write(buffer, 0, leitorByte);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
