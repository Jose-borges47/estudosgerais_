 import java.util.Scanner;
 public class LoginGlobal {
    static String validUser = "admin";
    static String validPass = "1234";
    static boolean login(String user, String pass) {
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