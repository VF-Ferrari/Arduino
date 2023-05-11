/*
 * CONTROLE DOS TEMPORIZADORES
*/


/*
 * Retorna TRUE se já passou 2 segundos do tempo informado
 */
boolean longPressed(unsigned long time){
  return ((millis() - time) > getLimitTime()) ? true : false;
}


/*
 * Return TRUE se o tempo atual chegou no tempo futuro
*/
boolean timing(unsigned long time){
  return (millis() > time) ? true : false;
}
