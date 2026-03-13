valid_user = "admin"
valid_pass = "1234"
def login(user, password):
    return user == valid_user and password == valid_pass
user = input("Usuario: ")
password = input("Senha: ")
if login(user, password):
    print("Acesso concedido")
else:
    print("Acesso negado")