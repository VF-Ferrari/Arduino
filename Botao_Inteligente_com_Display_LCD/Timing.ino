boolean longPressed(unsigned long time){
  return((millis() - time) > getLimitTime()) ? true : false;
  }

boolean timing(unsigned long time){
  return(millis() > time) ? true : false;
  }
