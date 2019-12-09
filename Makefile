all:
	@echo "Aucun parametre defini (chaine, arbre, table ou clean)."

chaine:
	@echo "#include \"../tad/tad_chaine/tad_chaine.h\"\nencyclopedie remplissage_encyclopedie(encyclopedie e);" > app/utils/remplissage.h
	gcc app/main.c app/encyclopedie/encyclopedie.c app/utils/utils.c app/utils/remplissage.c app/tad/tad_chaine/tad_chaine.c -o projet_wiki_chaine
	@echo "L'executable \"projet_wiki_chaine\" a ete cree : executez ./projet_wiki_chaine"

arbre:
	@echo "#include \"../tad/tad_arbre/tad_arbre.h\"\nencyclopedie remplissage_encyclopedie(encyclopedie e);" > app/utils/remplissage.h
	gcc app/main.c app/encyclopedie/encyclopedie.c app/utils/utils.c app/utils/remplissage.c app/tad/tad_arbre/tad_arbre.c -o projet_wiki_arbre
	@echo "L'executable \"projet_wiki_arbre\" a ete cree : executez ./projet_wiki_arbre"

table:
	@echo "#include \"../tad/tad_table/tad_table.h\"\nencyclopedie remplissage_encyclopedie(encyclopedie e);" > app/utils/remplissage.h
	gcc app/main.c app/encyclopedie/encyclopedie.c app/utils/utils.c app/utils/remplissage.c app/tad/tad_table/tad_table.c -o projet_wiki_table
	@echo "L'executable \"projet_wiki_table\" a ete cree : executez ./projet_wiki_table"

clean:
	rm -f projet_wiki_chaine projet_wiki_arbre projet_wiki_table
	@echo "Tous les executables ont ete supprimes."