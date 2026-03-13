def login(user, password):
    valid_user = "admin"
    valid_pass = "1234"
    return user == valid_user and password == valid_pass
user = input("Usuario: ")
password = input("Senha: ")
if login(user, password):
    print("Acesso concedido")
else:
    print("Acesso negado")