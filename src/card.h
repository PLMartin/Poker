#ifndef CARD_H
#define CARD_H


// V = 11 / Q = 12 / R = 13



typedef enum color {
  spad,     //pique
  heart,    //coeur
  diamond,  //carreau
  club,     //trefle
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
  card cards[7];
  unsigned last_card;
} carpet;



/********************************************************************/

carpet init_carpet(void);

extern carpet add_card_to_carpet(carpet carp, card c);

hand create_hand(card first, card second);

card create_card(int val, color col);

carpet fusion(hand h, carpet carp);

carpet sort_by_color(carpet carp);

carpet sort_by_number(carpet carp);


  
#endif
