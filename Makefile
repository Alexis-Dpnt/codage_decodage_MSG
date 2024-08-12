# Définitions des variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = main.c codage.c decodage.c utils.c resultat.c
TARGET = programme

# Règle pour générer l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Règle pour générer les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de nettoyage
clean:
	rm -f $(TARGET)
