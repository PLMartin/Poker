#include "card.h"
#include "chance.h"

#include <stdio.h>
#include <stdlib.h>



static card get_card(void)
{
  int c;
  unsigned cmp = 0;
  unsigned value = 0;
  color col = none;
  while((c = fgetc(stdout)) != EOF) //Something wrong here...
  {
    printf("(%c , %u)\n", c, cmp);
    if(cmp == 1)
    {
      switch(c)
      {
        case 's':
	  col = spad;
	  break;
        case 'h':
	  col = heart;
	  break;
        case 'd':
	  col = diamond;
	  break;
        case 'c':
	  col = club;
	  break;
        default:
	  fprintf(stderr, "wrong card\n");
	  exit(EXIT_FAILURE);
      }
      cmp++;
    }
    
    if(cmp == 0)
    {
      
      switch(c)
      {
        case 'R':
	  value = 13;
	  break;
        case 'D':
	  value = 12;
	  break;
        case 'V':
	  value = 11;
	  break;
        case 'X':
	  value = 10;
	  break;
        default:
	  value = c - '1';
	  break;
      }
      cmp++;
    }


  }
  return create_card(value, col);
}



int main(void)
{
  //FRENCH VERSION

  fprintf(stdout, "\n\n**************************************\n");
  fprintf(stdout, "*             POKER HELPER           *\n");
  fprintf(stdout, "**************************************\n\n");
  
  fprintf(stdout, "Quelles sont vos cartes (1 -> 9 X V D R)(s,h,d,c) (ex: '1s') ?\n");
  char c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  
  card card1 = get_card();
  card card2 = get_card();
  hand h = create_hand(card1, card2);
  carpet carp = init_carpet();
  display_proba(carp, h);
  fprintf(stdout, "Quelles sont les cartes sur le tapis ?\n");
  while ((c = getchar()) != '\n' && c != EOF) { }
  for(int i = 0; i < 5; i++)
  {
    carp = add_card_to_carpet(carp, get_card());
    display_proba(carp, h);
  }
  exit(EXIT_SUCCESS);
}
