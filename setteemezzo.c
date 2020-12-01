#include "setteemezzo.h"


/**
 * Create a list of number representing all the cards of the spanish deck sorted.
 * Generate random indexes to this list. Each position that has not been visited before is "deleted" leaving
 * the value 41 in that position. The original value that was in that position is added to the deck.
 */
void initialize_deck(unsigned int * deck)
{
  unsigned int cards[40];
  for (unsigned int i = 0; i < 40; i++)
  {
    cards[i] = i;
  }

  unsigned int added_num_cards = 0;
  while (added_num_cards < 40)
  {
  	unsigned int index = rand() % 40;
  	if (cards[index] != 41)
  	{
  	  deck[added_num_cards] = cards[index];
  	  cards[index] = 41;
  	  added_num_cards++;
  	}
  	else
  	{
  		continue;
  	}
  }
  
}

unsigned int get_scores_of_card_in_half_points(unsigned int card)
{
  unsigned int value = card % 10;
  // Treat a normal card
  if (value < 7)  
  {
    return 2 * (value + 1);  // We adjust points to return halves of points
  }
  // Treat a figure
  else
  {
    return 1;
  }
   
}



/**
 * Algorithm to play the "sette e mezzo" card game. 
 * 
 * We call deck to a list of 40 integers or less representing an spanish deck.
 * We will call "card" an integer number that goes from 0 to 39 representing a card of the spanish deck.
 *
 * To obtain the suit of the card we will use the division of the card number with 10, which 
 * is the number of cards for each suit. The quotient resulted from the division of the card number and 10 
 * can give 0 (oros), 1 (copas), 2 (espadas), 3 (basos).
 * 
 * To obtain the number of the card we will use the module operation against the card number with 10.
 * The rest resulted from the division of this number can give all the values from 0 to 9, being 0 the ace,
 * 1 the number two, 2 the number three and so on. Differently, 7 will be sota, 8 horse and 9 king.
 * We can easily deduct the value of a card.
 *
 * Scores are treated as integers and not as floats for the sake of simplicity. 15 half points will be the objective
 */ 
int main(int nargs, char* args[])
{

  unsigned int deck[40];
  unsigned int num_cards = 40;
  unsigned int computer_half_points = 0;
  unsigned int person_half_points = 0;
  unsigned int card_score;
  bool person_turn = true;
  unsigned int decision;

  srand(time(NULL));
  initialize_deck(deck);

  do
  {
    if (person_turn)
    {
      printf("\n\nTorn jugador. Què vols fer? Passar (0) o demanar (1)?");
      while (scanf("%u", &decision) != 1) {}
      if (decision)
      {
      	num_cards--;
      	card_score = get_scores_of_card_in_half_points(deck[num_cards]);
      	printf("\nS'ha tret una carta amb %f punts de valor.", (float)card_score / 2);
      	person_half_points += card_score;
      	printf("\nPortes %f punts.", (float) person_half_points / 2);
      	if (person_half_points == 15)
      	{
      	  printf("\nHas arribat a 7 i mig! Has guanyat.\n");
      	  exit(0);
      	}
      	else if (person_half_points > 15)
      	{
          printf("\nT'has passat de 7 i mig! Has perdut.\n");
          exit(0);
      	}
      }
      person_turn = !person_turn;
    }
    else
    {
      printf("\n\nTorn PC. Què vols fer? Passar (0) o demanar (1)?");
      decision = rand() % 2 == 1;
      if (decision)
      {
      	printf("\nOrdinador demana.");
      	num_cards--;
      	card_score = get_scores_of_card_in_half_points(deck[num_cards]);
      	printf("\nL'ordinador ha tret una carta amb %f punts de valor.", (float)card_score / 2);
      	computer_half_points += card_score;
      	printf("\nL'ordinador porta %f punts.", (float) computer_half_points / 2);
      	if (computer_half_points == 15)
      	{
      	  printf("\nL'ordinador ha arribat a 7 i mig! Has perdut.\n");
      	  exit(0);
      	}
      	else if (computer_half_points > 15)
      	{
          printf("\nL'ordinador s'ha passat de 7 i mig! Has guanyat.\n");
          exit(0);
      	}
      }
      else
      {
      	printf("\nOrdinador no demana carta.");
      }
      person_turn = !person_turn;
    }
  }
  while (num_cards > 0);

  printf("\nS'han acabat les cartes! Tothom guanya.\n");
}


