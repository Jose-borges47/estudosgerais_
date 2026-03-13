package main

import (
    "fmt"
)
func login(user, pass string) bool {
    validUser := "admin"
    validPass := "1234"
    return user == validUser && pass == validPass
}
func main() {
    var user, pass string
    fmt.Print("Usuario: ")
    fmt.Scanln(&user)
    fmt.Print("Senha: ")
    fmt.Scanln(&pass)
    if login(user, pass) {
        fmt.Println("Acesso concedido")
    } else {
        fmt.Println("Acesso negado")
    }
}