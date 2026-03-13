 import java.util.Scanner;
 public class LoginLocal {
    static boolean login(String user, String pass) {
        String validUser = "admin";
        String validPass = "1234";
        return user.equals(validUser) && pass.equals(validPass);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Usuario: ");
        String user = sc.nextLine();
        System.out.print("Senha: ");
        String pass = sc.nextLine();
        if (login(user, pass))
            System.out.println("Acesso concedido");
        else
            System.out.println("Acesso negado");
        sc.close();
    }
 }