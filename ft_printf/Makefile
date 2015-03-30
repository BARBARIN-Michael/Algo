#type du projet
TYPE = algebre
#TYPE = graphique

#Nom de lexecutable :
EXECUTABLE = Printf

# Choix du compilateur :
COMPILATEUR = gcc
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -O0

LIB    =   -I ./libft/Include/  -L ./libft/  -lft
LIB   +=   -I ./libftprintf/Include/  -L ./libftprintf/  -lftprintf
#LIB  +=   -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  +=   -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

ifeq ($(TYPE), graphique)
	LIB  += -I /usr/X11/include -L Lib/minilibx/ -lmlx
	LIB  += -L /usr/X11/lib/ -lXext -lX11 -lm
endif

# -------------------------------------------------------------------
#  Emplacement des sources et des objets, des includes et de lexecutable
# -------------------------------------------------------------------

# Dossier racine du code :
CODE :=.

# dossier de lexecutable
EXEDIR := $(CODE)/Bin

# Adresse des sources, des objets et des includes :
SRCDIR = $(CODE)/Srcs
OBJDIR = $(CODE)/Objets
INCDIR = $(CODE)/Includes

# creation de la liste des fichiers sources :
SRC =	$(SRCDIR)/main.c

# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: help

help:
	@echo
	@echo "\033[33;36m Programme \033[33;1m$(EXECUTABLE)\033[33;0m"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo "\033[33;36m Regles disponibles"
	@echo
	@echo "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@echo "\033[33;36m relib     : \033[33;0mRecompile la library"
	@echo "\033[33;36m cplib     : \033[33;0mcompile la library"
	@echo "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@echo "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@echo "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@echo "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@echo "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

re_pre: faire_dossier cp

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe
	@echo
	@echo "\033[33;32mFile created\tDONE\033[33;0m"
	@echo

# regle edition de liens
install: faire_dossier

cp: $(OBJ)
	$(COMPILATEUR) $(COPTIONS) $(LIB) -o $(EXEDIR)/$(EXECUTABLE) $(LIB) $(OBJ)
	cp ./libftprintf/*.a .

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	$(COMPILATEUR) -c  $(COPTIONS) $(LIB) -o $@ $(LIB) $<

# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin moulitest

# creation du dossier $(OBJDIR) si besoin :
dirobj:
	mkdir -p $(OBJDIR)

direxe:
	mkdir -p $(EXEDIR)
	make -C ./libft/ 
	make -C ./libftprintf/ 
	cp ./libftprintf/*.a .

relib:
	make -C ./libft/ re
	make -C ./libftprintf/ re
	cp ./libftprintf/*.a .

cplib:
	make -C ./libft/ 
	make -C ./libftprintf/ 
	cp ./libftprintf/*.a .
	make cp

moulitest:
	make -C ./moulitest/ft_printf_tests/ re

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	@rm -rf $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean: clean
	rm -rf $(EXEDIR) $(OBJDIR) && mkdir -p $(EXEDIR) $(OBJDIR)

uninstall:
	@printf "\r\033[33;31mDelete all project file and library file\033[33;0m\n"
	rm -rf $(OBJDIR) $(EXEDIR)
	make -C ./libft/ fclean
	make -C ./libftprintf/ fclean

re: 
	make relib
	 make cp
