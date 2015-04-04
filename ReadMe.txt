
dans cette verssion j'ai refait la classe claculePoid :
 
*   le poid d'une diagonale est la somme de ces petite diagonale  w(D)=w(D1)+...+w(Dn)

*  on a pas avtiver l'option de : si on la probabiliter < 10 puis -5 donc la prob == l1*l2*proba
    car la valour de proba va augmenter et donc la valeur de poids va se deminuer
    donc on tembe dans le cas au des petite diagonale (exemple D(9,9)) ont un poids > que des diagonale
   plus grand et ont un nb de simi plus grans aussi (exemple D(10,10))
 