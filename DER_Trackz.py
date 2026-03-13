from graphviz import Digraph

# Criando o diagrama DER com Graphviz
der = Digraph("DER_Trackz", format="png")
der.attr(rankdir="LR", size="10")

# Entidades principais
der.node("EntidadeOrganizadora", "EntidadeOrganizadora\n(id, nome, selo, validada)")
der.node("Organizacao", "Organizacao\n(id, nome, selo)")
der.node("Atleta", "Atleta\n(id, nome, selo, perfil_oficial)")
der.node("AtletaFantasma", "AtletaFantasma\n(id, nome)")
der.node("Campeonato", "Campeonato\n(id, nome, modalidade, data_inicio, data_fim)")
der.node("Rodada", "Rodada\n(id, numero, campeonato_id)")
der.node("Partida", "Partida\n(id, rodada_id, timeA_id, timeB_id, placar)")
der.node("Usuario", "Usuario\n(id, email, senha, tipo_perfil)")

# Relacionamentos
der.edge("EntidadeOrganizadora", "Campeonato", label="cadastra")
der.edge("Campeonato", "Rodada", label="possui")
der.edge("Rodada", "Partida", label="contém")
der.edge("Organizacao", "Partida", label="participa")
der.edge("Atleta", "Organizacao", label="pertence")
der.edge("AtletaFantasma", "Organizacao", label="pertence provisoriamente")
der.edge("Usuario", "EntidadeOrganizadora", label="admin/mantenedor de")
der.edge("Usuario", "Organizacao", label="admin/mantenedor de")
der.edge("Usuario", "Atleta", label="perfil")
der.edge("EntidadeOrganizadora", "Organizacao", label="autoriza participação")

# Renderizar
der.render("/mnt/data/DER_Trackz", format="png", cleanup=False)

"/mnt/data/DER_Trackz.png"
