#include "hedz.h"

int main(){

	 int bets = 0, pot = 0;

	 Deck game_deck = get_new_Deck();

	 welcome();

	 printf("\n");
	 hBorder();
	 printf("\n");

	 Player one = player_init(getName(), getRupies());
	 printf("Hi %s, you have %i rupies\n",one.name, one.rupies);
	 Player two = player_init("Link", one.rupies);
	 Player three = player_init("Mario", one.rupies);
	 Player four = player_init("Taloon", one.rupies);
	 getStatus(&two);
	 getStatus(&three);
	 getStatus(&four);
	 printf("\n\n");
	 hBorder();	 

	 Player *table[NUM_PLAYERS];
	 table[0] = &one;
	 table[1] = &two;
	 table[2] = &three;
	 table[3] = &four;

	 int gamenumber = 1;
	 int gamesplayed = 0;
	 while(gamenumber == 1){
		  gamesplayed++;
		  printf("\n\nREADY -- Here we go...\n\n");
		  shuffle(&game_deck, DECK_SIZE);
		  first_Deal(&game_deck, table, NUM_PLAYERS);
		  gamescene(3, table);

		  print_Hand(table, 1);
		  isHand(one.hand);
		  bets = betAmount(&one);
		  printf("%s, bets %i rupies\n",one.name, bets);
		  pot += bets;
		  pot += cpuActions(&game_deck, &two, &one, bets); 
		  pot += cpuActions(&game_deck, &three, &one, bets); 
		  pot += cpuActions(&game_deck, &four, &one, bets); 
		  hBorder();
		  
		  print_Hand(table, 1);
		  print_Options();
		  isHand(one.hand);

		  Deck MC_Deck = create_Monte(&one);
		  monteSuggest(monte_Analysis(&MC_Deck, &one));
		  printTextReco(&one);
		  /*
		  printf("Recommended exchange is: %i %i %i %i %i\n\n", one.mc_reco[0], one.mc_reco[1],one.mc_reco[2],one.mc_reco[3],one.mc_reco[4]);
*/
		  newCards(&game_deck,&one);
		  print_Hand(table, 1);
		  isHand(one.hand);
		  printf("\n\n");
		  bets = betAmount(&one);
		  pot += bets;
		  pot += cpuBets(&two, &one, bets);
		  pot += cpuBets(&three, &one, bets);
		  pot += cpuBets(&four, &one, bets);
		  
		  hBorder();
		  printResults(table);
		  evaluateHands(table); 
		  tableCompareTo(table);

		  /*for testing*/
		  printf("Player one's pos points: %i\nPlayer two's pos points: %i\nPlayer three's pos points: %i\nPlayer four's pos points: %i\n", one.position, two.position, three.position, four.position);

		  winnerIs(table, pot);
		  hBorder();
		  printf("\n");

		  gamenumber = playgame();
		  printf("\n\n\n\n");
		  tableRefresh(table);
	 }
	 return 0;
}
