# Segment-Display
Dupa citirea dimensiunilor, daca comanda data este 'Q' programul se
opreste, altfel continua pana cand comanda va fi 'Q', insa daca este 'F'
citesc in "digit" cifra, iar prin variabilele a, b,..., g, voi stii ce
cifra trebuie construita. Daca a = 1, in matricea display initializata
cu 0, pun pe segmentul 'a' valoarea 1, iar cand comanda este 'P' daca
atunci cand parcurg matricea gasesc valoarea '1' afisez "^ ", altfel
daca e '0', afisez "  ". In cazul in care primesc comanda W, A ,S sau D
mut valorile de 1 in directia dorita cu cat primesc la citire in "count"
si daca valoarea 1 depaseste marimea matricii, salvez valorile in alta
matrice auxiliara "last" si le inserez inapoi in "display" dupa mutarea
restul variabilelor ce nu depasesc marimea initiala.
