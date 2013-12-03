#include "hedz.h"



/***********************************************************
 *  the interface abstract is to interact with the user and *
 *  return a value to be used by the driver to update the   *
 *  status of the players attributes or the deck functions. *
 *  these are welcome/getName/getRupies/betAmount/newCards  *
 ***********************************************************/
void welcome(){
	 printf("\n\nWELCOME TO SCHMIDTCHUNK CASINO\n");
	 printf("--© 1998-2013 Schmidt Enterprises--\n--------------------------\n\n\n");
	 printf("Mario, Link and Taloon are waiting for you to sit down\n\n");
}

int playgame(){
	 char *game = malloc(sizeof(char)*255);
	 printf("Would you like to play again (please answer 'y' or 'n')? --> ");
	 scanf("%s",game);
	 if((strcmp(game, "y") ==0) || (strcmp(game, "yes") == 0)){
		  return 1;	  
	 }
	 else{
		  return 0;
	 }
}

void gamescene(int numPlayers, Player *table[]){
	 print_Dummy(table[1]);
	 printf("\n");
	 print_Dummy(table[2]);
	 printf("\n");
	 print_Dummy(table[3]);
}

char *getName(){
	 char * name = malloc(sizeof(char)*255);
	 printf("Please type in your name and hit enter\nso you won't be a stranger! --> ");
	 scanf("%s",name);
	 printf("\n");

	 return name;
}

int getRupies(){
	 int *rupies;
	 int x = 0;
	 rupies = &x;
	 printf("Please enter how many rupies would you like\nto play poker with today--> ");
	 scanf("%i", rupies);
	 printf("\n");

	 return *rupies;
}

int betAmount(Player *one){
	 int *bet;
	 int x =0;
	 bet = &x;
	 printf("How much would you like to wager--> ");
	 scanf("%i",bet);
	 one->rupies -= (*bet);
	 printf("\n");

	 return *bet;
}

int newCards(Deck *dealer, Player *player){
	 int *new;
	 int x = 0;
	 new = &x;
	 printf("How many cards would you like?--> ");
	 scanf("%i",new);
	 swap(dealer, player, *new);
	 return *new;
}

int swap(Deck *dealer, Player *player, int numCards){
	 int c, i, x = numCards;
	 printf("Please type the letter of the card you would like to exchange--> ");
	 while(x > 0){
		  c = getchar();
		  if(c == ' '){

		  }

		  else if(c == 'a'){
				i = 0;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'b'){
				i = 1;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'c'){
				i = 2;
				x--;
				exchange(dealer, player, i);
		  }

		  else if(c == 'd'){
				i = 3;
				x--;
				exchange(dealer, player, i);
		  }
		  else if(c == 'e'){
				i = 4;
				x--;
				exchange(dealer, player, i);
		  }
	 }

	 return 0;
}

/************************************************************
 *  displayDeck, displayCard and print_Hand are interface   *
 *  functions for interactions with the user. displayDeck   *
 *  is mostly used for testing, but displayCard is of great *
 *  importance for the exchange functions.                  *
 ***********************************************************/

int displayDeck(Deck deck){
	 int i;
	 printf("\n");
	 for(i=0;i<DECK_SIZE;i++){
		  printf("%s%s ",deck.deckCards[i].face, deck.deckCards[i].suit);
	 }
	 printf("\n");

	 return 0;
}

int displayCard(Card card){
	 printf("%s%s", card.face, card.suit);

	 return 0;
}

void displayHand(Player *currentPlayer, Card *hand){
	 int i;
	 for (i=0;i<HAND_SIZE; i++){
		  printf(" %s %s ", hand[i].face, hand[i].suit);
	 }
}

/***********************************************************
 *  this is the main print function for displaying a persons*
 *  hand with user name and format.                   r     *
 ***********************************************************/

void print_Hand(Player *table[], int playerNum){
	 if(playerNum == 1){
		  printf("\n");
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[0]->name, table[0]->hand[0].face, table[0]->hand[0].suit, table[0]->hand[1].face, table[0]->hand[1].suit, table[0]->hand[2].face, table[0]->hand[2].suit, table[0]->hand[3].face, table[0]->hand[3].suit, table[0]->hand[4].face, table[0]->hand[4].suit);
	 }
	 else if(playerNum == 2){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[1]->name, table[1]->hand[0].face, table[1]->hand[0].suit, table[1]->hand[1].face, table[1]->hand[1].suit, table[1]->hand[2].face, table[1]->hand[2].suit, table[1]->hand[3].face, table[1]->hand[3].suit, table[1]->hand[4].face, table[1]->hand[4].suit);
	 }
	 else if(playerNum == 3){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[2]->name, table[2]->hand[0].face, table[2]->hand[0].suit, table[2]->hand[1].face, table[2]->hand[1].suit, table[2]->hand[2].face, table[2]->hand[2].suit, table[2]->hand[3].face, table[2]->hand[3].suit, table[2]->hand[4].face, table[2]->hand[4].suit);
	 }
	 else if(playerNum == 4){
		  printf("%s\n %s%s  %s%s  %s%s  %s%s  %s%s\n", table[3]->name, table[3]->hand[0].face, table[3]->hand[0].suit, table[3]->hand[1].face, table[3]->hand[1].suit, table[3]->hand[2].face, table[3]->hand[2].suit, table[3]->hand[3].face, table[3]->hand[3].suit, table[3]->hand[4].face, table[3]->hand[4].suit);
	 }
}

/***********************************************************
 *  print_Dummy and print_Options are interface interaction *
 *  functions which allow the gui to operate as a poker     *
 *  interface should. These are 'easy' calls from the driver*
 *  for game flow.                                          *
 ***********************************************************/

void print_Dummy(Player *player){
	 int i;
	 printf("%s\n", player->name);
	 for(i = 0;i<HAND_SIZE;i++){
		  printf(" 🂠  ");

	 }
	 printf("\n");
}

void print_Options(){

	 printf(" a   b   c   d   e  \n\n");
	 printf("------------------------------------------------------\n|please select which cards would you like to exchange|\n|by typing the letter(s) of the card(s) below the    |\n|corresponding cards and hit enter. Example: a d     |\n------------------------------------------------------ \n");

}

void hBorder(){
	 printf("******************************************************\n");
}

void vBorder(int x){
	 while(x>0){
		  printf("*                                                    *\n");
		  x--;
	 }
}

void tableRefresh(Player *table[]){
	 int i;
	 for(i = 0;i<NUM_PLAYERS;i++){
		  table[i]->position = 0;
		  table[i]->inGame = 1;
	 }

}

void printResults(Player *table[]){
	 int i;
	 for(i = 0;i<NUM_PLAYERS;i++){
		  if(table[i]->inGame != 0){
				print_Hand(table, i+1);
				isHand(table[i]->hand);
		  }
	 }


}

void evaluateHands(Player *table[]){
	 int i;
	 for(i = 0;i<NUM_PLAYERS;i++){
		  if(table[i]->inGame != 0){
				handRank(table[i]);
		  }
	 }

}

int needRaise(Player *p1, Player *user, int bet){
	 
	 char *raise = malloc(sizeof(char)*255);
	 printf("%s raised to %i would you like to call or raise (Please type 'c' or 'r')? --> ", p1->name, bet);
	 scanf("%s", raise);
	 if((strcmp(raise, "c") ==0) || strcmp(raise, "call") == 0){
	 user->rupies -= bet;
	 printf("%s called %s\n", user->name, p1->name);
	 }
	 else if((strcmp(raise, "raise") ==0) || strcmp(raise, "r") == 0){
		betAmount(user);			
	 }
	 else{
		user->inGame = 0;
		printf("%s folded...", user->name);
	 }

	 return bet;
}

int monteSuggest(double rank){
	int i;
	int scale[10];
	for(i=0;i<10;i++){
		scale[i] = 0;
	}
	if(rank <= 12){
		scale[0]++;
	}

	if(rank > 12 && rank <=25){
		scale[1]++;

	}


	if(rank > 25 && rank <=54){
		scale[2]++;

	}
	if(rank >54 && rank <=67){
		scale[3]++;

	}
	if(rank >67 && rank <=81){
		scale[4]++;

	}
	if(rank >81 && rank <=97){
		scale[5]++;

	}
	if(rank >97 && rank <=113){
		scale[6]++;

	}
	if(rank > 113 && rank <=127){
		scale[7]++;

	}
	if(rank > 127 && rank <= 139){
		scale[8]++;

	}
	if(rank == 140){
		scale[9]++;

	}
	printReco(scale);
	return 0;
}

void printReco(int scale[10]){
	if(scale[0] == 1){
		printf("AI Data shows the most probable outcome to be a high card with the below exchange of cards...");
	}

	if(scale[1] == 1){
		printf("AI Data shows the most probable outcome to be a pair with the below exchange of cards...");
	}
	if(scale[2] == 1){
		printf("AI Data shows the most probable outcome to be two pair with the below exchange of cards...");
	}
	if(scale[3] == 1){
		printf("AI Data shows the most probable outcome to be three of a kind with the below exchange of cards...");
	}
	if(scale[4] == 1){
		printf("AI Data shows the most probable outcome to be a straight with the below exchange of cards...");
	}
	if(scale[5] == 1){
		printf("AI Data shows the most probable outcome to be a flush with the below exchange of cards...");
	}
	if(scale[6] == 1){
		printf("AI Data shows the most probable outcome to be a full house with the below exchange of cards...");
	}
	if(scale[7] == 1){
		printf("AI Data shows the most probable outcome to be four of a kind with the below exchange of cards...");
	}
	if(scale[8] == 1){
		printf("AI Data shows the most probable outcome to be a straight flush with the below exchange of cards...");
	}
	if(scale[9] == 1){
		printf("AI Data shows the most probable outcome to be a royal flush with the below exchange of cards...");
	}

	printf("\n");
}

int printTextReco(Player *person){
		if(person->mc_reco[0] == 1){
			printf(" a  ");
		}
		else{
			printf("    ");
		}
		if(person->mc_reco[1] == 1){
			printf(" b  ");
		}
		else{
			printf("    ");
		}
		if(person->mc_reco[2] == 1){
			printf(" c  ");
		}
		else{
			printf("    ");
		}
		if(person->mc_reco[3] == 1){
			printf(" d  ");
		}
		else{
			printf("    ");
		}
		if(person->mc_reco[4] == 1){
			printf(" e  ");
		}
		else{
			printf("    ");
		}
printf("\n");
return 0;
}
