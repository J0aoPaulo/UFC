import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

/*Crie uma aplicação em java que recebe via linha de comando o nome de um arquivo
* a ser encriptado, o nome de um arquivo encriptado a ser criado e a chave de encriptação.*/
public class Q02 {
    public static void main(String[] args) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, IOException {
        String encripArq = args[0];
        String nomeEncript = args[1];
        String senha = args[2];

        encrypt(encripArq, nomeEncript, senha);
        System.out.println("Arquivo encriptado com sucesso");
    }
    public static void encrypt(String encriptArq, String nomeEncript, String pass) throws NoSuchAlgorithmException,
            NoSuchPaddingException, InvalidKeyException, IOException {
        SecretKeySpec sks = new SecretKeySpec(pass.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, sks);

        try (FileInputStream fis = new FileInputStream(encriptArq);
        FileOutputStream fos = new FileOutputStream(nomeEncript);
        CipherOutputStream cos = new CipherOutputStream(fos, cipher)) {
            byte[] buffer = new byte[8192];
            int leitorByte;
            while ((leitorByte = fis.read(buffer)) != -1) {
                cos.write(buffer, 0, leitorByte);
            }
        }
    }
}