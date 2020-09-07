#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Property.h"

Game::Game() {
	debug = 1;

	srand((unsigned)time(0));

	m_payTwiceRent = false;

	//Load all data for properties from data file
	loadPropertyData();

	//Setup human and computer players
	setupPlayers();
	

	//Run game
	playGame();
	

}

void Game::loadPropertyData()
{
	std::ifstream file("GameData.csv");
	std::string dataLine = "";
	const int NUM_PROPERTY_VALUES = 12;
	int m_totalProperties = 0;

	int i = 0;
	if (!file)
	{
		std::cout << "ERROR!";
	}
	while (file.good())
	{
		std::getline(file, dataLine, '\n');
		std::stringstream ss(dataLine);
		std::vector<std::string> tokens;
		std::string token;


		//if not at the end of the file
		if (!dataLine.empty())
		{

			//Parse csv data for a property into tokens
			while (getline(ss, token, ','))
			{
				tokens.push_back(token);

			}

			//Set all the data for the property
			m_properties[i].setPropertyID(stoi(tokens[0]));
			m_properties[i].setName(tokens[1]);
			m_properties[i].setPrice(stoi(tokens[2]));
			m_properties[i].setMortgageValue(stoi(tokens[3]));
			m_properties[i].setBuildingCost(stoi(tokens[4]));
			m_properties[i].setRent(stoi(tokens[5]));
			m_properties[i].setMonopolyRent(stoi(tokens[6]));
			m_properties[i].setOneHouseRent(stoi(tokens[7]));
			m_properties[i].setTwoHouseRent(stoi(tokens[8]));
			m_properties[i].setThreeHouseRent(stoi(tokens[9]));
			m_properties[i].setFourHouseRent(stoi(tokens[10]));
			m_properties[i].setHotelRent(stoi(tokens[11]));
			m_properties[i].setPropertyGroupID(stoi(tokens[12]));
			m_properties[i].setPropertyOwnerID(0);
			m_properties[i].setNumHouses(0);
			m_properties[i].setNumHotels(0);

			if (debug)
			{

				std::cout << m_properties[i].getPropertyID() << " " << m_properties[i].getName() << " " << m_properties[i].getPrice() << " "
					<< m_properties[i].getMortgageValue() << " " << m_properties[i].getBuildingCost() << " " << m_properties[i].getRent() << " "
					<< m_properties[i].getMonopolyRent() << " " << m_properties[i].getOneHouseRent() << " " << m_properties[i].getTwoHouseRent()
					<< " " << m_properties[i].getThreeHouseRent() << " " << m_properties[i].getFourHouseRent() << " " <<
					m_properties[i].getHotelRent() << std::endl;
			}
	
			++m_totalProperties;
		}
		++i;

	}
}

void Game::setupPlayers()
{
	std::string playerName = "";
	m_totalPlayers = -1;
	const int MAX_PLAYERS = 8;
	const int MIN_PLAYERS = 0;

	//Get players info from user. Max number of players is 8 including computer players
	while (m_numHumanPlayers <= MIN_PLAYERS || m_numHumanPlayers >= MAX_PLAYERS)
	{
		std::cout << "Please enter the number of human players(maximum is 8): ";
		std::cin >> m_numHumanPlayers;
	}
	do
	{
		std::cout << "Please enter the number of computer players(maximum is " << 8 - m_numHumanPlayers << "): ";
		std::cin >> m_numCompPlayers;
		m_totalPlayers = m_numHumanPlayers + m_numCompPlayers;
	} while (m_totalPlayers >= MAX_PLAYERS || m_totalPlayers <= MIN_PLAYERS);

	for (int i = 0; i < m_totalPlayers-1; ++i)
	{
		std::cout << "Please enter name for Player " << i+1 << ": ";
		std::cin >> m_players[i].name;
		m_players[i].id = i + 1;
		m_players[i].money = 1500;
		m_players[i].curSpot = 0;
		m_players[i].getOutOfJailFree = 0;

	}

	//Randomly set current player
	m_curPlayerID = rand() % (m_totalPlayers + 1);

	if (debug)
	{
		for (int i = 0; i < m_totalPlayers; i++)
		{
			std::cout << m_players[i].name << std::endl;
		}
	}
}

//Function: rollDie
//Purpose: Simulates rolling a die and moves a player that many spots
//Returns: 0 if not doubles rolled, 1 if doubles rolled
int Game::rollDie() {

	int dieRoll = rand() % 7;
	if (dieRoll == 0)
		dieRoll = 1;

	return dieRoll;
}

int Game::calculateRent(int propertyID)
{
	int totalRent = 0;

	if (m_properties[propertyID].getOneHouseRent() > 0)
		totalRent = calculatePropertyRent(propertyID);
	else if (m_properties[propertyID].getName().find("RAILROAD") || m_properties[propertyID].getName().find("SHORT LINE"))
		totalRent = calculateRailroadRent();
	else if (m_properties[propertyID].getName().find("WATER") || m_properties[propertyID].getName().find("ELECTRIC"))
		totalRent = calculateUtilityRent();

	if (m_payTwiceRent == true)
	{
		totalRent = totalRent * 2;
		m_payTwiceRent = false;
	}
	return totalRent;
}

int Game::calculatePropertyRent(int propertyID)
{
	return 0;
}

int Game::calculateRailroadRent()
{
	return 0;
}

int Game::calculateUtilityRent()
{
	return 0;
}

void Game::viewAllProperties()
{
	int propertyNum = 0;
	while (propertyNum < NUM_PROPERTIES)
	{
		std::string propertyPrint = m_properties[propertyNum].getName();
		propertyPrint.append(" ("); 
		propertyPrint.append(getPlayerName(m_properties[propertyNum].getPropertyOwnerID()));
		propertyPrint.append(")      ");

		printf("%-35s", propertyPrint.c_str());
		if (propertyNum % 3 == 0)
			std::cout << "\n";

		++propertyNum;
	}

}

void Game::playGame()
{

	//Show pre-game menu
	//Get user selected choice
	//if r
	//   roll dice
	//   move player
	//   present property options
	//else if v
	//   show all properties and owners
	//else if m
	//   give user choice for which property to mortgage
	bool gameOver = false;

	while (!gameOver)
	{

		showPreRollMenu();

		executePlayersChoice();


		if (m_curPlayerID > m_totalPlayers)
			m_curPlayerID = 1;
		else
			++m_curPlayerID;
	}
}

void Game::showPlayerProperties(int curPlayerID)
{
	int i = 0;
	while (i < m_totalProperties)
	{
		if (m_properties[i].getPropertyOwnerID() == curPlayerID)
		{
			std::cout << m_properties[i].getName() << "\n";
			++i;
		}
	}

}

void Game::rollDice()
{
	int die1Roll,die2Roll = 0;

	die1Roll = rollDie();
	die2Roll = rollDie();

	std::cout << "Dice roll was " << die1Roll << " " << die2Roll << "\n";

	m_players[m_curPlayerID-1].curSpot += die1Roll + die2Roll;

	if (die1Roll == die2Roll)
		m_rollAgain = true;
}

void Game::showPreRollMenu()
{
	std::cout << "(r) Roll Dice (v) View Current Properties (m) Mortgage Property\n";
}

void Game::showPostRollMenu()
{
	int curPropertyID = m_players[m_curPlayerID-1].curSpot;

	//If player landed on a property owned by someone else
	if (m_properties[curPropertyID].getPropertyOwnerID() == m_curPlayerID)
	{ //if current player is owner.  do nothing
		std::cout << "You landed on " << m_properties[m_curPlayerID].getName() << std::endl;
		std::cout << "You own this" << std::endl;
	}
	else if (isProperty(curPropertyID) && m_properties[curPropertyID].getIsOwned())
	{
		std::cout << "You landed on " << m_properties[m_curPlayerID].getName() << std::endl;
		//if is a property and someone else owns it we need to pay rent
		payRent(m_curPlayerID, curPropertyID);
	}
	else if (isProperty(curPropertyID) && !m_properties[curPropertyID].getIsOwned())
	{

	}
	else if (isChance(curPropertyID))
	{
		std::cout << "You landed on Chance\n";
		drawChanceCard();
	}
	else if (isCommunityChest(curPropertyID))
	{
		std::cout << "You landed on Community Chest\n";
		drawCommunityChestCard();
	}
	curPropertyID = m_players[m_curPlayerID - 1].curSpot;
	std::cout << "You landed on " << m_properties[curPropertyID].getName() << std::endl;
	
	if (debug)
	{
		std::cout << "curPropertyID=" << curPropertyID << std::endl;
	}
}

void Game::executePlayersChoice()
{
	char playerChoice;

	std::cout << "Please enter choice: ";
	std::cin >> playerChoice;

	switch (playerChoice)
	{
	case 'R':
	case 'r':
		rollDice();
		showPostRollMenu();
		break;
	case 'V':
	case 'v':
		viewAllProperties();
		break;
	case 'M':
	case 'm':
		
		mortgageProperty();
		break;
	default:
		executePlayersChoice();
		break;
	}
}

void Game::mortgageProperty()
{
	std::string mortgageName = "";

	showPlayerProperties(m_curPlayerID);
	std::cout << "Please enter the name of the mortgage you would like to mortgage: ";
	std::cin >> mortgageName;
}

std::string Game::getPlayerName(int playerID)
{
	//if playerid = 0, then bank owns property
	if (playerID == 0)
		return "NONE";
	else
		return m_players[playerID].name;
}

bool Game::isProperty(int id)
{
	//if able to purchase property
	if (m_properties[id].getPrice() > 0)
		return true;
	else
		return false;
}

bool Game::isChance(int propertyid)
{
	if (m_properties[propertyid].getName() == "CHANCE")
		return true;
	else
		return false;
}

void Game::payRent(int payerid, int propertyid)
{
	int ownerid = 0;
	int rentAmt = 0;

	//find owner of property
	ownerid = m_properties[propertyid].getPropertyOwnerID();

	//calculate total rent for property
	rentAmt = calculateRent(propertyid);

	//Deduct rent from payer and add to owner
	m_players[payerid].money -= rentAmt;
	m_players[ownerid].money += rentAmt;
}

bool Game::isCommunityChest(int propertyid)
{
	if (m_properties[propertyid].getName() == "COMMUNITY CHEST")
		return true;
	else
		return false;

}

void Game::drawCommunityChestCard()
{
	std::cout << "Drawing a community chest card" << std::endl;

	int cardNum = rand() % 18;

	switch (cardNum)
	{
	case 1:
		std::cout << "Advance to Go (collect $200)\n";
		m_players[m_curPlayerID - 1].curSpot = 0;
		m_players[m_curPlayerID - 1].money += 200;
		break;
	case 2:
		std::cout << "Bank error in your favor - Collect $200\n";
		m_players[m_curPlayerID - 1].money += 200;
		break;
	case 3:
		std::cout << "Doctor's fees - Pay $50\n";
		m_players[m_curPlayerID - 1].money -= 50;
		break;
	case 4:
		std::cout << "Get out of jail free card\n";
		m_players[m_curPlayerID - 1].getOutOfJailFree += 1;
		break;
	case 5:
		std::cout << "Go to jail - Do not pass go - Do not collect $200\n";
		m_players[m_curPlayerID - 1].curSpot = 10;
		break;
	case 6:
		std::cout << "Grand Opera Night - Collect $50 from every player for opening night seats\n";
		collectMoneyFromEachPlayer(50);
		break;
	case 7:
		std::cout << "Holiday fund matures - Collect $100\n";
		m_players[m_curPlayerID - 1].money += 100;
		break;
	case 8:
		std::cout << "Income tax refund - Collect $20\n";
		m_players[m_curPlayerID].money += 20;
		break;
	case 9:
		std::cout << "It is your birthday - Collect $10 from each player\n";
		collectMoneyFromEachPlayer(10);
		break;
	case 10:
		std::cout << "Life insurance matures - Collect $100\n";
		m_players[m_curPlayerID].money += 100;
		break;
	case 11:
		std::cout << "Pay hospital fees of $100\n";
		m_players[m_curPlayerID - 1].money -= 100;
		break;
	case 12:
		std::cout << "Pay school fees of $150\n";
		m_players[m_curPlayerID - 1].money -= 150;
		break;
	case 13:
		std::cout << "Receive $25 consultancy fee\n";
		m_players[m_curPlayerID - 1].money += 25;
		break;
	case 14:
		std::cout << "You are assessed for street repairs - $40 per house - $115 per hotel\n";
		payForHousesAndHotels(40, 115);
		break;
	case 15:
		std::cout << "You have won second price at a beauty contest - Collect $10\n";
		m_players[m_curPlayerID - 1].money += 10;
		break; 
	case 16:
		std::cout << "You inherit $100\n";
		m_players[m_curPlayerID - 1].money += 100;
		break;
	default:
		std::cout << "ERROR - Unknown community chance card drawn.";
	}
}

void Game::drawChanceCard()
{
	std::cout << "Drawing a chance card" << std::endl;

	int cardNum = rand() % 18;

	switch (cardNum)
	{
	case 1:
		std::cout << "Advance to Go (Collect $200)\n";
		m_players[m_curPlayerID - 1].money += 200;
		m_players[m_curPlayerID - 1].curSpot = 0;
		break;
	case 2:
		std::cout << "Advance to Illinois Ave. - If you pass Go, collect $200\n";
		m_players[m_curPlayerID].curSpot = 24;
		if (m_players[m_curPlayerID].curSpot > 24)
			m_players[m_curPlayerID].money += 200;
		break;
	case 3:
		std::cout << "Advance to St.  Charles Place - If you pass Go, collect $200\n";
		m_players[m_curPlayerID].curSpot = 11;
		if (m_players[m_curPlayerID].curSpot > 11)
			m_players[m_curPlayerID].money += 200;
		break;
	case 4:
		std::cout << "Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times the amount thrown. \n";
		if (m_players[m_curPlayerID].curSpot < 20 && m_players[m_curPlayerID].curSpot > 2)
			m_players[m_curPlayerID].curSpot = 12;
		else
			m_players[m_curPlayerID].curSpot = 26;
		break;
	case 5:
	case 6:
		std::cout << "Advance token to nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled  If Railroad is unowned you may buy it from the bank. \n";
		if (m_players[m_curPlayerID].curSpot < 10 && m_players[m_curPlayerID].curSpot >= 0)
			m_players[m_curPlayerID].curSpot = 5;
		else if(m_players[m_curPlayerID].curSpot < 20 && m_players[m_curPlayerID].curSpot >= 10)
			m_players[m_curPlayerID].curSpot = 15;
		else if (m_players[m_curPlayerID].curSpot < 30 && m_players[m_curPlayerID].curSpot >= 20)
			m_players[m_curPlayerID].curSpot = 25;
		else 
			m_players[m_curPlayerID].curSpot = 35;
		m_payTwiceRent = true;
		break;
	case 7:
		std::cout << "Bank pays you a dividend of $50. \n";
		m_players[m_curPlayerID].money += 50;
		break;
	case 8:
		std::cout << "Get out of Jail Free.  This card may be kept until needed.\n";
		m_players[m_curPlayerID].getOutOfJailFree += 1;
		break;
	case 9:
		std::cout << "Go Back 3 Spaces.\n";
		m_players[m_curPlayerID].curSpot -= 3;
		break;
	case 10:
		std::cout << "Make general repairs on all your properties - $25 per house - $100 per hotel\n";
		payForHousesAndHotels(25, 100);
		break;
	case 11:
		std::cout << "Pay poor tax of $15.\n";
		m_players[m_curPlayerID].money -= 15;
		break;
	case 12:
		std::cout << "Take a trip to Reading Railroad.\n";
		m_players[m_curPlayerID].curSpot = 5;
		break;
	case 13:
		std::cout << "Take a walk on the Boardwalk – Advance token to Boardwalk.\n";
		m_players[m_curPlayerID].curSpot = 39;
		break;
	case 14:
		std::cout << "You have been elected Chairman of the Board – Pay each player $50.\n";
		payMoneyToEachPlayer(50);
		break;
	case 15:
		std::cout << "Your building loan matures – Collect $150\n";
		m_players[m_curPlayerID].money += 50;
		break;
	case 16:
		std::cout << "You have won a crossword competition - Collect $100\n";
		m_players[m_curPlayerID].money += 100;
		break;


	}
}

void Game::collectMoneyFromEachPlayer(int amount)
{
	int moneyCollected = 0;

	for (int i = 0; i < m_totalPlayers;  ++i)
	{
		if (i != (m_curPlayerID - 1))
		{
			m_players[i].money -= amount;
			moneyCollected += amount;
		}
	}

	m_players[m_curPlayerID].money += moneyCollected;
	std::cout << "You collected " << moneyCollected << " \n";
}

void Game::payMoneyToEachPlayer(int amount)
{
	int moneyPaid = 0;

	for (int i = 0; i < m_totalPlayers;++i)
	{
		if (i != (m_curPlayerID - 1))
		{
			m_players[i].money += amount;
			moneyPaid += amount;
		}
	}

	m_players[m_curPlayerID].money -= moneyPaid;
	std::cout << "You paid " << moneyPaid << " \n";
}

void Game::payForHousesAndHotels(int houseAmt, int hotelAmt)
{
	int totalMoneyDue = 0;

	for (int i = 0; i < m_totalProperties; ++i)
	{
		if (m_properties[i].getPropertyOwnerID() == m_players[m_curPlayerID].id)
		{
			totalMoneyDue += m_properties[i].getNumHouses() * houseAmt;
			totalMoneyDue += m_properties[i].getNumHotels() * hotelAmt;
		}
	}

	std::cout << "You paid " << totalMoneyDue << " for your houses & hotels\n";
}
