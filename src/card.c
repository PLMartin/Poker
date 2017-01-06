


typedef enum color {
  spads,    //pique
  heart,    //coeur
  diamond,  //carreau
  club,      //trefle
  none
} color;
  
  
typedef struct card {
  int value;
  color color;
} card;


typedef struct hand {
  card card1;
  card card2;
} hand;


typedef struct carpet {
  card cards[5];
} carpet;



/********************************************************************/

carpet init_carpet(void)
{
  carpet initial;
  for(int i = 0; i < 6; i++)
  {
    initial.cards[i].value = 0;
    initial.cards[i].color = none;
  }
  return initial;
}


hand init_hand(card first, card second)
{
  hand h;
  h.card1 = first;
  h.card2 = second;
  return h;
}


card create_card(int val, color col)
{
  card c;
  c.value = val;
  c.color = col;
  return c;
}
  





  








