import subprocess
import os

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

tests = [
    ("admin\n1234\n", "Acesso concedido"),
    ("admin\n0000\n", "Acesso negado"),
    ("root\n1234\n", "Acesso negado"),
]

programas = {
    "C login1": ["gcc", os.path.join(BASE_DIR, "C", "login1.c"), "-o", os.path.join(BASE_DIR, "C", "login1.out")],
    "C login2": ["gcc", os.path.join(BASE_DIR, "C", "login2.c"), "-o", os.path.join(BASE_DIR, "C", "login2.out")],
    "Go login1": ["go", "build", "-o", os.path.join(BASE_DIR, "go", "login1.out"), os.path.join(BASE_DIR, "go", "login1.go")],
    "Go login2": ["go", "build", "-o", os.path.join(BASE_DIR, "go", "login2.out"), os.path.join(BASE_DIR, "go", "login2.go")],
    "Java LoginGlobal": ["javac", os.path.join(BASE_DIR, "java", "LoginGlobal.java")],
    "Java LoginLocal": ["javac", os.path.join(BASE_DIR, "java", "LoginLocal.java")],
}

print("== Compilando ==")
for nome, cmd in programas.items():
    print(f"Compilando {nome}...")
    subprocess.run(cmd)

executaveis = {
    "C login1": [os.path.join(BASE_DIR, "C", "login1.out")],
    "C login2": [os.path.join(BASE_DIR, "C", "login2.out")],
    "Go login1": [os.path.join(BASE_DIR, "go", "login1.out")],
    "Go login2": [os.path.join(BASE_DIR, "go", "login2.out")],
    "Java LoginbGlobal1": ["java", "-cp", os.path.join(BASE_DIR, "java"), "LoginGlobal"],
    "Java LoginLocal": ["java", "-cp", os.path.join(BASE_DIR, "java"), "LoginLocal"],
    "Python login1": ["python3", os.path.join(BASE_DIR, "python", "login1.py")],
    "Python login2": ["python3", os.path.join(BASE_DIR, "python", "login2.py")],
}

print("\n== Executando Testes ==")
for nome, cmd in executaveis.items():
    print(f"\n--- Testando {nome} ---")
    for i, (entrada, esperado) in enumerate(tests, 1):
        result = subprocess.run(cmd, input=entrada.encode(), capture_output=True)
        saida = result.stdout.decode().strip()
        print(f"Teste {i}: entrada=({entrada.strip().replace(chr(10), ', ')})")
        print(f"Saída obtida:   {saida}")
        print(f"Saída esperada: {esperado}")
