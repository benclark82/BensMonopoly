#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "Property.h"

class Game {
public:
	Game();

	void loadPropertyData();


private:
	struct Player {
		int id; //1-8
		std::string name; 
		int curSpot;
		int money;
		int getOutOfJailFree;
		std::vector<int> propertiesOwned;

	};


	int rollDie();
	int calculateRent(int propertyID);
	int calculatePropertyRent(int propertyID);
	int calculateRailroadRent();
	int calculateUtilityRent();
	void rollDice();
	void playGame();
	void setupPlayers();
	void viewAllProperties();
	void showPlayerProperties(int curPlayerID);
	void mortgageProperty();
	void showPreRollMenu();
	void showPostRollMenu();
	void executePlayersChoice();
	void drawCommunityChestCard();
	void drawChanceCard();
	void collectMoneyFromEachPlayer(int amount);
	void payMoneyToEachPlayer(int amount);
	void payRent(int payerid, int propertyid);
	void payForHousesAndHotels(int houseAmt, int hotelAmt);
	bool isProperty(int propertyid);
	bool isChance(int propertyid);
	bool isCommunityChest(int propertyid);
	std::string getPlayerName(int playerID);

	//Number of properties in game
	const int NUM_PROPERTIES = 40;

	//Player rolled doubles and gets to go again
	bool m_rollAgain;

	//Player pays twice rent if true
	bool m_payTwiceRent;

	//Used for debug purposes
	int debug;

	//Number of human players playing the game
	int m_numHumanPlayers;

	//Number of computer players playing the game
	int m_numCompPlayers;

	//Current player that is their turn
	int m_curPlayerID;

	//Number of human and computer players
	int m_totalPlayers;

	//Number of properties in game
	int m_totalProperties;

	Property m_properties[40];
	Player m_players[8];
};

#endif